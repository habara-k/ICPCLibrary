#include "../template.cpp"

/**
 * @brief
 * 列を管理する平衡二分木
 * 任意箇所の要素の更新・取得・挿入・削除をO(log n)で行う.
 * @author habara-k
 * @date 2020/05/05
 */

template<typename T>
struct RandomizedBinarySearchTree {

    struct Node {
        Node *lch, *rch;
        int sz;
        T data;
        Node(const T& data) :
                lch(nullptr), rch(nullptr), sz(1),
                data(data) {}
    };

    RandomizedBinarySearchTree() : root(nullptr) {}

    /**
    * @brief 配列で初期化する. O(n)
    */
    void build(const vector<T>& v) { root = build(v, 0, v.size()); }

    /**
    * @brief 木のサイズを返す. O(1)
    */
    inline int size() {
        return size(root);
    }

    /**
    * @brief 要素の更新を行う. O(log n)
    * @param[in] i: 要素のindex
    * @param[in] q: x をq(x) で更新する.
    */
    template<class UpdateQuery>
    void update(int i, const UpdateQuery& q) {
        auto p0 = split(root, i);
        auto p1 = split(p0.second, 1);
        p1.first->data = q(p1.first->data);
        root = merge(p0.first, merge(p1.first, p1.second));
    }

    /**
    * @brief 要素の取得を行う. O(log n)
    * @param[in] i: 取得したい要素のindex
    * @return 取得した値
    */
    T operator[](int i) {
        auto p0 = split(root, i);
        auto p1 = split(p0.second, 1);
        T ret = p1.first->data;
        root = merge(p0.first, merge(p1.first, p1.second));
        return ret;
    }

    /**
    * @brief 要素の挿入を行う. O(log n)
    * @param[in] i: 挿入したいindex
    * @param[in] data: 挿入したい値
    */
    void insert(int i, const T& data) {
        auto q = _new(data);
        auto p = split(root, i);
        root = merge(merge(p.first, q), p.second);
    }

    /**
    * @brief 要素の削除を行う. O(log n)
    * @param[in] i: 挿入したいindex
    */
    T erase(int i) {
        auto p = split(root, i);
        auto q = split(p.second, 1);
        T ret = q.first->data;
        root = merge(p.first, q.second);
        return ret;
    }

    /**
    * @brief vector みたいに出力.
    */
    friend ostream& operator<<(ostream& os,
                               RandomizedBinarySearchTree& tr) {
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

    Node* merge(Node *l, Node *r) {
        if (!l) return r;
        if (!r) return l;
        if (xor128() % (size(l) + size(r)) < size(l)) {
            l->rch = merge(l->rch, r);
            return modify(l);
        } else {
            r->lch = merge(l, r->lch);
            return modify(r);
        }
    }

    pair<Node*, Node*> split(Node* t, int k) {
        if (!t) return {t, t};
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

    Node* build(const vector<T>& v, int l, int r) {
        if (l + 1 >= r) return _new(v[l]);
        return merge(build(v, l, (l + r) >> 1),
                     build(v, (l + r) >> 1, r));
    }

    inline Node* _new(const T& data) const { return new Node(data); }

    inline Node* modify(Node *t) {
        t->sz = size(t->lch) + size(t->rch) + 1;
        return t;
    }
};
