#include "../template.cpp"
#include "centroid.cpp"

/**
 * @brief 木のハッシュ化
 * @author habara-k
 * @date 2020/10/14
 * @details 使い方
 *   vector<vector<int>> g;
 *   int seed = 0;
 *   auto hash = RootedTreeHash(g, seed).get();
 */
struct TreeHash {
    using uint = uint64_t;

    /**
     * @brief コンストラクタ. O(|n|)
     * @param[in] g ハッシュ化する木
     * @param[in] seed ハッシュ化に使うシード
     */
    TreeHash(const vector<vector<int>>& g, int seed=0) : g(g) {
        int n = g.size();
        mt19937 random(seed);
        uniform_int_distribution<uint> dist(2, MASK61 - 2);
        for (int i = 0; i < n; ++i) base.emplace_back(dist(random));
    }

    /**
     * @brief ハッシュの計算. O(|n|)
     */
    uint get() {
        vector<uint> hash;
        for (int root : centroid(g)) {
            hash.emplace_back(dfs(root, -1, 0));
        }
        return *min_element(hash.begin(), hash.end());
    }

private:
    vector<uint> base;
    vector<vector<int>> g;
    static const uint MASK30 = (1LL << 30) - 1,
            MASK31 = (1LL << 31) - 1,
            MASK61 = (1LL << 61) - 1;

    static uint mul(uint a, uint b) {
        uint au = a >> 31, ad = a & MASK31,
                bu = b >> 31, bd = b & MASK31;
        uint m = au * bd + ad * bu;
        uint mu = m >> 30, md = m & MASK30;

        return mod(au * bu * 2 + mu + (md << 31) + ad * bd);
    }

    static uint mod(uint x) {
        uint xu = x >> 61, xd = x & MASK61;
        uint ret = xu + xd;
        if (ret >= MASK61) ret -= MASK61;
        return ret;
    }

    uint dfs(int u, int p, int d) {
        uint hash = 1;
        for (int v : g[u]) {
            if (v == p) continue;
            hash = mul(hash, dfs(v, u, d+1));
        }
        return mod(hash + base[d]);
    }
};

