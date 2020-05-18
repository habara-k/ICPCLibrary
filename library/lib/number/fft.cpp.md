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


# :warning: FFT <small>(lib/number/fft.cpp)</small>

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#12cd94d703d26487f7477e7dcce25e7f">lib/number</a>
* <a href="{{ site.github.repository_url }}/blob/master/lib/number/fft.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-19 00:21:46+09:00




## Depends on

* :heavy_check_mark: <a href="../template.cpp.html">lib/template.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include "../template.cpp"

/**
* @brief FFT
* @author habara-k
* @date 2020/05/19
* @verify https://atcoder.jp/contests/atc001/submissions/13384565
* @details 使い方
*   e.g. 多項式の積
*
*   vector<complex<double>> a(n+1), b(n+1);
*   auto A = FFT(a, 2*n+1).solve();
*   auto B = FFT(b, 2*n+1).solve();
*
*   vector<complex<double>> C(A.size());
*   REP(i, C.size()) C[i] = A[i] * B[i];
*
*   auto c = FFT(C, 2*n+1).solve(true);
*/

struct FFT {


    /**
    * @brief コンストラクタ. O(n)
    * @param[in] f_ 多項式の係数
    * @param[in] n_ 必要な点の数
    */
    FFT(const vector<complex<double>>& f_, int n_) : f(f_), n(1) {
        while (n < n_) n <<= 1;
        f.resize(n);
    }

    /**
    * @brief FFTの実行. O(nlog n)
    * @param[in] inverse 逆変換のフラグ.
    * @return f のFFT or inverse-FFT
    */
    vector<complex<double>> solve(bool inverse = false) {
        return fft(0, 0, inverse);
    }

private:
    vector<complex<double>> f;
    int n;
    const double PI = acos(-1);

    vector<complex<double>> fft(int d, int bit, bool inverse) {
        int sz = n >> d;
        if (sz == 1) return {f[bit] / (inverse ? (double)n : 1.0)};

        auto F0 = fft(d+1, bit, inverse);
        auto F1 = fft(d+1, bit | 1<<d, inverse);
        vector<complex<double>> F(sz);
        for (int i = 0; i < sz; ++i) {
            F[i] = F0[i % (sz / 2)] +
                    std::polar(1.0, 2*PI / sz * i * (inverse ? -1 : 1)) * F1[i % (sz / 2)];
        }
        return F;
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


#line 2 "lib/number/fft.cpp"

/**
* @brief FFT
* @author habara-k
* @date 2020/05/19
* @verify https://atcoder.jp/contests/atc001/submissions/13384565
* @details 使い方
*   e.g. 多項式の積
*
*   vector<complex<double>> a(n+1), b(n+1);
*   auto A = FFT(a, 2*n+1).solve();
*   auto B = FFT(b, 2*n+1).solve();
*
*   vector<complex<double>> C(A.size());
*   REP(i, C.size()) C[i] = A[i] * B[i];
*
*   auto c = FFT(C, 2*n+1).solve(true);
*/

struct FFT {


    /**
    * @brief コンストラクタ. O(n)
    * @param[in] f_ 多項式の係数
    * @param[in] n_ 必要な点の数
    */
    FFT(const vector<complex<double>>& f_, int n_) : f(f_), n(1) {
        while (n < n_) n <<= 1;
        f.resize(n);
    }

    /**
    * @brief FFTの実行. O(nlog n)
    * @param[in] inverse 逆変換のフラグ.
    * @return f のFFT or inverse-FFT
    */
    vector<complex<double>> solve(bool inverse = false) {
        return fft(0, 0, inverse);
    }

private:
    vector<complex<double>> f;
    int n;
    const double PI = acos(-1);

    vector<complex<double>> fft(int d, int bit, bool inverse) {
        int sz = n >> d;
        if (sz == 1) return {f[bit] / (inverse ? (double)n : 1.0)};

        auto F0 = fft(d+1, bit, inverse);
        auto F1 = fft(d+1, bit | 1<<d, inverse);
        vector<complex<double>> F(sz);
        for (int i = 0; i < sz; ++i) {
            F[i] = F0[i % (sz / 2)] +
                    std::polar(1.0, 2*PI / sz * i * (inverse ? -1 : 1)) * F1[i % (sz / 2)];
        }
        return F;
    }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

