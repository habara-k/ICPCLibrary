#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1308"

#include "../../lib/number/gauss_jordan.cpp"

struct GF2 {
    int x;
    bool operator==(int a) { return x == a; }
    bool operator!=(int a) { return !(*this == a); }
    GF2(int x=0) : x(x) {}
    GF2 &operator/=(GF2 a) {
        assert(a != 0);
        x /= a.x;
        return *this;
    }
    GF2 &operator-=(GF2 a) {
        x ^= a.x;
        return *this;
    }
    GF2 operator*(GF2 a) {
        return GF2(x * a.x);
    }
    friend istream& operator>>(istream& is, GF2& a) {
        int tmp; is >> tmp;
        a = tmp;
        return is;
    }
};

int main() {

    for (;;) {
        int m, n, d;
        cin >> m >> n >> d;
        if (m == 0) break;

        vector<vector<GF2>> mat(n*m, vector<GF2>(n*m+1));

        REP(i, n) REP(j, m) cin >> mat[i*m + j][n*m];

        REP(i, n) REP(j, m) {
            mat[i*m + j][i*m + j] = 1;
            REP(y, n) REP(x, m) {
                if (abs(y - i) + abs(x - j) == d) {
                    mat[i*m + j][y*m + x] = 1;
                }
            }
        }

        GaussJordanElimination(mat);

        int ans = true;
        REP(i, n * m) {
            int allZero = true;
            REP(j, n * m) {
                if (mat[i][j] != 0) {
                    allZero = false;
                    break;
                }
            }
            if (allZero and mat[i][n * m] == 1) {
                ans = false;
                break;
            }
        }
        cout << ans << endl;
    }

    return 0;
}

