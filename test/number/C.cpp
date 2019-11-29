#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/all/DPL_5_C"

#include "../../number/combination.cpp"

int main() {
    int64_t n, k; cin >> n >> k;
    const int64_t mod = 1e9+7;

    init_fact(k, mod);

    int64_t ans = 0;
    for (int64_t l = 0; l <= k; ++l) {
        int64_t tmp = powm(k-l, n, mod);
        (tmp *= C(k, l, mod)) %= mod;
        if (l & 1) tmp = (-tmp + mod) % mod;
        (ans += tmp) %= mod;
    }
    cout << ans << endl;
}
