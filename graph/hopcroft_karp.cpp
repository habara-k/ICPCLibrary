#include "template.cpp"

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
        for (int i = 0; i < g.size(); i++) {
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
                return (true);
            }
        }
        return (false);
    }

    int bipartite_matching() {
        int ret = 0;
        while (true) {
            bfs();
            vv.assign(g.size(), false);
            int flow = 0;
            for (int i = 0; i < g.size(); i++) {
                if (!used[i] && dfs(i)) ++flow;
            }
            if (flow == 0) return ret;
            ret += flow;
        }
    }
};
