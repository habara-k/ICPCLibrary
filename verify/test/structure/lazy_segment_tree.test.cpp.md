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


# :heavy_check_mark: test/structure/lazy_segment_tree.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#2c7aa83aa7981015c539598d29afdf98">test/structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/structure/lazy_segment_tree.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-07 03:51:42+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G">https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/structure/lazy_segment_tree.cpp.html">structure/lazy_segment_tree.cpp</a>
* :question: <a href="../../../library/template.cpp.html">template.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G"

#include "../../structure/lazy_segment_tree.cpp"

int main() {
    int N, Q;
    cin >> N >> Q;
    LazySegmentTree<ll> seg(N);
    while (Q--) {
        int C; cin >> C;
        if (C == 0) {
            int S, T; ll X;
            cin >> S >> T >> X;
            --S, --T;
            seg.update(S, T+1, X);
        } else {
            int S, T;
            cin >> S >> T;
            --S, --T;
            cout << seg.query(S, T+1) << endl;
        }
    }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/structure/lazy_segment_tree.test.cpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G"

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


#line 2 "structure/lazy_segment_tree.cpp"

template<typename M, typename OM = M>
struct LazySegmentTree {
    int sz;
    vector<M> data;
    vector<OM> lazy;

    // RangeSumRangeAdd
    const function<M(M,M)> f = [](M a,M b){ return a+b; };
    const function<M(M,OM,int)> g = [](M a,OM b,int l){ return a+b*l; };
    const function<OM(OM,OM)> h = [](OM a,OM b){ return a+b; };
    const M e = 0;
    const OM oe = 0;

    LazySegmentTree(int n) {
        sz = 1;
        while (sz < n) sz <<= 1;
        data.assign(2*sz, e);
        lazy.assign(2*sz, oe);
    }

    void propagate(int k, int len) {
        if (lazy[k] == oe) return;
        if (k < sz) {
            lazy[2*k  ] = h(lazy[2*k  ], lazy[k]);
            lazy[2*k+1] = h(lazy[2*k+1], lazy[k]);
        }
        data[k] = g(data[k], lazy[k], len);
        lazy[k] = oe;
    }

    M update(int a, int b, const OM &x, int k, int l, int r) {
        propagate(k, r - l);
        if (r <= a || b <= l) {
            return data[k];
        } else if (a <= l && r <= b) {
            lazy[k] = h(lazy[k], x);
            propagate(k, r - l);
            return data[k];
        } else {
            return data[k] = f(
                update(a, b, x, 2*k,   l, (l+r)/2),
                update(a, b, x, 2*k+1, (l+r)/2, r));
        }
    }

    void update(int a, int b, const OM &x) {
        // update [a, b) with x.
        update(a, b, x, 1, 0, sz);
    }

    M query(int a, int b, int k, int l, int r) {
        propagate(k, r - l);
        if (r <= a || b <= l) {
            return e;
        } else if (a <= l && r <= b) {
            return data[k];
        } else {
            return f(
                query(a, b, 2*k,   l, (l+r)/2),
                query(a, b, 2*k+1, (l+r)/2, r));
        }
    }

    M query(int a, int b) {
        // return f[a, b).
        return query(a, b, 1, 0, sz);
    }
};
#line 4 "test/structure/lazy_segment_tree.test.cpp"

int main() {
    int N, Q;
    cin >> N >> Q;
    LazySegmentTree<ll> seg(N);
    while (Q--) {
        int C; cin >> C;
        if (C == 0) {
            int S, T; ll X;
            cin >> S >> T >> X;
            --S, --T;
            seg.update(S, T+1, X);
        } else {
            int S, T;
            cin >> S >> T;
            --S, --T;
            cout << seg.query(S, T+1) << endl;
        }
    }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

