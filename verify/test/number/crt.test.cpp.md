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


# :heavy_check_mark: test/number/crt.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#27c49c4e5cc6f85fad5dbff6f8f0ef1b">test/number</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/number/crt.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-25 22:26:20+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2659">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2659</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/lib/number/crt.cpp.html"> <small>(lib/number/crt.cpp)</small></a>
* :heavy_check_mark: <a href="../../../library/lib/number/extended_gcd.cpp.html">lib/number/extended_gcd.cpp</a>
* :heavy_check_mark: <a href="../../../library/lib/template.cpp.html">lib/template.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2659"

#include "../../lib/number/crt.cpp"

int main() {
  ll n, m, d; cin >> n >> m >> d;
  vll mod(m);
  REP(i, m) {
    cin >> mod[i];
  }
  vvll a(d, vll(m));
  REP(i, d) {
    REP(j, m) {
      cin >> a[i][j];
    }
  }

  bool ok = true;
  REP(i, d) {
    vll b, nowmod;
    REP(j, m) {
      if(a[i][j] != -1) b.push_back(a[i][j]), nowmod.push_back(mod[j]);
    }
    if(b.empty()) continue;

    pair<ll, ll> p = crt(b, nowmod);

    if(p.second == -1 || n < p.first) ok = false;

    n = n - (n - p.first) % p.second;
  }

  if(ok) cout << n << endl;
  else cout << -1 << endl;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/number/crt.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2659"

#line 1 "lib/template.cpp"



#include <bits/stdc++.h>

using namespace std;

#define REP(i, n) for (int i=0; i<(n); ++i)
#define RREP(i, n) for (int i=(int)(n)-1; i>=0; --i)
#define FOR(i, a, n) for (int i=(a); i<(n); ++i)
#define RFOR(i, a, n) for (int i=(int)(n)-1; i>=(a); --i)

#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

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


#line 2 "lib/number/extended_gcd.cpp"

ll extended_gcd(ll a, ll b, ll& x, ll& y) {
    // solve ax + by = gcd(a, b)
    if (b == 0) { x = 1; y = 0; return a; }
    ll X, Y;
    ll g = extended_gcd(b, a % b, X, Y);
    x = Y; y = X - a/b * Y;
    return g;
}
#line 2 "lib/number/crt.cpp"

/**
 * @brief
 * 中国式場予定理(CRT)
 * m1で割ったあまりがa1, m2で割ったあまりがa2のとき、m1*m2でわったあまりを構築
 * @author Md
 * @date 2020/04/25
 */

/**
 * @return first: 答え, second: modの値
 */
pair<ll, ll> crt(ll a1, ll m1, ll a2, ll m2) {
  ll p, q;
  ll g = extended_gcd(m1, m2, p, q);
  if ((a1 - a2) % g) return make_pair(0, -1);
  return make_pair(a1 + m1 * (a2 - a1) / g * p % (m2 / g), m1 * (m2 / g));
}

/**
 * @brief
 * 式が複数個ある場合
 * @return first: 答え, second: modの値
 */
pair<ll, ll> crt(const vector<ll> &a, const vector<ll> &m) {
  ll r = 0, mod = 1;
  REP(i, SZ(a)) {
    ll p, q;
    ll g = extended_gcd(mod, m[i], p, q);
    if ((a[i] - r) % g) return make_pair(0, -1);
    ll tmp = (a[i] - r) / g * p % (m[i] / g);
    r += mod * tmp;
    mod *= m[i] / g;
  }
  return make_pair(r % mod, mod);
}
#line 4 "test/number/crt.test.cpp"

int main() {
  ll n, m, d; cin >> n >> m >> d;
  vll mod(m);
  REP(i, m) {
    cin >> mod[i];
  }
  vvll a(d, vll(m));
  REP(i, d) {
    REP(j, m) {
      cin >> a[i][j];
    }
  }

  bool ok = true;
  REP(i, d) {
    vll b, nowmod;
    REP(j, m) {
      if(a[i][j] != -1) b.push_back(a[i][j]), nowmod.push_back(mod[j]);
    }
    if(b.empty()) continue;

    pair<ll, ll> p = crt(b, nowmod);

    if(p.second == -1 || n < p.first) ok = false;

    n = n - (n - p.first) % p.second;
  }

  if(ok) cout << n << endl;
  else cout << -1 << endl;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

