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

* category: <a href="../../../index.html#e46c0047b1d14ef43eeaaf13f64d385f">test/string</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/string/rolling_hash.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-23 18:17:04+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/14/ALDS1_14_B">https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/14/ALDS1_14_B</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/string/rolling_hash.cpp.html">string/rolling_hash.cpp</a>
* :question: <a href="../../../library/template.cpp.html">template.cpp</a>


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

#line 1 "template.cpp"



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

