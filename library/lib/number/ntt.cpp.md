---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :warning:  <small>(lib/number/ntt.cpp)</small>

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#12cd94d703d26487f7477e7dcce25e7f">lib/number</a>
* <a href="{{ site.github.repository_url }}/blob/master/lib/number/ntt.cpp">View this file on GitHub</a>
    - Last commit date: 2020-07-11 00:18:50+09:00




## Depends on

* :heavy_check_mark: <a href="../template.cpp.html">lib/template.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include "../template.cpp"

/**
 * @brief
 * Number Theoretic Transform
 * @author habara-k
 * @date 2020/07/11
 * @verify https://atcoder.jp/contests/atc001/submissions/15125563
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

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "lib/template.cpp"



#include <bits/stdc++.h>

using namespace std;

#define REP(i, n) for (int i=0; i<(n); ++i)
#define RREP(i, n) for (int i=(int)(n)-1; i>=0; --i)
#define FOR(i, a, n) for (int i=(a); i<(n); ++i)
#define RFOR(i, a, n) for (int i=(int)(n)-1; i>=(a); --i)

#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()

#define DUMP(x) cerr<<#x<<" = "<<(x)<<endl
#define DEBUG(x) cerr<<#x<<" = "<<(x)<<" (L"<<__LINE__<<")"<<endl;

template<class T>
ostream &operator<<(ostream &os, const vector <T> &v) {
    os << "[";
    REP(i, SZ(v)) {
        if (i) os << ", ";
        os << v[i];
    }
    return os << "]";
}

template<class T, class U>
ostream &operator<<(ostream &os, const pair <T, U> &p) {
    return os << "(" << p.first << " " << p.second << ")";
}

template<class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
bool chmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using P = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using vvll = vector<vll>;

const ll MOD = 1e9 + 7;
const int INF = INT_MAX / 2;
const ll LINF = LLONG_MAX / 2;
const ld eps = 1e-9;

/*
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);

    // ifstream in("in.txt");
    // cin.rdbuf(in.rdbuf());

    return 0;
}
*/


#line 2 "lib/number/ntt.cpp"

/**
 * @brief
 * Number Theoretic Transform
 * @author habara-k
 * @date 2020/07/11
 * @verify https://atcoder.jp/contests/atc001/submissions/15125563
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

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

