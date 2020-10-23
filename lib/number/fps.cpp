#include "../template.cpp"
#include "mint.cpp"
#include "ntt.cpp"

/*
 * @brief 形式的冪級数
 * @ref https://ei1333.github.io/luzhiled/snippets/math/formal-power-series.html
 * @author habara-k
 * @date 2020/10/23
 * @details
 * 多項式の累乗がO(nlog n)でできる最低限の実装にしてある
 */
template<int mod=998244353, int root=3>
struct FPS {
    using Int = mint<mod>;
    int n=0;
    vector<Int> a;
    FPS(const vector<Int>& a) : n(a.size()), a(a) {}

    FPS& operator+=(Int x) {
        a[0] += x;
        return *this;
    }
    FPS operator+(Int x) const {
        return FPS(*this) += x;
    }
    FPS& operator*=(Int x) {
        REP(i, n) a[i] *= x;
        return *this;
    }
    FPS operator*(Int x) const {
        return FPS(*this) *= x;
    }

    FPS& operator+=(const FPS& r) {
        if (chmax(n, r.n)) a.resize(n);
        REP(i, r.n) a[i] += r.a[i];
        return *this;
    }
    FPS operator-() const {
        vector<Int> ret = a;
        REP(i, n) ret[i] = -ret[i];
        return ret;
    }
    FPS& operator-=(const FPS& r) {
        if (chmax(n, r.n)) a.resize(n);
        REP(i, r.n) a[i] -= r.a[i];
        return *this;
    }
    FPS operator+(const FPS& r) const {
        return FPS(a) += r;
    }
    FPS operator-(const FPS& r) const {
        return FPS(a) -= r;
    }

    FPS operator*(const FPS& r) const {
        return NTT<mod,root>().multiply(a, r.a);
    }

    FPS pre(int sz) const {
        return FPS({a.begin(), a.begin() + min(sz,n)});
    }
    FPS diff() const {
        if (n == 0) return *this;
        vector<Int> ret(n-1);
        FOR(i, 1, n) ret[i-1] = a[i] * i;
        return ret;
    }
    FPS integral() const {
        vector<Int> ret(n+1);
        REP(i, n) ret[i+1] = a[i] / (i+1);
        return ret;
    }
    FPS inv(int deg = -1) const {
        assert(!a.empty() and a.at(0) != 0);
        FPS ret({1 / a[0]});
        if (deg == -1) deg = n;
        for (int i = 1; i < deg; i<<=1) {
            ret = (ret * 2 - ret * ret * pre(i<<1)).pre(i<<1);
        }
        return ret.pre(deg);
    }
    FPS log(int deg = -1) const {
        assert(!a.empty() and a.at(0) == 1);
        if (deg == -1) deg = n;
        return (diff() * inv(deg)).pre(deg-1).integral();
    }
    FPS exp(int deg = -1) const {
        assert(!a.empty() and a.at(0) == 0);
        if (deg == -1) deg = n;
        FPS ret({1});
        for (int i = 1; i < deg; i<<=1) {
            ret = (ret * (pre(i<<1) + 1 - ret.log(i<<1))).pre(i<<1);
        }
        return ret.pre(deg);
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

