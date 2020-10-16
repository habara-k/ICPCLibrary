#include "../template.cpp"

/**
* @brief HL分解
* @author habara-k
* @date 2020/10/15
* @details 使い方
*   vector<vector<int>> g(n); // 無向木
*   HLDecomposition hld(g);
*/

struct HLDecomposition {

    /**
    * @brief コンストラクタ O(V)
    * @param[in] g: 無向木
    * @param[in] root: 根
    */
    HLDecomposition(const vector<vector<int>>& g, int root=0) :
            g(g), par(g.size()), size(g.size()), depth(g.size()),
            head(g.size()), vid(g.size()) {
        dfs(root, -1, 0);
        int k = 0;
        hld(root, root, k);
    }

    /**
    * @brief LCAを求める. O(logV)
    */
    int lca(int u, int v) const {
        for (;; v = par[head[v]]) {
            if (depth[head[u]] > depth[head[v]]) swap(u, v);
            if (head[u] == head[v]) {
                if (depth[u] > depth[v]) swap(u, v);
                return u;
            }
        }
    }

    /**
     * @brief 頂点u,v間の距離を取得する. O(logV)
     */
    int dist(int u, int v) {
        return depth[u] + depth[v] - 2 * depth[lca(u,v)];
    }

    /**
    * @brief 指定した2頂点間のパス上で更新クエリを実行する. O(logV)*O(q).
    * @param[in] u, v: 更新クエリを実行するパスの両端
    * @param[in] q: 実行する更新クエリ
    * @param[in] edge: 辺クエリか頂点クエリか
    * @details 使い方
    *     e.g. Range Update Query
    *     LazySegmentTree<int> segt(n);
    *       // 頂点v (辺クエリの場合は(par[v],v)) のデータがvid[v]に保存される
    *
    *     hld.update(u, v, [&](int s,int t){ segt.update(s, t, x); });
    *       // u, v 間の全ての頂点の値をx に変更する.
    *     hld.update(u, v, [&](int s,int t){ segt.update(s, t, x); }, true);
    *       // u, v 間の全ての辺の値をx に変更する.
    */
    template<class UpdateQuery>
    void update(int u, int v, const UpdateQuery& q, bool edge = false) const {
        for (;; v = par[head[v]]) {
            if (depth[head[u]] > depth[head[v]]) swap(u, v);
            if (head[u] == head[v]) {
                if (vid[u] > vid[v]) swap(u, v);
                q(vid[u] + edge, vid[v] + 1);
                break;
            } else {
                q(vid[head[v]], vid[v] + 1);
            }
        }
    }

    /**
    * @brief 指定した2頂点間のパス上で取得クエリを実行する. O(logV)*(O(q)+O(f))
    * @param[in] u, v: 取得クエリを実行するパスの両端
    * @param[in] q: 実行する取得クエリ
    * @param[in] f: 小分けにした区間から取得した値をマージする方法
    * @param[in] ident: fの単位元
    * @param[in] edge 辺クエリか頂点クエリか
    * @return 取得した値
    *
    * @details 使い方
    *     e.g. Range Minimum Query
    *     SegmentTree<int> segt;
    *       // 頂点v (辺クエリの場合は(par[v],v)) のデータがvid[v]に保存される
    *
    *     hld.query(u, v,
    *          [&](int s,int t){ return segt.query(s,t); },
    *          [&](int a,int b){ return min(a,b); }, INF);
    *       // u, v 間のパス上にある全ての頂点の値のminを取得する.
    */
    template<class Query, class MergeFunc, typename T>
    T query(int u, int v,
            const Query& q, const MergeFunc& f,
            const T& ident, bool edge = false) const {
        T ret = ident;
        for (;; v = par[head[v]]) {
            if (depth[head[u]] > depth[head[v]]) swap(u, v);
            if (head[u] == head[v]) {
                if (vid[u] > vid[v]) swap(u, v);
                return f(ret, q(vid[u] + edge, vid[v] + 1));
            } else {
                ret = f(ret, q(vid[head[v]], vid[v] + 1));
            }
        }
    }

private:
    const vector<vector<int>>& g;
    vector<int> par, size, depth, head, vid;
    // par[v]   : 頂点v の親頂点
    // size[v]  : 頂点v を根とした部分木の頂点数
    // depth[v] : 頂点v の深さ. 根の深さは0
    // head[v]  : HL分解した際に, 頂点v を含む区間の先頭に位置する頂点
    // vid[v]   : 頂点v に対応する内部index. HL分解した後の各区間上でvidは連続

    void dfs(int v, int p, int d) {
        par[v] = p; depth[v] = d; size[v] = 1;
        for (int u : g[v]) {
            if (u == p) continue;
            dfs(u, v, d+1);
            size[v] += size[u];
        }
    }
    void hld(int v, int h, int& k) {
        head[v] = h; vid[v] = k++;
        int ma = 0, id = -1;
        for (int u : g[v]) {
            if (u == par[v]) continue;
            if (chmax(ma, size[u])) id = u;
        }
        if (id == -1) return;
        hld(id, h, k);
        for (int u : g[v]) {
            if (u == id or u == par[v]) continue;
            hld(u, u, k);
        }
    }
};

