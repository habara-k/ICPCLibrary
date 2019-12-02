#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/all/DPL_5_C"

#include "../../number/combination.cpp"

int main() {
    ll n, k; cin >> n >> k;
    const ll mod = 1e9+7;

    init_fact(k, mod);

    ll ans = 0;
    for (ll l = 0; l <= k; ++l) {
        ll tmp = powm(k-l, n, mod);
        (tmp *= C(k, l, mod)) %= mod;
        if (l & 1) tmp = (-tmp + mod) % mod;
        (ans += tmp) %= mod;
    }
    cout << ans << endl;
}
