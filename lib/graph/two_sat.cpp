#include "scc.cpp"

/**
 * @brief
 * 2-sat O(n)
 * add_hogeでリテラルを追加していって、solveで結果を得る
 */

struct TwoSat {
  int n;
  vector<vector<int>> g;

  TwoSat(int n): n(n) {
    g.resize(2*n);
  }

  int neg(int x) {
    if(x < n) return x + n;
    else return x - n;
  }

  void add_ifthen(int u, int v) {
    g[u].push_back(v);
    g[neg(v)].push_back(neg(u));
  }

  void add_or(int u, int v) {
    add_ifthen(neg(u), v);
  }

  void add_nand(int u, int v) {
    add_ifthen(u, neg(v));
  }

  void add_true(int u) {
    g[neg(u)].push_back(u);
  }

  void add_false(int u) {
    g[u].push_back(neg(u));
  }

  vector<int> solve() {
    StronglyConnectedComponents scc(g);
    scc.build();
    vector<int> result(n);
    REP(i, n) {
      if(scc.comp[i] == scc.comp[neg(i)]) return {};
      result[i] = scc.comp[i] > scc.comp[neg(i)];
    }
    return result;
  }
};

