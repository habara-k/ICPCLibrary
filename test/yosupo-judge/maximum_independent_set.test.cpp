#define PROBLEM "https://judge.yosupo.jp/problem/maximum_independent_set"

#include "../../lib/graph/maximum_independent_set.cpp"


int main() {
  int n, m; cin >> n >> m;
  vector<ll> g(n);
  REP(i, m) {
    int u, v; cin >> u >> v;
    g[u] |= 1ll<<v;
    g[v] |= 1ll<<u;
  }
  MaximumIndependentSet mid(g);
  int sz = mid.maximum_independent_set();
  vi ans;
  REP(i, n) {
    if((mid.ans>>i)&1) {
      ans.push_back(i);
    }
  }
  cout << sz << endl;
  for(auto &e: ans) {
    cout << e << " ";
  }
  cout << endl;
}

