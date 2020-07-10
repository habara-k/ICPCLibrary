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


# :warning: test/structure/bit_range_add.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#2c7aa83aa7981015c539598d29afdf98">test/structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/structure/bit_range_add.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-18 04:03:37+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E&lang=jp">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E&lang=jp</a>


## Depends on

* :heavy_check_mark: <a href="../../lib/structure/binary_indexed_tree.cpp.html">lib/structure/binary_indexed_tree.cpp</a>
* :warning: <a href="../../lib/structure/bit_range_add.cpp.html">lib/structure/bit_range_add.cpp</a>
* :question: <a href="../../lib/template.cpp.html">lib/template.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E&lang=jp"

#include "../../lib/structure/bit_range_add.cpp"

int main() {
  int n, q; cin >> n >> q;
  RangeAdd<ll> bit(n);
  REP(_, q) {
    int t; cin >> t;
    if(t == 0) {
      int l, r, x; cin >> l >> r >> x;
      l--;
      bit.add(l, r, x);
    } else {
      int i; cin >> i;
      i--;
      cout << bit.sum(i) - bit.sum(i-1) << endl;
    }
  }
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/structure/bit_range_add.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E&lang=jp"

#line 1 "lib/template.cpp"



#include <bits/stdc++.h>

using namespace std;

#define REP(i, n) for (int i=0; i<(n); ++i)
#define RREP(i, n) for (int i=(int)(n)-1; i>=0; --i)
#define FOR(i, a, n) for (int i=(a); i<(n); ++i)
#define RFOR(i, a, n) for (int i=(int)(n)-1; i>=(a); --i)

#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()

#define DUMP(x) cerr<<#x<<" = "<<(x)<<endl
#define DEBUG(x) cerr<<#x<<" = "<<(x)<<" (L"<<__LINE__<<")"<<endl;

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


#line 2 "lib/structure/binary_indexed_tree.cpp"

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
#line 2 "lib/structure/bit_range_add.cpp"

/**
 * 区間add区間sum
 */

template<typename T>
struct RangeAdd {
  BIT<T> bit1, bit2;

  RangeAdd(int n): bit1(BIT<T>(n+1)), bit2(BIT<T>(n+1)) {
  }

  // [l, r)にvalを加算
  void add(int l, int r, T val) {
    bit1.add(l, -l*val);
    bit1.add(r, r*val);
    bit2.add(l, val);
    bit2.add(r, -val);
  }

  // [0, idx)の和を取得
  T sum(int idx) {
    idx++;
    return bit1.sum(idx) + idx * bit2.sum(idx);
  }
};
#line 4 "test/structure/bit_range_add.cpp"

int main() {
  int n, q; cin >> n >> q;
  RangeAdd<ll> bit(n);
  REP(_, q) {
    int t; cin >> t;
    if(t == 0) {
      int l, r, x; cin >> l >> r >> x;
      l--;
      bit.add(l, r, x);
    } else {
      int i; cin >> i;
      i--;
      cout << bit.sum(i) - bit.sum(i-1) << endl;
    }
  }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

