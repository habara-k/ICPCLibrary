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
  ll ans = maximum_independent_set(n, (1ll<<n)-1, g);
  vi ansv;
  REP(i, n) {
    if((ans>>i)&1) {
      ansv.push_back(i);
    }
  }
  cout << SZ(ansv) << endl;
  for(auto &e: ansv) {
    cout << e << " ";
  }
  cout << endl;
}

