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


# :heavy_check_mark: セグメント木 <small>(lib/structure/segment_tree.cpp)</small>

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#c4d905b3311a5371af1ce28a5d3ead13">lib/structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/lib/structure/segment_tree.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-04 15:55:27+09:00




## Depends on

* :heavy_check_mark: <a href="../template.cpp.html">lib/template.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/structure/segment_tree.test.cpp.html">test/structure/segment_tree.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include "../template.cpp"

/**
* @brief セグメント木
* @author habara-k
* @date ?
*/

template<typename M>
struct SegmentTree {

    /**
    * @brief コンストラクタ. O(n)
    * @param[in] n セグ木のサイズ.
    * @param[in] f モノイドの演算.
    * @param[in] e モノイドの単位元.
    * @details 使い方
    *   e.g. Range Minimum
    *   SegmentTree<int> segt(
    *            n,
    *            [](int a,int b){ return min(a+b); },
    *            INF);
    *               // 全て単位元で初期化される.
    */
    SegmentTree(
            int n,
            const function<M(M,M)>& f,
            const M& e) : n(n), f(f), e(e) {
        sz = 1;
        while (sz < n) sz <<= 1;
        data.assign(2 * sz, e);
    }

    /**
    * @brief 全体に初期値を入れる. O(n)
    * @param[in] v 要素モノイドのvector. 初期化する.
    * @details 使い方
    *   segt.build(vector<int>(n, 0));
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
    * @brief 指定した位置に更新クエリを実行する. O(log n)
    * @param[in] k 位置k の要素に作用させる.
    * @param[in] q 値x をq(x) で更新する.
    * @details 使い方
    *   e.g. Add Query
    *   int i, x; // 位置i をx を足したい.
    *   segt.update(i, [&](int a){ return a + x; });
    *
    *   e.g. Update Query
    *   int i, x; // 位置i をx に更新したい.
    *   segt.update(i, [&](int a){ return x; });
    */
    template<class UpdateQuery>
    void update(int k, const UpdateQuery &q) {
        k += sz;
        data[k] = q(data[k]);
        while (k >>= 1) {
            data[k] = f(data[2 * k], data[2 * k + 1]);
        }
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
    M query(int a, int b) const {
        return query(a, b, 1, 0, sz);
    }

    /**
    * @brief 指定したindexの要素を取得. O(1)
    * @param[in] i 取得したい要素のindex
    * @return 取得した値.
    */
    M operator[](int k) const {
        return data[k + sz];
    }

    /**
    * @brief vector みたいに出力.
    */
    friend ostream& operator<<(ostream& os, SegmentTree& s) {
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
    const function<M(M,M)> f;
    const M e;

    M query(int a, int b, int k, int l, int r) const {
        if (r <= a || b <= l) {
            return e;
        } else if (a <= l && r <= b) {
            return data[k];
        } else {
            return f(query(a,b,2*k,  l,(l+r)/2),
                     query(a,b,2*k+1,(l+r)/2,r));
        }
    }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
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


#line 2 "lib/structure/segment_tree.cpp"

/**
* @brief セグメント木
* @author habara-k
* @date ?
*/

template<typename M>
struct SegmentTree {

    /**
    * @brief コンストラクタ. O(n)
    * @param[in] n セグ木のサイズ.
    * @param[in] f モノイドの演算.
    * @param[in] e モノイドの単位元.
    * @details 使い方
    *   e.g. Range Minimum
    *   SegmentTree<int> segt(
    *            n,
    *            [](int a,int b){ return min(a+b); },
    *            INF);
    *               // 全て単位元で初期化される.
    */
    SegmentTree(
            int n,
            const function<M(M,M)>& f,
            const M& e) : n(n), f(f), e(e) {
        sz = 1;
        while (sz < n) sz <<= 1;
        data.assign(2 * sz, e);
    }

    /**
    * @brief 全体に初期値を入れる. O(n)
    * @param[in] v 要素モノイドのvector. 初期化する.
    * @details 使い方
    *   segt.build(vector<int>(n, 0));
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
    * @brief 指定した位置に更新クエリを実行する. O(log n)
    * @param[in] k 位置k の要素に作用させる.
    * @param[in] q 値x をq(x) で更新する.
    * @details 使い方
    *   e.g. Add Query
    *   int i, x; // 位置i をx を足したい.
    *   segt.update(i, [&](int a){ return a + x; });
    *
    *   e.g. Update Query
    *   int i, x; // 位置i をx に更新したい.
    *   segt.update(i, [&](int a){ return x; });
    */
    template<class UpdateQuery>
    void update(int k, const UpdateQuery &q) {
        k += sz;
        data[k] = q(data[k]);
        while (k >>= 1) {
            data[k] = f(data[2 * k], data[2 * k + 1]);
        }
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
    M query(int a, int b) const {
        return query(a, b, 1, 0, sz);
    }

    /**
    * @brief 指定したindexの要素を取得. O(1)
    * @param[in] i 取得したい要素のindex
    * @return 取得した値.
    */
    M operator[](int k) const {
        return data[k + sz];
    }

    /**
    * @brief vector みたいに出力.
    */
    friend ostream& operator<<(ostream& os, SegmentTree& s) {
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
    const function<M(M,M)> f;
    const M e;

    M query(int a, int b, int k, int l, int r) const {
        if (r <= a || b <= l) {
            return e;
        } else if (a <= l && r <= b) {
            return data[k];
        } else {
            return f(query(a,b,2*k,  l,(l+r)/2),
                     query(a,b,2*k+1,(l+r)/2,r));
        }
    }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

