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


# :heavy_check_mark: test/graph/kruskal.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#baa37bfd168b079b758c0db816f7295f">test/graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/graph/kruskal.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-07 03:51:42+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A">https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/graph/kruskal.cpp.html">graph/kruskal.cpp</a>
* :question: <a href="../../../library/graph/template.cpp.html">graph/template.cpp</a>
* :heavy_check_mark: <a href="../../../library/structure/union_find.cpp.html">structure/union_find.cpp</a>
* :question: <a href="../../../library/template.cpp.html">template.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A"

#include "../../graph/kruskal.cpp"

int main() {
    int V, E;
    cin >> V >> E;
    vector<edge<int>> edges;
    for(int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({a, b, c});
    }
    cout << kruskal(edges, V) << endl;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/graph/kruskal.test.cpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A"

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


#line 2 "graph/kruskal.cpp"

#line 2 "structure/union_find.cpp"

struct UnionFind
{
    vector<int> par, sz;
    UnionFind(int n) : par(n), sz(n, 1) {
        for (int i = 0; i < n; ++i) par[i] = i;
    }
    int root(int x) {
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }
    void merge(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return;
        if (sz[x] < sz[y]) swap(x, y);
        par[y] = x;
        sz[x] += sz[y];
        sz[y] = 0;
    }
    bool issame(int x, int y) {
        return root(x) == root(y);
    }
    int size(int x) {
        return sz[root(x)];
    }
};
#line 4 "graph/kruskal.cpp"

template<typename T>
T kruskal(vector<edge<T>> &es, int V) {

    UnionFind uf(V);
    T ret = 0;

    // sort destructively
    sort(es.begin(), es.end(), [](edge<T> &a,edge<T> &b){
            return a.cost < b.cost;
            });
    for (auto &e : es) {
        if (!uf.issame(e.src, e.to)) {
            ret += e.cost;
            uf.merge(e.src, e.to);
        }
    }

    // // sort only the order to check
    // vector<int> ord(es.size());
    // iota(ord.begin(), ord.end(), 0);
    // sort(ord.begin(), ord.end(), [&](int i,int j){
    //         return es[i].cost < es[j].cost;
    //         });
    // for (auto i : ord) {
    //     auto &e = es[i];
    //     if (!uf.issame(e.src, e.to)) {
    //         ret += e.cost;
    //         uf.merge(e.src, e.to);
    //     }
    // }

    return ret;
}
#line 4 "test/graph/kruskal.test.cpp"

int main() {
    int V, E;
    cin >> V >> E;
    vector<edge<int>> edges;
    for(int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({a, b, c});
    }
    cout << kruskal(edges, V) << endl;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

