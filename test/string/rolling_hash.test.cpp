#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/14/ALDS1_14_B"

#include "../../lib/string/rolling_hash.cpp"

int main() {
    string T, P;
    cin >> T >> P;
    int n = T.size(), m = P.size();

    RollingHash hashT(T), hashP(P);
    for (int i = 0; i+m <= n; i++) {
        if (hashT.get(i, i+m) == hashP.get(0, m)) {
            cout << i << endl;
        }
    }
}
