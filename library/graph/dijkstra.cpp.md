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


# :heavy_check_mark:  <small>(graph/dijkstra.cpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/dijkstra.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-07 03:51:42+09:00




## Depends on

* :question: <a href="template.cpp.html">graph/template.cpp</a>
* :question: <a href="../template.cpp.html">template.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/graph/dijkstra.test.cpp.html">test/graph/dijkstra.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include "template.cpp"

/**
 * @brief
 * 単一始点最短路(ダイクストラ)
 * 二分ヒープ(priority_queue)を使ってO((E+V)logV)
 * @author ?
 * @date 2019/12
 * 
 * @param[in] g グラフ
 * @param[in] s 始点
 * @return vector<T> sからそれぞれの頂点への最短路
 * 
 * @details
 * 2020/04/07 コメント追加、テスト有無のチェック by Md
 */

template<typename T>
vector<T> dijkstra(const Graph<T> &g, int s) {
    const auto INF = numeric_limits<T>::max();
    vector<T> d(g.size(), INF);

    using Pi = pair<T, int>;
    priority_queue<Pi, vector<Pi>, greater<Pi>> que;
    d[s] = 0;
    que.emplace(d[s], s);
    while (!que.empty()) {
        T cost;
        int v;
        tie(cost, v) = que.top();
        que.pop();
        if (d[v] < cost) continue;
        for (auto &e : g[v]) {
            auto nxt = cost + e.cost;
            if (d[e.to] > nxt) {
                d[e.to] = nxt;
                que.emplace(nxt, e.to);
            }
        }
    }
    return d;
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


#line 2 "graph/dijkstra.cpp"

/**
 * @brief
 * 単一始点最短路(ダイクストラ)
 * 二分ヒープ(priority_queue)を使ってO((E+V)logV)
 * @author ?
 * @date 2019/12
 * 
 * @param[in] g グラフ
 * @param[in] s 始点
 * @return vector<T> sからそれぞれの頂点への最短路
 * 
 * @details
 * 2020/04/07 コメント追加、テスト有無のチェック by Md
 */

template<typename T>
vector<T> dijkstra(const Graph<T> &g, int s) {
    const auto INF = numeric_limits<T>::max();
    vector<T> d(g.size(), INF);

    using Pi = pair<T, int>;
    priority_queue<Pi, vector<Pi>, greater<Pi>> que;
    d[s] = 0;
    que.emplace(d[s], s);
    while (!que.empty()) {
        T cost;
        int v;
        tie(cost, v) = que.top();
        que.pop();
        if (d[v] < cost) continue;
        for (auto &e : g[v]) {
            auto nxt = cost + e.cost;
            if (d[e.to] > nxt) {
                d[e.to] = nxt;
                que.emplace(nxt, e.to);
            }
        }
    }
    return d;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

