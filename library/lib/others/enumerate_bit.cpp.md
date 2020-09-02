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


# :warning: lib/others/enumerate_bit.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#2569b475fca6e8e7d428548d20016ff0">lib/others</a>
* <a href="{{ site.github.repository_url }}/blob/master/lib/others/enumerate_bit.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-03 08:26:44+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
// 集合Sの部分集合を列挙 (SとTを列挙するときにこれをつかうと4^nから3^nになる）
for(int T=S; ;T = (T - 1) & S) {
  // hoge
  if(T == 0) break;
}

// n個からk個えらんだ集合を列挙
for (int x = (1 << k) - 1; x < (1 << n); ) {
    ...
    int t = x | (x - 1);
    x = (t + 1) | (((~ t & - ~ t) - 1) >> (__builtin_ctz(x) + 1));
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "lib/others/enumerate_bit.cpp"
// 集合Sの部分集合を列挙 (SとTを列挙するときにこれをつかうと4^nから3^nになる）
for(int T=S; ;T = (T - 1) & S) {
  // hoge
  if(T == 0) break;
}

// n個からk個えらんだ集合を列挙
for (int x = (1 << k) - 1; x < (1 << n); ) {
    ...
    int t = x | (x - 1);
    x = (t + 1) | (((~ t & - ~ t) - 1) >> (__builtin_ctz(x) + 1));
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

