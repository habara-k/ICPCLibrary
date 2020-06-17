#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E&lang=jp"

#include "../../lib/structure/bit_range_add.cpp"

int main() {
  int n, q; cin >> n >> q;
  RangeAdd<ll> bit(n);
  REP(_, q) {
    int t; cin >> t;
    if(t == 0) {
      int l, r, x; cin >> l >> r >> x;
      l--;
      bit.add(l, r, x);
    } else {
      int i; cin >> i;
      i--;
      cout << bit.sum(i) - bit.sum(i-1) << endl;
    }
  }
}