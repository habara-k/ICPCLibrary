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


# :warning: test/graph/topological_sort.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#baa37bfd168b079b758c0db816f7295f">test/graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/graph/topological_sort.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-07 03:51:42+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/4/GRL_4_B">https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/4/GRL_4_B</a>


## Depends on

* :heavy_check_mark: <a href="../../graph/template.cpp.html">graph/template.cpp</a>
* :warning: <a href="../../graph/topological_sort.cpp.html">graph/topological_sort.cpp</a>
* :heavy_check_mark: <a href="../../template.cpp.html">template.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/4/GRL_4_B"

#include "../../graph/topological_sort.cpp"

int main() {
    int V, E; cin >> V >> E;
    vector<vector<int>> G(V);
    for (int i = 0; i < E; ++i) {
        int s, t; cin >> s >> t;
        G[s].push_back(t);
    }
    vector<int> ord;
    topological_sort(G, ord);
    for (auto v : ord) {
        cout << v << endl;
    }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/graph/topological_sort.cpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/4/GRL_4_B"

#line 1 "graph/template.cpp"



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


#line 5 "graph/template.cpp"

template<typename T>
struct edge {
    int src, to;
    T cost;
    // edge(int src, int to, T cost): src(src), to(to), cost(cost) {}
    // // G[i].push_back({src, to, cost}) requires no constructor
};

template<typename T>
using Graph = vector<vector<edge<T>>>;


#line 2 "graph/topological_sort.cpp"

void topological_sort(const vector<vector<int>>& G, vector<int>& ord)
{
    int n = G.size();
    vector<int> num(n, 0);
    ord.assign(n, 0);
    for (int i = 0; i < n; ++i) {
        for (auto u : G[i]) {
            ++num[u];
        }
    }
    stack<int> st;
    for(int i = 0; i < n; ++i) {
        if (num[i] == 0) {
            st.push(i);
        }
    }
    for (int k = 0; !st.empty(); ++k) {
        int i = st.top(); st.pop();
        ord[k] = i;
        for (auto u : G[i]) {
            if (--num[u] == 0) {
                st.push(u);
            }
        }
    }
}
#line 4 "test/graph/topological_sort.cpp"

int main() {
    int V, E; cin >> V >> E;
    vector<vector<int>> G(V);
    for (int i = 0; i < E; ++i) {
        int s, t; cin >> s >> t;
        G[s].push_back(t);
    }
    vector<int> ord;
    topological_sort(G, ord);
    for (auto v : ord) {
        cout << v << endl;
    }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

