#define PROBLEM "https://judge.yosupo.jp/problem/number_of_substrings"

#include "../../lib/string/suffix_array.cpp"

int main() {
    string S;
    cin >> S;

    auto sa = SA::construct_sa(S);
    auto lcp = SA::construct_lcp(S, sa);

    ll ans = 1ll * S.size() * (1 + S.size()) / 2;
    for (auto e : lcp) {
        ans -= e;
    }
    cout << ans << endl;
    return 0;
}