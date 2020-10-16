#include "../template.cpp"

struct MaximumIndependentSet {
  int n;
  int ma = 0;
  ll ans = 0;
  vector<P> d;
  vector<P> smalld;
  vector<ll> g;

  MaximumIndependentSet(const vector<ll> &g) : n(SZ(g)), g(g) {
    REP(i, n) {
      P tmp;
      tmp.second = i;
      tmp.first = __builtin_popcountll(g[i]);
      if (tmp.first <= 1) {
        smalld.emplace_back(tmp);
      } else {
        d.emplace_back(tmp);
      }
    }
  }

  int maximum_independent_set() {
    ll now = (1ll << n) - 1;
    ll sel = 0;
    REP(i, SZ(smalld)) {
      int val, idx;
      tie(val, idx) = smalld[i];
      if (!((now >> idx) & 1)) continue;
      sel |= (1ll << idx);
      now &= ~(1ll << idx);
      now &= ~(g[idx]);
    }
    dfs(0, now, sel);
    return ma;
  }

private:

  void dfs(int k, ll now, ll sel) {
    if (k == SZ(d)) {
      bool upd = chmax(ma, __builtin_popcountll(sel));
      if (upd) ans = sel;
      return;
    }
    int val, idx;
    tie(val, idx) = d[k];
    if (!((now >> idx) & 1)) {
      dfs(k + 1, now, sel);
      return;
    }
    now &= ~(1ll << idx);
    dfs(k + 1, now, sel);
    sel |= (1ll << idx);
    now &= ~(g[idx]);
    dfs(k + 1, now, sel);
  }
};

