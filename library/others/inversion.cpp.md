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


# :warning: others/inversion.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#5e2bab0ecb94c4ea40777733195abe1b">others</a>
* <a href="{{ site.github.repository_url }}/blob/master/others/inversion.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-07 03:51:42+09:00




## Depends on

* :heavy_check_mark: <a href="../structure/binary_indexed_tree.cpp.html">structure/binary_indexed_tree.cpp</a>
* :heavy_check_mark: <a href="../template.cpp.html">template.cpp</a>


## Required by

* :warning: <a href="../test/others/inversion.cpp.html">test/others/inversion.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include "../template.cpp"

#include "../structure/binary_indexed_tree.cpp"

template<typename T>
ll inversion(const vector<T>& a)
{
    map<T,int> mp;
    for (auto e : a) mp[e] = -1;
    int sz = 0;
    for (auto &q : mp) {
        q.second = sz++;
    }

    BIT<int> bit(sz+1);
    ll res = 0;
    for (int i = 0; i < a.size(); ++i) {
        res += i - bit.sum(mp[a[i]]);
        bit.add(mp[a[i]], 1);
    }
    return res;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "template.cpp"



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
const ld eps = 1e-9;
const ll MOD = 1000000007;

//int main() {
//    cin.tie(0);
//    ios::sync_with_stdio(false);
//    cout << fixed << setprecision(10);
//
//}


#line 2 "others/inversion.cpp"

#line 2 "structure/binary_indexed_tree.cpp"

template<typename T>
struct BIT {
    vector<T> bit;
    int sz;
    BIT(int n) : sz(n+1), bit(n+1) {}
    void add(int i, T x) {
        i += 1;
        while (i < sz) { bit[i] += x; i += i & -i; }
    }
    T sum(int i) {
        i += 1; T s = 0;
        while (i > 0) { s += bit[i]; i -= i & -i; }
        return s;
    }
};
#line 4 "others/inversion.cpp"

template<typename T>
ll inversion(const vector<T>& a)
{
    map<T,int> mp;
    for (auto e : a) mp[e] = -1;
    int sz = 0;
    for (auto &q : mp) {
        q.second = sz++;
    }

    BIT<int> bit(sz+1);
    ll res = 0;
    for (int i = 0; i < a.size(); ++i) {
        res += i - bit.sum(mp[a[i]]);
        bit.add(mp[a[i]], 1);
    }
    return res;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

