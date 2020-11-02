#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A&lang=jp"

#include "../../lib/graph/ford_fulkerson.cpp"

int main() {
  int n, m; cin >> n >> m;
  FordFulkerson<int> flow(n);
  REP(i, m) {
    int u, v, c; cin >> u >> v >> c;
    flow.add_edge(u, v, c);
  }
  cout << flow.max_flow(0, n-1) << endl;
}
