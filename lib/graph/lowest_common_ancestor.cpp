#include "../template.cpp"

/**
 * @brief
 * 最小共通祖先（ダブリング）
 * 構築O(VlogV), クエリO(logV)
 *
 * LCA(G, root)で構築（無向木Gを、rootを根として向きづけしたときのLCAを構築）
 * query(u, v)で取得
 *
 * @author ゆきのん？
 * @date 2019/12
 */

struct LCA {

    /**
    * @brief コンストラクタ. O(nlog n)
    * @param[in] G 無向木.
    * @param[in] root 指定した根.
    */
    LCA(const vector<vector<int>>& G, int root = 0) :
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

    /**
    * @brief lca を取得する. O(log n);
    * @param[in] u, v: lca を求めたい2頂点.
    * @return u, v のlca.
    */
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