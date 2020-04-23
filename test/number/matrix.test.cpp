#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2397"

#include "../../lib/number/matrix.cpp"


struct modint {
    ll x;
    modint(ll x=0) : x(x) {}
    modint &operator+=(const modint& a) {
        (x += a.x) %= MOD;
        return *this;
    }
    friend modint operator*(const modint& a, const modint& b) {
        return modint((a.x * b.x) % MOD);
    }
    friend ostream &operator<<(ostream &os, const modint &a) {
        return os << a.x;
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);

    for (int t = 1;; ++t) {
        ll W, H, N;
        cin >> W >> H >> N;
        if (W == 0) break;
        bool zero = false;
        map<ll, vi> obs;
        REP(i, N) {
            ll x, y;
            cin >> x >> y;
            --x, --y;
            if (x == 0 and y == 0) {
                zero = true;
            }
            if (y > 0) obs[y].emplace_back(x);
        }
        if (zero) {
            cout << 0 << endl;
            return 0;
        }

        Matrix<modint> A(W, vector<modint>(W));
        REP(i, W) A[i][i] = 1;

        Matrix<modint> B = A;
        REP(i, W) {
            if (i - 1 >= 0) B[i][i - 1] = 1;
            if (i + 1 < W) B[i][i + 1] = 1;
        }

        ll prv = 0;
        for (auto &tp : obs) {
            ll now = tp.first;

            A = A * pow(B, now - prv - 1);

            Matrix<modint> tmp = B;
            for (int j : tp.second) {
                REP(i, W) tmp[i][j] = 0;
            }
            A = A * tmp;

            prv = now;

        }

        A = A * pow(B, H - prv - 1);

        cout << "Case " << t << ": " << A[0][W - 1].x << endl;
    }

    return 0;
}
