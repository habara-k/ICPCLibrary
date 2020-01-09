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


# :warning: test/others/inversion.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#387155223b8efcb396433364712bb3df">test/others</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/others/inversion.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-05 01:41:42+09:00


* see: <a href="https://atcoder.jp/contests/agc034/tasks/agc034_b">https://atcoder.jp/contests/agc034/tasks/agc034_b</a>


## Depends on

* :warning: <a href="../../others/inversion.cpp.html">others/inversion.cpp</a>
* :warning: <a href="../../structure/binary_indexed_tree.cpp.html">structure/binary_indexed_tree.cpp</a>
* :heavy_check_mark: <a href="../../template.cpp.html">template.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://atcoder.jp/contests/agc034/tasks/agc034_b"

#include "../../others/inversion.cpp"

int main()
{
    string s; cin >> s;

    vector<vector<int>> vs;
    vector<int> v;
    for (int i = 0; i <= s.size(); ++i) {
        if (i == s.size()) {
            if (v.size()) vs.push_back(v);
            v.clear();
        } else if (s[i] == 'A') {
            v.push_back(1);
        } else if (i+1 < s.size() && s[i] == 'B' && s[i+1] == 'C') {
            v.push_back(0);
            ++i;
        } else {
            if (v.size()) vs.push_back(v);
            v.clear();
        }
    }

    ll ans = 0;
    for (auto v : vs) {
        ans += inversion(v);
    }
    cout << ans << endl;

    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/others/inversion.cpp"
#define PROBLEM "https://atcoder.jp/contests/agc034/tasks/agc034_b"

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


#line 2 "test/others/../../others/inversion.cpp"

#line 1 "test/others/../../others/../structure/../template.cpp"



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


#line 2 "test/others/../../others/../structure/binary_indexed_tree.cpp"

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
#line 4 "test/others/../../others/inversion.cpp"

template<typename T>
ll inversion(const vector<T>& a)
{
    map<T,int> mp;
    for (auto e : a) mp[e] = -1;
    int sz = 0;
    for (auto &q : mp) {
        q.second = sz++;
    }

    BIT<int> bit(sz+1);
    ll res = 0;
    for (int i = 0; i < a.size(); ++i) {
        res += i - bit.sum(mp[a[i]]);
        bit.add(mp[a[i]], 1);
    }
    return res;
}
#line 4 "test/others/inversion.cpp"

int main()
{
    string s; cin >> s;

    vector<vector<int>> vs;
    vector<int> v;
    for (int i = 0; i <= s.size(); ++i) {
        if (i == s.size()) {
            if (v.size()) vs.push_back(v);
            v.clear();
        } else if (s[i] == 'A') {
            v.push_back(1);
        } else if (i+1 < s.size() && s[i] == 'B' && s[i+1] == 'C') {
            v.push_back(0);
            ++i;
        } else {
            if (v.size()) vs.push_back(v);
            v.clear();
        }
    }

    ll ans = 0;
    for (auto v : vs) {
        ans += inversion(v);
    }
    cout << ans << endl;

    return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

