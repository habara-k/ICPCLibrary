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


# :heavy_check_mark: test/structure/weighted_union_find.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#2c7aa83aa7981015c539598d29afdf98">test/structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/structure/weighted_union_find.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-24 14:14:43+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_1_B">https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_1_B</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/lib/structure/weighted_union_find.cpp.html">lib/structure/weighted_union_find.cpp</a>
* :heavy_check_mark: <a href="../../../library/lib/template.cpp.html">lib/template.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_1_B"

#include "../../lib/structure/weighted_union_find.cpp"

int main() {
    int N, M;
    cin >> N >> M;
    WeightedUnionFind<int> uf(N);
    while (M--) {
        int A, B, C, D;
        cin >> A >> B >> C;
        if (A == 0) {
            cin >> D;
            uf.merge(B, C, D);
        } else {
            if (uf.root(B) == uf.root(C)) {
                cout << uf.diff(B, C) << endl;
            } else {
                cout << "?" << endl;
            }
        }
    }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/structure/weighted_union_find.test.cpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_1_B"

#line 1 "lib/template.cpp"



#include <bits/stdc++.h>

using namespace std;

#define REP(i, n) for (int i=0; i<(n); ++i)
#define RREP(i, n) for (int i=(int)(n)-1; i>=0; --i)
#define FOR(i, a, n) for (int i=(a); i<(n); ++i)
#define RFOR(i, a, n) for (int i=(int)(n)-1; i>=(a); --i)

#define SZ(x) ((int)(x).size())
#define all(x) begin(x),end(x)

#define dump(x) cerr<<#x<<" = "<<(x)<<endl
#define debug(x) cerr<<#x<<" = "<<(x)<<" (L"<<__LINE__<<")"<<endl;

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


#line 2 "lib/structure/weighted_union_find.cpp"

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
#line 4 "test/structure/weighted_union_find.test.cpp"

int main() {
    int N, M;
    cin >> N >> M;
    WeightedUnionFind<int> uf(N);
    while (M--) {
        int A, B, C, D;
        cin >> A >> B >> C;
        if (A == 0) {
            cin >> D;
            uf.merge(B, C, D);
        } else {
            if (uf.root(B) == uf.root(C)) {
                cout << uf.diff(B, C) << endl;
            } else {
                cout << "?" << endl;
            }
        }
    }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>
