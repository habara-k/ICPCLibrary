#include "../template.cpp"

/*
 * @breif 赤黒木
 * @ref
 * https://ei1333.github.io/luzhiled/snippets/structure/red-black-tree.html
 * http://blog.mitaki28.info/1447078746296/
 * @author habara-k
 * @data 2020/10/22
 * @details
 * merge, split, insert, erase, range-query, range-update: O(log n)
 * WARNING: POOL >= 2*MAX_N となるようにPOOLをとる
 */
template<
        class M,
        M (*f)(M,M),
        M (*e)(),
        class OM,
        M (*g)(M, OM),
        OM (*h)(OM, OM),
        OM (*id)(),
        int POOL>
struct RBTree {
    RBTree() : pool(POOL), stock(POOL) { clear(); }

    static const bool R = 0, B = 1;
    struct node;
    using ptr = node*;
    struct node {
        ptr l=nullptr, r=nullptr;
        M prd = e();
        OM lazy = id();
        int sz=1, rnk=0;
        bool color=B;
        node() {}
        node(M val) : prd(val) {}
        node(ptr l, ptr r, int color) : l(l), r(r), prd(f(l->prd,r->prd)),
                                        sz(l->sz + r->sz), rnk(l->rnk + l->color), color(color) {}
    };
    int size() { return size(root); }
    int size(ptr p) { return p ? p->sz : 0; }

    void build(const vector<M>& init) {
        root = build(init, 0, init.size());
    }

    ptr merge(ptr a, ptr b) {
        if (!a) return b;
        if (!b) return a;
        auto c = mergeSub(a, b);
        return asRoot(c);
    }
    pair<ptr,ptr> split(ptr a, int k) {
        assert(0 <= k and k <= size(a));
        if (k == 0) return {nullptr, a};
        if (k == size(a)) return {a, nullptr};
        a = push(a);
        ptr l = a->l, r = a->r;
        del(a);
        if (k < l->sz) {
            auto p = split(l, k);
            return {p.first, merge(p.second, asRoot(r))};
        }
        if (k > l->sz) {
            auto p = split(r, k - l->sz);
            return {merge(asRoot(l), p.first), p.second};
        }
        return {asRoot(l), asRoot(r)};
    }

    void insert(int k, M val) {
        assert(0 <= k and k <= size());
        auto p = split(root, k);
        root = merge(merge(p.first, alloc(val)), p.second);
    }
    M erase(int k) {
        assert(0 <= k and k < size());
        auto p = split(root, k);
        auto q = split(p.second, 1);
        M val = q.first->prd;
        del(q.first);
        root = merge(p.first, q.second);
        return val;
    }

    M prod(int l, int r) {
        assert(0 <= l and l <= r and r <= size());
        return prod(root, 0, root->sz, id(), l, r);
    }
    M operator[](int k) {
        assert(0 <= k and k < size());
        return prod(k, k+1);
    }
    void apply(int l, int r, OM lazy) {
        assert(0 <= l and l <= r and r <= size());
        auto p = split(root, l);
        auto q = split(p.second, r-l);
        root = merge(p.first, merge(set_lazy(q.first, lazy), q.second));
    }
    friend ostream &operator<<(ostream &os, RBTree &t) {
        for (int i = 0; i < t.root->sz; ++i) {
            if (i) cout << ' ';
            cout << t[i];
        }
        return os;
    }
    ptr root;

protected:

    vector<node> pool;
    vector<ptr> stock;
    int head = POOL;

    template<typename... U>
    ptr alloc(U... args) {
        return &(*stock[--head] = node(args...));
    }
    void delf(ptr p) {
        stock[head++] = p;
    }
    virtual void del(ptr p) {
        delf(p);
    }
    void clear() {
        head = POOL;
        for (int i = 0; i < POOL; ++i) stock[i] = &pool[i];
    }
    inline virtual ptr clone(ptr p) {
        return p;
    }

    ptr set_lazy(ptr p, const OM& lazy) {
        p = clone(p);
        p->prd = g(p->prd, lazy);
        if (p->l) p->lazy = h(p->lazy, lazy);
        return p;
    }

    ptr push(ptr p) {
        if (p->lazy == id()) return p;
        p->l = set_lazy(p->l, p->lazy);
        p->r = set_lazy(p->r, p->lazy);
        p->lazy = id();
        return p;
    }

    ptr build(const vector<M>& init, int l, int r) {
        if (r - l == 1) return alloc(init[l]);
        return merge(build(init, l, (l+r)/2), build(init, (l+r)/2, r));
    }

    ptr mergeSub(ptr a, ptr b) {
        if (a->rnk < b->rnk) {
            b = push(b);
            auto c = mergeSub(a, b->l);
            ptr ret;
            if (b->color and !c->color and !c->l->color) {
                if (b->r->color) ret = alloc(c->l, alloc(c->r, b->r, R), B), delf(c);
                else ret = alloc(asRoot(c), asRoot(b->r), R);
            } else {
                ret = alloc(c, b->r, b->color);
            }
            del(b); return ret;
        } else if (a->rnk > b->rnk) {
            a = push(a);
            auto c = mergeSub(a->r, b);
            ptr ret;
            if (a->color and !c->color and !c->r->color) {
                if (a->l->color) ret = alloc(alloc(a->l, c->l, R), c->r, B), delf(c);
                else ret = alloc(asRoot(a->l), asRoot(c), R);
            } else {
                ret = alloc(a->l, c, a->color);
            }
            del(a); return ret;
        } else {
            return alloc(a, b, R);
        }
    }

    ptr asRoot(ptr p) {
        if (!p or p->color) return p;
        p->color = B;
        return p;
    }

    M prod(ptr p, int a, int b, OM lazy, int l, int r) {
        if (b <= l or r <= a) return e();
        if (l <= a and b <= r) return g(p->prd, lazy);
        return f(prod(p->l, a, a + p->l->sz, h(p->lazy, lazy), l, r),
                 prod(p->r, b - p->r->sz, b, h(p->lazy, lazy), l, r));
    }
};

/*
 * @breif 永続赤黒木
 * @ref
 * https://ei1333.github.io/luzhiled/snippets/structure/red-black-tree.html
 * http://blog.mitaki28.info/1447078746296/
 * @author habara-k
 * @data 2020/10/22
 * @details
 * copy-and-paste ができる.
 * WARNING: POOLはできるだけ大きくとる(メモリ制約を確認)
 * WARNING: クエリの終わりに必ず if (full()) rebuild() を呼ぶ.
 */
template<
        class M,
        M (*f)(M,M),
        M (*e)(),
        class OM,
        M (*g)(M, OM),
        OM (*h)(OM, OM),
        OM (*id)(),
        int POOL,
        int FULL=1000>
struct PersistentRBTree : RBTree<M,f,e,OM,g,h,id,POOL> {
    using RBT = RBTree<M,f,e,OM,g,h,id,POOL>;
    using ptr = typename RBT::ptr;
    inline ptr clone(ptr p) override {
        return &(*this->stock[--this->head] = *p);
    }
    inline void del(ptr p) override {}
    bool full() {
        return this->head < FULL;
    }
    void rebuild() {
        vector<M> data(this->size());
        auto it = data.begin();
        dfs(this->root, id(), it);
        this->clear();
        this->build(data);
    }
    void dfs(ptr p, OM lazy, typename vector<M>::iterator& it) {
        if (!p->l) {
            *it++ = g(p->prd, lazy);
            return;
        }
        lazy = h(lazy, p->lazy);
        dfs(p->l, lazy, it);
        dfs(p->r, lazy, it);
    }
};

