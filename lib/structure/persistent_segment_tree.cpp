#include "../template.cpp"

/**
* @brief 完全永続セグメント木
* @author habara-k
* @date 2020/05/04
* @details 使い方
*   build, updateするたびにNode* が返る.
*   これを保存して置いて, 取得時に利用する.
*
*   e.g.
*   vector<vector<int>> g(n) // tree;
*   PersistentSegmentTree<int> segt(
*           sz, [](int a,int b){ return a+b; }, 0);
*
*   // 頂点 -> Node* を保存する.
*   map<int,PersistentSegmentTree<int>::Node*> root;
*
*   function<void(int,int)> dfs = [&](int v, int p) {
*       root[v] = segt.update(root[p],
*               x[v], [](int a){ return a+1; });
*       for (int u : G[v]) {
*           if (u != p) dfs(u, v);
*       }
*   };
*
*   root[-1] = segt.build();
*   dfs(0, -1);
*/
template<typename M>
struct PersistentSegmentTree {
    struct Node {
        Node *l, *r;
        M data;
        Node() : l(nullptr), r(nullptr) {}
    };

    /**
    * @brief コンストラクタ. O(1)
    * @param[in] n 遅延セグ木のサイズ.
    * @param[in] f モノイドの演算.
    * @param[in] e モノイドの単位元.
    * @details 使い方
    *   e.g. Range Sum
    *   PersistentSegmentTree<int> segt(
    *            n, [](int a,int b){ return a+b; }, 0);
    */
    PersistentSegmentTree(int n, const function<M(M,M)>& f, const M& e) :
            n(n), f(f), e(e) {}

    /**
    * @brief セグメント木を構築する. O(nlog n)
    * @details 使い方
    *   root[-1] = segt.build();
    */
    Node* build() const {
        return build(0, n);
    }

    /**
    * @brief 指定した位置に更新クエリを実行する. O(log n)
    * @param[in] root: 作用させるセグ木の根.
    * @param[in] k: 位置k の要素に作用させる.
    * @param[in] q: 値x をq(x) で更新する.
    * @details 使い方
    *   e.g. Add Query
    *   int i, x; // 位置i をx を足したい.
    *   root[v] = segt.update(root[p], i, [&](int a){ return a + x; });
    *
    *   e.g. Update Query
    *   int i, x; // 位置i をx に更新したい.
    *   root[v] = segt.update(root[p], i, [&](int a){ return x; });
    */
    template<typename UpdateQuery>
    Node* update(Node* root, int k, const UpdateQuery& q) const {
        return update(root, k, q, 0, n);
    }

    /**
    * @brief 指定した区間に取得クエリを実行する. O(log n)
    * @param[in] l, r 区間[l, r) を取得する.
    * @return 取得した値.
    * @details 使い方
    *   e.g. Range Minimum
    *   int l, r; // 区間[l, r) のminを取得したい.
    *   cout << segt.query(root[v], l, r) << endl;
    */
    M query(Node* root, int a, int b) const {
        return query(root, a, b, 0, n);
    }

private:
    const int n;
    const function<M(M,M)> f;
    const M e;

    Node* _new(const M& data) const {
        auto t = new Node();
        t->data = data;
        return t;
    }

    Node* _new(Node* l, Node* r) const {
        auto t = new Node();
        t->l = l, t->r = r, t->data = f(l->data, r->data);
        return t;
    }

    Node* build(int l, int r) const {
        assert(l < r);
        if (l + 1 == r) return _new(e);
        return _new(build(l, (l + r) >> 1), build((l + r) >> 1, r));
    }

    template<typename UpdateQuery>
    Node* update(Node* t, int k, const UpdateQuery& q, int l, int r) const {
        if (k == l and k + 1 == r) return _new(q(t->data));
        if (r <= k or k < l) return t;
        return _new(update(t->l, k, q, l, (l + r) >> 1),
                    update(t->r, k, q, (l + r) >> 1, r));
    }

    M query(Node* t, int a, int b, int l, int r) const {
        if (r <= a or b <= l) return e;
        if (a <= l and r <= b) return t->data;
        return f(query(t->l, a, b, l, (l + r) >> 1),
                 query(t->r, a, b, (l + r) >> 1, r));
    }
};
