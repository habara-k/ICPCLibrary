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


# :heavy_check_mark: test/string/rolling_hash_2D.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#e46c0047b1d14ef43eeaaf13f64d385f">test/string</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/string/rolling_hash_2D.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-07-05 15:39:35+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1312">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1312</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/lib/string/rolling_hash_2D.cpp.html">2次元文字列のハッシュ化 <small>(lib/string/rolling_hash_2D.cpp)</small></a>
* :heavy_check_mark: <a href="../../../library/lib/template.cpp.html">lib/template.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1312"

#include "../../lib/string/rolling_hash_2D.cpp"

int main() {
    while (true) {
        int w, h, p; cin >> w >> h >> p;
        if (w == 0) break;
        vector<vector<int>> image(h), pattern(p);
        REP(i, h) {
            string str; cin >> str;
            for (char c : str) {
                int n = -1;
                if ('A' <= c and c <= 'Z') n = c - 'A';
                if ('a' <= c and c <= 'z') n = c - 'a' + 26;
                if ('0' <= c and c <= '9') n = c - '0' + 52;
                if (c == '+') n = 62;
                if (c == '/') n = 63;

                REP(j, 6) {
                    image[i].push_back(n >> (5 - j) & 1);
                }
            }
        }
        REP(i, p) {
            string str; cin >> str;
            for (char c : str) {
                int n = -1;
                if ('A' <= c and c <= 'Z') n = c - 'A';
                if ('a' <= c and c <= 'z') n = c - 'a' + 26;
                if ('0' <= c and c <= '9') n = c - '0' + 52;
                if (c == '+') n = 62;
                if (c == '/') n = 63;

                REP(j, 6) {
                    pattern[i].push_back(n >> (5 - j) & 1);
                }
            }
        }

        auto base1 = RollingHash2D::gen_base();
        auto base2 = RollingHash2D::gen_base();

        RollingHash2D Image(image, base1, base2);
        vector<long long> patternHash;

        {
            vector<vector<int>> alt(p, vector<int>(p));
            for (int i = 0; i < p; ++i) {
                for (int j = 0; j < p; ++j) {
                    alt[i][j] = pattern[i][j];
                }
            }
            patternHash.push_back(RollingHash2D(alt, base1, base2).get(0, 0, p, p));
        }
        {
            vector<vector<int>> alt(p, vector<int>(p));
            for (int i = 0; i < p; ++i) {
                for (int j = 0; j < p; ++j) {
                    alt[p-1-i][j] = pattern[i][j];
                }
            }
            patternHash.push_back(RollingHash2D(alt, base1, base2).get(0, 0, p, p));
        }
        {
            vector<vector<int>> alt(p, vector<int>(p));
            for (int i = 0; i < p; ++i) {
                for (int j = 0; j < p; ++j) {
                    alt[i][p-1-j] = pattern[i][j];
                }
            }
            patternHash.push_back(RollingHash2D(alt, base1, base2).get(0, 0, p, p));
        }
        {
            vector<vector<int>> alt(p, vector<int>(p));
            for (int i = 0; i < p; ++i) {
                for (int j = 0; j < p; ++j) {
                    alt[p-1-i][p-1-j] = pattern[i][j];
                }
            }
            patternHash.push_back(RollingHash2D(alt, base1, base2).get(0, 0, p, p));
        }
        {
            vector<vector<int>> alt(p, vector<int>(p));
            for (int i = 0; i < p; ++i) {
                for (int j = 0; j < p; ++j) {
                    alt[i][j] = pattern[j][i];
                }
            }
            patternHash.push_back(RollingHash2D(alt, base1, base2).get(0, 0, p, p));
        }
        {
            vector<vector<int>> alt(p, vector<int>(p));
            for (int i = 0; i < p; ++i) {
                for (int j = 0; j < p; ++j) {
                    alt[p-1-i][j] = pattern[j][i];
                }
            }
            patternHash.push_back(RollingHash2D(alt, base1, base2).get(0, 0, p, p));
        }
        {
            vector<vector<int>> alt(p, vector<int>(p));
            for (int i = 0; i < p; ++i) {
                for (int j = 0; j < p; ++j) {
                    alt[i][p-1-j] = pattern[j][i];
                }
            }
            patternHash.push_back(RollingHash2D(alt, base1, base2).get(0, 0, p, p));
        }
        {
            vector<vector<int>> alt(p, vector<int>(p));
            for (int i = 0; i < p; ++i) {
                for (int j = 0; j < p; ++j) {
                    alt[p-1-i][p-1-j] = pattern[j][i];
                }
            }
            patternHash.push_back(RollingHash2D(alt, base1, base2).get(0, 0, p, p));
        }

        int ans = 0;
        for (int i = 0; i + p <= h; ++i) {
            for (int j = 0; j + p <= w; ++j) {
                long long imageHash = Image.get(i, j, i + p, j + p);
                for (long long hash : patternHash) {
                    if (imageHash == hash) {
                        ++ans;
                        break;
                    }
                }
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
#line 1 "test/string/rolling_hash_2D.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1312"

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
#line 4 "test/string/rolling_hash_2D.test.cpp"

int main() {
    while (true) {
        int w, h, p; cin >> w >> h >> p;
        if (w == 0) break;
        vector<vector<int>> image(h), pattern(p);
        REP(i, h) {
            string str; cin >> str;
            for (char c : str) {
                int n = -1;
                if ('A' <= c and c <= 'Z') n = c - 'A';
                if ('a' <= c and c <= 'z') n = c - 'a' + 26;
                if ('0' <= c and c <= '9') n = c - '0' + 52;
                if (c == '+') n = 62;
                if (c == '/') n = 63;

                REP(j, 6) {
                    image[i].push_back(n >> (5 - j) & 1);
                }
            }
        }
        REP(i, p) {
            string str; cin >> str;
            for (char c : str) {
                int n = -1;
                if ('A' <= c and c <= 'Z') n = c - 'A';
                if ('a' <= c and c <= 'z') n = c - 'a' + 26;
                if ('0' <= c and c <= '9') n = c - '0' + 52;
                if (c == '+') n = 62;
                if (c == '/') n = 63;

                REP(j, 6) {
                    pattern[i].push_back(n >> (5 - j) & 1);
                }
            }
        }

        auto base1 = RollingHash2D::gen_base();
        auto base2 = RollingHash2D::gen_base();

        RollingHash2D Image(image, base1, base2);
        vector<long long> patternHash;

        {
            vector<vector<int>> alt(p, vector<int>(p));
            for (int i = 0; i < p; ++i) {
                for (int j = 0; j < p; ++j) {
                    alt[i][j] = pattern[i][j];
                }
            }
            patternHash.push_back(RollingHash2D(alt, base1, base2).get(0, 0, p, p));
        }
        {
            vector<vector<int>> alt(p, vector<int>(p));
            for (int i = 0; i < p; ++i) {
                for (int j = 0; j < p; ++j) {
                    alt[p-1-i][j] = pattern[i][j];
                }
            }
            patternHash.push_back(RollingHash2D(alt, base1, base2).get(0, 0, p, p));
        }
        {
            vector<vector<int>> alt(p, vector<int>(p));
            for (int i = 0; i < p; ++i) {
                for (int j = 0; j < p; ++j) {
                    alt[i][p-1-j] = pattern[i][j];
                }
            }
            patternHash.push_back(RollingHash2D(alt, base1, base2).get(0, 0, p, p));
        }
        {
            vector<vector<int>> alt(p, vector<int>(p));
            for (int i = 0; i < p; ++i) {
                for (int j = 0; j < p; ++j) {
                    alt[p-1-i][p-1-j] = pattern[i][j];
                }
            }
            patternHash.push_back(RollingHash2D(alt, base1, base2).get(0, 0, p, p));
        }
        {
            vector<vector<int>> alt(p, vector<int>(p));
            for (int i = 0; i < p; ++i) {
                for (int j = 0; j < p; ++j) {
                    alt[i][j] = pattern[j][i];
                }
            }
            patternHash.push_back(RollingHash2D(alt, base1, base2).get(0, 0, p, p));
        }
        {
            vector<vector<int>> alt(p, vector<int>(p));
            for (int i = 0; i < p; ++i) {
                for (int j = 0; j < p; ++j) {
                    alt[p-1-i][j] = pattern[j][i];
                }
            }
            patternHash.push_back(RollingHash2D(alt, base1, base2).get(0, 0, p, p));
        }
        {
            vector<vector<int>> alt(p, vector<int>(p));
            for (int i = 0; i < p; ++i) {
                for (int j = 0; j < p; ++j) {
                    alt[i][p-1-j] = pattern[j][i];
                }
            }
            patternHash.push_back(RollingHash2D(alt, base1, base2).get(0, 0, p, p));
        }
        {
            vector<vector<int>> alt(p, vector<int>(p));
            for (int i = 0; i < p; ++i) {
                for (int j = 0; j < p; ++j) {
                    alt[p-1-i][p-1-j] = pattern[j][i];
                }
            }
            patternHash.push_back(RollingHash2D(alt, base1, base2).get(0, 0, p, p));
        }

        int ans = 0;
        for (int i = 0; i + p <= h; ++i) {
            for (int j = 0; j + p <= w; ++j) {
                long long imageHash = Image.get(i, j, i + p, j + p);
                for (long long hash : patternHash) {
                    if (imageHash == hash) {
                        ++ans;
                        break;
                    }
                }
            }
        }

        cout << ans << endl;
    }
    return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

