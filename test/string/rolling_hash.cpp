#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/14/ALDS1_14_B"

#include "../../string/rolling_hash.cpp"

main() {
    string T, P;
    cin >> T >> P;
    int n = T.size(), m = P.size();
    vector<int> t(T.begin(), T.end()),
                p(P.begin(), P.end());

    RollingHash rh(t), rh2(p);
    for (int i = 0; i+m <= n; i++) {
        if (rh.get(i, i+m) == rh2.get(0, m) &&
            rh.get(i, i+m, 1) == rh2.get(0, m, 1)) {
            cout << i << endl;
        }
    }
}
