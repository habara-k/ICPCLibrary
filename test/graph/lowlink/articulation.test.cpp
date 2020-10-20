#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/3/GRL_3_A"

#include "../../../lib/graph/lowlink.cpp"

int main() {
  int n, m; cin >> n >> m;
  vvi g(n);
  REP(i, m) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  Lowlink lowlink(g);

  sort(ALL(lowlink.articulation));
  for(auto &e: lowlink.articulation) {
    cout << e << endl;
  }

  return 0;
}
