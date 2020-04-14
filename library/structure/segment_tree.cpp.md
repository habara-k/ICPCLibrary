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


# :heavy_check_mark: structure/segment_tree.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#07414f4e15ca943e6cde032dec85d92f">structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/structure/segment_tree.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-07 03:51:42+09:00




## Depends on

* :question: <a href="../template.cpp.html">template.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/structure/segment_tree.test.cpp.html">test/structure/segment_tree.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include "../template.cpp"

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


#line 2 "structure/segment_tree.cpp"

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

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

