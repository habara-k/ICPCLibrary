#define PROBLEM "https://judge.yosupo.jp/problem/discrete_logarithm_mod"

#include "../../lib/number/mod.cpp"

int main()
{
    int T; cin >> T;
    while (T--) {
        ll X, Y, M; cin >> X >> Y >> M;
        cout << logm(X, Y, M) << endl;

    }
    return 0;
}
