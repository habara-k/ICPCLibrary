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
