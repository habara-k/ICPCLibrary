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
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :warning: string/z_algorithm.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#b45cffe084dd3d20d928bee85e7b0f21">string</a>
* <a href="{{ site.github.repository_url }}/blob/master/string/z_algorithm.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-07 03:51:42+09:00




## Depends on

* :question: <a href="../template.cpp.html">template.cpp</a>


## Required by

* :warning: <a href="../test/string/z_algorithm.cpp.html">test/string/z_algorithm.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include "../template.cpp"

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

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
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

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

