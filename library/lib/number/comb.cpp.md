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


# :warning: lib/number/comb.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#12cd94d703d26487f7477e7dcce25e7f">lib/number</a>
* <a href="{{ site.github.repository_url }}/blob/master/lib/number/comb.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-24 17:28:09+09:00




## Depends on

* :heavy_check_mark: <a href="../template.cpp.html">lib/template.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include "../template.cpp"

#define SNIPPET_ONLY

template<typename Field>
struct Combination {
    vector<Field> _fact, _rfact, _inv;

    Combination(int n) : _fact(n), _rfact(n), _inv(n) {
        _fact[0] = _rfact[n-1] = 1;
        for (int i = 1; i < n; ++i) _fact[i] = _fact[i-1] * i;
        _rfact[n-1] /= _fact[n-1];
        for (int i = n-1; i > 0; --i) _rfact[i-1] = _rfact[i] * i;
        for (int i = 1; i < n; ++i) _inv[i] = _rfact[i] * _fact[i-1];
    }

    inline Field fact(int k) const { return _fact.at(k); }

    inline Field rfact(int k) const { return _rfact.at(k); }

    inline Field inv(int k) const { assert(k != 0); return _inv.at(k); }

    Field P(int n, int r) const {
        if (r < 0 or n < r) return 0;
        return fact(n) * rfact(n-r);
    }

    Field C(int n, int r) const {
        if (r < 0 or n < r) return 0;
        return fact(n) * rfact(r) * rfact(n-r);
    }

    Field H (int n, int r) const {
        return (n == 0 and r == 0) ? 1 : C(n+r-1, r);
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


#line 2 "lib/number/comb.cpp"

#define SNIPPET_ONLY

template<typename Field>
struct Combination {
    vector<Field> _fact, _rfact, _inv;

    Combination(int n) : _fact(n), _rfact(n), _inv(n) {
        _fact[0] = _rfact[n-1] = 1;
        for (int i = 1; i < n; ++i) _fact[i] = _fact[i-1] * i;
        _rfact[n-1] /= _fact[n-1];
        for (int i = n-1; i > 0; --i) _rfact[i-1] = _rfact[i] * i;
        for (int i = 1; i < n; ++i) _inv[i] = _rfact[i] * _fact[i-1];
    }

    inline Field fact(int k) const { return _fact.at(k); }

    inline Field rfact(int k) const { return _rfact.at(k); }

    inline Field inv(int k) const { assert(k != 0); return _inv.at(k); }

    Field P(int n, int r) const {
        if (r < 0 or n < r) return 0;
        return fact(n) * rfact(n-r);
    }

    Field C(int n, int r) const {
        if (r < 0 or n < r) return 0;
        return fact(n) * rfact(r) * rfact(n-r);
    }

    Field H (int n, int r) const {
        return (n == 0 and r == 0) ? 1 : C(n+r-1, r);
    }
};


```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

