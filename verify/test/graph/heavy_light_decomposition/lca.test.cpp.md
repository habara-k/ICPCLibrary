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
<script type="text/javascript" src="../../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../../assets/css/copy-button.css" />


# :heavy_check_mark: test/graph/heavy_light_decomposition/lca.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#f108cdd252ebfc58a7b9bc5c4c206374">test/graph/heavy_light_decomposition</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/graph/heavy_light_decomposition/lca.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-04 15:56:10+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_C">https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_C</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/lib/graph/heavy_light_decomposition.cpp.html">HL分解 <small>(lib/graph/heavy_light_decomposition.cpp)</small></a>
* :heavy_check_mark: <a href="../../../../library/lib/template.cpp.html">lib/template.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_C"

#include "../../../lib/graph/heavy_light_decomposition.cpp"

int main() {
    int N, Q;
    cin >> N;
    vector<vector<int>> g(N);
    for (int i = 0; i < N; ++i) {
        int k; cin >> k;
        while (k--) {
            int c; cin >> c;
            g[i].push_back(c);
        }
    }

    HLDecomposition hld(g);
    hld.build(0);

    cin >> Q;
    while (Q--) {
        int x, y; cin >> x >> y;
        printf("%d\n", hld.lca(x, y));
    }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/graph/heavy_light_decomposition/lca.test.cpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_C"

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


#line 2 "lib/graph/heavy_light_decomposition.cpp"

/**
* @brief HL分解
* @author habara-k
* @date 2020/04/26
* @details 使い方
*   vector<vector<int>> g(n); // tree
*
*   HLDecomposition hld(g);
*   hld.build(); // 必ずbuildする!
*/

struct HLDecomposition {

    /**
    * @brief コンストラクタ. O(|V|).
    * @param[in] g HL分解する木.
    */
    HLDecomposition(const vector<vector<int>>& g) :
        g(g), par(g.size()), size(g.size()), depth(g.size()),
        head(g.size()), vid(g.size()) {}

    /**
    * @brief HL分解を行う. O(|V|).
    * @param[in] root 根を指定する. デフォルトは0
    */
    void build(int root = 0) {
        dfs(root, -1, 0);
        int k = 0;
        hld(root, root, k);
    }

    /**
    * @brief HL分解を行う. O(log|V|).
    * @param[in] u, v lcaを求めたい2頂点
    * @return 2頂点u, v のlca
    */
    int lca(int u, int v) const {
        for (;; v = par[head[v]]) {
            if (depth[head[u]] > depth[head[v]]) swap(u, v);
            if (head[u] == head[v]) {
                if (depth[u] > depth[v]) swap(u, v);
                return u;
            }
        }
    }

    /**
    * @brief 指定した2頂点間のパス上で更新クエリを実行する. O(log|V|) * O(q).
    * @param[in] u, v 更新クエリを実行するパスの両端.
    * @param[in] q 実行する更新クエリ.
    * @param[in] edge 辺クエリか頂点クエリか. デフォルトは頂点クエリ.
    *   辺クエリ:
    *     木上の辺に対してクエリを処理する.
    *     辺のデータは子頂点のindexに対応している.
    *     親頂点のindexに対応する辺は無い.
    *   頂点クエリ:
    *     木上の頂点に対してクエリを処理する.
    *
    * @details 使い方
    *     e.g. Range Update Query
    *     LazySegmentTree<int> segt;
    *            // 木に対応する遅延セグメント木.
    *            // 木の頂点がそのままsegtのindexになるわけでは無いので注意.
    *     int u, v, x;
    *            // u, v 間のパス上にある全ての頂点の値をx に変更したい.
    *     hld.update(u, v, [&](int s,int t){ segt.update(s, t, x); });
    *            // u, v 間のパスを小分けにした区間全体に
    *            // 第三引数の関数が実行される.
    */
    template<class UpdateQuery>
    void update(int u, int v, const UpdateQuery& q, bool edge = false) const {
        for (;; v = par[head[v]]) {
            if (depth[head[u]] > depth[head[v]]) swap(u, v);
            if (head[u] == head[v]) {
                if (vid[u] > vid[v]) swap(u, v);
                q(vid[u] + edge, vid[v] + 1);
                break;
            } else {
                q(vid[head[v]], vid[v] + 1);
            }
        }
    }

    /**
    * @brief 指定した2頂点間のパス上で取得クエリを実行. O(log|V|) * (O(q)+O(f)).
    * @param[in] u, v 取得クエリを実行するパスの両端.
    * @param[in] q 実行する取得クエリ.
    * @param[in] f 小分けにした区間から取得した値をマージする方法.
    * @param[in] ident fの単位元.
    * @param[in] edge 辺クエリか頂点クエリか. デフォルトは頂点クエリ.
    * @return 取得した値.
    *
    * @details 使い方
    *     e.g. Range Minimum Query
    *     SegmentTree<int> segt;
    *            // 木に対応するセグメント木.
    *            // 木の頂点がそのままsegtのindexになるわけでは無いので注意.
    *     int u, v;
    *            // u, v 間のパス上にある全ての頂点の値のminを取得したい.
    *     hld.query(u, v,
    *          [&](int s,int t){ return segt.query(s,t); },
    *          [&](int a,int b){ return min(a,b); }, INF);
    *            // u, v 間のパスを小分けにした区間全体に
    *            // 第三引数の関数が実行される.
    *            // 各区間から取得した値は, 第四引数の関数によってマージされる.
    *            // minの単位元INFを第五引数に渡す.
    */
    template<class Query, class MergeFunc, typename T>
    T query(int u, int v,
            const Query& q, const MergeFunc& f,
            const T& ident, bool edge = false) const {
        T ret = ident;
        for (;; v = par[head[v]]) {
            if (depth[head[u]] > depth[head[v]]) swap(u, v);
            if (head[u] == head[v]) {
                if (vid[u] > vid[v]) swap(u, v);
                return f(ret, q(vid[u] + edge, vid[v] + 1));
            } else {
                ret = f(ret, q(vid[head[v]], vid[v] + 1));
            }
        }
    }

private:
    const vector<vector<int>>& g;
    vector<int> par, size, depth, head, vid;
    // par[v] := 頂点v の親頂点.
    // size[v] := 頂点v を根とした部分木の頂点数.
    // depth[v] := 頂点v の深さ. 根の深さは0.
    // head[v] := HL分解した際に, 頂点v を含む区間の先頭に位置する頂点.
    // vid[v] := 頂点v に対応する内部index.
    //           HL分解した後の各区間上で, vidは連続している.

    void dfs(int v, int p, int d) {
        par[v] = p; depth[v] = d; size[v] = 1;
        for (int u : g[v]) {
            if (u == p) continue;
            dfs(u, v, d+1);
            size[v] += size[u];
        }
    }
    void hld(int v, int h, int& k) {
        head[v] = h; vid[v] = k++;
        int ma = 0, id = -1;
        for (int u : g[v]) {
            if (u == par[v]) continue;
            if (chmax(ma, size[u])) id = u;
        }
        if (id == -1) return;
        hld(id, h, k);
        for (int u : g[v]) {
            if (u == id or u == par[v]) continue;
            hld(u, u, k);
        }
    }
};
#line 4 "test/graph/heavy_light_decomposition/lca.test.cpp"

int main() {
    int N, Q;
    cin >> N;
    vector<vector<int>> g(N);
    for (int i = 0; i < N; ++i) {
        int k; cin >> k;
        while (k--) {
            int c; cin >> c;
            g[i].push_back(c);
        }
    }

    HLDecomposition hld(g);
    hld.build(0);

    cin >> Q;
    while (Q--) {
        int x, y; cin >> x >> y;
        printf("%d\n", hld.lca(x, y));
    }
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

