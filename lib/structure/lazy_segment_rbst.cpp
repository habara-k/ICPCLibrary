#include "../template.cpp"

/**
 * @brief
 * 列を管理する平衡二分木
 * 任意箇所の要素の更新・取得・挿入・削除をO(log n)で行う.
 * モノイドが乗る. 区間取得をO(log n) で行う.
 * 遅延処理が乗る.
 * @author habara-k
 * @date 2020/05/05
 */

template<typename M, typename OM = M>
struct LazySegmentRBST {

    struct Node {
        Node *lch, *rch;
        int sz;
        M data, sum;
        OM lazy;
        Node(const M& data, const OM& lazy) :
            lch(nullptr), rch(nullptr), sz(1),
            data(data), sum(data), lazy(lazy) {}
    };

    using F = function<M(M,M)>;
    using G = function<M(M,OM,int)>;
    using H = function<OM(OM,OM)>;

    LazySegmentRBST(const F& f, const G& g, const H& h, M e, OM oe) :
        f(f), g(g), h(h), e(e), oe(oe), root(nullptr) {}

    /**
    * @brief 配列で初期化する. O(n)
    */
    void build(const vector<M>& v) { root = build(v, 0, v.size()); }

    /**
    * @brief 木のサイズを返す. O(1)
    */
    inline int size() {
        return size(root);
    }

    /**
    * @brief 区間update. O(log n)
    * @param[in] a, b: updateする区間
    * @param[in] lazy: 作用の要素
    */
    void update(int a, int b, const OM& lazy) {
        auto p0 = split(root, a);
        auto p1 = split(p0.second, b-a);
        p1.first->lazy = h(p1.first->lazy, lazy);
        p1.first = propagate(p1.first);
        root = merge(p0.first, merge(p1.first, p1.second));
    }

    /**
    * @brief 要素の取得を行う. O(log n)
    * @param[in] a, b: 取得したい区間
    * @return 取得した値
    */
    M query(int a, int b) {
        auto p0 = split(root, a);
        auto p1 = split(p0.second, b - a);
        p1.first = propagate(p1.first);
        M ret = sum(p1.first);
        root = merge(p0.first, merge(p1.first, p1.second));
        return ret;
    }

    /**
    * @brief 要素の取得を行う. O(log n)
    * @param[in] i: 取得したい要素のindex
    * @return 取得した値
    */
    M operator[](int i) {
        return query(i, i + 1);
    }

    /**
    * @brief 要素の挿入を行う. O(log n)
    * @param[in] i: 挿入したいindex
    * @param[in] data: 挿入したい値
    */
    void insert(int i, const M& data) {
        auto q = _new(data);
        auto p = split(root, i);
        root = merge(merge(p.first, q), p.second);
    }

    /**
    * @brief 要素の削除を行う. O(log n)
    * @param[in] i: 挿入したいindex
    */
    M erase(int i) {
        auto p = split(root, i);
        auto q = split(p.second, 1);
        M ret = q.first->data;
        root = merge(p.first, q.second);
        return ret;
    }

    /**
    * @brief vector みたいに出力.
    */
    friend ostream& operator<<(ostream& os,
                               LazySegmentRBST& tr) {
        os << "[";
        for (int i = 0; i < tr.size(); ++i) {
            if (i) os << " ";
            os << tr[i];
        }
        return os << "]";
    }

protected:
    Node* root;

    inline int size(Node* t) const { return t ? t->sz : 0; }
    inline M sum(Node* t) const { return t ? t->sum : e; }
    inline OM lazy(Node* t) const { return t ? t->lazy : oe; }

    Node* merge(Node *l, Node *r) {
        if (!l) return r;
        if (!r) return l;
        if (xor128() % (size(l) + size(r)) < size(l)) {
            l = propagate(l);
            l->rch = merge(l->rch, r);
            return modify(l);
        } else {
            r = propagate(r);
            r->lch = merge(l, r->lch);
            return modify(r);
        }
    }

    pair<Node*, Node*> split(Node* t, int k) {
        if (!t) return {t, t};
        t = propagate(t);
        if (k > size(t->lch)) {
            auto p = split(t->rch, k-size(t->lch)-1);
            t->rch = p.first;
            return {modify(t), p.second};
        } else {
            auto p = split(t->lch, k);
            t->lch = p.second;
            return {p.first, modify(t)};
        }
    }

private:
    const F f;
    const G g;
    const H h;
    const M e;
    const OM oe;

    inline int xor128() {
        static int x = 123456789;
        static int y = 362436069;
        static int z = 521288629;
        static int w = 88675123;
        int t;

        t = x ^ (x << 11);
        x = y;
        y = z;
        z = w;
        return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
    }

    Node* build(const vector<M>& v, int l, int r) {
        if (l + 1 >= r) return _new(v[l]);
        return merge(build(v, l, (l + r) >> 1),
                     build(v, (l + r) >> 1, r));
    }

    inline Node* _new(const M& data) const { return new Node(data, oe); }

    inline Node* modify(Node *t) {
        t->sz = size(t->lch) + size(t->rch) + 1;
        t->sum = f(f(sum(t->lch), t->data), sum(t->rch));
        return t;
    }

    Node* propagate(Node* t) {
        if (!t) return t;
        if (lazy(t) == oe) return t;
        if (t->lch != nullptr) {
            t->lch->lazy = h(lazy(t->lch), lazy(t));
            t->lch->sum = g(sum(t->lch), lazy(t), size(t->lch));
        }
        if (t->rch != nullptr) {
            t->rch->lazy = h(lazy(t->rch), lazy(t));
            t->rch->sum = g(sum(t->rch), lazy(t), size(t->rch));
        }
        t->data = g(t->data, lazy(t), 1);
        t->lazy = oe;
        return modify(t);
    }
};
