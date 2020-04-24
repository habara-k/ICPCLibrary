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


# :heavy_check_mark: test/number/matrix.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#27c49c4e5cc6f85fad5dbff6f8f0ef1b">test/number</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/number/matrix.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-24 14:14:43+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2397">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2397</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/lib/number/matrix.cpp.html"> <small>(lib/number/matrix.cpp)</small></a>
* :heavy_check_mark: <a href="../../../library/lib/template.cpp.html">lib/template.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2397"

#include "../../lib/number/matrix.cpp"


template<int mod>
struct modint {
    ll x;
    modint(ll x=0) : x(x) {}
    modint &operator+=(const modint& a) {
        (x += a.x) %= mod;
        return *this;
    }
    friend modint operator*(const modint& a, const modint& b) {
        return modint((a.x * b.x) % mod);
    }
    friend ostream &operator<<(ostream &os, const modint &a) {
        return os << a.x;
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);

    for (int t = 1;; ++t) {
        ll W, H, N;
        cin >> W >> H >> N;
        if (W == 0) break;
        bool zero = false;
        map<ll, vi> obs;
        REP(i, N) {
            ll x, y;
            cin >> x >> y;
            --x, --y;
            if (x == 0 and y == 0) {
                zero = true;
            }
            if (y > 0) obs[y].emplace_back(x);
        }
        if (zero) {
            cout << 0 << endl;
            return 0;
        }

        using Int = modint<1000000009>;

        Matrix<Int> A(W, vector<Int>(W));
        REP(i, W) A[i][i] = 1;

        Matrix<Int> B = A;
        REP(i, W) {
            if (i - 1 >= 0) B[i][i - 1] = 1;
            if (i + 1 < W) B[i][i + 1] = 1;
        }

        ll prv = 0;
        for (auto &tp : obs) {
            ll now = tp.first;

            A = A * pow(B, now - prv - 1);

            Matrix<Int> tmp = B;
            for (int j : tp.second) {
                REP(i, W) tmp[i][j] = 0;
            }
            A = A * tmp;

            prv = now;

        }

        A = A * pow(B, H - prv - 1);

        cout << "Case " << t << ": " << A[0][W - 1].x << endl;
    }

    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/number/matrix.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2397"

#line 1 "lib/template.cpp"



#include <bits/stdc++.h>

using namespace std;

#define REP(i, n) for (int i=0; i<(n); ++i)
#define RREP(i, n) for (int i=(int)(n)-1; i>=0; --i)
#define FOR(i, a, n) for (int i=(a); i<(n); ++i)
#define RFOR(i, a, n) for (int i=(int)(n)-1; i>=(a); --i)

#define SZ(x) ((int)(x).size())
#define all(x) begin(x),end(x)

#define dump(x) cerr<<#x<<" = "<<(x)<<endl
#define debug(x) cerr<<#x<<" = "<<(x)<<" (L"<<__LINE__<<")"<<endl;

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

// verify: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2397

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
    int n = a.size(), m = a[0].size();
    Matrix<T> ret(n, vector<T>(m));
    REP(i, n) ret[i][i] = 1;
    while (k) {
        if (k & 1) ret = ret * a;
        a = a * a; k >>= 1;
    }
    return ret;
}
#line 4 "test/number/matrix.test.cpp"


template<int mod>
struct modint {
    ll x;
    modint(ll x=0) : x(x) {}
    modint &operator+=(const modint& a) {
        (x += a.x) %= mod;
        return *this;
    }
    friend modint operator*(const modint& a, const modint& b) {
        return modint((a.x * b.x) % mod);
    }
    friend ostream &operator<<(ostream &os, const modint &a) {
        return os << a.x;
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);

    for (int t = 1;; ++t) {
        ll W, H, N;
        cin >> W >> H >> N;
        if (W == 0) break;
        bool zero = false;
        map<ll, vi> obs;
        REP(i, N) {
            ll x, y;
            cin >> x >> y;
            --x, --y;
            if (x == 0 and y == 0) {
                zero = true;
            }
            if (y > 0) obs[y].emplace_back(x);
        }
        if (zero) {
            cout << 0 << endl;
            return 0;
        }

        using Int = modint<1000000009>;

        Matrix<Int> A(W, vector<Int>(W));
        REP(i, W) A[i][i] = 1;

        Matrix<Int> B = A;
        REP(i, W) {
            if (i - 1 >= 0) B[i][i - 1] = 1;
            if (i + 1 < W) B[i][i + 1] = 1;
        }

        ll prv = 0;
        for (auto &tp : obs) {
            ll now = tp.first;

            A = A * pow(B, now - prv - 1);

            Matrix<Int> tmp = B;
            for (int j : tp.second) {
                REP(i, W) tmp[i][j] = 0;
            }
            A = A * tmp;

            prv = now;

        }

        A = A * pow(B, H - prv - 1);

        cout << "Case " << t << ": " << A[0][W - 1].x << endl;
    }

    return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

