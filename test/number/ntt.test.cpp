#define PROBLEM "https://atcoder.jp/contests/atc001/tasks/fft_c"

#include "../../lib/number/ntt.cpp"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);

    // ifstream in("in.txt");
    // cin.rdbuf(in.rdbuf());

    int n; cin >> n;
    vector<ll> a(2*n+1), b(2*n+1);
    REP(i, n) {
        cin >> a[i+1] >> b[i+1];
    }

    vector<ll> c = NTT<>::multiply(a, b);

    FOR(k, 1, 2*n+1) {
        cout << c[k] << endl;
    }

    return 0;
}
