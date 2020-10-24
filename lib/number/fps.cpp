#include "../template.cpp"
#include "mint.cpp"
#include "ntt.cpp"

/*
 * @brief 形式的冪級数
 * @ref https://ei1333.github.io/library/math/fps/formal-power-series.cpp
 * @author habara-k
 * @date 2020/10/23
 * @details
 * 多項式の累乗がO(nlog n)でできる最低限の実装にしてある
 * @usage
 *     vector<FPS<>::Int> a(n);
 *     REP(i, n) cin >> a[i];
 *     auto ans = FPS<>(a).pow(m).a;
 */
template<int mod = 998244353, int root = 3>
struct FPS {
    using Int = mint<mod>;
    int n = 0;
    vector<Int> a;

    FPS(const vector<Int> &a) : n(a.size()), a(a) {}

    FPS &operator*=(Int x) {
        REP(i, n) a[i] *= x;
        return *this;
    }

    FPS operator*(Int x) const {
        return FPS(*this) *= x;
    }

    FPS operator*(const FPS &r) const {
        return NTT<mod,root>::multiply(a, r.a);
    }

    static void ntt(vector<Int>& F) {
        NTT<mod,root>::ntt(F);
    }

    static void intt(vector<Int>& F) {
        NTT<mod,root>::intt(F);
    }

    FPS pre(int sz) const {
        return FPS({a.begin(), a.begin() + min(sz, n)});
    }

    FPS diff() const {
        if (n == 0) return *this;
        vector<Int> ret(n - 1);
        FOR(i, 1, n) ret[i - 1] = a[i] * i;
        return ret;
    }

    FPS integral() const {
        vector<Int> ret(n + 1);
        REP(i, n) ret[i + 1] = a[i] / (i + 1);
        return ret;
    }

    FPS inv(int deg = -1) const {
        assert(!a.empty() and a[0] != 0);
        if (deg == -1) deg = n;
        vector<Int> ret{a[0].inv()};
        for (int d = 1; d < n; d <<= 1) {
            vector<Int> f(2 * d), g(2 * d);
            REP(j, min(n, 2*d)) f[j] = a[j];
            REP(j, d) g[j] = ret[j];
            ntt(f);
            ntt(g);
            REP(j, 2*d) f[j] *= g[j];
            intt(f);
            REP(j, d) f[j] = 0, f[j+d] = -f[j+d];
            ntt(f);
            REP(j, 2*d) f[j] *= g[j];
            intt(f);
            REP(j, d) f[j] = ret[j];
            ret = f;
        }
        return FPS(ret).pre(n);
    }

    FPS log(int deg = -1) const {
        assert(!a.empty() and a[0] == 1);
        if (deg == -1) deg = n;
        return (diff() * inv(deg)).pre(deg - 1).integral();
    }

    FPS exp(int deg = -1) const {
        assert(a.empty() or a[0] == 0);
        if (deg == -1) deg = n;
        auto inplace_integral = [&](vector<Int>& F) -> void {
            F.insert(F.begin(), 0);
            FOR(i, 1, SZ(F)) F[i] /= i;
        };

        auto inplace_diff = [](vector<Int>& F) -> void {
            if (F.empty()) return;
            F.erase(F.begin());
            REP(i, SZ(F)) F[i] *= i+1;
        };

        vector<Int> b{1, n > 1 ? a[1] : 0}, c{1}, z1, z2{1, 1};
        for (int m = 2; m < deg; m *= 2) {
            auto y = b;
            y.resize(2 * m);
            ntt(y);
            z1 = z2;
            vector<Int> z(m);
            REP(i, m) z[i] = y[i] * z1[i];
            intt(z);
            fill(z.begin(), z.begin() + m / 2, 0);
            ntt(z);
            REP(i, m) z[i] *= -z1[i];
            intt(z);
            c.insert(c.end(), z.begin() + m / 2, z.end());
            z2 = c;
            z2.resize(2 * m);
            ntt(z2);
            vector<Int> x(a.begin(), a.begin() + min(n, m));
            inplace_diff(x);
            x.emplace_back(0);
            ntt(x);
            REP(i, m) x[i] *= y[i];
            intt(x);
            REP(i, m-1) x[i] -= b[i+1] * (i+1);
            x.resize(2 * m);
            REP(i, m-1) x[m+i] = x[i], x[i] = 0;
            ntt(x);
            REP(i, 2*m) x[i] *= z2[i];
            intt(x);
            x.pop_back();
            inplace_integral(x);
            FOR(i, m, min(n, 2*m)) x[i] += a[i];
            fill(x.begin(), x.begin() + m, 0);
            ntt(x);
            REP(i, 2*m) x[i] *= y[i];
            intt(x);
            b.insert(b.end(), x.begin() + m, x.end());
        }
        return FPS({b.begin(), b.begin() + deg});
    }

    FPS pow(ll k, int deg = -1) {
        if (deg == -1) deg = n;
        REP(i, n) {
            if (a[i] == 0) continue;
            vector<Int> ret(deg);
            if (i * k >= deg) return ret;
            FPS C = ((FPS({a.begin() + i, a.end()}) * a[i].inv()).log() * k).exp() * a[i].pow(k);
            for (int j = 0; j + i * k < deg and j < C.n; ++j) {
                ret[j + i * k] = C.a[j];
            }
            return ret;
        }
        return *this;
    }
};

