---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :heavy_check_mark: test/structure/persistent_segment_tree.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#2c7aa83aa7981015c539598d29afdf98">test/structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/structure/persistent_segment_tree.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-04 16:42:34+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2270">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2270</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/lib/graph/lowest_common_ancestor.cpp.html"> <small>(lib/graph/lowest_common_ancestor.cpp)</small></a>
* :heavy_check_mark: <a href="../../../library/lib/structure/persistent_segment_tree.cpp.html">完全永続セグメント木 <small>(lib/structure/persistent_segment_tree.cpp)</small></a>
* :question: <a href="../../../library/lib/template.cpp.html">lib/template.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2270"

#include "../../lib/structure/persistent_segment_tree.cpp"
#include "../../lib/graph/lowest_common_ancestor.cpp"

int main()
{
    int N, Q;
    cin >> N >> Q;
    vector<int> x(N);
    for (int i = 0; i < N; ++i) {
        cin >> x[i];
    }

    vector<vector<int>> G(N);
    for (int i = 0; i < N-1; ++i) {
        int a, b; cin >> a >> b;
        --a, --b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    // compress
    map<int,int> comp, comp_inv;
    for (auto X : x) comp[X] = -1;
    int comp_size = 0;
    for (auto &p : comp) {
        p.second = comp_size++;
    }
    for (auto p : comp) {
        comp_inv[p.second] = p.first;
    }

    // lca
    auto lca = LCA(G);

    // persistent segtree
    PersistentSegmentTree<int> segt(
            comp.size(), [](int a,int b){ return a+b; }, 0);

    map<int,PersistentSegmentTree<int>::Node*> root;
    vector<int> par(N);

    function<void(int,int)> dfs = [&](int v, int p) {
        par[v] = p;
        root[v] = segt.update(root[p],
                comp[x[v]], [](int a){ return a+1; });
        for (int u : G[v]) {
            if (u != p) dfs(u, v);
        }
    };

    root[-1] = segt.build();
    dfs(0, -1);

    for (int i = 0; i < Q; ++i)
    {
        int v, w, l; cin >> v >> w >> l; --v, --w;

        // search x s.t. there are more than l numbers less than or equal to x

        int u = lca.query(v, w);

        auto check = [&](int m) {
            int nv = segt.query(root[v], 0, m+1),
                nw = segt.query(root[w], 0, m+1),
                nu = segt.query(root[u], 0, m+1),
                np = segt.query(root[par[u]], 0, m+1);

            return nv + nw - nu - np >= l;
        };

        int ng = -1, ok = comp.size()-1;
        while (abs(ok - ng) > 1) {
            int mid = (ng + ok) / 2;
            (check(mid) ? ok : ng) = mid;
        }

        cout << comp_inv[ok] << endl;
    }

    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/structure/persistent_segment_tree.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2270"

#line 1 "lib/template.cpp"



#include <bits/stdc++.h>

using namespace std;

#define REP(i, n) for (int i=0; i<(n); ++i)
#define RREP(i, n) for (int i=(int)(n)-1; i>=0; --i)
#define FOR(i, a, n) for (int i=(a); i<(n); ++i)
#define RFOR(i, a, n) for (int i=(int)(n)-1; i>=(a); --i)

#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

#define dump(x) cerr<<#x<<" = "<<(x)<<endl
#define debug(x) cerr<<#x<<" = "<<(x)<<" (L"<<__LINE__<<")"<<endl;

template<class T>
ostream &operator<<(ostream &os, const vector <T> &v) {
    os << "[";
    REP(i, SZ(v)) {
        if (i) os << ", ";
        os << v[i];
    }
    return os << "]";
}

template<class T, class U>
ostream &operator<<(ostream &os, const pair <T, U> &p) {
    return os << "(" << p.first << " " << p.second << ")";
}

template<class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
bool chmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using P = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using vvll = vector<vll>;

const ll MOD = 1e9 + 7;
const int INF = INT_MAX / 2;
const ll LINF = LLONG_MAX / 2;
const ld eps = 1e-9;

/*
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);

    // ifstream in("in.txt");
    // cin.rdbuf(in.rdbuf());

    return 0;
}
*/


#line 2 "lib/structure/persistent_segment_tree.cpp"

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
#line 2 "lib/graph/lowest_common_ancestor.cpp"

/**
 * @brief
 * 最小共通祖先（ダブリング）
 * 構築O(VlogV), クエリO(logV)
 *
 * LCA(G, root)で構築（無向木Gを、rootを根として向きづけしたときのLCAを構築）
 * query(u, v)で取得
 *
 * @author ゆきのん？
 * @date 2019/12
 */

struct LCA {

    /**
    * @brief コンストラクタ. O(nlog n)
    * @param[in] G 無向木.
    * @param[in] root 指定した根.
    */
    LCA(const vector<vector<int>>& G, int root = 0) :
            n(G.size()), log2_n(log2(n)), depth(n),
            par(log2_n+1, vector<int>(n,-1)) {

        dfs(G, root, -1, 0);

        for (int k = 0; k < log2_n; ++k) {
            for (int v = 0; v < n; ++v) {
                if (par[k][v] != -1) {
                    par[k+1][v] = par[k][par[k][v]];
                }
            }
        }
    }

    /**
    * @brief lca を取得する. O(log n);
    * @param[in] u, v: lca を求めたい2頂点.
    * @return u, v のlca.
    */
    int query(int u, int v) {
        if (depth[u] > depth[v]) swap(u, v);

        for (int k = 0; k <= log2_n; ++k) {
            if ((depth[v] - depth[u]) >> k & 1) {
                v = par[k][v];
            }
        }
        if (u == v) return u;

        for (int k = log2_n; k >= 0; --k) {
            if (par[k][u] != par[k][v]) {
                u = par[k][u];
                v = par[k][v];
            }
        }
        return par[0][u];
    }

private:
    int n, log2_n;
    vector<int> depth;
    vector<vector<int>> par;

    void dfs(const vector<vector<int>>& G, int v, int p, int d) {
        depth[v] = d;
        par[0][v] = p;
        for (auto to : G[v]) {
            if (to != p) dfs(G, to, v, d+1);
        }
    }
};
#line 5 "test/structure/persistent_segment_tree.test.cpp"

int main()
{
    int N, Q;
    cin >> N >> Q;
    vector<int> x(N);
    for (int i = 0; i < N; ++i) {
        cin >> x[i];
    }

    vector<vector<int>> G(N);
    for (int i = 0; i < N-1; ++i) {
        int a, b; cin >> a >> b;
        --a, --b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    // compress
    map<int,int> comp, comp_inv;
    for (auto X : x) comp[X] = -1;
    int comp_size = 0;
    for (auto &p : comp) {
        p.second = comp_size++;
    }
    for (auto p : comp) {
        comp_inv[p.second] = p.first;
    }

    // lca
    auto lca = LCA(G);

    // persistent segtree
    PersistentSegmentTree<int> segt(
            comp.size(), [](int a,int b){ return a+b; }, 0);

    map<int,PersistentSegmentTree<int>::Node*> root;
    vector<int> par(N);

    function<void(int,int)> dfs = [&](int v, int p) {
        par[v] = p;
        root[v] = segt.update(root[p],
                comp[x[v]], [](int a){ return a+1; });
        for (int u : G[v]) {
            if (u != p) dfs(u, v);
        }
    };

    root[-1] = segt.build();
    dfs(0, -1);

    for (int i = 0; i < Q; ++i)
    {
        int v, w, l; cin >> v >> w >> l; --v, --w;

        // search x s.t. there are more than l numbers less than or equal to x

        int u = lca.query(v, w);

        auto check = [&](int m) {
            int nv = segt.query(root[v], 0, m+1),
                nw = segt.query(root[w], 0, m+1),
                nu = segt.query(root[u], 0, m+1),
                np = segt.query(root[par[u]], 0, m+1);

            return nv + nw - nu - np >= l;
        };

        int ng = -1, ok = comp.size()-1;
        while (abs(ok - ng) > 1) {
            int mid = (ng + ok) / 2;
            (check(mid) ? ok : ng) = mid;
        }

        cout << comp_inv[ok] << endl;
    }

    return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

