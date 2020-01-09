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


# :warning: test/graph/lowest_common_ancestor.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#baa37bfd168b079b758c0db816f7295f">test/graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/graph/lowest_common_ancestor.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-05 00:07:05+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_C">https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_C</a>


## Depends on

* :warning: <a href="../../graph/lowest_common_ancestor.cpp.html">graph/lowest_common_ancestor.cpp</a>
* :warning: <a href="../../template.cpp.html">template.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_C"

#include "../../graph/lowest_common_ancestor.cpp"

int main() {
    int N, Q;
    cin >> N;
    vector<vector<int>> g(N);
    for(int i = 0; i < N; i++) {
        int k; cin >> k;
        while (k--) {
            int c; cin >> c;
            g[i].push_back(c);
        }
    }
    LCA lca(g);
    cin >> Q;
    while (Q--) {
        int x, y; cin >> x >> y;
        printf("%d\n", lca.query(x, y));
    }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/graph/lowest_common_ancestor.cpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_C"

#line 1 "test/graph/../../graph/../template.cpp"



#include <bits/stdc++.h>
using namespace std;

#define SZ(x) (int)(x.size())
#define REP(i, n) for(int i = 0; i < n; i++)
#define FOR(i, a, b) for(int i = a; i < b; i++)

using ll = long long;
using ld = long double;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
const double eps = 1e-8;
const int MOD = 1000000007;

//int main() {
//    cin.tie(0);
//    ios::sync_with_stdio(false);
//    cout << fixed << setprecision(10);
//
//}


#line 2 "test/graph/../../graph/lowest_common_ancestor.cpp"

struct LCA {
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

    LCA(const vector<vector<int>>& G, int root=0) :
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

    int query(int u, int v) {
        if (depth[u] > depth[v]) swap(u, v);

        // align the depth of u and v
        for (int k = 0; k <= log2_n; ++k) {
            if ((depth[v] - depth[u]) >> k & 1) {
                v = par[k][v];
            }
        }
        if (u == v) return u;

        // go back until u and v's parents do not match
        for (int k = log2_n; k >= 0; --k) {
            if (par[k][u] != par[k][v]) {
                u = par[k][u];
                v = par[k][v];
            }
        }
        return par[0][u];
    }
};
#line 4 "test/graph/lowest_common_ancestor.cpp"

int main() {
    int N, Q;
    cin >> N;
    vector<vector<int>> g(N);
    for(int i = 0; i < N; i++) {
        int k; cin >> k;
        while (k--) {
            int c; cin >> c;
            g[i].push_back(c);
        }
    }
    LCA lca(g);
    cin >> Q;
    while (Q--) {
        int x, y; cin >> x >> y;
        printf("%d\n", lca.query(x, y));
    }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

