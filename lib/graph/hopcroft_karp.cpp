#include "template.cpp"

/**
 * @brief
 * HopcroftKarp(二部グラフの最大マッチング)
 * O(|E| sqrt(|V|))
 * |最大マッチング| + |最小辺カバー| = |V|
 * （二部グラフについて）|最大マッチング| = |最小点カバー|
 * |最大安定集合| + |最小点カバー| = |V|
 *
 * @author Md
 * @date 2019/12
 * @details
 * 2020/04/14 コメント追加 by Md
 */

struct HopcroftKarp {
    vector<vector<int>> g;
    vector<int> d, mch;
    vector<bool> used, vv;

    HopcroftKarp(int n, int m) : g(n), mch(m, -1), used(n) {}

    void add_edge(int u, int v) {
        g[u].push_back(v);
    }

    void bfs() {
        d.assign(g.size(), -1);
        queue<int> que;
        for (int i = 0; i < (int)(g.size()); i++) {
            if (!used[i]) {
                que.emplace(i);
                d[i] = 0;
            }
        }

        while (!que.empty()) {
            int a = que.front();
            que.pop();
            for (auto &b : g[a]) {
                int c = mch[b];
                if (c >= 0 && d[c] == -1) {
                    d[c] = d[a] + 1;
                    que.emplace(c);
                }
            }
        }
    }

    bool dfs(int a) {
        vv[a] = true;
        for (auto &b : g[a]) {
            int c = mch[b];
            if (c < 0 || (!vv[c] && d[c] == d[a] + 1 && dfs(c))) {
                mch[b] = a;
                used[a] = true;
                return true;
            }
        }
        return false;
    }

    int bipartite_matching() {
        int ret = 0;
        while (true) {
            bfs();
            vv.assign(g.size(), false);
            int flow = 0;
            for (int i = 0; i < (int)(g.size()); i++) {
                if (!used[i] && dfs(i)) ++flow;
            }
            if (flow == 0) return ret;
            ret += flow;
        }
    }
};
