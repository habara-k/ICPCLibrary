#define PROBLEM "https://atcoder.jp/contests/abc141/tasks/abc141_e"

#include "../../string/z_algorithm.cpp"

int main() {
    int n; cin >> n;
    string s; cin >> s;

    int ans = 0;

    for (int i = 0; i < n; ++i) {
        vector<int> a;
        z_algorithm(s.substr(i, n-i), a);
        for (int j = 0; j < a.size(); ++j) {
            if (a[j] <= j) {
                ans = max(ans, a[j]);
            }
        }
    }

    cout << ans << endl;
}
