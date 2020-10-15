#include "../template.cpp"

/**
 * @brief 木の重心列挙. O(n)
 * @author habara-k
 * @date 2020/10/14
 */
vector<int> centroid(const vector<vector<int>>& g) {
    const int n = g.size();
    vector<int> sz(n,1), ret;
    function<int(int,int)> dfs = [&](int u,int p) {
        bool isCent = true;
        for (int v : g[u]) {
            if (v == p) continue;
            sz[u] += dfs(v, u);
            if (sz[v] > n / 2) isCent = false;
        }
        if (n - sz[u] > n / 2) isCent = false;
        if (isCent) ret.emplace_back(u);
        return sz[u];
    };
    dfs(0, -1);
    return ret;
}

