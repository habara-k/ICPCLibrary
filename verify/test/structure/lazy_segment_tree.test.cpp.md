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
    - Last commit date: 2020-05-04 15:56:10+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G">https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/lib/structure/lazy_segment_tree.cpp.html">遅延セグメント木 <small>(lib/structure/lazy_segment_tree.cpp)</small></a>
* :heavy_check_mark: <a href="../../../library/lib/template.cpp.html">lib/template.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G"

#include "../../lib/structure/lazy_segment_tree.cpp"

int main() {
    int N, Q;
    cin >> N >> Q;
    LazySegmentTree<ll> seg(
            N,
            [](ll a, ll b){ return a+b; },
            [](ll a, ll b, ll w){ return a + b*w; },
            [](ll a, ll b){ return a+b; },
            0, 0);

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

#line 1 "lib/template.cpp"



#include <bits/stdc++.h>

using namespace std;

#define REP(i, n) for (int i=0; i<(n); ++i)
#define RREP(i, n) for (int i=(int)(n)-1; i>=0; --i)
#define FOR(i, a, n) for (int i=(a); i<(n); ++i)
#define RFOR(i, a, n) for (int i=(int)(n)-1; i>=(a); --i)

#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

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


#line 2 "lib/structure/lazy_segment_tree.cpp"

/**
* @brief 遅延セグメント木
* @author habara-k
* @date 2020/04/26
*/

template<typename M, typename OM = M>
struct LazySegmentTree {

    /**
    * @brief コンストラクタ. O(n)
    * @param[in] n 遅延セグ木のサイズ.
    * @param[in] f 要素モノイドの演算.
    * @param[in] g 要素に作用素を作用させる演算.
    * @param[in] h 作用素モノイドの演算.
    * @param[in] e 要素モノイドの単位元.
    * @param[in] oe 作用素モノイドの単位元.
    * @details 使い方
    *   e.g. Range Add Range Sum
    *   LazySegmentTree<int> segt(
    *            n,
    *            [](int a,int b){ return a+b; },
    *            [](int a,int b,int w){ return a + b*w; },
    *            [](int a,int b){ return a+b; },
    *            0, 0);
    *               // 全て単位元で初期化される.
    */
    LazySegmentTree(
            int n,
            const function<M(M,M)>& f,
            const function<M(M,OM,int)>& g,
            const function<OM(OM,OM)>& h,
            const M& e, const OM& oe
            ) : n(n), f(f), g(g), h(h), e(e), oe(oe) {
        sz = 1;
        while (sz < n) sz <<= 1;
        data.assign(2 * sz, e);
        lazy.assign(2 * sz, oe);
    }

    /**
    * @brief 全体に初期値を入れる. O(n)
    * @param[in] v 要素モノイドのvector. 初期化する.
    * @details 使い方
    *   segt.build(vector<int>(n, INF));
    */
    void build(const vector<M>& v) {
        assert(v.size() <= n);
        for (int i = 0; i < v.size(); ++i) {
            data[i + sz] = v[i];
        }
        for (int i = sz-1; i > 0; --i) {
            data[i] = f(data[2 * i], data[2 * i + 1]);
        }
    }

    /**
    * @brief 指定した区間に作用素x を作用させる. O(log n)
    * @param[in] l, r 区間[l, r) に作用させる.
    * @param[in] x 作用素モノイドの元.
    * @details 使い方
    *   e.g. Range Update
    *   int l, r, x; // 区間[l, r) をx に更新したい.
    *   segt.update(l, r, x);
    */
    void update(int a, int b, const OM& x) {
        update(a, b, x, 1, 0, sz);
    }

    /**
    * @brief 指定した区間に取得クエリを実行する. O(log n)
    * @param[in] l, r 区間[l, r) を取得する.
    * @return 取得した値.
    * @details 使い方
    *   e.g. Range Minimum
    *   int l, r; // 区間[l, r) のminを取得したい.
    *   cout << segt.query(l, r) << endl;
    */
    M query(int a, int b) {
        return query(a, b, 1, 0, sz);
    }

    /**
    * @brief 指定したindexの要素を取得. O(1)
    * @param[in] i 取得したい要素のindex
    * @return 取得した値.
    */
    M operator[](int i) {
        return query(i, i + 1);
    }

    /**
    * @brief vector みたいに出力.
    */
    friend ostream& operator<<(ostream& os, LazySegmentTree& s) {
        os << "[";
        for (int i = 0; i < s.n; ++i) {
            if (i) os << " ";
            os << s[i];
        }
        return os << "]";
    }

private:

    int n, sz;
    vector<M> data;
    vector<OM> lazy;
    const function<M(M,M)> f;
    const function<M(M,OM,int)> g;
    const function<OM(OM,OM)> h;
    const M e;
    const OM oe;

    void propagate(int k, int len) {
        if (lazy[k] == oe) return;
        if (k < sz) {
            lazy[2 * k    ] = h(lazy[2 * k    ], lazy[k]);
            lazy[2 * k + 1] = h(lazy[2 * k + 1], lazy[k]);
        }
        data[k] = g(data[k], lazy[k], len);
        lazy[k] = oe;
    }

    void update(int a, int b, const OM& x, int k, int l, int r) {
        propagate(k, r - l);
        if (r <= a or b <= l) return;
        else if (a <= l and r <= b) {
            lazy[k] = h(lazy[k], x);
            propagate(k, r - l);
        } else {
            update(a, b, x, 2 * k,     l, (l + r) >> 1);
            update(a, b, x, 2 * k + 1, (l + r) >> 1, r);
            data[k] = f(data[2 * k], data[2 * k + 1]);
        }
    }

    M query(int a, int b, int k, int l, int r) {
        propagate(k, r - l);
        if (r <= a or b <= l) return e;
        else if (a <= l and r <= b) return data[k];
        else return f(
                query(a, b, 2 * k,     l, (l + r) >> 1),
                query(a, b, 2 * k + 1, (l + r) >> 1, r));
    }
};
#line 4 "test/structure/lazy_segment_tree.test.cpp"

int main() {
    int N, Q;
    cin >> N >> Q;
    LazySegmentTree<ll> seg(
            N,
            [](ll a, ll b){ return a+b; },
            [](ll a, ll b, ll w){ return a + b*w; },
            [](ll a, ll b){ return a+b; },
            0, 0);

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

