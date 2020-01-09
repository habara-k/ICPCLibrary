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


# :warning: graph/hopcroft_karp.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/hopcroft_karp.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-05 00:07:05+09:00




## Depends on

* :warning: <a href="template.cpp.html">graph/template.cpp</a>
* :warning: <a href="../template.cpp.html">template.cpp</a>


## Required by

* :warning: <a href="../test/graph/hopcroft_karp.cpp.html">test/graph/hopcroft_karp.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include "template.cpp"

struct HopcroftKarp {
    vector<vector<int>> g;
    vector<int> d, mch;
    vector<bool> used, vv;

    HopcroftKarp(int n, int m) : g(n), mch(m, -1), used(n) {}

    void add_edge(int u, int v) {
        g[u].push_back(v);
    }

    void bfs() {
        d.assign(g.size(), -1);
        queue<int> que;
        for (int i = 0; i < g.size(); i++) {
            if (!used[i]) {
                que.emplace(i);
                d[i] = 0;
            }
        }

        while (!que.empty()) {
            int a = que.front();
            que.pop();
            for (auto &b : g[a]) {
                int c = mch[b];
                if (c >= 0 && d[c] == -1) {
                    d[c] = d[a] + 1;
                    que.emplace(c);
                }
            }
        }
    }

    bool dfs(int a) {
        vv[a] = true;
        for (auto &b : g[a]) {
            int c = mch[b];
            if (c < 0 || (!vv[c] && d[c] == d[a] + 1 && dfs(c))) {
                mch[b] = a;
                used[a] = true;
                return (true);
            }
        }
        return (false);
    }

    int bipartite_matching() {
        int ret = 0;
        while (true) {
            bfs();
            vv.assign(g.size(), false);
            int flow = 0;
            for (int i = 0; i < g.size(); i++) {
                if (!used[i] && dfs(i)) ++flow;
            }
            if (flow == 0) return ret;
            ret += flow;
        }
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


#line 2 "graph/hopcroft_karp.cpp"

struct HopcroftKarp {
    vector<vector<int>> g;
    vector<int> d, mch;
    vector<bool> used, vv;

    HopcroftKarp(int n, int m) : g(n), mch(m, -1), used(n) {}

    void add_edge(int u, int v) {
        g[u].push_back(v);
    }

    void bfs() {
        d.assign(g.size(), -1);
        queue<int> que;
        for (int i = 0; i < g.size(); i++) {
            if (!used[i]) {
                que.emplace(i);
                d[i] = 0;
            }
        }

        while (!que.empty()) {
            int a = que.front();
            que.pop();
            for (auto &b : g[a]) {
                int c = mch[b];
                if (c >= 0 && d[c] == -1) {
                    d[c] = d[a] + 1;
                    que.emplace(c);
                }
            }
        }
    }

    bool dfs(int a) {
        vv[a] = true;
        for (auto &b : g[a]) {
            int c = mch[b];
            if (c < 0 || (!vv[c] && d[c] == d[a] + 1 && dfs(c))) {
                mch[b] = a;
                used[a] = true;
                return (true);
            }
        }
        return (false);
    }

    int bipartite_matching() {
        int ret = 0;
        while (true) {
            bfs();
            vv.assign(g.size(), false);
            int flow = 0;
            for (int i = 0; i < g.size(); i++) {
                if (!used[i] && dfs(i)) ++flow;
            }
            if (flow == 0) return ret;
            ret += flow;
        }
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

