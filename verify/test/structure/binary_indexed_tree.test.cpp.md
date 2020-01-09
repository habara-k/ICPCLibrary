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


# :heavy_check_mark: test/structure/binary_indexed_tree.test.cpp

<a href="../../../index.html">Back to top page</a>

* <a href="{{ site.github.repository_url }}/blob/master/test/structure/binary_indexed_tree.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-01-09 20:32:27+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B">https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/structure/binary_indexed_tree.cpp.html">structure/binary_indexed_tree.cpp</a>
* :heavy_check_mark: <a href="../../../library/template.cpp.html">template.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B"

#include "../../structure/binary_indexed_tree.cpp"

int main() {
    int N, Q;
    cin >> N >> Q;
    BIT<int> bit(N);
    while (Q--) {
        int T, X, Y;
        cin >> T >> X >> Y;
        if (T == 0) bit.add(X - 1, Y);
        else printf("%d\n", bit.sum(Y - 1) - bit.sum(X - 2));
    }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/structure/binary_indexed_tree.test.cpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B"

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


#line 2 "test/structure/../../structure/binary_indexed_tree.cpp"

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
#line 4 "test/structure/binary_indexed_tree.test.cpp"

int main() {
    int N, Q;
    cin >> N >> Q;
    BIT<int> bit(N);
    while (Q--) {
        int T, X, Y;
        cin >> T >> X >> Y;
        if (T == 0) bit.add(X - 1, Y);
        else printf("%d\n", bit.sum(Y - 1) - bit.sum(X - 2));
    }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

