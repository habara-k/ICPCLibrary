#include "../template.cpp"

/**
* @brief 文字列のハッシュ化
* @author habara-k
* @date 2020/04/26
* @details 使い方
*   using uint = RollingHash::uint;
*   uint base = RollingHash::gen_base();
*
*   string t; cin >> t;
*   RollingHash hash(t, base);
*
*   cout << hash.get(0, t.size()) << endl;
*/

struct RollingHash {
    using uint = uint64_t;

    /**
    * @brief コンストラクタ. O(|s|)
    * @param[in] s ハッシュ化する文字列(or vector).
    * @param[in] base ハッシュ化に使う基数. RollingHash::gen_base で作る.
    */
    template<typename S>
    RollingHash(const S& s, uint base) {
        int n = s.size();
        hash.assign(n+1, 0);
        pow.assign(n+1, 1);
        for (int i = 0; i < n; ++i) {
            hash[i+1] = mod(mul(hash[i], base) + s[i]);
            pow[i+1] = mul(pow[i], base);
        }
    }

    /**
    * @brief ハッシュを計算する. O(1)
    * @param[in] l, r ハッシュを計算したい区間.
    * @return 区間[l, r) のハッシュ.
    */
    uint get(int l, int r) const {
        return mod(hash[r] + MASK61 - mul(hash[l], pow[r - l]));
    }

    /**
    * @brief 基数を生成する. O(1)
    * @return ランダムな基数.
    */
    static uint gen_base() {
        mt19937 random{random_device{}()};
        uniform_int_distribution<uint> dist(2, MASK61-2);
        return dist(random);
    }

private:
    vector<uint> hash, pow;
    static const uint MASK30 = (1LL<<30)-1,
                      MASK31 = (1LL<<31)-1,
                      MASK61 = (1LL<<61)-1;

    static uint mul(uint a, uint b) {
        uint au = a >> 31, ad = a & MASK31,
             bu = b >> 31, bd = b & MASK31;
        uint m = au * bd + ad * bu;
        uint mu = m >> 30, md = m & MASK30;

        return mod(au*bu*2 + mu + (md<<31) + ad*bd);
    }
    static uint mod(uint x) {
        uint xu = x >> 61, xd = x & MASK61;
        uint ret = xu + xd;
        if (ret >= MASK61) ret -= MASK61;
        return ret;
    }
};
