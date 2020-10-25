#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/all/DPL_5_C"

#include "../../lib/number/mint.cpp"
#include "../../lib/number/comb.cpp"

int main() {
    ll n, k; cin >> n >> k;
    using Int = mint<MOD>;
    Combination<Int> comb;

    Int ans = 0;
    for (ll l = 0; l <= k; ++l) {
        ans += comb.C(k, l) * Int{k-l}.pow(n) * (l & 1 ? -1 : 1);
    }
    cout << ans << endl;
}
