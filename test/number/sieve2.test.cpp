#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2858"

#include "../../lib/number/sieve.cpp"

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);

  int l, r;
  cin >> l >> r;
  if (r == 1) {
    cout << 0 << endl;
    return 0;
  } else if (l == 1) {
    l++;
  }

  ll ma = 1;
  while (ma * ma <= r) ma++;

  vector<bool> v = sieve(ma);
  vector<int> primes;
  for (int i = 2; i <= ma; ++i) {
    if (v[i]) primes.push_back(i);
  }


  vvi v2(r - l + 1);
  for (auto &p: primes) {
    int j = (l / p) * p;
    while(j < l) j += p;
    for (; j <= r; j+=p) {
      v2[j - l].push_back(p);
    }
  }

  vi cnt(r - l + 1);
  for (int j = l; j <= r; ++j) {
    int val = j;
    for(auto &e: v2[j-l]) {
      while(val % e == 0) {
        val /= e;
        cnt[j-l]++;
      }
    }
    if(val != 1) cnt[j-l]++;
  }


  int ans = 0;
  REP(i, r-l+1) {
    ans += v[cnt[i]];
  }
  cout << ans << endl;

  return 0;
}