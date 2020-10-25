#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_G"

#include "../../lib/number/mint.cpp"
#include "../../lib/number/comb.cpp"

int main() {
    ll n, k; cin >> n >> k;
    Combination<mint<MOD>> comb;

    cout << comb.Bell(n, k) << endl;
}
