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


# :heavy_check_mark: graph/kruskal.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/kruskal.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-23 18:17:04+09:00




## Depends on

* :question: <a href="template.cpp.html">graph/template.cpp</a>
* :heavy_check_mark: <a href="../structure/union_find.cpp.html">structure/union_find.cpp</a>
* :question: <a href="../template.cpp.html">template.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/graph/kruskal.test.cpp.html">test/graph/kruskal.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include "template.cpp"

#include "../structure/union_find.cpp"

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

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "graph/template.cpp"



#line 1 "template.cpp"



#include <bits/stdc++.h>

using namespace std;

#define REP(i, n) for (int i=0; i<(n); ++i)
#define RREP(i, n) for (int i=(int)(n)-1; i>=0; --i)
#define FOR(i, a, n) for (int i=(a); i<(n); ++i)
#define RFOR(i, a, n) for (int i=(int)(n)-1; i>=(a); --i)

#define SZ(x) ((int)(x).size())
#define all(x) begin(x),end(x)

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

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

