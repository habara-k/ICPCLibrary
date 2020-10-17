#define PROBLEM "https://judge.yosupo.jp/problem/two_sat"

#include "../../lib/graph/two_sat.cpp"

int main() {
  string tmp;
  cin >> tmp >> tmp;
  int n, m; cin >> n >> m;
  TwoSat twosat(n);
  REP(i, m) {
    int a, b, c; cin >> a >> b >> c;
    if(a < 0) {
      a = n - a;
    }
    if(b < 0) {
      b = n - b;
    }
    a--;
    b--;
    twosat.add_or(a, b);
  }

  auto res = twosat.solve();
  if(res.empty()) {
    cout << "s UNSATISFIABLE" << endl;
  } else {
    cout << "s SATISFIABLE" << endl;
    cout << "v";
    REP(i, n) {
      cout << " " << ((2 * res[i] - 1) * (i+1));
    }
    cout << " " << 0 << endl;
  }
}

