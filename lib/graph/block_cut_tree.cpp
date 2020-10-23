#include "./lowlink.cpp"

/**
 * @brief
 * 二重頂点連結成分分解する
 * edgeにちゃんとidxを載せたら線形になるけど、面倒なのでlogを載せています...
 *
 * verify先がなくてこまった
 * あまり信用しない
 *
 * @input
 * g: 無向単純グラフ
 * mp: 頂点のペアから辺番号への写像（u < vなるペアu, vについてmp[{u, v}]を登録)
 *
 * @output
 * components: 二重頂点連結成分ごとに辺の配列が格納される
 *
 * @author Md
 * @date 2020/10/21
 */

struct BlockCutTree {
  int n;
  vvi g;
  map<P, int> mp;
  Lowlink lowlink;
  vector<bool> sel;
  vector<vector<int>> components;
  vector<int> tmp_edges;

  BlockCutTree(const vvi &g, const map<P, int> mp): g(g), lowlink(g), mp(mp) {
    int n = SZ(g);
    sel.resize(n, false);
    REP(i, n) {
      if(!sel[i]) dfs(i, -1);
    }
  }

  void build() {
    REP(i, n) {

    }
  }

private:
  void dfs(int now, int prev) {
    sel[now] = true;
    bool tmp = false;
    for(auto &nxt: g[now]) {
      int now_nxt_num = -1;
      if(now < nxt) now_nxt_num = tmp_edges.emplace_back(mp[{now, nxt}]);
      else now_nxt_num = tmp_edges.emplace_back(mp[{nxt, now}]);
      if(nxt == prev && !tmp) {
        tmp = true;
        continue;
      }
      if(!sel[nxt] || lowlink.ord[now] > lowlink.ord[nxt]) {
        tmp_edges.emplace_back(now_nxt_num);
      }
      if(!sel[nxt]) {
        dfs(nxt, now);
        if(lowlink.low[nxt] >= lowlink.ord[now]) {
          components.emplace_back();
          while(1) {
            int edge_num = tmp_edges.back();
            components.back().emplace_back(edge_num);
            tmp_edges.pop_back();
            if(edge_num == now_nxt_num) {
              break;
            }
          }
        }
      }
    }

  }
};

