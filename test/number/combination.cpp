#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/all/DPL_5_C"

#include "../../number/combination.cpp"

int main() {
    long long n, k; cin >> n >> k;
    const long long mod = 1e9+7;

    init_fact(k, mod);

    long long ans = 0;
    for (long long l = 0; l <= k; ++l) {
        long long tmp = powm(k-l, n, mod);
        (tmp *= C(k, l, mod)) %= mod;
        if (l & 1) tmp = (-tmp + mod) % mod;
        (ans += tmp) %= mod;
    }
    cout << ans << endl;
}
