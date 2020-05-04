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


# :heavy_check_mark:  <small>(lib/graph/dijkstra.cpp)</small>

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#6e267a37887a7dcb68cbf7008d6c7e48">lib/graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/lib/graph/dijkstra.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-04 15:30:16+09:00




## Depends on

* :heavy_check_mark: <a href="template.cpp.html">lib/graph/template.cpp</a>
* :heavy_check_mark: <a href="../template.cpp.html">lib/template.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/graph/dijkstra.test.cpp.html">test/graph/dijkstra.test.cpp</a>


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
 * @param[in] inf 到達不可能を表す無限値
 * @return vector<T> sからそれぞれの頂点への最短路
 *
 * @details
 * 2020/04/07 コメント追加、テスト有無のチェック by Md
 * 2020/05/04 inf に使う値を明示的に渡す. by haraba-k
 */

template<typename T>
vector<T> dijkstra(const Graph<T> &g, int s, T inf) {
    vector<T> d(g.size(), inf);

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
#line 1 "lib/graph/template.cpp"



#line 1 "lib/template.cpp"



#include <bits/stdc++.h>

using namespace std;

#define REP(i, n) for (int i=0; i<(n); ++i)
#define RREP(i, n) for (int i=(int)(n)-1; i>=0; --i)
#define FOR(i, a, n) for (int i=(a); i<(n); ++i)
#define RFOR(i, a, n) for (int i=(int)(n)-1; i>=(a); --i)

#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

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


#line 5 "lib/graph/template.cpp"

template<typename T>
struct edge {
    int src, to;
    T cost;
};

template<typename T>
using Graph = vector<vector<edge<T>>>;


#line 2 "lib/graph/dijkstra.cpp"

/**
 * @brief
 * 単一始点最短路(ダイクストラ)
 * 二分ヒープ(priority_queue)を使ってO((E+V)logV)
 * @author ?
 * @date 2019/12
 *
 * @param[in] g グラフ
 * @param[in] s 始点
 * @param[in] inf 到達不可能を表す無限値
 * @return vector<T> sからそれぞれの頂点への最短路
 *
 * @details
 * 2020/04/07 コメント追加、テスト有無のチェック by Md
 * 2020/05/04 inf に使う値を明示的に渡す. by haraba-k
 */

template<typename T>
vector<T> dijkstra(const Graph<T> &g, int s, T inf) {
    vector<T> d(g.size(), inf);

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

<a href="../../../index.html">Back to top page</a>

