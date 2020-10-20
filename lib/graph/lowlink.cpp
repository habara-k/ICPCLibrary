#include "./template.cpp"

struct Lowlink {
  vvi g;
  int n;
  vi ord, low;
  vector<P> bridge;
  vector<int> articulation;
  int t = 0;

  Lowlink(const vvi &G): g(G) {
    n = SZ(g);
    ord.resize(n, INF);
    low.resize(n, INF);

    REP(i, n) {
      if(ord[i] == INF) {
        dfs(i, -1);
      }
    }
  }

  void dfs(int now, int prev) {
    ord[now] = t;
    low[now] = ord[now];
    t++;
    int d = 0;
    bool ar = false;
    for(auto &nxt: g[now]) {
      if(nxt == prev) continue;
      if(ord[nxt] == INF) {
        d++;
        dfs(nxt, now);
        chmin(low[now], low[nxt]);
        ar |= prev != -1 && ord[now] <= low[nxt];
        if(ord[now] < low[nxt]) {
          if(now < nxt) bridge.emplace_back(now, nxt);
          else bridge.emplace_back(nxt, now);
        }
      } else {
        chmin(low[now], ord[nxt]);
      }
    }
    ar |= prev == -1 && d >= 2;
    if(ar) articulation.push_back(now);
  }
};
