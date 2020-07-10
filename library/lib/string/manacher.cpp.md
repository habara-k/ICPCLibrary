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


# :warning: 文字列の各位置を中心とする回文長をO(|S|)で求める <small>(lib/string/manacher.cpp)</small>

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#9a48db5fb6f746df590a3d4604f6478b">lib/string</a>
* <a href="{{ site.github.repository_url }}/blob/master/lib/string/manacher.cpp">View this file on GitHub</a>
    - Last commit date: 2020-07-10 01:09:12+09:00




## Depends on

* :question: <a href="../template.cpp.html">lib/template.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include "../template.cpp"

/*
 * @brief 文字列の各位置を中心とする回文長をO(|S|)で求める
 * @detail 偶数長の回文について同じことをしたいときははabcde -> $a$b$c$d$e$ みたいな変換をして使う
 * @author Md
 * @date 2020/07/10
 */
vi Manacher(string s) {
  int c = 0, n = SZ(s); // c: すでに見つけた回文のうち、右端が最も右に有るようなもの
  vi r(n, 1);
  REP(i, n) {
    int l = c - (i - c);
    if(i + r[l] < c + r[c]) { // 位置cの回文に位置lの回文が含まれていれば、r[l]とr[i]は一致する
      r[i] = r[l];
    } else {
      int j = c + r[c] - i; // cに含まれている部分は大丈夫(そうでなければif節に行くはず
      while(i - j >= 0 && i + j < n && s[i-j] == s[i+j]) ++j; // 愚直に求める
      r[i] = j;
      c = i;
    }
  }
  return r;
}

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


#line 2 "lib/string/manacher.cpp"

/*
 * @brief 文字列の各位置を中心とする回文長をO(|S|)で求める
 * @detail 偶数長の回文について同じことをしたいときははabcde -> $a$b$c$d$e$ みたいな変換をして使う
 * @author Md
 * @date 2020/07/10
 */
vi Manacher(string s) {
  int c = 0, n = SZ(s); // c: すでに見つけた回文のうち、右端が最も右に有るようなもの
  vi r(n, 1);
  REP(i, n) {
    int l = c - (i - c);
    if(i + r[l] < c + r[c]) { // 位置cの回文に位置lの回文が含まれていれば、r[l]とr[i]は一致する
      r[i] = r[l];
    } else {
      int j = c + r[c] - i; // cに含まれている部分は大丈夫(そうでなければif節に行くはず
      while(i - j >= 0 && i + j < n && s[i-j] == s[i+j]) ++j; // 愚直に求める
      r[i] = j;
      c = i;
    }
  }
  return r;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

