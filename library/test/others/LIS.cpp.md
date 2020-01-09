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


# :warning: test/others/LIS.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#387155223b8efcb396433364712bb3df">test/others</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/others/LIS.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-05 01:51:04+09:00


* see: <a href="https://atcoder.jp/contests/tdpc/tasks/tdpc_target">https://atcoder.jp/contests/tdpc/tasks/tdpc_target</a>


## Depends on

* :warning: <a href="../../others/LIS.cpp.html">others/LIS.cpp</a>
* :warning: <a href="../../template.cpp.html">template.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://atcoder.jp/contests/tdpc/tasks/tdpc_target"

#include "../../others/LIS.cpp"

int main()
{
    int n; cin >> n;
    vector<pair<int,int>> X(n);
    for (int i = 0; i < n; ++i) {
        int x, r; cin >> x >> r;
        X[i] = {x+r, x-r};
    }

    sort(X.rbegin(), X.rend());
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        a[i] = X[i].second;
    }

    int ans = LIS(a);
    cout << ans << endl;

    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/others/LIS.cpp"
#define PROBLEM "https://atcoder.jp/contests/tdpc/tasks/tdpc_target"

#line 1 "test/others/../../others/../template.cpp"



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
const double eps = 1e-8;
const int MOD = 1000000007;

//int main() {
//    cin.tie(0);
//    ios::sync_with_stdio(false);
//    cout << fixed << setprecision(10);
//
//}


#line 2 "test/others/../../others/LIS.cpp"

template<typename T>
int LIS(const vector<T>& a) {
    int n = a.size();
    T INF = numeric_limits<T>::max();
    vector<T> dp(n, INF);
    for(int i = 0; i < n; ++i) {
        *lower_bound(dp.begin(), dp.end(), a[i]) = a[i];
    }
    return distance(dp.begin(), lower_bound(dp.begin(), dp.end(), INF));
}
#line 4 "test/others/LIS.cpp"

int main()
{
    int n; cin >> n;
    vector<pair<int,int>> X(n);
    for (int i = 0; i < n; ++i) {
        int x, r; cin >> x >> r;
        X[i] = {x+r, x-r};
    }

    sort(X.rbegin(), X.rend());
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        a[i] = X[i].second;
    }

    int ans = LIS(a);
    cout << ans << endl;

    return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

