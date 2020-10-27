#include "../template.cpp"

/**
 * @brief 文字列のハッシュ化
 * @author habara-k
 * @date 2020/10/28
 * @usage
 *   auto base = RollingHash::gen_base();
 *   string s; cin >> s;
 *   RollingHash hash(s, base);   // O(|s|)
 *   hash.get(l, r);   // s[l,r)のハッシュ. O(1)
 */
struct RollingHash {
    using u64 = uint64_t;
    using i128 = __int128_t;

    template<typename S>
    RollingHash(const S &s, u64 base) {
        int n = s.size();
        hash.assign(n+1, 0);
        pow.assign(n+1, 1);
        for (int i = 0; i < n; ++i) {
            hash[i+1] = mul(hash[i], base) + s[i];
            if (hash[i+1] >= MOD) hash[i+1] -= MOD;
            pow[i+1] = mul(pow[i], base);
        }
    }

    u64 get(int l, int r) const {
        u64 ret = hash[r] + MOD - mul(hash[l], pow[r-l]);
        return ret >= MOD ? ret - MOD : ret;
    }

    static u64 gen_base() {
        mt19937 random{random_device{}()};
        uniform_int_distribution<u64> dist(2, MOD-2);
        return dist(random);
    }

private:
    vector<u64> hash, pow;
    static const u64 MOD = (1ul << 61) - 1;

    static u64 mul(i128 a, i128 b) {
        i128 t = a * b;
        t = (t >> 61) + (t & MOD);
        if (t >= MOD) t -= MOD;
        return t;
    }
};

