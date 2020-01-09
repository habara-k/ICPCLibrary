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


# :warning: test/graph/warshall_floyd.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#baa37bfd168b079b758c0db816f7295f">test/graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/graph/warshall_floyd.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-05 00:07:05+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C">https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C</a>


## Depends on

* :heavy_check_mark: <a href="../../graph/template.cpp.html">graph/template.cpp</a>
* :warning: <a href="../../graph/warshall_floyd.cpp.html">graph/warshall_floyd.cpp</a>
* :heavy_check_mark: <a href="../../template.cpp.html">template.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C"

#include "../../graph/warshall_floyd.cpp"

int main() {
    int V, E;
    cin >> V >> E;

    const int INF = numeric_limits<int>::max();
    vector<vector<int>> G(V, vector<int>(V, INF));
    for (int i = 0; i < V; ++i) G[i][i] = 0;
    for (int i = 0; i < E; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        G[x][y] = z;
    }

    warshall_floyd(G);
    for (int i = 0; i < V; ++i) {
        if (G[i][i] < 0) {
            puts("NEGATIVE CYCLE");
            return 0;
        }
    }
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            if (j > 0) putchar(' ');
            if (G[i][j] == INF) printf("INF");
            else printf("%d", G[i][j]);
        }
        putchar('\n');
    }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/graph/warshall_floyd.cpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C"

#line 1 "test/graph/../../graph/template.cpp"



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


#line 5 "test/graph/../../graph/template.cpp"

template<typename T>
struct edge {
    int src, to;
    T cost;
    // edge(int src, int to, T cost): src(src), to(to), cost(cost) {}
    // // G[i].push_back({src, to, cost}) requires no constructor
};

template<typename T>
using Graph = vector<vector<edge<T>>>;


#line 2 "test/graph/../../graph/warshall_floyd.cpp"

template<typename T>
void warshall_floyd(vector<vector<T>> &g) {
    const auto INF = numeric_limits<T>::max();
    int n = g.size();
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(g[i][k] == INF || g[k][j] == INF) continue;
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
}
#line 4 "test/graph/warshall_floyd.cpp"

int main() {
    int V, E;
    cin >> V >> E;

    const int INF = numeric_limits<int>::max();
    vector<vector<int>> G(V, vector<int>(V, INF));
    for (int i = 0; i < V; ++i) G[i][i] = 0;
    for (int i = 0; i < E; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        G[x][y] = z;
    }

    warshall_floyd(G);
    for (int i = 0; i < V; ++i) {
        if (G[i][i] < 0) {
            puts("NEGATIVE CYCLE");
            return 0;
        }
    }
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            if (j > 0) putchar(' ');
            if (G[i][j] == INF) printf("INF");
            else printf("%d", G[i][j]);
        }
        putchar('\n');
    }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

