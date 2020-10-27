#include "../template.cpp"

/**
 * @brief 2次元文字列のハッシュ化
 * @author habara-k
 * @date 2020/10/28
 * @usage
 *   auto base1 = RollingHash2D::gen_base(),
 *        base2 = RolligHash2D::gen_base();
 *   vector<string> vs;
 *   RollingHash2D hash(vs, base1, base2);
 *   hash.get(i1, j1, i2, j2);
 */
struct RollingHash2D {
    using u64 = uint64_t;
    using i128 = __int128_t;

    template<typename VS>
    RollingHash2D(const VS &vs, u64 base1, u64 base2) {
        int n = vs.size();
        int m = vs[0].size();
        hash.assign(n+1, vector<u64>(m+1));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                hash[i+1][j+1] = mul(hash[i+1][j], base2) + vs[i][j];
                if (hash[i+1][j+1] >= MOD) hash[i+1][j+1] -= MOD;
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                hash[i+1][j+1] = mul(hash[i][j+1], base1) + hash[i+1][j+1];
                if (hash[i+1][j+1] >= MOD) hash[i+1][j+1] -= MOD;
            }
        }

        pow1.assign(n+1, 1);
        for (int i = 0; i < n; ++i) {
            pow1[i + 1] = mul(pow1[i], base1);
        }
        pow2.assign(m+1, 1);
        for (int j = 0; j < m; ++j) {
            pow2[j + 1] = mul(pow2[j], base2);
        }
    }

    long long get(int i0, int j0, int i1, int j1) {
        u64 a = hash[i1][j1] + MOD - mul(hash[i1][j0], pow2[j1-j0]);
        if (a >= MOD) a -= MOD;
        u64 b = hash[i0][j1] + MOD - mul(hash[i0][j0], pow2[j1-j0]);
        if (b >= MOD) b -= MOD;
        u64 ret = a + MOD - mul(b, pow1[i1-i0]);
        return ret >= MOD ? ret - MOD : ret;
    }

    static u64 gen_base() {
        mt19937 random{random_device{}()};
        uniform_int_distribution <u64> dist(2, MOD - 2);
        return dist(random);
    }

private:
    vector<vector<u64>> hash;
    vector<u64> pow1, pow2;
    static const u64 MOD = (1ul << 61) - 1;

    static u64 mul(i128 a, i128 b) {
        i128 t = a * b;
        t = (t >> 61) + (t & MOD);
        if (t >= MOD) t -= MOD;
        return t;
    }
};

