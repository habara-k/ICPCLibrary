#include "../template.cpp"

/**
 * @brief LCA
 * @author habara-k
 * @date 2020/10/15
 */
struct LCA {

    /**
     * @brief コンストラクタ. O(VlogV)
     * @param[in] g 無向木
     * @param[in] root 根
     */
    LCA(const vector<vector<int>> &g, int root = 0) :
            n(g.size()), m(log2(n)), depth(n),
            g(g), par(m + 1, vector<int>(n, -1)) {

        dfs(root, -1, 0);

        for (int k = 0; k < m; ++k) {
            for (int v = 0; v < n; ++v) {
                if (par[k][v] != -1) {
                    par[k + 1][v] = par[k][par[k][v]];
                }
            }
        }
    }

    /**
     * @brief lca を取得する. O(logV)
     */
    int query(int u, int v) {
        if (depth[u] > depth[v]) swap(u, v);
        for (int k = 0; k <= m; ++k) {
            if ((depth[v] - depth[u]) >> k & 1) {
                v = par[k][v];
            }
        }
        if (u == v) return u;
        for (int k = m; k >= 0; --k) {
            if (par[k][u] != par[k][v]) {
                u = par[k][u];
                v = par[k][v];
            }
        }
        return par[0][u];
    }

    /**
     * @brief 頂点u,v間の距離を取得する. O(logV)
     */
    int dist(int u, int v) {
        return depth[u] + depth[v] - 2 * depth[query(u,v)];
    }

private:
    int n, m;
    vector<int> depth;
    vector<vector<int>> g, par;

    void dfs(int u, int p, int d) {
        depth[u] = d;
        par[0][u] = p;
        for (auto v : g[u]) {
            if (v != p) dfs(v, u, d + 1);
        }
    }
};

