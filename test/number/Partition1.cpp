#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_J"

#include "../../number/combination.cpp"

int main() {
    int64_t n, k; cin >> n >> k;
    const int64_t mod = 1e9+7;

    init_partition(k, n, mod);

    cout << Part[k][n] << endl;
}
