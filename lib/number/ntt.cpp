#include "../template.cpp"

/*
 * @brief NTT
 * @author habara-k
 * @usage
 *   vector<NTT<>::Int> a, b;
 *   NTT<> ntt;
 *   auto c = ntt.multiply(a, b);
 * 有名なmod, rootの組
 * 998244353, 3
 * 163577857, 23
 * 167772161, 3
 * 469762049, 3
 */
template<int mod=998244353, int root=3>
struct NTT {
    using Int = mint<mod>;
    int n;
    Int r;
    void ensure(int need) {
        n = 1;
        while (n < need) n <<= 1;
        r = Int{root}.pow((mod-1) / n);
    }

    vector<Int> multiply(vector<Int> a, vector<Int> b) {
        int need = SZ(a) + SZ(b) - 1;
        ensure(need);
        ntt(a);
        ntt(b);
        REP(i, n) (a[i] *= b[i]) /= n;
        reverse(a.begin() + 1, a.end());
        ntt(a); a.resize(need);
        return a;
    }

    void ntt(vector<Int>& a) {
        a.resize(n);
        int p = 0;
        FOR(i, 1, n-1) {
            for (int k = n >> 1; k > (p ^= k); k >>= 1);
            if (i < p) swap(a[i], a[p]);
        }
        for (int k = 1; k < n; k <<= 1) {
            Int base = r.pow(n / (2*k));
            Int z = 1;
            REP(j, k) {
                for (int i = j; i < n; i += 2*k) {
                    Int v = a[i+k] * z;
                    a[i+k] = a[i] - v;
                    a[i] += v;
                }
                z *= base;
            }
        }
    }
};

