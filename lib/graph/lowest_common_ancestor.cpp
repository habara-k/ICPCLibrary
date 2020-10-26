#include "../template.cpp"

/**
 * @brief LCA
 * @author habara-k
 * @date 2020/10/26
 * @usage
 * vector<vector<int>> g(n);
 * int root;
 * LCA lca(g, root); // rootを根としてLCAを構築. O(nlog n)
 *
 * int u, v;
 * lca.get(u, v); // u,vのLCAを取得. O(log n)
 */
struct LCA {

    LCA(const vector<vector<int>>& G, int root) :
            n(G.size()), log2_n(log2(n)), depth(n),
            par(log2_n+1, vector<int>(n,-1)) {
        dfs(G, root, -1, 0);
        for (int k = 0; k < log2_n; ++k) {
            for (int v = 0; v < n; ++v) {
                if (par[k][v] != -1) {
                    par[k+1][v] = par[k][par[k][v]];
                }
            }
        }
    }

    int query(int u, int v) {
        if (depth[u] > depth[v]) swap(u, v);
        for (int k = 0; k <= log2_n; ++k) {
            if ((depth[v] - depth[u]) >> k & 1) {
                v = par[k][v];
            }
        }
        if (u == v) return u;
        for (int k = log2_n; k >= 0; --k) {
            if (par[k][u] != par[k][v]) {
                u = par[k][u];
                v = par[k][v];
            }
        }
        return par[0][u];
    }

private:
    int n, log2_n;
    vector<int> depth;
    vector<vector<int>> par;

    void dfs(const vector<vector<int>>& G, int v, int p, int d) {
        depth[v] = d;
        par[0][v] = p;
        for (auto to : G[v]) {
            if (to != p) dfs(G, to, v, d+1);
        }
    }
};
