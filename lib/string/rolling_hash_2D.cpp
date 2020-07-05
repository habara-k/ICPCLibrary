#include "../template.cpp"

/**
* @brief 2次元文字列のハッシュ化
* @author habara-k
* @date 2020/07/05
*/

struct RollingHash2D {
    using uint = uint64_t;

    /**
    * @brief コンストラクタ. O(|vs|)
    * @param[in] vs ハッシュ化する文字列のベクトル(or matrix).
    * @param[in] base1, base2 ハッシュ化に使う基数. RollingHash2D::gen_base で作る.
    * @details 使い方
    *   auto base1 = RollingHash2D::gen_base(),
    *        base2 = RolligHash2D::gen_base();
    *
    *   vector<string> t;
    *   RollingHash2D hash(t, base1, base2);
    */
    template<typename VS>
    RollingHash2D(const VS &vs, uint base1, uint base2) {
        int n = vs.size();
        int m = vs[0].size();
        hash.resize(n + 1);
        for (int i = 0; i <= n; ++i) hash[i].resize(m + 1);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                hash[i + 1][j + 1] = mod(mul(hash[i + 1][j], base2) + vs[i][j]);
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                hash[i + 1][j + 1] = mod(mul(hash[i][j + 1], base1) + hash[i + 1][j + 1]);
            }
        }

        pow1.assign(n + 1, 1);
        for (int i = 0; i < n; ++i) {
            pow1[i + 1] = mul(pow1[i], base1);
        }
        pow2.assign(m + 1, 1);
        for (int j = 0; j < m; ++j) {
            pow2[j + 1] = mul(pow2[j], base2);
        }
    }

    /**
    * @brief ハッシュを計算する. O(1)
    * @param[in] i0, j0, i1, j1 ハッシュを計算したい区間.
    * @return 区間[(i0,j0), (i1,j1)) のハッシュ.
    * @details 使い方
    *   cout << hash.get(0, 0, t.size(), t[0].size()) << endl;
    */
    long long get(int i0, int j0, int i1, int j1) {
        uint a = mod(hash[i1][j1] + MASK61 - mul(hash[i1][j0], pow2[j1 - j0]));
        uint b = mod(hash[i0][j1] + MASK61 - mul(hash[i0][j0], pow2[j1 - j0]));
        return mod(a + MASK61 - mul(b, pow1[i1 - i0]));
    }

    /**
    * @brief 基数を生成する. O(1)
    * @return ランダムな基数.
    * @details 使い方
    *   auto base = RollingHash::gen_base();
    */
    static uint gen_base() {
        mt19937 random{random_device{}()};
        uniform_int_distribution <uint> dist(2, MASK61 - 2);
        return dist(random);
    }

private:
    vector<vector<uint>> hash;
    vector<uint> pow1, pow2;
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
};
