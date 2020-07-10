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


# :heavy_check_mark: lib/graph/scc.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#6e267a37887a7dcb68cbf7008d6c7e48">lib/graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/lib/graph/scc.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-06 01:41:24+09:00




## Depends on

* :heavy_check_mark: <a href="template.cpp.html">lib/graph/template.cpp</a>
* :question: <a href="../template.cpp.html">lib/template.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/graph/scc.test.cpp.html">test/graph/scc.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include "template.cpp"

template<typename T>
struct SCC {
    int sz, cnt, num;
    vi post, comp;
    vector<pair<int, int>> vp;
    vector<bool> sel;
    Graph<T> revg;

    SCC(const Graph<T> &g) {
        sz = g.size();
        cnt = 0;
        num = 0;
        post.resize(sz, -1);
        comp.resize(sz, -1);
        sel.resize(sz, false);
        revg.resize(sz);
    }

    void build(const Graph<T> &g) {
        for(int i=0;i<sz;++i) {
            if(sel[i]) continue;
            sel[i] = true;
            dfs1(g, i);
        }

        rev(g, revg);

        for(int i=0;i<sz;++i) {
            vp.emplace_back(make_pair(post[i], i));
        }
        sort(vp.begin(), vp.end());
        reverse(vp.begin(), vp.end());
        sel.clear();
        sel.resize(sz, false);
        for(int i=0;i<sz;++i) {
            if(sel[vp[i].second]) continue;
            sel[vp[i].second] = true;
            comp[vp[i].second] = num;
            dfs2(revg, vp[i].second);
            num++;
        }
    }

    vi get_comp() {return comp;}

    Graph<T> build_graph(const Graph<T> &g) {
        build(g);
        vector<set<int>> s(sz);
        Graph<T> res(sz);
        for(int i=0;i<sz;++i) {
            for(int j=0;j<(int)(g[i].size());++j) {
                s[comp[i]].insert(comp[g[i][j].to]);
            }
        }
        for(int i=0;i<sz;++i) {
            for(auto j: s[i]) {
                if(i != j) res[i].push_back(edge<int>({i, j, 1}));
            }
        }
        return res;
    }

    void dfs1(const Graph<T> &g, int now) {
        for(int i=0;i<(int)(g[now].size());++i) {
            int nxt = g[now][i].to;
            if(sel[nxt]) continue;
            sel[nxt] = true;
            dfs1(g, nxt);
        }
        post[now] = cnt;
        cnt++;
    }

    void rev(const Graph<T> &g, Graph<T> &revg) {
        for(int i=0;i<sz;++i) {
            for(int j=0;j<(int)(g[i].size());++j) {
                revg[g[i][j].to].push_back({
                        g[i][j].to, g[i][j].src, g[i][j].cost});
            }
        }
    }

    void dfs2(const Graph<T> &revg, int now) {
        for(int i=0;i<(int)(revg[now].size());++i) {
            int nxt = revg[now][i].to;
            if(sel[nxt]) continue;
            sel[nxt] = true;
            comp[nxt] = num;
            dfs2(revg, nxt);
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


#line 5 "lib/graph/template.cpp"

template<typename T>
struct edge {
    int src, to;
    T cost;
};

template<typename T>
using Graph = vector<vector<edge<T>>>;


#line 2 "lib/graph/scc.cpp"

template<typename T>
struct SCC {
    int sz, cnt, num;
    vi post, comp;
    vector<pair<int, int>> vp;
    vector<bool> sel;
    Graph<T> revg;

    SCC(const Graph<T> &g) {
        sz = g.size();
        cnt = 0;
        num = 0;
        post.resize(sz, -1);
        comp.resize(sz, -1);
        sel.resize(sz, false);
        revg.resize(sz);
    }

    void build(const Graph<T> &g) {
        for(int i=0;i<sz;++i) {
            if(sel[i]) continue;
            sel[i] = true;
            dfs1(g, i);
        }

        rev(g, revg);

        for(int i=0;i<sz;++i) {
            vp.emplace_back(make_pair(post[i], i));
        }
        sort(vp.begin(), vp.end());
        reverse(vp.begin(), vp.end());
        sel.clear();
        sel.resize(sz, false);
        for(int i=0;i<sz;++i) {
            if(sel[vp[i].second]) continue;
            sel[vp[i].second] = true;
            comp[vp[i].second] = num;
            dfs2(revg, vp[i].second);
            num++;
        }
    }

    vi get_comp() {return comp;}

    Graph<T> build_graph(const Graph<T> &g) {
        build(g);
        vector<set<int>> s(sz);
        Graph<T> res(sz);
        for(int i=0;i<sz;++i) {
            for(int j=0;j<(int)(g[i].size());++j) {
                s[comp[i]].insert(comp[g[i][j].to]);
            }
        }
        for(int i=0;i<sz;++i) {
            for(auto j: s[i]) {
                if(i != j) res[i].push_back(edge<int>({i, j, 1}));
            }
        }
        return res;
    }

    void dfs1(const Graph<T> &g, int now) {
        for(int i=0;i<(int)(g[now].size());++i) {
            int nxt = g[now][i].to;
            if(sel[nxt]) continue;
            sel[nxt] = true;
            dfs1(g, nxt);
        }
        post[now] = cnt;
        cnt++;
    }

    void rev(const Graph<T> &g, Graph<T> &revg) {
        for(int i=0;i<sz;++i) {
            for(int j=0;j<(int)(g[i].size());++j) {
                revg[g[i][j].to].push_back({
                        g[i][j].to, g[i][j].src, g[i][j].cost});
            }
        }
    }

    void dfs2(const Graph<T> &revg, int now) {
        for(int i=0;i<(int)(revg[now].size());++i) {
            int nxt = revg[now][i].to;
            if(sel[nxt]) continue;
            sel[nxt] = true;
            comp[nxt] = num;
            dfs2(revg, nxt);
        }
    }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

