#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"

#include "../../lib/string/z_algorithm.cpp"

int main() {
  string s; cin >> s;
  vi a(SZ(s));
  z_algorithm(s, a);
  REP(i, SZ(s)) {
    cout << a[i];
    if(i == SZ(s)-1) cout << endl;
    else cout << " ";
  }
}

