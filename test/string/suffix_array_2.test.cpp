#define PROBLEM "https://judge.yosupo.jp/problem/number_of_substrings"

#include "../../lib/string/suffix_array.cpp"

int main() {
  string s; cin >> s;
  auto sa = SA::construct_sa(s);
  auto lcp = SA::construct_lcp(s, sa);

  ll n = s.size();
  ll ans = n * (n + 1) / 2;
  for(int i=0;i<=n;++i) {
    ans -= lcp[i];
  }
  cout << ans << endl;

}
