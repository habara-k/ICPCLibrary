#include "../template.cpp"

/**
 * @brief
 * Number Theoretic Transform
 * @author habara-k
 * @date 2020/07/11
 */

template<ll mod=998244353, ll primitive=3>
struct NTT {

    /**
    * @brief 畳み込みの実行. O(nlog n)
    * @require n <= 2^23
    * @param[in] a, b: 畳み込みたい配列
    * @return 畳み込みした結果
    * @usage
    *   vector<ll> a(2*n+1), b(2*n+1);
    *   vector<ll> c = NTT<>::multiply(a, b);
    */
    static vector<ll> multiply(const vector<ll>& a, const vector<ll>& b) {
        auto A = NTT(a).solve();
        auto B = NTT(b).solve();

        vector<ll> C(A.size());
        REP(i, C.size()) C[i] = (A[i] * B[i]) % 998244353;

        return NTT(C).solve(true);
    }

private:
    int n;
    vector<ll> a;
    ll inv_n, root, inv_root;

    NTT(const vector<ll>& a) : n(1), a(a) {
        while (n < a.size()) n <<= 1;
        this->a.resize(n);
        inv_n = modpow(n, mod-2);
        root = modpow(primitive, (mod-1) / n);
        inv_root = modpow(root, mod-2);
    }

    vector<ll> solve(bool inverse = false) {
        return ntt(0, 0, inverse, inverse ? inv_root : root);
    }

    vector<ll> ntt(int d, int bit, bool inverse, ll base) {
        int sz = n >> d;
        if (sz == 1) return {(a[bit] * (inverse ? inv_n : 1)) % mod};

        auto f0 = ntt(d+1, bit, inverse, (base * base) % mod);
        auto f1 = ntt(d+1, bit | 1<<d, inverse, (base * base) % mod);
        vector<ll> f(sz);
        ll tmp = 1;
        for (int i = 0; i < sz; ++i) {
            f[i] = (f0[i % (sz / 2)] + tmp * f1[i % (sz / 2)]) % mod;
            (tmp *= base) %= mod;
        }
        return f;
    }

    ll modpow(ll a, ll p) {
        ll ret = 1;
        while (p) {
            if (p & 1) (ret *= a) %= mod;
            (a *= a) %= mod;
            p >>= 1;
        }
        return ret;
    }
};
