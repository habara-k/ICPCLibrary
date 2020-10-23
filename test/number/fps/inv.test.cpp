#define PROBLEM "https://judge.yosupo.jp/problem/inv_of_formal_power_series"

#include "../../../lib/number/fps.cpp"

int main() {
    int n; cin >> n;
    vector<FPS<>::Int> a(n);
    REP(i, n) cin >> a[i];
    auto ans = FPS<>(a).inv().a;
    REP(i, n) {
        if (i) cout << ' ';
        cout << ans[i];
    }
    cout << endl;

    return 0;
}

