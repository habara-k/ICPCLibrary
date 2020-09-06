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


# :warning: lib/string/suffix_automaton.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#9a48db5fb6f746df590a3d4604f6478b">lib/string</a>
* <a href="{{ site.github.repository_url }}/blob/master/lib/string/suffix_automaton.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-06 11:22:41+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
// https://codeforces.com/gym/102428/submission/90057804 (by kanra824)
// ↑テスト　使ってるだけ 2019-2020 ACM-ICPC Latin American Regional Programming Contest

// 参考: https://w.atwiki.jp/uwicoder/pages/2842.html

struct state {
  int len, link;
  map<char, int> next;
};
 
const int MAXLEN = 200010;
state st[MAXLEN * 2];
int sz, last;
 
void sa_init() {
  sz = last = 0;
  st[0].len = 0;
  st[0].link = -1;
  sz++;
}
 

void sa_extend(char c) {
  int cur = sz++;
  st[cur].len = st[last].len + 1;
  int p;
  for (p = last; p != -1 && !st[p].next.count(c); p = st[p].link) {
    st[p].next[c] = cur;
  }
  if (p == -1) {
    st[cur].link = 0;
  } else {
    int q = st[p].next[c];
    if (st[p].len + 1 == st[q].len) {
      st[cur].link = q;
    } else {
      int clone = sz++;
      st[clone].len = st[p].len + 1;
      st[clone].next = st[q].next;
      st[clone].link = st[q].link;
      for (; p != -1 && st[p].next[c] == q; p = st[p].link) {
        st[p].next[c] = clone;
      }
      st[q].link = st[cur].link = clone;
    }
  }
  last = cur;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "lib/string/suffix_automaton.cpp"
// https://codeforces.com/gym/102428/submission/90057804 (by kanra824)
// ↑テスト　使ってるだけ 2019-2020 ACM-ICPC Latin American Regional Programming Contest

// 参考: https://w.atwiki.jp/uwicoder/pages/2842.html

struct state {
  int len, link;
  map<char, int> next;
};
 
const int MAXLEN = 200010;
state st[MAXLEN * 2];
int sz, last;
 
void sa_init() {
  sz = last = 0;
  st[0].len = 0;
  st[0].link = -1;
  sz++;
}
 

void sa_extend(char c) {
  int cur = sz++;
  st[cur].len = st[last].len + 1;
  int p;
  for (p = last; p != -1 && !st[p].next.count(c); p = st[p].link) {
    st[p].next[c] = cur;
  }
  if (p == -1) {
    st[cur].link = 0;
  } else {
    int q = st[p].next[c];
    if (st[p].len + 1 == st[q].len) {
      st[cur].link = q;
    } else {
      int clone = sz++;
      st[clone].len = st[p].len + 1;
      st[clone].next = st[q].next;
      st[clone].link = st[q].link;
      for (; p != -1 && st[p].next[c] == q; p = st[p].link) {
        st[p].next[c] = clone;
      }
      st[q].link = st[cur].link = clone;
    }
  }
  last = cur;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

