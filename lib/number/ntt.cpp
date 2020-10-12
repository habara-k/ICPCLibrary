#include "../template.cpp"

/**
 * @brief NTT
 * @author habara-k
 * @usage
 *   vector<NTT<>::Int> a, b;
 *   NTT<> ntt;
 *   auto c = ntt.multiply(a, b);
 */

template<ll mod=998244353, ll primitive=3>
struct NTT {
    using Int = mint<mod>;
    vector<Int> multiply(vector<Int> a, vector<Int> b) {
        int need = SZ(a) + SZ(b) - 1;
        ensure(need);
        assert((n & (n-1)) == 0);
        a.resize(n);
        b.resize(n);
        ntt(a);
        ntt(b);

        vector<Int> c(n);
        for (int i = 0; i < n; ++i) c[i] = a[i] * b[i] / n;
        reverse(c.begin() + 1, c.end());
        ntt(c); c.resize(need);
        return c;
    }

private:
    int n;
    Int root;

    void ensure(int need) {
        n = 1;
        while (n < need) n <<= 1;
        root = Int{primitive}.pow((mod-1) / n);
    }

    void ntt(vector<Int>& a) {
        int p = 0;
        for (int i = 1; i < n - 1; ++i) {
            for (int k = n >> 1; k > (p ^= k); k >>= 1);
            if (i < p) swap(a[i], a[p]);
        }
        for (int k = 1; k < n; k <<= 1) {
            Int base = root.pow(n / (2*k));
            Int z = 1;
            for (int j = 0; j < k; ++j) {
                for (int i = j; i < n; i += 2*k) {
                    Int u = a[i], v = a[i+k] * z;
                    a[i] = u + v;
                    a[i+k] = u - v;
                }
                z *= base;
            }
        }
    }
};

