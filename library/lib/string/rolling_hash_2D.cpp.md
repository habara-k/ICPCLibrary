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


# :heavy_check_mark: 2次元文字列のハッシュ化 <small>(lib/string/rolling_hash_2D.cpp)</small>

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#9a48db5fb6f746df590a3d4604f6478b">lib/string</a>
* <a href="{{ site.github.repository_url }}/blob/master/lib/string/rolling_hash_2D.cpp">View this file on GitHub</a>
    - Last commit date: 2020-07-05 15:39:35+09:00




## Depends on

* :question: <a href="../template.cpp.html">lib/template.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/string/rolling_hash_2D.test.cpp.html">test/string/rolling_hash_2D.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include "../template.cpp"

/**
* @brief 2次元文字列のハッシュ化
* @author habara-k
* @date 2020/07/05
*/

struct RollingHash2D {
    using uint = uint64_t;

    /**
    * @brief コンストラクタ. O(|vs|)
    * @param[in] vs ハッシュ化する文字列のベクトル(or matrix).
    * @param[in] base1, base2 ハッシュ化に使う基数. RollingHash2D::gen_base で作る.
    * @details 使い方
    *   auto base1 = RollingHash2D::gen_base(),
    *        base2 = RolligHash2D::gen_base();
    *
    *   vector<string> t;
    *   RollingHash2D hash(t, base1, base2);
    */
    template<typename VS>
    RollingHash2D(const VS &vs, uint base1, uint base2) {
        int n = vs.size();
        int m = vs[0].size();
        hash.resize(n + 1);
        for (int i = 0; i <= n; ++i) hash[i].resize(m + 1);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                hash[i + 1][j + 1] = mod(mul(hash[i + 1][j], base2) + vs[i][j]);
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                hash[i + 1][j + 1] = mod(mul(hash[i][j + 1], base1) + hash[i + 1][j + 1]);
            }
        }

        pow1.assign(n + 1, 1);
        for (int i = 0; i < n; ++i) {
            pow1[i + 1] = mul(pow1[i], base1);
        }
        pow2.assign(m + 1, 1);
        for (int j = 0; j < m; ++j) {
            pow2[j + 1] = mul(pow2[j], base2);
        }
    }

    /**
    * @brief ハッシュを計算する. O(1)
    * @param[in] i0, j0, i1, j1 ハッシュを計算したい区間.
    * @return 区間[(i0,j0), (i1,j1)) のハッシュ.
    * @details 使い方
    *   cout << hash.get(0, 0, t.size(), t[0].size()) << endl;
    */
    long long get(int i0, int j0, int i1, int j1) {
        uint a = mod(hash[i1][j1] + MASK61 - mul(hash[i1][j0], pow2[j1 - j0]));
        uint b = mod(hash[i0][j1] + MASK61 - mul(hash[i0][j0], pow2[j1 - j0]));
        return mod(a + MASK61 - mul(b, pow1[i1 - i0]));
    }

    /**
    * @brief 基数を生成する. O(1)
    * @return ランダムな基数.
    * @details 使い方
    *   auto base = RollingHash::gen_base();
    */
    static uint gen_base() {
        mt19937 random{random_device{}()};
        uniform_int_distribution <uint> dist(2, MASK61 - 2);
        return dist(random);
    }

private:
    vector<vector<uint>> hash;
    vector<uint> pow1, pow2;
    static const uint MASK30 = (1LL << 30) - 1,
            MASK31 = (1LL << 31) - 1,
            MASK61 = (1LL << 61) - 1;

    static uint mul(uint a, uint b) {
        uint au = a >> 31, ad = a & MASK31,
                bu = b >> 31, bd = b & MASK31;
        uint m = au * bd + ad * bu;
        uint mu = m >> 30, md = m & MASK30;

        return mod(au * bu * 2 + mu + (md << 31) + ad * bd);
    }

    static uint mod(uint x) {
        uint xu = x >> 61, xd = x & MASK61;
        uint ret = xu + xd;
        if (ret >= MASK61) ret -= MASK61;
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


#line 2 "lib/string/rolling_hash_2D.cpp"

/**
* @brief 2次元文字列のハッシュ化
* @author habara-k
* @date 2020/07/05
*/

struct RollingHash2D {
    using uint = uint64_t;

    /**
    * @brief コンストラクタ. O(|vs|)
    * @param[in] vs ハッシュ化する文字列のベクトル(or matrix).
    * @param[in] base1, base2 ハッシュ化に使う基数. RollingHash2D::gen_base で作る.
    * @details 使い方
    *   auto base1 = RollingHash2D::gen_base(),
    *        base2 = RolligHash2D::gen_base();
    *
    *   vector<string> t;
    *   RollingHash2D hash(t, base1, base2);
    */
    template<typename VS>
    RollingHash2D(const VS &vs, uint base1, uint base2) {
        int n = vs.size();
        int m = vs[0].size();
        hash.resize(n + 1);
        for (int i = 0; i <= n; ++i) hash[i].resize(m + 1);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                hash[i + 1][j + 1] = mod(mul(hash[i + 1][j], base2) + vs[i][j]);
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                hash[i + 1][j + 1] = mod(mul(hash[i][j + 1], base1) + hash[i + 1][j + 1]);
            }
        }

        pow1.assign(n + 1, 1);
        for (int i = 0; i < n; ++i) {
            pow1[i + 1] = mul(pow1[i], base1);
        }
        pow2.assign(m + 1, 1);
        for (int j = 0; j < m; ++j) {
            pow2[j + 1] = mul(pow2[j], base2);
        }
    }

    /**
    * @brief ハッシュを計算する. O(1)
    * @param[in] i0, j0, i1, j1 ハッシュを計算したい区間.
    * @return 区間[(i0,j0), (i1,j1)) のハッシュ.
    * @details 使い方
    *   cout << hash.get(0, 0, t.size(), t[0].size()) << endl;
    */
    long long get(int i0, int j0, int i1, int j1) {
        uint a = mod(hash[i1][j1] + MASK61 - mul(hash[i1][j0], pow2[j1 - j0]));
        uint b = mod(hash[i0][j1] + MASK61 - mul(hash[i0][j0], pow2[j1 - j0]));
        return mod(a + MASK61 - mul(b, pow1[i1 - i0]));
    }

    /**
    * @brief 基数を生成する. O(1)
    * @return ランダムな基数.
    * @details 使い方
    *   auto base = RollingHash::gen_base();
    */
    static uint gen_base() {
        mt19937 random{random_device{}()};
        uniform_int_distribution <uint> dist(2, MASK61 - 2);
        return dist(random);
    }

private:
    vector<vector<uint>> hash;
    vector<uint> pow1, pow2;
    static const uint MASK30 = (1LL << 30) - 1,
            MASK31 = (1LL << 31) - 1,
            MASK61 = (1LL << 61) - 1;

    static uint mul(uint a, uint b) {
        uint au = a >> 31, ad = a & MASK31,
                bu = b >> 31, bd = b & MASK31;
        uint m = au * bd + ad * bu;
        uint mu = m >> 30, md = m & MASK30;

        return mod(au * bu * 2 + mu + (md << 31) + ad * bd);
    }

    static uint mod(uint x) {
        uint xu = x >> 61, xd = x & MASK61;
        uint ret = xu + xd;
        if (ret >= MASK61) ret -= MASK61;
        return ret;
    }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

