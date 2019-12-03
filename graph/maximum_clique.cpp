#include "template.cpp"

int maximum_clique(const vector<vector<bool>>& G) {
    // G: 隣接行列, 無向グラフ
    int n = G.size();
    vector<int> deg(n);
    int M = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            ++deg[i], ++deg[j], ++M;
        }
    }
    vector<vector<bool>> g = G;
    vector<bool> used(n);

    int lim = sqrt(2*M), ret = 0;

    for (int t = 0; t < n; ++t) {
        int u = -1;
        for (int i = 0; i < n; ++i) {
            if (!used[i] && deg[i] < lim) {
                u = i;
                used[u] = true;
                break;
            }
        }

        vector<int> neighbor;
        if (u != -1) neighbor.push_back(u);
        for (int v = 0; v < n; ++v) if (!used[v]) {
            if (u == -1 || g[u][v]) {
                neighbor.push_back(v);
            }
        }

        int sz = neighbor.size();
        vector<int> bit(sz);
        for(int i = 0; i < sz; i++) {
            for(int j = i+1; j < sz; j++) {
                if(!g[neighbor[i]][neighbor[j]]) {
                    bit[i] |= 1 << j;
                    bit[j] |= 1 << i;
                }
            }
        }

        vector<int> dp(1<<sz);
        dp[0] = 1;
        for (int s = 1; s < 1<<sz; ++s) {
            int i = __builtin_ffs(s) - 1;

            if (dp[s] = dp[s & ~(1<<i)] && (bit[i] & s) == 0) {
                ret = max(ret, __builtin_popcount(s));
            }
        }

        if (u == -1) break;

        for (auto v : neighbor) {
            --deg[v], --deg[u];
            g[u][v] = g[v][u] = false;
        }
    }

    return ret;
}
