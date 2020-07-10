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
    - Last commit date: 2020-05-27 02:06:18+09:00




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
* @date 2020/05/27
* @verify https://atcoder.jp/contests/atc001/submissions/13627626
* @details 使い方
*   e.g. 多項式の積
*
*   vector<complex<double>> a(2*n+1), b(2*n+1);
*
*   auto A = FFT<double>(a).solve();
*   auto B = FFT<double>(b).solve();
*
*   vector<complex<double>> C(A.size());
*   REP(i, C.size()) C[i] = A[i] * B[i];
*
*   auto c = FFT<double>(C).solve(true);
*/


template<typename T>
struct FFT {

    /**
    * @brief コンストラクタ. O(n)
    * @param[in] a_: 多項式の係数
    */
    FFT(const vector<complex<T>>& a_) : a(a_), n(1) {
        while (n < a.size()) n <<= 1;
        a.resize(n);
    }

    /**
    * @brief FFTの実行. O(nlog n)
    * @param[in] inverse: 逆変換のフラグ.
    * @return FFT or inverse-FFT
    */
    vector<complex<T>> solve(bool inverse = false) {
        return fft(0, 0, inverse);
    }

private:
    vector<complex<T>> a;
    int n;
    const T PI = acos(-1);

    vector<complex<T>> fft(int d, int bit, bool inverse) {
        int sz = n >> d;
        if (sz == 1) return {a[bit] / (inverse ? static_cast<T>(n) : 1.0)};

        auto f0 = fft(d+1, bit, inverse);
        auto f1 = fft(d+1, bit | 1<<d, inverse);
        vector<complex<T>> f(sz);
        for (int i = 0; i < sz; ++i) {
            f[i] = f0[i % (sz / 2)] +
                   std::polar(1.0, 2*PI / sz * i * (inverse ? -1 : 1)) *
                   f1[i % (sz / 2)];
        }
        return f;
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
* @date 2020/05/27
* @verify https://atcoder.jp/contests/atc001/submissions/13627626
* @details 使い方
*   e.g. 多項式の積
*
*   vector<complex<double>> a(2*n+1), b(2*n+1);
*
*   auto A = FFT<double>(a).solve();
*   auto B = FFT<double>(b).solve();
*
*   vector<complex<double>> C(A.size());
*   REP(i, C.size()) C[i] = A[i] * B[i];
*
*   auto c = FFT<double>(C).solve(true);
*/


template<typename T>
struct FFT {

    /**
    * @brief コンストラクタ. O(n)
    * @param[in] a_: 多項式の係数
    */
    FFT(const vector<complex<T>>& a_) : a(a_), n(1) {
        while (n < a.size()) n <<= 1;
        a.resize(n);
    }

    /**
    * @brief FFTの実行. O(nlog n)
    * @param[in] inverse: 逆変換のフラグ.
    * @return FFT or inverse-FFT
    */
    vector<complex<T>> solve(bool inverse = false) {
        return fft(0, 0, inverse);
    }

private:
    vector<complex<T>> a;
    int n;
    const T PI = acos(-1);

    vector<complex<T>> fft(int d, int bit, bool inverse) {
        int sz = n >> d;
        if (sz == 1) return {a[bit] / (inverse ? static_cast<T>(n) : 1.0)};

        auto f0 = fft(d+1, bit, inverse);
        auto f1 = fft(d+1, bit | 1<<d, inverse);
        vector<complex<T>> f(sz);
        for (int i = 0; i < sz; ++i) {
            f[i] = f0[i % (sz / 2)] +
                   std::polar(1.0, 2*PI / sz * i * (inverse ? -1 : 1)) *
                   f1[i % (sz / 2)];
        }
        return f;
    }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

