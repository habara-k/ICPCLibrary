#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"

#include "../../lib/number/mint.cpp"
#include "../../lib/number/ntt.cpp"

int main() {
    int n, m; cin >> n >> m;
    vector<NTT<>::Int> a(n), b(m);
    REP(i, n) cin >> a[i];
    REP(i, m) cin >> b[i];

    NTT<> ntt;
    auto c = ntt.multiply(a,b);
    REP(i, SZ(c)) {
        if (i) cout << ' ';
        cout << c[i];
    }
    cout << endl;

    return 0;
}
