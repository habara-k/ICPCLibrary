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


# :heavy_check_mark:  <small>(lib/number/matrix.cpp)</small>

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#12cd94d703d26487f7477e7dcce25e7f">lib/number</a>
* <a href="{{ site.github.repository_url }}/blob/master/lib/number/matrix.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-06 01:41:24+09:00




## Depends on

* :question: <a href="../template.cpp.html">lib/template.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/number/matrix.test.cpp.html">test/number/matrix.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include "../template.cpp"

/**
 * @brief
 * 行列累乗
 * @author habara-k
 * @date 2020/04/24
 * @param[in] a 行列
 * @param[in] k 指数
 * @return 行列 a^k
 *
 * @details
 * T に渡すのは環であり、operator *, += を定義すること
 */

template<class T>
using Matrix = vector<vector<T>>;

template<class T>
Matrix<T> operator*(const Matrix<T>& A, const Matrix<T>& B) {
    assert(A[0].size() == B.size());
    int n = A.size(), m = B[0].size(), p = A[0].size();
    Matrix<T> C(n, vector<T>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            for (int k = 0; k < p; ++k)
                C[i][j] += A[i][k] * B[k][j];
    return C;
}

template<class T>
Matrix<T> pow(Matrix<T> a, ll k) {
    assert(a.size() == a[0].size());
    int n = a.size();
    Matrix<T> ret(n, vector<T>(n));
    for (int i = 0; i < n; ++i) ret[i][i] = 1;
    while (k) {
        if (k & 1) ret = ret * a;
        a = a * a; k >>= 1;
    }
    return ret;
}

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


#line 2 "lib/number/matrix.cpp"

/**
 * @brief
 * 行列累乗
 * @author habara-k
 * @date 2020/04/24
 * @param[in] a 行列
 * @param[in] k 指数
 * @return 行列 a^k
 *
 * @details
 * T に渡すのは環であり、operator *, += を定義すること
 */

template<class T>
using Matrix = vector<vector<T>>;

template<class T>
Matrix<T> operator*(const Matrix<T>& A, const Matrix<T>& B) {
    assert(A[0].size() == B.size());
    int n = A.size(), m = B[0].size(), p = A[0].size();
    Matrix<T> C(n, vector<T>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            for (int k = 0; k < p; ++k)
                C[i][j] += A[i][k] * B[k][j];
    return C;
}

template<class T>
Matrix<T> pow(Matrix<T> a, ll k) {
    assert(a.size() == a[0].size());
    int n = a.size();
    Matrix<T> ret(n, vector<T>(n));
    for (int i = 0; i < n; ++i) ret[i][i] = 1;
    while (k) {
        if (k & 1) ret = ret * a;
        a = a * a; k >>= 1;
    }
    return ret;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

