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


# :warning: lib/graph/twoconnectedcomponents.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#6e267a37887a7dcb68cbf7008d6c7e48">lib/graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/lib/graph/twoconnectedcomponents.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-04 15:30:16+09:00




## Depends on

* :warning: <a href="lowlink.cpp.html">lib/graph/lowlink.cpp</a>
* :heavy_check_mark: <a href="template.cpp.html">lib/graph/template.cpp</a>
* :question: <a href="../template.cpp.html">lib/template.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include "./lowlink.cpp"

template<typename T>
struct TwoEdgeConnectedComponents: LowLink<T> {
    using lowlink = LowLink<T>;
    vector<int> comp;

    TwoEdgeConnectedComponents(const Graph<T> &g): lowlink(g) {}

    int operator[] (const int &k) {
        return comp[k];
    }

    void dfs(int idx, int par, int &k) {
        if(!par && this->pre[par] >= this->low[idx]) comp[idx] = comp[par];
        else comp[idx] == k++;
        for(auto &e: this->g[idx]) {
            if(comp[e.to] == -1) dfs(e.to, idx, k);
        }
    }

    void build(Graph<T> &t) {
        lowlink::build();
        comp.assign(this->g.size(), -1);
        int k = 0;
        for(int i=0;i<(int)(comp.size());++i) {
            if(comp[i] == -1) dfs(i, -1, k);
        }
        t.resize(k);
        for(auto &e: this->bridge) {
            int x = comp[e.first], y = comp[e.second];
            t[x].push_back(y);
            t[y].push_back(x);
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


#line 2 "lib/graph/lowlink.cpp"

template<typename T>
struct LowLink {
    const int inf = 1000000000;
    int sz;
    std::vector<int> pre, low;
    std::vector<bool> sel;
    std::vector<std::pair<int, int>> bridge;
    std::vector<int> articulation;

    LowLink(const Graph<T> &g) {
        sz = g.size();
        pre.resize(sz, inf);
        low.resize(sz, inf);
        sel.resize(sz, false);
        int cnt = 0;
        dfs(g, 0, -1, cnt);
    }

    void dfs(const Graph<T> &g, int now, int prev, int &cnt) {
        if(pre[now] != inf) {
            low[prev] = min(low[prev], pre[now]);
            return;
        }
        pre[now] = cnt;
        low[now] = cnt;
        cnt++;
        for(int i=0;i<(int)(g[now].size());++i) {
            int nxt = g[now][i].to;
            //if g is an undirected graph
            if(nxt == prev) continue;
            dfs(g, nxt, now, cnt);
        }
        if(prev != -1) low[prev] = min(low[prev], low[now]);
        if(prev != -1 && pre[prev] < low[now]) {
            bridge.emplace_back(make_pair(prev, now));
        }
    }

    void get_articulation(const Graph<T> &g, int now, int prev) {
        sel[now] = true;
        int art = 0;
        for(int i=0;i<(int)(g[now].size());++i) {
            int nxt = g[now][i].to;
            //cout << now << ":" << nxt << endl;
            if(sel[nxt]) continue;
            // if g is an undirected graph
            if(nxt == prev) continue;
            if(now == 0 || pre[now] <= low[nxt]) art++;
            get_articulation(g, nxt, now);
        }
        if((now == 0 && art >= 2) || (now != 0 && art >= 1)) {
            articulation.push_back(now);
        }
    }
};
#line 2 "lib/graph/twoconnectedcomponents.cpp"

template<typename T>
struct TwoEdgeConnectedComponents: LowLink<T> {
    using lowlink = LowLink<T>;
    vector<int> comp;

    TwoEdgeConnectedComponents(const Graph<T> &g): lowlink(g) {}

    int operator[] (const int &k) {
        return comp[k];
    }

    void dfs(int idx, int par, int &k) {
        if(!par && this->pre[par] >= this->low[idx]) comp[idx] = comp[par];
        else comp[idx] == k++;
        for(auto &e: this->g[idx]) {
            if(comp[e.to] == -1) dfs(e.to, idx, k);
        }
    }

    void build(Graph<T> &t) {
        lowlink::build();
        comp.assign(this->g.size(), -1);
        int k = 0;
        for(int i=0;i<(int)(comp.size());++i) {
            if(comp[i] == -1) dfs(i, -1, k);
        }
        t.resize(k);
        for(auto &e: this->bridge) {
            int x = comp[e.first], y = comp[e.second];
            t[x].push_back(y);
            t[y].push_back(x);
        }
    }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

