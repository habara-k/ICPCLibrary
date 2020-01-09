#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_L"

#include "../../number/combination.cpp"

int main() {
    ll n, k; cin >> n >> k;
    const ll mod = 1e9+7;

    init_partition(k, n, mod);

    cout << (Part[k][n] - Part[k-1][n] + mod) % mod << endl;
}
