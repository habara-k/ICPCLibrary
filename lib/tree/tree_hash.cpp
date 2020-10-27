#include "../template.cpp"
#include "centroid.cpp"

/**
 * @brief 木のハッシュ化
 * @author habara-k
 * @date 2020/10/28
 * @usage
 *   vector<vector<int>> g;
 *   int seed = 0;
 *   auto hash = RootedTreeHash(g, seed).get();
 */
struct TreeHash {
    using u64 = uint64_t;
    using i128 = __int128_t;

    TreeHash(const vector<vector<int>>& g, int seed=0) : g(g) {
        int n = g.size();
        mt19937 random(seed);
        uniform_int_distribution<u64> dist(2, MOD-2);
        for (int i = 0; i < n; ++i) base.emplace_back(dist(random));
    }

    u64 get() {
        vector<u64> hash;
        for (int root : centroid(g)) {
            hash.emplace_back(dfs(root, -1, 0));
        }
        return *min_element(hash.begin(), hash.end());
    }

private:
    vector<u64> base;
    vector<vector<int>> g;
    static const u64 MOD = (1ul << 61) - 1;

    static u64 mul(i128 a, i128 b) {
        i128 t = a * b;
        t = (t >> 61) + (t & MOD);
        if (t >= MOD) t -= MOD;
        return t;
    }

    u64 dfs(int u, int p, int d) {
        u64 hash = 1;
        for (int v : g[u]) {
            if (v == p) continue;
            hash = mul(hash, dfs(v, u, d+1));
        }
        hash += base[d];
        return hash >= MOD ? hash - MOD : hash;
    }
};

