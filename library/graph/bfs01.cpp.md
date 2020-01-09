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


# :warning: graph/bfs01.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/bfs01.cpp">View this file on GitHub</a>
    - Last commit date: 2020-01-09 02:18:56+09:00




## Depends on

* :warning: <a href="../template.cpp.html">template.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include "../template.cpp"

// verify: https://codeforces.com/contest/590/problem/C

template <typename T>
std::vector<T> bfs01(const vector<vector<edge<T>>> &g, int s) {
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
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
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


#line 2 "graph/bfs01.cpp"

// verify: https://codeforces.com/contest/590/problem/C

template <typename T>
std::vector<T> bfs01(const vector<vector<edge<T>>> &g, int s) {
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
```
{% endraw %}

<a href="../../index.html">Back to top page</a>

