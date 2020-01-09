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


# :warning: test/graph/dinic.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#baa37bfd168b079b758c0db816f7295f">test/graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/graph/dinic.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-05 00:07:05+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A">https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A</a>


## Depends on

* :warning: <a href="../../graph/dinic.cpp.html">graph/dinic.cpp</a>
* :heavy_check_mark: <a href="../../graph/template.cpp.html">graph/template.cpp</a>
* :heavy_check_mark: <a href="../../template.cpp.html">template.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A"

#include "../../graph/dinic.cpp"

int main() {
    int V, E;
    cin >> V >> E;
    Dinic<int> g(V);
    for(int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g.add_edge(a, b, c);
    }
    cout << g.max_flow(0, V-1) << endl;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/graph/dinic.cpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A"

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


#line 2 "test/graph/../../graph/dinic.cpp"

template<typename T>
struct Dinic {
    const T INF;

    struct edge {
        int to;
        T cap;
        int rev;
        bool isrev;
    };

    vector<vector<edge>> g;
    vector<int> level, iter;

    Dinic(int V) : INF(numeric_limits<T>::max()), g(V) {}

    void add_edge(int from, int to, T cap) {
        g[from].push_back({to, cap, (int)g[to].size(), false});
        g[to].push_back({from, 0, (int)g[from].size()-1, true});
    }

    bool bfs(int s, int t) {
        level.assign(g.size(), -1);
        queue<int> que;
        level[s] = 0;
        que.push(s);
        while (!que.empty()) {
            int v = que.front();
            que.pop();
            for (auto &e : g[v]) {
                if (e.cap > 0 && level[e.to] == -1) {
                    level[e.to] = level[v] + 1;
                    que.push(e.to);
                }
            }
        }
        return level[t] != -1;
    }

    T dfs(int v, const int t, T flow) {
        if (v == t) return flow;
        for (int &i = iter[v]; i < g[v].size(); i++) {
            edge &e = g[v][i];
            if (e.cap > 0 && level[v] < level[e.to]) {
                T d = dfs(e.to, t, min(flow, e.cap));
                if (d > 0) {
                    e.cap -= d;
                    g[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    T max_flow(int s, int t) {
        T flow = 0;
        while (bfs(s, t)) {
            iter.assign(g.size(), 0);
            T f = 0;
            while((f = dfs(s, t, INF)) > 0) flow += f;
        }
        return flow;
    }
};
#line 4 "test/graph/dinic.cpp"

int main() {
    int V, E;
    cin >> V >> E;
    Dinic<int> g(V);
    for(int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g.add_edge(a, b, c);
    }
    cout << g.max_flow(0, V-1) << endl;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

