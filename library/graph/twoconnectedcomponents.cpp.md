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


# :warning: graph/twoconnectedcomponents.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/twoconnectedcomponents.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-07 03:51:42+09:00




## Depends on

* :warning: <a href="lowlink.cpp.html">graph/lowlink.cpp</a>
* :question: <a href="template.cpp.html">graph/template.cpp</a>
* :question: <a href="../template.cpp.html">template.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include "./lowlink.cpp"

template<typename T>
struct TwoEdgeConnectedComponents: LowLink<T> {
    using lowlink = LowLink<T>;
    vector<int> comp;

    TwoEdgeConnectedComponents(const Graph<T> &g): lowlink(g) {}

    int operator[] (const int &k) {
        return comp[k];
    }

    void dfs(int idx, int par, int &k) {
        if(!par && this->pre[par] >= this->low[idx]) comp[idx] = comp[par];
        else comp[idx] == k++;
        for(auto &e: this->g[idx]) {
            if(comp[e.to] == -1) dfs(e.to, idx, k);
        }
    }

    void build(Graph<T> &t) {
        lowlink::build();
        comp.assign(this->g.size(), -1);
        int k = 0;
        for(int i=0;i<(int)(comp.size());++i) {
            if(comp[i] == -1) dfs(i, -1, k);
        }
        t.resize(k);
        for(auto &e: this->bridge) {
            int x = comp[e.first], y = comp[e.second];
            t[x].push_back(y);
            t[y].push_back(x);
        }
    }
};
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


#line 2 "graph/lowlink.cpp"

template<typename T>
struct LowLink {
    const int inf = 1000000000;
    int sz;
    std::vector<int> pre, low;
    std::vector<bool> sel;
    std::vector<std::pair<int, int>> bridge;
    std::vector<int> articulation;

    LowLink(const Graph<T> &g) {
        sz = g.size();
        pre.resize(sz, inf);
        low.resize(sz, inf);
        sel.resize(sz, false);
        int cnt = 0;
        dfs(g, 0, -1, cnt);
    }

    void dfs(const Graph<T> &g, int now, int prev, int &cnt) {
        if(pre[now] != inf) {
            low[prev] = min(low[prev], pre[now]);
            return;
        }
        pre[now] = cnt;
        low[now] = cnt;
        cnt++;
        for(int i=0;i<(int)(g[now].size());++i) {
            int nxt = g[now][i].to;
            //if g is an undirected graph
            if(nxt == prev) continue;
            dfs(g, nxt, now, cnt);
        }
        if(prev != -1) low[prev] = min(low[prev], low[now]);
        if(prev != -1 && pre[prev] < low[now]) {
            bridge.emplace_back(make_pair(prev, now));
        }
    }

    void get_articulation(const Graph<T> &g, int now, int prev) {
        sel[now] = true;
        int art = 0;
        for(int i=0;i<(int)(g[now].size());++i) {
            int nxt = g[now][i].to;
            //cout << now << ":" << nxt << endl;
            if(sel[nxt]) continue;
            // if g is an undirected graph
            if(nxt == prev) continue;
            if(now == 0 || pre[now] <= low[nxt]) art++;
            get_articulation(g, nxt, now);
        }
        if((now == 0 && art >= 2) || (now != 0 && art >= 1)) {
            articulation.push_back(now);
        }
    }
};
#line 2 "graph/twoconnectedcomponents.cpp"

template<typename T>
struct TwoEdgeConnectedComponents: LowLink<T> {
    using lowlink = LowLink<T>;
    vector<int> comp;

    TwoEdgeConnectedComponents(const Graph<T> &g): lowlink(g) {}

    int operator[] (const int &k) {
        return comp[k];
    }

    void dfs(int idx, int par, int &k) {
        if(!par && this->pre[par] >= this->low[idx]) comp[idx] = comp[par];
        else comp[idx] == k++;
        for(auto &e: this->g[idx]) {
            if(comp[e.to] == -1) dfs(e.to, idx, k);
        }
    }

    void build(Graph<T> &t) {
        lowlink::build();
        comp.assign(this->g.size(), -1);
        int k = 0;
        for(int i=0;i<(int)(comp.size());++i) {
            if(comp[i] == -1) dfs(i, -1, k);
        }
        t.resize(k);
        for(auto &e: this->bridge) {
            int x = comp[e.first], y = comp[e.second];
            t[x].push_back(y);
            t[y].push_back(x);
        }
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

