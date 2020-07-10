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


# :warning: lib/others/dice.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#2569b475fca6e8e7d428548d20016ff0">lib/others</a>
* <a href="{{ site.github.repository_url }}/blob/master/lib/others/dice.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-23 21:12:16+09:00




## Depends on

* :heavy_check_mark: <a href="../template.cpp.html">lib/template.cpp</a>


## Required by

* :warning: <a href="../../test/others/dice.cpp.html">test/others/dice.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include "../template.cpp"

// 0: 上, 1: 手前, 2: 左, 3: 奥, 4: 右, 5: 下
struct Dice {
  vi face;
  void init() {
    face.resize(6);
  }

  // 左に転がす
  void rotl() {
    vi newface = {face[4], face[1], face[0], face[3], face[5], face[2]};
    swap(face, newface);
  }

  // 右に転がす
  void rotr() {
    vi newface = {face[2], face[1], face[5], face[3], face[0], face[4]};
    swap(face, newface);
  }

  // 奥に転がす
  void rotu() {
    vi newface = {face[1], face[5], face[2], face[0], face[4], face[3]};
    swap(face, newface);
  }

  // 手前に転がす
  void rotd() {
    vi newface = {face[3], face[0], face[2], face[5], face[4], face[1]};
    swap(face, newface);
  }
};

bool operator==(Dice d1, Dice d2) {
  return d1.face == d2.face;
}

bool operator<(Dice d1, Dice d2) {
  return d1.face < d2.face;
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


#line 2 "lib/others/dice.cpp"

// 0: 上, 1: 手前, 2: 左, 3: 奥, 4: 右, 5: 下
struct Dice {
  vi face;
  void init() {
    face.resize(6);
  }

  // 左に転がす
  void rotl() {
    vi newface = {face[4], face[1], face[0], face[3], face[5], face[2]};
    swap(face, newface);
  }

  // 右に転がす
  void rotr() {
    vi newface = {face[2], face[1], face[5], face[3], face[0], face[4]};
    swap(face, newface);
  }

  // 奥に転がす
  void rotu() {
    vi newface = {face[1], face[5], face[2], face[0], face[4], face[3]};
    swap(face, newface);
  }

  // 手前に転がす
  void rotd() {
    vi newface = {face[3], face[0], face[2], face[5], face[4], face[1]};
    swap(face, newface);
  }
};

bool operator==(Dice d1, Dice d2) {
  return d1.face == d2.face;
}

bool operator<(Dice d1, Dice d2) {
  return d1.face < d2.face;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

