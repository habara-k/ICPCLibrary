#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_L"

#include "../../lib/number/mint.cpp"
#include "../../lib/number/comb.cpp"

int main() {
    ll n, k; cin >> n >> k;

    auto part = Partition<mint<MOD>>(n, k);

    cout << (part[n][k] - part[n][k-1]) << endl;
}
