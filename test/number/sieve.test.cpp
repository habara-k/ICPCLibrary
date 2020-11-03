#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C&lang=ja"
#include "../../lib/number/sieve.cpp"

const int MA = 100000000;
int main() {
  auto prime = sieve(MA);

  int n; cin >> n;
  int cnt = 0;
  REP(i, n) {
    int x; cin >> x;
    cnt += prime[x];
  }
  cout << cnt << endl;
}