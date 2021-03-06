#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/14/ALDS1_14_B"

#include "../../lib/string/rolling_hash.cpp"

int main() {
    string T, P;
    cin >> T >> P;
    int n = T.size(), m = P.size();

    auto base = RollingHash::gen_base();

    RollingHash rht(T, base);
    RollingHash rhp(P, base);

    for (int i = 0; i+m <= n; ++i) {
        if (rht.get(i, i+m) == rhp.get(0, m)) {
            cout << i << endl;
        }
    }
}
