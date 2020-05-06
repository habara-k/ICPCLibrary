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


# :heavy_check_mark:  <small>(lib/graph/bfs01.cpp)</small>

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#6e267a37887a7dcb68cbf7008d6c7e48">lib/graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/lib/graph/bfs01.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-06 01:41:24+09:00




## Depends on

* :heavy_check_mark: <a href="template.cpp.html">lib/graph/template.cpp</a>
* :heavy_check_mark: <a href="../template.cpp.html">lib/template.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/graph/bfs01.test.cpp.html">test/graph/bfs01.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include "template.cpp"

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
 * テストはdijkstraのものを流用(01-BFSでしか通らない問題、ある？)
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
#define ALL(x) (x).begin(),(x).end()

#define DUMP(x) cerr<<#x<<" = "<<(x)<<endl
#define DEBUG(x) cerr<<#x<<" = "<<(x)<<" (L"<<__LINE__<<")"<<endl;

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
};

template<typename T>
using Graph = vector<vector<edge<T>>>;


#line 2 "lib/graph/bfs01.cpp"

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
 * テストはdijkstraのものを流用(01-BFSでしか通らない問題、ある？)
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

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

