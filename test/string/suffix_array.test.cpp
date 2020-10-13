#define PROBLEM "https://judge.yosupo.jp/problem/suffixarray"

#include "../../lib/string/suffix_array.cpp"

int main() {
  string s; cin >> s;
  auto sa = SA::construct_sa(s);
  int sz = s.size();
  for(int i=1;i<=sz;++i) {
    cout << sa[i];
    if(i == sz) cout << "\n";
    else cout << " ";
  }
}