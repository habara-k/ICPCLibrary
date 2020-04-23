#define PROBLEM "https://atcoder.jp/contests/tdpc/tasks/tdpc_target"

#include "../../lib/others/LIS.cpp"

int main()
{
    int n; cin >> n;
    vector<pair<int,int>> X(n);
    for (int i = 0; i < n; ++i) {
        int x, r; cin >> x >> r;
        X[i] = {x+r, x-r};
    }

    sort(X.rbegin(), X.rend());
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        a[i] = X[i].second;
    }

    int ans = LIS(a);
    cout << ans << endl;

    return 0;
}
