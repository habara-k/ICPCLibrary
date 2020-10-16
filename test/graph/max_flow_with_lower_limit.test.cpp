#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1615&lang=jp"

#include "../../lib/graph/max_flow_with_lower_limit.cpp"

bool check(int l, int r, int n, int m, vector<P> &edges) {
  MaxFlowWithLowerLimit<Dinic<int>, int> flow(n+m+2);
  int s = n + m, t = n + m + 1;

  REP(i, n) {
    flow.add_edge(s, i, l, r);
  }

  REP(i, m) {
    int u, v;
    tie(u, v) = edges[i];
    flow.add_edge(u, n+i, 0, 1);
    flow.add_edge(v, n+i, 0, 1);
    flow.add_edge(n+i, t, 0, 1);
  }

  return flow.max_flow(s, t) == m;
}

int main() {
  while(1) {
    int n, m;
    cin >> n >> m;
    if(n == 0 && m == 0) break;
    vector<P> edges(m);
    REP(i, m) {
      int u, v;
      cin >> u >> v;
      u--;
      v--;
      edges[i] = {u, v};
    }

    int ans = INF;
    int ansl = -1, ansr = -1;
    int r = 0;
    REP(l, n + 1) {
      if (r < l) r++;
      while (r < n) {
        bool res = check(l, r, n, m, edges);
        if (res) {
          if (r - l <= ans) {
            ans = r - l;
            ansl = l;
            ansr = r;
          }
          break;
        } else {
          r++;
        }
      }
    }
    cout << ansl << " " << ansr << endl;
  }

}

