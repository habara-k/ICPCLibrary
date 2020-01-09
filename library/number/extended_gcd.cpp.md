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


# :warning: number/extended_gcd.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#b1bc248a7ff2b2e95569f56de68615df">number</a>
* <a href="{{ site.github.repository_url }}/blob/master/number/extended_gcd.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-05 00:07:05+09:00




## Depends on

* :warning: <a href="../template.cpp.html">template.cpp</a>


## Required by

* :warning: <a href="../test/number/extended_gcd.cpp.html">test/number/extended_gcd.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include "../template.cpp"

ll extended_gcd(ll a, ll b, ll& x, ll& y) {
    // solve ax + by = gcd(a, b)
    if (b == 0) { x = 1; y = 0; return a; }
    ll X, Y;
    ll g = extended_gcd(b, a % b, X, Y);
    x = Y; y = X - a/b * Y;
    return g;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "number/../template.cpp"



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


#line 2 "number/extended_gcd.cpp"

ll extended_gcd(ll a, ll b, ll& x, ll& y) {
    // solve ax + by = gcd(a, b)
    if (b == 0) { x = 1; y = 0; return a; }
    ll X, Y;
    ll g = extended_gcd(b, a % b, X, Y);
    x = Y; y = X - a/b * Y;
    return g;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

