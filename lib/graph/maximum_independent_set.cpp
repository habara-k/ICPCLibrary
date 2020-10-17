#include "../template.cpp"

// 最大独立集合 40頂点は行ける それ以上はわからん
// gは隣接行列 各行はbitでもつ
// 呼ぶときはnowをn頂点のbitが立った状態にする（(1ll<<n)-1)
// author: Md
// date: 2020/10/17
ll maximum_independent_set(int n, ll now, const vector<ll> &g) {
  if(now == 0) return 0;

  REP(i, n) {
    if((now>>i)&1) {
      int d = __builtin_popcountll(g[i] & now);
      if(d <= 1) return maximum_independent_set(n, now & ~(1ll<<i) & ~g[i], g) | (1ll<<i);
    }
  }

  int max_degree = 0;
  int argma = -1;
  REP(i, n) {
    if((now>>i)&1) {
      bool upd = chmax(max_degree, __builtin_popcountll(g[i]));
      if(upd) argma = i;
    }
  }

  if(max_degree == 2) {
    return maximum_independent_set(n, now & ~(1ll<<argma) & ~g[argma], g) | (1ll<<argma);
  }

  ll tmp1 = maximum_independent_set(n, now & ~(1ll<<argma) & ~g[argma], g) | (1ll<<argma);
  ll tmp2 = maximum_independent_set(n, now & ~(1ll<<argma), g);
  ll cnt1 = __builtin_popcountll(tmp1);
  ll cnt2 = __builtin_popcountll(tmp2);

  return cnt1 > cnt2 ? tmp1 : tmp2;
}