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


# :warning: test/structure/segment_tree.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#2c7aa83aa7981015c539598d29afdf98">test/structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/structure/segment_tree.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-05 00:07:05+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A">https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A</a>


## Depends on

* :warning: <a href="../../structure/segment_tree.cpp.html">structure/segment_tree.cpp</a>
* :heavy_check_mark: <a href="../../template.cpp.html">template.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A"

#include "../../structure/segment_tree.cpp"

int main() {
    int N, Q;
    cin >> N >> Q;
    SegmentTree<int> seg(N);
    while (Q--) {
        int T, X, Y;
        cin >> T >> X >> Y;
        if (T == 0) seg.update(X, Y);
        else printf("%d\n", seg.query(X, Y + 1));
    }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/structure/segment_tree.cpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A"

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


#line 2 "test/structure/../../structure/segment_tree.cpp"

template<typename M>
struct SegmentTree {
    int sz;
    vector<M> data;

    // RMQ
    const M e = numeric_limits<M>::max();
    const function<M(M,M)> f = [](M a,M b){ return min(a,b); };

    SegmentTree(int n) {
        sz = 1;
        while (sz < n) sz <<= 1;
        data.assign(2*sz, e);
    }

    void update(int k, const M &x) {
        k += sz;
        data[k] = x;
        while (k >>= 1) {
            data[k] = f(data[2*k], data[2*k+1]);
        }
    }

    M query(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l) {
            return e;
        } else if (a <= l && r <= b) {
            return data[k];
        } else {
            return f(query(a,b,2*k,  l,(l+r)/2),
                     query(a,b,2*k+1,(l+r)/2,r));
        }
    }

    M query(int a, int b) {
        // return f[a,b)
        return query(a, b, 1, 0, sz);
    }

    M operator[](int k) {
        return data[k + sz];
    }
};
#line 4 "test/structure/segment_tree.cpp"

int main() {
    int N, Q;
    cin >> N >> Q;
    SegmentTree<int> seg(N);
    while (Q--) {
        int T, X, Y;
        cin >> T >> X >> Y;
        if (T == 0) seg.update(X, Y);
        else printf("%d\n", seg.query(X, Y + 1));
    }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

