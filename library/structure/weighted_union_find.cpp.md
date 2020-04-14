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


# :heavy_check_mark: structure/weighted_union_find.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#07414f4e15ca943e6cde032dec85d92f">structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/structure/weighted_union_find.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-07 03:51:42+09:00




## Depends on

* :question: <a href="../template.cpp.html">template.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/structure/weighted_union_find.test.cpp.html">test/structure/weighted_union_find.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include "../template.cpp"

template<typename A>
struct WeightedUnionFind
{
    vector<int> par, sz;
    vector<A> data;     // data[x]: diff from root to x
    WeightedUnionFind(int n, A e=0) :
        par(n), sz(n, 1), data(n, e) {
        for (int i = 0; i < n; ++i) par[i] = i;
    }

    int root(int x) {
        if (par[x] == x) return x;
        int r = root(par[x]);
        data[x] += data[par[x]];
        return par[x] = r;
    }

    A weight(int x) {
        root(x);
        return data[x];
    }

    A diff(int x, int y) {
        // diff from x to y
        return data[y] - data[x];
    }

    void merge(int x, int y, A w) {
        // merge so that "diff from x to y" will be w.
        w += weight(x); w -= weight(y);
        x = root(x); y = root(y);
        if (x == y) return;
        if (sz[x] < sz[y]) swap(x, y), w = -w;
        par[y] = x;
        sz[x] += sz[y];
        sz[y] = 0;
        data[y] = w;
    }

    bool issame(int x, int y) {
        return root(x) == root(y);
    }
};

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


#line 2 "structure/weighted_union_find.cpp"

template<typename A>
struct WeightedUnionFind
{
    vector<int> par, sz;
    vector<A> data;     // data[x]: diff from root to x
    WeightedUnionFind(int n, A e=0) :
        par(n), sz(n, 1), data(n, e) {
        for (int i = 0; i < n; ++i) par[i] = i;
    }

    int root(int x) {
        if (par[x] == x) return x;
        int r = root(par[x]);
        data[x] += data[par[x]];
        return par[x] = r;
    }

    A weight(int x) {
        root(x);
        return data[x];
    }

    A diff(int x, int y) {
        // diff from x to y
        return data[y] - data[x];
    }

    void merge(int x, int y, A w) {
        // merge so that "diff from x to y" will be w.
        w += weight(x); w -= weight(y);
        x = root(x); y = root(y);
        if (x == y) return;
        if (sz[x] < sz[y]) swap(x, y), w = -w;
        par[y] = x;
        sz[x] += sz[y];
        sz[y] = 0;
        data[y] = w;
    }

    bool issame(int x, int y) {
        return root(x) == root(y);
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

