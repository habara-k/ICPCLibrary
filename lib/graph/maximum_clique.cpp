#include "template.cpp"

/**
 * @brief Maximum Clique
 * V,E <= 200くらいなら耐える
 * @author habara-k
 * @ref https://www.slideshare.net/wata_orz/ss-12131479
 * @date 2020/10/27
 * @param G 隣接行列
 * @return 最大クリークに選ばれた頂点
 */
vector<int> maximum_clique(vector<vector<bool>> g) {
    int n = g.size();
    vector<int> deg(n);
    int M = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            if (g[i][j]) ++deg[i], ++deg[j], ++M;
        }
    }
    vector<bool> used(n);
    int lim = sqrt(2*M);
    vector<int> ret;
    for (int t = 0; t < n; ++t) {
        int u = -1;
        for (int i = 0; i < n; ++i) {
            if (!used[i] and deg[i] < lim) {
                u = i;
                used[u] = true;
                break;
            }
        }
        vector<int> neighbor;
        if (u != -1) neighbor.push_back(u);
        for (int v = 0; v < n; ++v) {
            if (used[v]) continue;
            if (u == -1 || g[u][v]) {
                neighbor.push_back(v);
            }
        }
        int sz = neighbor.size();
        vector<int> bit(sz);
        for (int i = 0; i < sz; ++i) {
            for (int j = i+1; j < sz; ++j) {
                if (!g[neighbor[i]][neighbor[j]]) {
                    bit[i] |= 1 << j;
                    bit[j] |= 1 << i;
                }
            }
        }
        vector<int> dp(1<<sz);
        dp[0] = 1;
        int ma = 0, maxs = 0;
        for (int s = 1; s < 1<<sz; ++s) {
            int i = __builtin_ctz(s);
            dp[s] = dp[s & ~(1<<i)] and (bit[i] & s) == 0;
            if (!dp[s]) continue;
            if (chmax(ma, __builtin_popcount(s))) {
                maxs = s;
            }
        }
        if (SZ(ret) < ma) {
            ret.clear();
            for (int i = 0; i < sz; ++i) {
                if (maxs >> i & 1) ret.emplace_back(neighbor[i]);
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

