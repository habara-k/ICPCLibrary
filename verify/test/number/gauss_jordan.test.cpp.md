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


# :heavy_check_mark: test/number/gauss_jordan.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#27c49c4e5cc6f85fad5dbff6f8f0ef1b">test/number</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/number/gauss_jordan.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-24 14:14:43+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1308">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1308</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/lib/number/gauss_jordan.cpp.html"> <small>(lib/number/gauss_jordan.cpp)</small></a>
* :heavy_check_mark: <a href="../../../library/lib/template.cpp.html">lib/template.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1308"

#include "../../lib/number/gauss_jordan.cpp"

struct GF2 {
    int x;
    bool operator==(int a) { return x == a; }
    bool operator!=(int a) { return !(*this == a); }
    GF2(int x=0) : x(x) {}
    GF2 &operator/=(GF2 a) {
        assert(a != 0);
        x /= a.x;
        return *this;
    }
    GF2 &operator-=(GF2 a) {
        x ^= a.x;
        return *this;
    }
    GF2 operator*(GF2 a) {
        return GF2(x * a.x);
    }
    friend istream& operator>>(istream& is, GF2& a) {
        int tmp; is >> tmp;
        a = tmp;
        return is;
    }
};

int main() {

    for (;;) {
        int m, n, d;
        cin >> m >> n >> d;
        if (m == 0) break;

        vector<vector<GF2>> mat(n*m, vector<GF2>(n*m+1));

        REP(i, n) REP(j, m) cin >> mat[i*m + j][n*m];

        REP(i, n) REP(j, m) {
            mat[i*m + j][i*m + j] = 1;
            REP(y, n) REP(x, m) {
                if (abs(y - i) + abs(x - j) == d) {
                    mat[i*m + j][y*m + x] = 1;
                }
            }
        }

        GaussJordanElimination(mat);

        int ans = true;
        REP(i, n * m) {
            int allZero = true;
            REP(j, n * m) {
                if (mat[i][j] != 0) {
                    allZero = false;
                    break;
                }
            }
            if (allZero and mat[i][n * m] == 1) {
                ans = false;
                break;
            }
        }
        cout << ans << endl;
    }

    return 0;
}


```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/number/gauss_jordan.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1308"

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


#line 2 "lib/number/gauss_jordan.cpp"

// verify: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1308

/**
 * @brief
 * ガウスの消去法
 * 行列をランクを求めたり、Ax = b を解いたりする
 * @author habara-k
 * @date 2020/4
 * @param[in] mat 行列
 * @return int mat のランク
 */

template<class T>
int GaussJordanElimination(vector<vector<T>>& mat) {
    int H = mat.size(), W = mat[0].size(), rank = 0;
    for (int col = 0; col < W; ++col) {
        int pivot = -1;
        for (int row = rank; row < H; ++row) {
            if (mat[row][col] != 0) {
                pivot = row;
                break;
            }
        }
        if (pivot == -1) continue;
        swap(mat[rank], mat[pivot]);
        T topLeft = mat[rank][col];
        for (int c = col; c < W; ++c) {
            mat[rank][c] /= topLeft;
        }
        for (int row = rank+1; row < H; ++row) {
            T ratio = mat[row][col];
            for (int c = col; c < W; ++c)
                mat[row][c] -= ratio * mat[rank][c];
        }
        ++rank;
    }
    return (rank);
}
#line 4 "test/number/gauss_jordan.test.cpp"

struct GF2 {
    int x;
    bool operator==(int a) { return x == a; }
    bool operator!=(int a) { return !(*this == a); }
    GF2(int x=0) : x(x) {}
    GF2 &operator/=(GF2 a) {
        assert(a != 0);
        x /= a.x;
        return *this;
    }
    GF2 &operator-=(GF2 a) {
        x ^= a.x;
        return *this;
    }
    GF2 operator*(GF2 a) {
        return GF2(x * a.x);
    }
    friend istream& operator>>(istream& is, GF2& a) {
        int tmp; is >> tmp;
        a = tmp;
        return is;
    }
};

int main() {

    for (;;) {
        int m, n, d;
        cin >> m >> n >> d;
        if (m == 0) break;

        vector<vector<GF2>> mat(n*m, vector<GF2>(n*m+1));

        REP(i, n) REP(j, m) cin >> mat[i*m + j][n*m];

        REP(i, n) REP(j, m) {
            mat[i*m + j][i*m + j] = 1;
            REP(y, n) REP(x, m) {
                if (abs(y - i) + abs(x - j) == d) {
                    mat[i*m + j][y*m + x] = 1;
                }
            }
        }

        GaussJordanElimination(mat);

        int ans = true;
        REP(i, n * m) {
            int allZero = true;
            REP(j, n * m) {
                if (mat[i][j] != 0) {
                    allZero = false;
                    break;
                }
            }
            if (allZero and mat[i][n * m] == 1) {
                ans = false;
                break;
            }
        }
        cout << ans << endl;
    }

    return 0;
}


```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

