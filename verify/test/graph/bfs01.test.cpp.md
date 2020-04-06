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


# :heavy_check_mark: test/graph/bfs01.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#baa37bfd168b079b758c0db816f7295f">test/graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/graph/bfs01.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-07 03:56:38+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A">https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/graph/bfs01.cpp.html"> <small>(graph/bfs01.cpp)</small></a>
* :heavy_check_mark: <a href="../../../library/graph/template.cpp.html">graph/template.cpp</a>
* :heavy_check_mark: <a href="../../../library/template.cpp.html">template.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A"

#include "../../graph/bfs01.cpp"

int main() {
    int V, E, R;
    cin >> V >> E >> R;
    Graph<int> g(V);
    for (int i = 0; i < E; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({a,b,c});
    }
    for (auto &dist : bfs01(g, R)) {
        if (dist == numeric_limits<int>::max()) puts("INF");
        else cout << dist << endl;
    }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/graph/bfs01.test.cpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A"

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


#line 2 "graph/bfs01.cpp"

// verify: https://codeforces.com/contest/590/problem/C

/**
 * @brief
 * 01-BFS
 * 辺の重みが01の時にO(E+V)で単一始点最短路をやる
 * @author Md
 * @date 2019/12
 * @param[in] g グラフ
 * @param[in] s 始点
 * @return vector<T> sからそれぞれの頂点への最短路
 * 
 * @details
 * 2020/04/07
 * ソースコード修正、コメント追加、テスト追加 by Md
 * テストはdijkstraのものを流用(01-BFSでしか通らない問題、あるか？)
 */

template <typename T>
std::vector<T> bfs01(const Graph<T> &g, int s) {
    const T INF = numeric_limits<T>::max();
    std::vector<T> res(SZ(g), INF);
    deque<pair<T, int>> deq;
    res[s] = 0;
    deq.push_back({0, s});
    while(!deq.empty()) {
        auto elm = deq.front(); deq.pop_front();
        T cost = elm.first;
        int now = elm.second;
        if(cost > res[now]) continue;

        for(auto &ne: g[now]) {
            int nxt = ne.to;
            if(res[nxt] > cost + ne.cost) {
                res[nxt] = cost + ne.cost;
                if(ne.cost == 0) {
                    deq.push_front({res[nxt], nxt});
                } else {
                    deq.push_back({res[nxt], nxt});
                }
            }
        }
    }
    
    return res;
}
#line 4 "test/graph/bfs01.test.cpp"

int main() {
    int V, E, R;
    cin >> V >> E >> R;
    Graph<int> g(V);
    for (int i = 0; i < E; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({a,b,c});
    }
    for (auto &dist : bfs01(g, R)) {
        if (dist == numeric_limits<int>::max()) puts("INF");
        else cout << dist << endl;
    }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

