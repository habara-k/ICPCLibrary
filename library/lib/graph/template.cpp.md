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


# :heavy_check_mark: lib/graph/template.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#6e267a37887a7dcb68cbf7008d6c7e48">lib/graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/lib/graph/template.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-25 22:26:20+09:00




## Depends on

* :heavy_check_mark: <a href="../template.cpp.html">lib/template.cpp</a>


## Required by

* :heavy_check_mark: <a href="bfs01.cpp.html"> <small>(lib/graph/bfs01.cpp)</small></a>
* :heavy_check_mark: <a href="dijkstra.cpp.html"> <small>(lib/graph/dijkstra.cpp)</small></a>
* :heavy_check_mark: <a href="dinic.cpp.html"> <small>(lib/graph/dinic.cpp)</small></a>
* :heavy_check_mark: <a href="hopcroft_karp.cpp.html"> <small>(lib/graph/hopcroft_karp.cpp)</small></a>
* :heavy_check_mark: <a href="kruskal.cpp.html"> <small>(lib/graph/kruskal.cpp)</small></a>
* :warning: <a href="lowlink.cpp.html">lib/graph/lowlink.cpp</a>
* :warning: <a href="maximum_clique.cpp.html">lib/graph/maximum_clique.cpp</a>
* :heavy_check_mark: <a href="primal_dual.cpp.html">lib/graph/primal_dual.cpp</a>
* :heavy_check_mark: <a href="scc.cpp.html">lib/graph/scc.cpp</a>
* :warning: <a href="topological_sort.cpp.html">lib/graph/topological_sort.cpp</a>
* :warning: <a href="twoconnectedcomponents.cpp.html">lib/graph/twoconnectedcomponents.cpp</a>
* :heavy_check_mark: <a href="warshall_floyd.cpp.html">lib/graph/warshall_floyd.cpp</a>
* :warning: <a href="../../test/graph/maximum_clique.cpp.html">test/graph/maximum_clique.cpp</a>
* :warning: <a href="../../test/graph/topological_sort.cpp.html">test/graph/topological_sort.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/graph/bfs01.test.cpp.html">test/graph/bfs01.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/graph/dijkstra.test.cpp.html">test/graph/dijkstra.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/graph/dinic.test.cpp.html">test/graph/dinic.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/graph/hopcroft_karp.test.cpp.html">test/graph/hopcroft_karp.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/graph/kruskal.test.cpp.html">test/graph/kruskal.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/graph/primal_dual.test.cpp.html">test/graph/primal_dual.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/graph/scc.test.cpp.html">test/graph/scc.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/graph/warshall_floyd.test.cpp.html">test/graph/warshall_floyd.test.cpp</a>


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
#line 1 "lib/graph/template.cpp"



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


#line 5 "lib/graph/template.cpp"

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

<a href="../../../index.html">Back to top page</a>

