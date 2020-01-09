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


# :heavy_check_mark: graph/primal_dual.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/primal_dual.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-05 00:59:25+09:00




## Depends on

* :heavy_check_mark: <a href="template.cpp.html">graph/template.cpp</a>
* :heavy_check_mark: <a href="../template.cpp.html">template.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/graph/primal_dual.test.cpp.html">test/graph/primal_dual.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include "template.cpp"

template<typename flow_t, typename cost_t>
struct PrimalDual {
    const cost_t INF;

    struct edge {
        int to;
        flow_t cap;
        cost_t cost;
        int rev;
    };
    vector<vector<edge>> g;
    vector<cost_t> h, d;
    vector<int> prevv, preve;

    PrimalDual(int V) : g(V), INF(numeric_limits< cost_t >::max()) {}

    void add_edge(int from, int to, flow_t cap, cost_t cost) {
        g[from].push_back({to, cap, cost, (int)g[to].size()});
        g[to].push_back({from, 0, -cost, (int)g[from].size()-1});
    }

    cost_t min_cost_flow(int s, int t, flow_t f) {
        int V = (int)g.size();
        cost_t ret = 0;
        using Pi = pair<cost_t, int>;
        priority_queue<Pi, vector<Pi>, greater<Pi>> que;
        h.assign(V, 0);
        preve.assign(V, -1);
        prevv.assign(V, -1);

        while (f > 0) {
            d.assign(V, INF);
            que.emplace(0, s);
            d[s] = 0;
            while (!que.empty()) {
                Pi p = que.top(); que.pop();
                if (d[p.second] < p.first) continue;
                for (int i = 0; i < g[p.second].size(); i++) {
                    edge &e = g[p.second][i];
                    cost_t nextCost = d[p.second] + e.cost +
                        h[p.second] - h[e.to];
                    if (e.cap > 0 && d[e.to] > nextCost) {
                        d[e.to] = nextCost;
                        prevv[e.to] = p.second, preve[e.to] = i;
                        que.emplace(d[e.to], e.to);
                    }
                }
            }
            if (d[t] == INF) return -1;
            for (int v = 0; v < V; v++) h[v] += d[v];
            flow_t addflow = f;
            for (int v = t; v != s; v = prevv[v]) {
                addflow = min(addflow, g[prevv[v]][preve[v]].cap);
            }
            f -= addflow;
            ret += addflow * h[t];
            for (int v = t; v != s; v = prevv[v]) {
                edge &e = g[prevv[v]][preve[v]];
                e.cap -= addflow;
                g[v][e.rev].cap += addflow;
            }
        }
        return ret;
    }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "graph/template.cpp"



#line 1 "graph/../template.cpp"



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


#line 2 "graph/primal_dual.cpp"

template<typename flow_t, typename cost_t>
struct PrimalDual {
    const cost_t INF;

    struct edge {
        int to;
        flow_t cap;
        cost_t cost;
        int rev;
    };
    vector<vector<edge>> g;
    vector<cost_t> h, d;
    vector<int> prevv, preve;

    PrimalDual(int V) : g(V), INF(numeric_limits< cost_t >::max()) {}

    void add_edge(int from, int to, flow_t cap, cost_t cost) {
        g[from].push_back({to, cap, cost, (int)g[to].size()});
        g[to].push_back({from, 0, -cost, (int)g[from].size()-1});
    }

    cost_t min_cost_flow(int s, int t, flow_t f) {
        int V = (int)g.size();
        cost_t ret = 0;
        using Pi = pair<cost_t, int>;
        priority_queue<Pi, vector<Pi>, greater<Pi>> que;
        h.assign(V, 0);
        preve.assign(V, -1);
        prevv.assign(V, -1);

        while (f > 0) {
            d.assign(V, INF);
            que.emplace(0, s);
            d[s] = 0;
            while (!que.empty()) {
                Pi p = que.top(); que.pop();
                if (d[p.second] < p.first) continue;
                for (int i = 0; i < g[p.second].size(); i++) {
                    edge &e = g[p.second][i];
                    cost_t nextCost = d[p.second] + e.cost +
                        h[p.second] - h[e.to];
                    if (e.cap > 0 && d[e.to] > nextCost) {
                        d[e.to] = nextCost;
                        prevv[e.to] = p.second, preve[e.to] = i;
                        que.emplace(d[e.to], e.to);
                    }
                }
            }
            if (d[t] == INF) return -1;
            for (int v = 0; v < V; v++) h[v] += d[v];
            flow_t addflow = f;
            for (int v = t; v != s; v = prevv[v]) {
                addflow = min(addflow, g[prevv[v]][preve[v]].cap);
            }
            f -= addflow;
            ret += addflow * h[t];
            for (int v = t; v != s; v = prevv[v]) {
                edge &e = g[prevv[v]][preve[v]];
                e.cap -= addflow;
                g[v][e.rev].cap += addflow;
            }
        }
        return ret;
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

