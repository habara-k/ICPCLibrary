#include "./lowlink.cpp"

/**
 * @brief
 * 単純な無向グラフgを二重辺連結成分分解する
 *
 * 単純でないグラフについても
 *   自己ループ: 無視
 *   多重辺: メモっておいて、最後にunionfind
 * とすると二重辺連結成分がほぼ線形で求まる
 *
 * @author Md
 * @date 2020/10/21
 *
 */


struct TwoEdgeCC {
  vvi g;
  int n;
  Lowlink lowlink;
  vi comp;
  int id = 0;

  TwoEdgeCC(const vvi &g): g(g), lowlink(g) {
    n = SZ(g);
    comp.resize(n, -1);
    REP(i, n) {
      if(comp[i] == -1) {
        dfs(i, -1);
      }
    }
  }

  vvi build_graph() {
    vvi t(id);
    for(auto &e: lowlink.bridge) {
      int u = comp[e.first];
      int v = comp[e.second];
      t[u].push_back(v);
      t[v].push_back(u);
    }
    return t;
  }

private:
  void dfs(int now, int prev) {
    if(prev != -1 && lowlink.ord[prev] >= lowlink.low[now]) {
      comp[now] = comp[prev];
    } else {
      comp[now] = id;
      id++;
    }
    for(auto &nxt: g[now]) {
      if(comp[nxt] == -1) dfs(nxt, now);
    }
  }
};

