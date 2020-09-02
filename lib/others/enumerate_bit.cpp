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
