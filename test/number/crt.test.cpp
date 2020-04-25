#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2659"

#include "../../lib/number/crt.cpp"

int main() {
  ll n, m, d; cin >> n >> m >> d;
  vll mod(m);
  REP(i, m) {
    cin >> mod[i];
  }
  vvll a(d, vll(m));
  REP(i, d) {
    REP(j, m) {
      cin >> a[i][j];
    }
  }

  bool ok = true;
  REP(i, d) {
    vll b, nowmod;
    REP(j, m) {
      if(a[i][j] != -1) b.push_back(a[i][j]), nowmod.push_back(mod[j]);
    }
    if(b.empty()) continue;

    pair<ll, ll> p = crt(b, nowmod);

    if(p.second == -1 || n < p.first) ok = false;

    n = n - (n - p.first) % p.second;
  }

  if(ok) cout << n << endl;
  else cout << -1 << endl;
}