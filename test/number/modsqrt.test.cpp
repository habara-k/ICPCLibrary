#define PROBLEM "https://judge.yosupo.jp/problem/sqrt_mod"

#include "../../lib/number/mod.cpp"

int main()
{
    int T; cin >> T;
    while (T--) {
        ll Y, P; cin >> Y >> P;
        cout << modsqrt(Y, P) << endl;
    }
    return 0;
}
