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
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :heavy_check_mark: graph/template.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/template.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-07 03:51:42+09:00




## Depends on

* :heavy_check_mark: <a href="../template.cpp.html">template.cpp</a>


## Required by

* :heavy_check_mark: <a href="bfs01.cpp.html"> <small>(graph/bfs01.cpp)</small></a>
* :heavy_check_mark: <a href="dijkstra.cpp.html"> <small>(graph/dijkstra.cpp)</small></a>
* :heavy_check_mark: <a href="dinic.cpp.html"> <small>(graph/dinic.cpp)</small></a>
* :heavy_check_mark: <a href="hopcroft_karp.cpp.html">graph/hopcroft_karp.cpp</a>
* :heavy_check_mark: <a href="kruskal.cpp.html">graph/kruskal.cpp</a>
* :warning: <a href="lowlink.cpp.html">graph/lowlink.cpp</a>
* :warning: <a href="maximum_clique.cpp.html">graph/maximum_clique.cpp</a>
* :heavy_check_mark: <a href="primal_dual.cpp.html">graph/primal_dual.cpp</a>
* :heavy_check_mark: <a href="scc.cpp.html">graph/scc.cpp</a>
* :warning: <a href="topological_sort.cpp.html">graph/topological_sort.cpp</a>
* :warning: <a href="twoconnectedcomponents.cpp.html">graph/twoconnectedcomponents.cpp</a>
* :heavy_check_mark: <a href="warshall_floyd.cpp.html">graph/warshall_floyd.cpp</a>
* :warning: <a href="../test/graph/maximum_clique.cpp.html">test/graph/maximum_clique.cpp</a>
* :warning: <a href="../test/graph/topological_sort.cpp.html">test/graph/topological_sort.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/graph/bfs01.test.cpp.html">test/graph/bfs01.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/graph/dijkstra.test.cpp.html">test/graph/dijkstra.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/graph/dinic.test.cpp.html">test/graph/dinic.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/graph/hopcroft_karp.test.cpp.html">test/graph/hopcroft_karp.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/graph/kruskal.test.cpp.html">test/graph/kruskal.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/graph/primal_dual.test.cpp.html">test/graph/primal_dual.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/graph/scc.test.cpp.html">test/graph/scc.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/graph/warshall_floyd.test.cpp.html">test/graph/warshall_floyd.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef GRAPH_TEMPLATE
#define GRAPH_TEMPLATE

#include "../template.cpp"

template<typename T>
struct edge {
    int src, to;
    T cost;
    // edge(int src, int to, T cost): src(src), to(to), cost(cost) {}
    // // G[i].push_back({src, to, cost}) requires no constructor
};

template<typename T>
using Graph = vector<vector<edge<T>>>;

#endif

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "graph/template.cpp"



#line 1 "template.cpp"



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
const ld eps = 1e-9;
const ll MOD = 1000000007;

//int main() {
//    cin.tie(0);
//    ios::sync_with_stdio(false);
//    cout << fixed << setprecision(10);
//
//}


#line 5 "graph/template.cpp"

template<typename T>
struct edge {
    int src, to;
    T cost;
    // edge(int src, int to, T cost): src(src), to(to), cost(cost) {}
    // // G[i].push_back({src, to, cost}) requires no constructor
};

template<typename T>
using Graph = vector<vector<edge<T>>>;



```
{% endraw %}

<a href="../../index.html">Back to top page</a>

