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


# :heavy_check_mark:  <small>(lib/graph/re_rooting.cpp)</small>

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#6e267a37887a7dcb68cbf7008d6c7e48">lib/graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/lib/graph/re_rooting.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-18 18:41:54+09:00




## Depends on

* :heavy_check_mark: <a href="../template.cpp.html">lib/template.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/graph/re_rooting.test.cpp.html">test/graph/re_rooting.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include "../template.cpp"

/**
 * @brief
 * 全方位木dp
 * @author habara-k
 * @date 2020/05/18
 * @verify https://codeforces.com/gym/102433/submission/80588275
 * @details 使い方
 *   e.g. 直径
 *   using T = pair<int,int>; // 頂点が持つべきデータ
 *   using Data = int;        // 親が子を引っ張り上げるときに必要なデータ

 *   ReRooting<Data,T> tr(
 *           n,
 *           [](T a, T b){
 *               vector<int> v{a.first,a.second,b.first,b.second};
 *               sort(v.rbegin(),v.rend());
 *               return T{v[0],v[1]};
 *               },                       // 子をマージする演算
 *           [](T a, Data w){
 *               return T{a.first+w, 0};
 *               },                       // 子を引っ張り上げる演算
 *           vector<T>(n, T{0, 0}),       // 頂点が持つデータの初期値
 *           T{0,0}                       // 子をマージする演算の単位元
 *           );
 *
 *   for (int i = 0; i < n-1; ++i) {
 *       int s, t, w; cin >> s >> t >> w;
 *       tr.add_edge(s, t, Data{w}, Data{w});
 *   }
 *
 *   auto ans = tr.solve();
 */

template<typename Data, typename T>
struct ReRooting {

    using F1 = function<T(T, T)>;
    using F2 = function<T(T, Data)>;

    /**
    * @brief コンストラクタ. O(1).
    * @param[in] n: 頂点数
    * @param[in] f1: 子が持つデータをマージする演算
    * @param[in] f2: 親が子を引っ張り上げる演算
    * @param[in] init: 頂点が持つデータの初期値
    * @param[in] ident: f1の単位元
    */
    ReRooting(
            int n, const F1 &f1, const F2 &f2,
            const vector<T> &init, const T &ident) :
        g(n), ldp(n), rdp(n), lptr(n), rptr(n),
        f1(f1), f2(f2), init(init), ident(ident) {}

    /**
    * @brief 辺を追加する. O(1)
    * @param[in] u, v: 辺u, v を追加する.
    * @param[in] d: u がv を引っ張り上げるときに必要なデータ.
    * @param[in] e: v がu を引っ張り上げるときに必要なデータ.
    */
    void add_edge(int u, int v, const Data &d, const Data &e) {
        g[u].emplace_back((edge){v, (int)g[v].size(), d});
        g[v].emplace_back((edge){u, (int)g[u].size()-1, e});
    }


    /**
    * @brief 全方位木dp を実行する.
    * @return vector<T> 各頂点を根としたときの演算の結果.
    */
    vector<T> solve() {
        for (int i = 0; i < g.size(); ++i) {
            ldp[i].assign(g[i].size()+1, ident);
            rdp[i].assign(g[i].size()+1, ident);
            lptr[i] = 0;
            rptr[i] = (int)g[i].size()-1;
            ldp[i][0] = init[i];
        }
        vector<T> ret(g.size());
        for (int i = 0; i < g.size(); ++i) {
            ret[i] = dfs(i, -1);
        }
        return ret;
    }

private:
    struct edge {
        int to, rev;
        Data data;
    };

    vector<vector<edge>> g;
    vector<vector<T>> ldp, rdp;
    vector<int> lptr, rptr;
    const F1 f1;
    const F2 f2;
    const vector<T> init;
    const T ident;

