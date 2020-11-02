#include "../template.cpp"

template <typename T>
struct FordFulkerson {
  struct Edge {
    int to, rev;
    T cap;
  };

  int n;
  vector<vector<Edge>> g;
  vector<bool> used;

  FordFulkerson(int n): n(n) {
    g.resize(n);
    used.resize(n);
  }

  void add_edge(int from, int to, T cap) {
    g[from].push_back({to, SZ(g[to]), cap});
    g[to].push_back({from, SZ(g[from])-1, 0});
  }

  T max_flow(int s, int t) {
    int flow = 0, f = 0;
    while(1){
      REP(i, n) {
        used[i] = false;
      }
      f = dfs(s, t, INF);
      if(f == 0) return flow;
      flow += f;
    }
  }

private:
  int dfs(int now, int t, int f) {
    if(now == t) return f;
    used[now] = true;
    for(auto &e: g[now]) {
      if(used[e.to] || e.cap <= 0) continue;
      int d = dfs(e.to, t, min(f, e.cap));
      if(d > 0) {
        e.cap -= d;
        g[e.to][e.rev].cap += d;
        return d;
      }
    }
    return 0;
  }

};
