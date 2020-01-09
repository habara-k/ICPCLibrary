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


# :heavy_check_mark: test/structure/union_find.test.cpp

<a href="../../../index.html">Back to top page</a>

* <a href="{{ site.github.repository_url }}/blob/master/test/structure/union_find.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-01-09 20:32:27+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_1_A">https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_1_A</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/structure/union_find.cpp.html">structure/union_find.cpp</a>
* :heavy_check_mark: <a href="../../../library/template.cpp.html">template.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_1_A"

#include "../../structure/union_find.cpp"

int main() {
    int N, Q;
    cin >> N >> Q;
    UnionFind uf(N);
    while (Q--) {
        int t, x, y;
        cin >> t >> x >> y;
        if (t == 0) uf.merge(x, y);
        else printf("%d\n", uf.root(x) == uf.root(y));
    }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/structure/union_find.test.cpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_1_A"

#line 1 "test/structure/../../structure/../template.cpp"



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


#line 2 "test/structure/../../structure/union_find.cpp"

struct UnionFind
{
    vector<int> par, sz;
    UnionFind(int n) : par(n), sz(n, 1) {
        for (int i = 0; i < n; ++i) par[i] = i;
    }
    int root(int x) {
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }
    void merge(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return;
        if (sz[x] < sz[y]) swap(x, y);
        par[y] = x;
        sz[x] += sz[y];
        sz[y] = 0;
    }
    bool issame(int x, int y) {
        return root(x) == root(y);
    }
    int size(int x) {
        return sz[root(x)];
    }
};
#line 4 "test/structure/union_find.test.cpp"

int main() {
    int N, Q;
    cin >> N >> Q;
    UnionFind uf(N);
    while (Q--) {
        int t, x, y;
        cin >> t >> x >> y;
        if (t == 0) uf.merge(x, y);
        else printf("%d\n", uf.root(x) == uf.root(y));
    }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

