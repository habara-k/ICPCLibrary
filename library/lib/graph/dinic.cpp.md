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


# :heavy_check_mark:  <small>(lib/graph/dinic.cpp)</small>

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#6e267a37887a7dcb68cbf7008d6c7e48">lib/graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/lib/graph/dinic.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-24 14:14:43+09:00




## Depends on

* :heavy_check_mark: <a href="template.cpp.html">lib/graph/template.cpp</a>
* :heavy_check_mark: <a href="../template.cpp.html">lib/template.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/graph/dinic.test.cpp.html">test/graph/dinic.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include "template.cpp"

/**
 * @brief
 * Dinic法(最大流)
 * 始点から終点までフローを流したときの最大流量を求める
 * O(EV^2) （だいたいもっとはやい）
 * @author Md
 * @date 2019/12
 * @detail
 * 2020/04/07 コメント追加 by Md
 * 構築したい
 */

template <typename T>
struct Dinic {
  int sz;
  T inf = numeric_limits<T>::max();
  vector<int> level, iter;

  struct Edge {
    int to, rev;
    T cap;
    Edge(int to, int rev, T cap): to(to), rev(rev), cap(cap) {}
  };
  vector<vector<Edge>> g;

  /**
   * @brief コンストラクタ
   * @param V 頂点数
   */
  Dinic(int V): sz(V) {
    g.resize(V);
    level.resize(V);
    iter.resize(V);
  };

  /**
   * @brief 辺を追加
   * @param[in] from 始点
   * @param[in] to 終点
   * @param[in] cap 容量
   */
  void add_edge(int from, int to, T cap) {
    g[from].emplace_back(to, (int)(g[to].size()), cap);
    g[to].emplace_back(from, (int)(g[from].size())-1, 0);
  }

  /**
   * @brief 最大流を求める
   * @param[in] s 始点
   * @param[in] t 終点
   */
  T max_flow(int s, int t) {
    T flow = 0;
    while(1) {
      bfs(s);
      if(level[t] < 0) return flow;
      iter.assign(sz, 0);
      T f = dfs(s, t, inf);
      while(f > 0) {
        flow += f;
        f = dfs(s, t, inf);
      }
    }
  }

private:
  void bfs(int s) {
    level.assign(sz, -1);
    level[s] = 0;
    queue<int> que;
    que.push(s);
    while(!que.empty()) {
      int now = que.front(); que.pop();
      for(auto &e: g[now]) {
        if(e.cap > 0 && level[e.to] < 0) {
          level[e.to] = level[now] + 1;
          que.push(e.to);
        }
      }
    }
  }

  T dfs(int s, int t, T flow) {
    if(s == t) return flow;
    for(int i=iter[s];i<(int)(g[s].size());++i) {
      iter[s] = i;
      auto e = g[s][i];
      if(e.cap > 0 && level[s] < level[e.to]) {
        T d = dfs(e.to, t, min(flow, e.cap));
        if(d > 0) {
          g[s][i].cap -= d;
          g[e.to][e.rev].cap += d;
          return d;
        }
      }
    }
    return 0;
  }
};
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


#line 5 "lib/graph/template.cpp"

template<typename T>
struct edge {
    int src, to;
    T cost;
    // edge(int src, int to, T cost): src(src), to(to), cost(cost) {}
    // // G[i].push_back({src, to, cost}) requires no constructor
};

template<typename T>
using Graph = vector<vector<edge<T>>>;


#line 2 "lib/graph/dinic.cpp"

/**
 * @brief
 * Dinic法(最大流)
 * 始点から終点までフローを流したときの最大流量を求める
 * O(EV^2) （だいたいもっとはやい）
 * @author Md
 * @date 2019/12
 * @detail
 * 2020/04/07 コメント追加 by Md
 * 構築したい
 */

template <typename T>
struct Dinic {
  int sz;
  T inf = numeric_limits<T>::max();
  vector<int> level, iter;

  struct Edge {
    int to, rev;
    T cap;
    Edge(int to, int rev, T cap): to(to), rev(rev), cap(cap) {}
  };
  vector<vector<Edge>> g;

  /**
   * @brief コンストラクタ
   * @param V 頂点数
   */
  Dinic(int V): sz(V) {
    g.resize(V);
    level.resize(V);
    iter.resize(V);
  };

  /**
   * @brief 辺を追加
   * @param[in] from 始点
   * @param[in] to 終点
   * @param[in] cap 容量
   */
  void add_edge(int from, int to, T cap) {
    g[from].emplace_back(to, (int)(g[to].size()), cap);
    g[to].emplace_back(from, (int)(g[from].size())-1, 0);
  }

  /**
   * @brief 最大流を求める
   * @param[in] s 始点
   * @param[in] t 終点
   */
  T max_flow(int s, int t) {
    T flow = 0;
    while(1) {
      bfs(s);
      if(level[t] < 0) return flow;
      iter.assign(sz, 0);
      T f = dfs(s, t, inf);
      while(f > 0) {
        flow += f;
        f = dfs(s, t, inf);
      }
    }
  }

private:
  void bfs(int s) {
    level.assign(sz, -1);
    level[s] = 0;
    queue<int> que;
    que.push(s);
    while(!que.empty()) {
      int now = que.front(); que.pop();
      for(auto &e: g[now]) {
        if(e.cap > 0 && level[e.to] < 0) {
          level[e.to] = level[now] + 1;
          que.push(e.to);
        }
      }
    }
  }

  T dfs(int s, int t, T flow) {
    if(s == t) return flow;
    for(int i=iter[s];i<(int)(g[s].size());++i) {
      iter[s] = i;
      auto e = g[s][i];
      if(e.cap > 0 && level[s] < level[e.to]) {
        T d = dfs(e.to, t, min(flow, e.cap));
        if(d > 0) {
          g[s][i].cap -= d;
          g[e.to][e.rev].cap += d;
          return d;
        }
      }
    }
    return 0;
  }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

