#define PROBLEM "https://judge.yosupo.jp/problem/two_edge_connected_components"

#include "../../lib/graph/two_edge_connected_components.cpp"
#include "../../lib/structure/union_find.cpp"


int main() {
  int n, m; cin >> n >> m;
  vvi g(n);
  map<P, int> cnt;
  REP(i, m) {
    int u, v; cin >> u >> v;
    if(u == v) continue;
    if(u > v) swap(u, v);
    if(cnt[{u, v}] == 0) {
      g[u].push_back(v);
      g[v].push_back(u);
    }
    cnt[{u, v}]++;
  }
  TwoEdgeCC tecc(g);

  UnionFind uf(tecc.id);
  for(auto &e: cnt) {
    if(e.second > 1) {
      uf.merge(tecc.comp[e.first.first], tecc.comp[e.first.second]);
    }
  }

  map<int, set<int>> mp;
  REP(i, n) {
    int val = uf.root(tecc.comp[i]);
    mp[val].insert(i);
  }

  cout << SZ(mp) << endl;
  for(auto &e: mp) {
    auto &v = e.second;
    cout << SZ(v);
    for(auto &e2: v) {
      cout << " " << e2;
    }
    cout << endl;
  }
}
