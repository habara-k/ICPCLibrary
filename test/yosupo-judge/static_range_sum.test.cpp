#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"

#include "../../lib/template.cpp"

int main() {
    int n, q; cin >> n >> q;
    vector<ll> a(n+1);
    REP(i, n) cin >> a[i+1], a[i+1] += a[i];

    while (q--) {
        int l, r; cin >> l >> r;
        cout << a[r] - a[l] << endl;
    }


    return 0;
}
