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


# :warning:  <small>(lib/structure/convex_hull_trick.cpp)</small>

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#c4d905b3311a5371af1ce28a5d3ead13">lib/structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/lib/structure/convex_hull_trick.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-24 21:07:17+09:00




## Depends on

* :question: <a href="../template.cpp.html">lib/template.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include "../template.cpp"

/**
 * @brief
 * ax + b の最小値を管理
 * @author habara-k
 * @date 2020/05/24
 * @verify https://onlinejudge.u-aizu.ac.jp/services/review.html#rupc2014_whiteboard/4508173
 */

template<typename T>
struct ConvexHullTrick {

    /**
    * @brief コンストラクタ O(n)
    * @param[in] n: 追加する線分の上限
    */
    ConvexHullTrick(int n) : deq(n), s(0), t(0), prev(numeric_limits<T>::min()) {}

    /**
    * @brief 追加クエリ ならしO(1)
    * @param[in] a, b: ax + b を追加
    */
    void insert(T a, T b) {
        Line l = {a, b};
        while (t - s >= 2 and check(deq[t - 2], deq[t - 1], l)) --t;
        deq[t++] = l;
    }

    /**
    * @brief 取得クエリ ならしO(1)
    * @param[in] x: xにおける最小値を返す
    * @details x は昇順に呼ぶこと
    */
    T query(T x) {
        assert(prev <= x);
        prev = x;
        while (t - s >= 2 and f(deq[s], x) >= f(deq[s + 1], x)) ++s;
        return f(deq[s], x);
    }

private:
    struct Line {
        T a, b;
    };
    vector<Line> deq;
    int s, t;
    T prev;

    bool check(const Line& l1, const Line& l2, const Line& l3) const {
        return (l2.a - l1.a) * (l3.b - l2.b) >= (l2.b - l1.b) * (l3.a - l2.a);
    }
    T f(Line& l, T x) const {
        return l.a * x + l.b;
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


#line 2 "lib/structure/convex_hull_trick.cpp"

/**
 * @brief
 * ax + b の最小値を管理
 * @author habara-k
 * @date 2020/05/24
 * @verify https://onlinejudge.u-aizu.ac.jp/services/review.html#rupc2014_whiteboard/4508173
 */

template<typename T>
struct ConvexHullTrick {

    /**
    * @brief コンストラクタ O(n)
    * @param[in] n: 追加する線分の上限
    */
    ConvexHullTrick(int n) : deq(n), s(0), t(0), prev(numeric_limits<T>::min()) {}

    /**
    * @brief 追加クエリ ならしO(1)
    * @param[in] a, b: ax + b を追加
    */
    void insert(T a, T b) {
        Line l = {a, b};
        while (t - s >= 2 and check(deq[t - 2], deq[t - 1], l)) --t;
        deq[t++] = l;
    }

    /**
    * @brief 取得クエリ ならしO(1)
    * @param[in] x: xにおける最小値を返す
    * @details x は昇順に呼ぶこと
    */
    T query(T x) {
        assert(prev <= x);
        prev = x;
        while (t - s >= 2 and f(deq[s], x) >= f(deq[s + 1], x)) ++s;
        return f(deq[s], x);
    }

private:
    struct Line {
        T a, b;
    };
    vector<Line> deq;
    int s, t;
    T prev;

    bool check(const Line& l1, const Line& l2, const Line& l3) const {
        return (l2.a - l1.a) * (l3.b - l2.b) >= (l2.b - l1.b) * (l3.a - l2.a);
    }
    T f(Line& l, T x) const {
        return l.a * x + l.b;
    }
};



```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

