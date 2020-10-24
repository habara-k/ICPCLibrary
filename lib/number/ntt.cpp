#include "../template.cpp"

/*
 * @brief NTT
 * @ref https://ei1333.github.io/library/math/fft/number-theoretic-transform-friendly-mod-int.cpp
 * @author habara-k
 * @usage
 *   vector<NTT<>::Int> a, b;
 *   auto c = NTT<>::multiply(a, b);
 *
 * rootの探索
 * int root = 2;
 * while (Int{root}.pow((mod-1)/2) == 1) ++root;
 */
template<int mod = 998244353, int root = 3>
struct NTT {
    using Int = mint<mod>;
    constexpr static int sz = __builtin_ctz(mod-1);

    static void ntt(vector<Int> &a) {
        const int n = (int) a.size();
        assert((n & (n - 1)) == 0);
        assert(__builtin_ctz(n) <= sz);
        Int dw[sz];
        REP(i, sz) {
            dw[i] = -Int{root}.pow((mod-1) >> (i+2));
        }
        for (int m = n; m >>= 1;) {
            Int w = 1;
            for (int s = 0, k = 0; s < n; s += 2 * m) {
                for (int i = s, j = s + m; i < s + m; ++i, ++j) {
                    auto x = a[i], y = a[j] * w;
                    a[i] = x + y, a[j] = x - y;
                }
                w *= dw[__builtin_ctz(++k)];
            }
        }
    }

    static void intt(vector<Int> &a) {
        const int n = (int) a.size();
        assert((n & (n - 1)) == 0);
        assert(__builtin_ctz(n) <= sz);
        Int idw[sz];
        REP(i, sz) {
            idw[i] = (-Int{root}.pow((mod-1) >> (i+2))).inv();
        }
        for (int m = 1; m < n; m *= 2) {
            Int w = 1;
            for (int s = 0, k = 0; s < n; s += 2 * m) {
                for (int i = s, j = s + m; i < s + m; ++i, ++j) {
                    auto x = a[i], y = a[j];
                    a[i] = x + y, a[j] = (x - y) * w;
                }
                w *= idw[__builtin_ctz(++k)];
            }
        }
        Int inv_n = Int{n}.inv();
        REP(i, n) a[i] *= inv_n;
    }

    static vector<Int> multiply(vector<Int> a, vector<Int> b) {
        int need = SZ(a) + SZ(b) - 1;
        int n = 1;
        while (n < need) n <<= 1;
        a.resize(n);
        b.resize(n);
        ntt(a);
        ntt(b);
        REP(i, n) a[i] *= b[i];
        intt(a);
        a.resize(need);
        return a;
    }
};

