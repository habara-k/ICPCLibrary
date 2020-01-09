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
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :heavy_check_mark: string/rolling_hash.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#b45cffe084dd3d20d928bee85e7b0f21">string</a>
* <a href="{{ site.github.repository_url }}/blob/master/string/rolling_hash.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-05 00:07:05+09:00




## Depends on

* :heavy_check_mark: <a href="../template.cpp.html">template.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/string/rolling_hash.test.cpp.html">test/string/rolling_hash.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include "../template.cpp"

struct RollingHash {
    const int base = 9973;
    const int mod[2] = {999999937, 1000000007};
    vector<int> s;
    vector<ll> hash[2], pow[2];

    RollingHash(const vector<int> &cs) : s(cs) {
        int n = s.size();
        for (int id = 0; id < 2; ++id) {
            hash[id].assign(n+1, 0);
            pow[id].assign(n+1, 1);
            for (int i = 0; i < n; ++i) {
                hash[id][i+1] = (hash[id][i] * base + s[i]) % mod[id];
                pow[id][i+1] = pow[id][i] * base % mod[id];
            }
        }
    }

    // get hash of s[l:r)
    ll get(int l, int r, int id = 0) {
        ll res = hash[id][r] - hash[id][l] * pow[id][r-l] % mod[id];
        if (res < 0) res += mod[id];
        return res;
    }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "string/../template.cpp"



#include <bits/stdc++.h>
using namespace std;

#define SZ(x) (int)(x.size())
#define REP(i, n) for(int i = 0; i < n; i++)
#define FOR(i, a, b) for(int i = a; i < b; i++)

using ll = long long;
using ld = long double;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
const double eps = 1e-8;
const int MOD = 1000000007;

//int main() {
//    cin.tie(0);
//    ios::sync_with_stdio(false);
//    cout << fixed << setprecision(10);
//
//}


#line 2 "string/rolling_hash.cpp"

struct RollingHash {
    const int base = 9973;
    const int mod[2] = {999999937, 1000000007};
    vector<int> s;
    vector<ll> hash[2], pow[2];

    RollingHash(const vector<int> &cs) : s(cs) {
        int n = s.size();
        for (int id = 0; id < 2; ++id) {
            hash[id].assign(n+1, 0);
            pow[id].assign(n+1, 1);
            for (int i = 0; i < n; ++i) {
                hash[id][i+1] = (hash[id][i] * base + s[i]) % mod[id];
                pow[id][i+1] = pow[id][i] * base % mod[id];
            }
        }
    }

    // get hash of s[l:r)
    ll get(int l, int r, int id = 0) {
        ll res = hash[id][r] - hash[id][l] * pow[id][r-l] % mod[id];
        if (res < 0) res += mod[id];
        return res;
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

