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


# :heavy_check_mark: test/number/C.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#27c49c4e5cc6f85fad5dbff6f8f0ef1b">test/number</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/number/C.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-18 18:10:40+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/all/DPL_5_C">https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/all/DPL_5_C</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/lib/number/combination.cpp.html">lib/number/combination.cpp</a>
* :heavy_check_mark: <a href="../../../library/lib/number/mod.cpp.html"> <small>(lib/number/mod.cpp)</small></a>
* :heavy_check_mark: <a href="../../../library/lib/template.cpp.html">lib/template.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/all/DPL_5_C"

#include "../../lib/number/combination.cpp"

int main() {
    ll n, k; cin >> n >> k;
    const ll mod = 1e9+7;

    init_fact(k, mod);

    ll ans = 0;
    for (ll l = 0; l <= k; ++l) {
        ll tmp = powm(k-l, n, mod);
        (tmp *= C(k, l, mod)) %= mod;
        if (l & 1) tmp = (-tmp + mod) % mod;
        (ans += tmp) %= mod;
    }
    cout << ans << endl;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/number/C.test.cpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/all/DPL_5_C"

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


#line 2 "lib/number/mod.cpp"

ll powm(ll a, ll n, ll m) {
    ll ret = 1;
    while (n > 0) {
        if (n & 1) (ret *= a) %= m;
        (a *= a) %= m;
        n >>= 1;
    }
    return ret;
}

ll invm(ll a, ll m) {
    return powm(a, m-2, m);
}


/**
 * @brief
 * 離散対数 O(sqrt(m))
 * @author habara-k
 * @date 2020/05/18
 * @verify https://atcoder.jp/contests/arc042/submissions/13372745
 *
 * @param[in] a: 0 < a < m
 * @param[in] b: 0 <= b < m
 * @param[in] m: prime
 * @return:
 *     minimum x >= 0 s.t. a^x == b mod m
 *     if no x satisfies the condition, return -1
 */

ll logm(ll a, ll b, ll m) {

    ll sm = sqrt(m);

    map<ll,int> mp;
    for (ll t = 1, r = 0; r < sm; (t *= a) %= m, ++r) {
        if (!mp.count(t)) mp[t] = r;
    }

    ll A = invm(powm(a, sm, m), m);
    for (ll t = b, p = 0; p <= sm; (t *= A) %= m, ++p) {
        if (mp.count(t)) {
            return sm * p + mp[t];
        }
    }
    return -1;
}
#line 2 "lib/number/combination.cpp"

vector<ll> fact;
void init_fact(int n, ll m) {
    fact.assign(n+1, 1);
    for (int i = 2; i <= n; ++i) {
        (fact[i] = fact[i-1] * i) %= m;
    }
}

// require init_fact(GREATER THAN OR EQUAL TO n, m)
ll C(ll n, ll r, ll m) {
    return (fact[n] * invm((fact[r] * fact[n-r]) % m, m)) % m;
}

// Stirling number
// Stirling(n, k) := the number of cases
//            to split n balls(distinguished)
//            into k boxes(not distinguished)
//            s.t. each box contains at least one ball.
//
// require init_fact(GREATER THAN OR EQUAL TO k, m)
ll Stirling(ll n, ll k, ll m) {
    ll ret = 0;
    for (ll l = 0; l <= k; ++l) {
        ll tmp = (C(k, l, m) * powm((k-l) % m, n, m)) % m;
        if (l & 1) tmp = (-tmp + m) % m;
        (ret += tmp) %= m;
    }
    return (ret *= invm(fact[k], m)) %= m;
}

// Bell number
// Bell(n, k) := the number of cases
//            to split n balls(distinguished)
//            into k boxes(not distinguished)
//
// require init_fact(GREATER THAN OR EQUAL TO k, m)
ll Bell(ll n, ll k, ll m) {
    ll ret = 0;
    for (ll l = 0; l <= k; ++l) {
        (ret += Stirling(n, l, m)) %= m;
    }
    return ret;
}

// Partition function
// Partition[k][n] := the number of cases
//            to split n balls(not distinguished)
//            into k boxes(not distinguished)
vector<vector<ll>> Part;
void init_partition(ll k, ll n, ll m) {
    Part.assign(k+1, vector<ll>(n+1, 0));
    Part[0][0] = 1;
    for (int i = 1; i <= k; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (j-i >= 0) {
                Part[i][j] = (Part[i-1][j] + Part[i][j-i]) % m;
            } else {
                Part[i][j] = Part[i-1][j];
            }
        }
    }
}
#line 4 "test/number/C.test.cpp"

int main() {
    ll n, k; cin >> n >> k;
    const ll mod = 1e9+7;

    init_fact(k, mod);

    ll ans = 0;
    for (ll l = 0; l <= k; ++l) {
        ll tmp = powm(k-l, n, mod);
        (tmp *= C(k, l, mod)) %= mod;
        if (l & 1) tmp = (-tmp + mod) % mod;
        (ans += tmp) %= mod;
    }
    cout << ans << endl;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>
