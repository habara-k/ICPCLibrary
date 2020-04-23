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


# :warning: test/string/z_algorithm.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#e46c0047b1d14ef43eeaaf13f64d385f">test/string</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/string/z_algorithm.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-23 18:17:04+09:00


* see: <a href="https://atcoder.jp/contests/abc141/tasks/abc141_e">https://atcoder.jp/contests/abc141/tasks/abc141_e</a>


## Depends on

* :warning: <a href="../../string/z_algorithm.cpp.html">string/z_algorithm.cpp</a>
* :question: <a href="../../template.cpp.html">template.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://atcoder.jp/contests/abc141/tasks/abc141_e"

#include "../../string/z_algorithm.cpp"

int main() {
    int n; cin >> n;
    string s; cin >> s;

    int ans = 0;

    for (int i = 0; i < n; ++i) {
        vector<int> a;
        z_algorithm(s.substr(i, n-i), a);
        for (int j = 0; j < a.size(); ++j) {
            if (a[j] <= j) {
                ans = max(ans, a[j]);
            }
        }
    }

    cout << ans << endl;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/string/z_algorithm.cpp"
#define PROBLEM "https://atcoder.jp/contests/abc141/tasks/abc141_e"

#line 1 "template.cpp"



#include <bits/stdc++.h>

using namespace std;

#define REP(i, n) for (int i=0; i<(n); ++i)
#define RREP(i, n) for (int i=(int)(n)-1; i>=0; --i)
#define FOR(i, a, n) for (int i=(a); i<(n); ++i)
#define RFOR(i, a, n) for (int i=(int)(n)-1; i>=(a); --i)

#define SZ(x) ((int)(x).size())
#define all(x) begin(x),end(x)

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


#line 2 "string/z_algorithm.cpp"

// GET A[i]: the longest common prefix size of S and S[i:n-1]
template<typename S>
void z_algorithm(const S& s, vector<int>& A) {
    int n = s.size();
    A.resize(n);
    A[0] = n;
    int i = 1, j = 0;
    while (i < n) {
        while (i+j < n && s[j] == s[i+j]) ++j;
        A[i] = j;
        if (j == 0) { ++i; continue; }
        int k = 1;
        while (i+k < n && k+A[k] < j) { A[i+k] = A[k]; ++k; }
        i += k; j -= k;
    }
}
#line 4 "test/string/z_algorithm.cpp"

int main() {
    int n; cin >> n;
    string s; cin >> s;

    int ans = 0;

    for (int i = 0; i < n; ++i) {
        vector<int> a;
        z_algorithm(s.substr(i, n-i), a);
        for (int j = 0; j < a.size(); ++j) {
            if (a[j] <= j) {
                ans = max(ans, a[j]);
            }
        }
    }

    cout << ans << endl;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

