#include "template.cpp"

/*
 * ordにはトポロジカルソートされた順番で頂点番号が入る
 * DAGでなければ空の配列を返す
 */

vector<int> topological_sort(const vector<vector<int>>& G) {
    vector<int> ord;
    int n = G.size();
    vector<int> num(n, 0);
    REP(i, n) {
        for (auto u : G[i]) {
            ++num[u];
        }
    }
    queue<int> que;
    REP(i, n) {
      if (num[i] == 0) {
            que.push(i);
        }
    }
    for (int k = 0; !que.empty(); ++k) {
        int i = que.front(); que.pop();
        ord.emplace_back(i);
        for (auto u : G[i]) {
            if (--num[u] == 0) {
                que.push(u);
            }
        }
    }

    if(SZ(ord) != n) return {};
    else return ord;
}
