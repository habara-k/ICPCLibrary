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


# :heavy_check_mark: lib/number/mod.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#12cd94d703d26487f7477e7dcce25e7f">lib/number</a>
* <a href="{{ site.github.repository_url }}/blob/master/lib/number/mod.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-06 01:41:24+09:00




## Depends on

* :question: <a href="../template.cpp.html">lib/template.cpp</a>


## Required by

* :heavy_check_mark: <a href="combination.cpp.html">lib/number/combination.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/number/Bell.test.cpp.html">test/number/Bell.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/number/C.test.cpp.html">test/number/C.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/number/Partition1.test.cpp.html">test/number/Partition1.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/number/Partition2.test.cpp.html">test/number/Partition2.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/number/Stirling.test.cpp.html">test/number/Stirling.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include "../template.cpp"

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

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