    T dfs(int idx, int par) {
        while (lptr[idx] != par and lptr[idx] < g[idx].size()) {
            auto &e = g[idx][lptr[idx]];
            ldp[idx][lptr[idx]+1] = f1(
                    ldp[idx][lptr[idx]],
                    f2(dfs(e.to, e.rev), e.data));
            ++lptr[idx];
        }
        while (rptr[idx] != par and rptr[idx] >= 0) {
            auto &e = g[idx][rptr[idx]];
            rdp[idx][rptr[idx]] = f1(
                    rdp[idx][rptr[idx]+1],
                    f2(dfs(e.to, e.rev), e.data));
            --rptr[idx];
        }
        if (par < 0) return rdp[idx][0];
        return f1(ldp[idx][par], rdp[idx][par+1]);
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


#line 2 "lib/graph/re_rooting.cpp"

/**
 * @brief
 * 全方位木dp
 * @author habara-k
 * @date 2020/05/18
 * @verify https://codeforces.com/gym/102433/submission/80588275
 * @details 使い方
 *   e.g. 直径
 *   using T = pair<int,int>; // 頂点が持つべきデータ
 *   using Data = int;        // 親が子を引っ張り上げるときに必要なデータ

 *   ReRooting<Data,T> tr(
 *           n,
 *           [](T a, T b){
 *               vector<int> v{a.first,a.second,b.first,b.second};
 *               sort(v.rbegin(),v.rend());
 *               return T{v[0],v[1]};
 *               },                       // 子をマージする演算
 *           [](T a, Data w){
 *               return T{a.first+w, 0};
 *               },                       // 子を引っ張り上げる演算
 *           vector<T>(n, T{0, 0}),       // 頂点が持つデータの初期値
 *           T{0,0}                       // 子をマージする演算の単位元
 *           );
 *
 *   for (int i = 0; i < n-1; ++i) {
 *       int s, t, w; cin >> s >> t >> w;
 *       tr.add_edge(s, t, Data{w}, Data{w});
 *   }
 *
 *   auto ans = tr.solve();
 */

template<typename Data, typename T>
struct ReRooting {

    using F1 = function<T(T, T)>;
    using F2 = function<T(T, Data)>;

    /**
    * @brief コンストラクタ. O(1).
    * @param[in] n: 頂点数
    * @param[in] f1: 子が持つデータをマージする演算
    * @param[in] f2: 親が子を引っ張り上げる演算
    * @param[in] init: 頂点が持つデータの初期値
    * @param[in] ident: f1の単位元
    */
    ReRooting(
            int n, const F1 &f1, const F2 &f2,
            const vector<T> &init, const T &ident) :
        g(n), ldp(n), rdp(n), lptr(n), rptr(n),
        f1(f1), f2(f2), init(init), ident(ident) {}

    /**
    * @brief 辺を追加する. O(1)
    * @param[in] u, v: 辺u, v を追加する.
    * @param[in] d: u がv を引っ張り上げるときに必要なデータ.
    * @param[in] e: v がu を引っ張り上げるときに必要なデータ.
    */
    void add_edge(int u, int v, const Data &d, const Data &e) {
        g[u].emplace_back((edge){v, (int)g[v].size(), d});
        g[v].emplace_back((edge){u, (int)g[u].size()-1, e});
    }


    /**
    * @brief 全方位木dp を実行する.
    * @return vector<T> 各頂点を根としたときの演算の結果.
    */
    vector<T> solve() {
        for (int i = 0; i < g.size(); ++i) {
            ldp[i].assign(g[i].size()+1, ident);
            rdp[i].assign(g[i].size()+1, ident);
            lptr[i] = 0;
            rptr[i] = (int)g[i].size()-1;
            ldp[i][0] = init[i];
        }
        vector<T> ret(g.size());
        for (int i = 0; i < g.size(); ++i) {
            ret[i] = dfs(i, -1);
        }
        return ret;
    }

private:
    struct edge {
        int to, rev;
        Data data;
    };

    vector<vector<edge>> g;
    vector<vector<T>> ldp, rdp;
    vector<int> lptr, rptr;
    const F1 f1;
    const F2 f2;
    const vector<T> init;
    const T ident;

    T dfs(int idx, int par) {
        while (lptr[idx] != par and lptr[idx] < g[idx].size()) {
            auto &e = g[idx][lptr[idx]];
            ldp[idx][lptr[idx]+1] = f1(
                    ldp[idx][lptr[idx]],
                    f2(dfs(e.to, e.rev), e.data));
            ++lptr[idx];
        }
        while (rptr[idx] != par and rptr[idx] >= 0) {
            auto &e = g[idx][rptr[idx]];
            rdp[idx][rptr[idx]] = f1(
                    rdp[idx][rptr[idx]+1],
                    f2(dfs(e.to, e.rev), e.data));
            --rptr[idx];
        }
        if (par < 0) return rdp[idx][0];
        return f1(ldp[idx][par], rdp[idx][par+1]);
    }
};


```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

