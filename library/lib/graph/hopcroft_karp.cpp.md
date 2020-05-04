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


# :heavy_check_mark:  <small>(lib/graph/hopcroft_karp.cpp)</small>

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#6e267a37887a7dcb68cbf7008d6c7e48">lib/graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/lib/graph/hopcroft_karp.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-04 15:30:16+09:00




## Depends on

* :heavy_check_mark: <a href="template.cpp.html">lib/graph/template.cpp</a>
* :heavy_check_mark: <a href="../template.cpp.html">lib/template.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/graph/hopcroft_karp.test.cpp.html">test/graph/hopcroft_karp.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include "template.cpp"

/**
 * @brief
 * HopcroftKarp(二部グラフの最大マッチング)
 * O(|E| sqrt(|V|))
 * |最大マッチング| + |最小辺カバー| = |V|
 * |最大マッチング| = |最小点カバー|
 * |最大安定集合| + |最小点カバー| = |V|
 *
 * @author Md
 * @date 2019/12
 * @details
 * 2020/04/14 コメント追加 by Md
 */

struct HopcroftKarp {
    vector<vector<int>> g;
    vector<int> d, mch;
    vector<bool> used, vv;

    HopcroftKarp(int n, int m) : g(n), mch(m, -1), used(n) {}

    void add_edge(int u, int v) {
        g[u].push_back(v);
    }

    void bfs() {
        d.assign(g.size(), -1);
        queue<int> que;
        for (int i = 0; i < (int)(g.size()); i++) {
            if (!used[i]) {
                que.emplace(i);
                d[i] = 0;
            }
        }

        while (!que.empty()) {
            int a = que.front();
            que.pop();
            for (auto &b : g[a]) {
                int c = mch[b];
                if (c >= 0 && d[c] == -1) {
                    d[c] = d[a] + 1;
                    que.emplace(c);
                }
            }
        }
    }

    bool dfs(int a) {
        vv[a] = true;
        for (auto &b : g[a]) {
            int c = mch[b];
            if (c < 0 || (!vv[c] && d[c] == d[a] + 1 && dfs(c))) {
                mch[b] = a;
                used[a] = true;
                return true;
            }
        }
        return false;
    }

    int bipartite_matching() {
        int ret = 0;
        while (true) {
            bfs();
            vv.assign(g.size(), false);
            int flow = 0;
            for (int i = 0; i < (int)(g.size()); i++) {
                if (!used[i] && dfs(i)) ++flow;
            }
            if (flow == 0) return ret;
            ret += flow;
        }
    }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "lib/graph/template.cpp"



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


#line 5 "lib/graph/template.cpp"

template<typename T>
struct edge {
    int src, to;
    T cost;
};

template<typename T>
using Graph = vector<vector<edge<T>>>;


#line 2 "lib/graph/hopcroft_karp.cpp"

/**
 * @brief
 * HopcroftKarp(二部グラフの最大マッチング)
 * O(|E| sqrt(|V|))
 * |最大マッチング| + |最小辺カバー| = |V|
 * |最大マッチング| = |最小点カバー|
 * |最大安定集合| + |最小点カバー| = |V|
 *
 * @author Md
 * @date 2019/12
 * @details
 * 2020/04/14 コメント追加 by Md
 */

struct HopcroftKarp {
    vector<vector<int>> g;
    vector<int> d, mch;
    vector<bool> used, vv;

    HopcroftKarp(int n, int m) : g(n), mch(m, -1), used(n) {}

    void add_edge(int u, int v) {
        g[u].push_back(v);
    }

    void bfs() {
        d.assign(g.size(), -1);
        queue<int> que;
        for (int i = 0; i < (int)(g.size()); i++) {
            if (!used[i]) {
                que.emplace(i);
                d[i] = 0;
            }
        }

        while (!que.empty()) {
            int a = que.front();
            que.pop();
            for (auto &b : g[a]) {
                int c = mch[b];
                if (c >= 0 && d[c] == -1) {
                    d[c] = d[a] + 1;
                    que.emplace(c);
                }
            }
        }
    }

    bool dfs(int a) {
        vv[a] = true;
        for (auto &b : g[a]) {
            int c = mch[b];
            if (c < 0 || (!vv[c] && d[c] == d[a] + 1 && dfs(c))) {
                mch[b] = a;
                used[a] = true;
                return true;
            }
        }
        return false;
    }

    int bipartite_matching() {
        int ret = 0;
        while (true) {
            bfs();
            vv.assign(g.size(), false);
            int flow = 0;
            for (int i = 0; i < (int)(g.size()); i++) {
                if (!used[i] && dfs(i)) ++flow;
            }
            if (flow == 0) return ret;
            ret += flow;
        }
    }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

