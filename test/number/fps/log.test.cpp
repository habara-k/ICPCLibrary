#define PROBLEM "https://judge.yosupo.jp/problem/log_of_formal_power_series"

#include "../../../lib/number/fps.cpp"

int main() {
    int n; cin >> n;
    vector<FPS<>::Int> a(n);
    REP(i, n) cin >> a[i];
    auto ans = FPS<>(a).log().a;
    REP(i, n) {
        if (i) cout << ' ';
        cout << ans[i];
    }
    cout << endl;

    return 0;
}

