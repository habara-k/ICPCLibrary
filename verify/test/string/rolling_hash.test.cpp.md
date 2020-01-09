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


# :heavy_check_mark: test/string/rolling_hash.test.cpp

<a href="../../../index.html">Back to top page</a>

* <a href="{{ site.github.repository_url }}/blob/master/test/string/rolling_hash.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-01-09 20:32:27+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/14/ALDS1_14_B">https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/14/ALDS1_14_B</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/string/rolling_hash.cpp.html">string/rolling_hash.cpp</a>
* :heavy_check_mark: <a href="../../../library/template.cpp.html">template.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/14/ALDS1_14_B"

#include "../../string/rolling_hash.cpp"

int main() {
    string T, P;
    cin >> T >> P;
    int n = T.size(), m = P.size();
    vector<int> t(T.begin(), T.end()),
                p(P.begin(), P.end());

    RollingHash rh(t), rh2(p);
    for (int i = 0; i+m <= n; i++) {
        if (rh.get(i, i+m) == rh2.get(0, m) &&
            rh.get(i, i+m, 1) == rh2.get(0, m, 1)) {
            cout << i << endl;
        }
    }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/string/rolling_hash.test.cpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/14/ALDS1_14_B"

#line 1 "test/string/../../string/../template.cpp"



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


#line 2 "test/string/../../string/rolling_hash.cpp"

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
#line 4 "test/string/rolling_hash.test.cpp"

int main() {
    string T, P;
    cin >> T >> P;
    int n = T.size(), m = P.size();
    vector<int> t(T.begin(), T.end()),
                p(P.begin(), P.end());

    RollingHash rh(t), rh2(p);
    for (int i = 0; i+m <= n; i++) {
        if (rh.get(i, i+m) == rh2.get(0, m) &&
            rh.get(i, i+m, 1) == rh2.get(0, m, 1)) {
            cout << i << endl;
        }
    }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

