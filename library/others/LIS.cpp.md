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


# :warning: others/LIS.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#5e2bab0ecb94c4ea40777733195abe1b">others</a>
* <a href="{{ site.github.repository_url }}/blob/master/others/LIS.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-05 01:51:04+09:00




## Depends on

* :warning: <a href="../template.cpp.html">template.cpp</a>


## Required by

* :warning: <a href="../test/others/LIS.cpp.html">test/others/LIS.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include "../template.cpp"

template<typename T>
int LIS(const vector<T>& a) {
    int n = a.size();
    T INF = numeric_limits<T>::max();
    vector<T> dp(n, INF);
    for(int i = 0; i < n; ++i) {
        *lower_bound(dp.begin(), dp.end(), a[i]) = a[i];
    }
    return distance(dp.begin(), lower_bound(dp.begin(), dp.end(), INF));
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "others/../template.cpp"



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


#line 2 "others/LIS.cpp"

template<typename T>
int LIS(const vector<T>& a) {
    int n = a.size();
    T INF = numeric_limits<T>::max();
    vector<T> dp(n, INF);
    for(int i = 0; i < n; ++i) {
        *lower_bound(dp.begin(), dp.end(), a[i]) = a[i];
    }
    return distance(dp.begin(), lower_bound(dp.begin(), dp.end(), INF));
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

