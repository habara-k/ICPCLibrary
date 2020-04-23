#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_I"

#include "../../lib/number/combination.cpp"

int main() {
    ll n, k; cin >> n >> k;
    const ll mod = 1e9+7;

    init_fact(k, mod);

    cout << Stirling(n, k, mod) << endl;
}
