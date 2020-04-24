#include "../template.cpp"

// verify: https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/14/ALDS1_14_B

/**
 * @brief
 * ロリハ
 * 部分列のハッシュ値をO(1) で返す. 何回もアクセスする場合はメモ化してね
 * @author habara-k
 * @date 2019/04/24
 * @param[in] s 文字列. vector でも可
 *
 * @param[in] l, r 区間
 * @return pair<ll,ll> [l, r) に対応するハッシュ値(ペア)を返す.
 */

struct RollingHash {
    const int base = 9973;
    const int mod[2] = {999999937, 1000000007};
    vector<int> s;
    vector<ll> hash[2], pow[2];

    template<class S>
    RollingHash(const S &s) {
        int n = s.size();
        for (int id = 0; id < 2; ++id) {
            hash[id].assign(n+1, 0);
            pow[id].assign(n+1, 1);
            for (int i = 0; i < n; ++i) {
                hash[id][i+1] = (hash[id][i] * base + s[i]) % mod[id];
                pow[id][i+1] = pow[id][i] * base % mod[id];
            }
        }
    }

    // get hash of s[l:r)
    pair<ll,ll> get(int l, int r) {
        ll ret[2];
        for (int id = 0; id < 2; ++id) {
            ret[id] = hash[id][r] - hash[id][l] * pow[id][r - l] % mod[id];
            if (ret[id] < 0) ret[id] += mod[id];
        }
        return { ret[0], ret[1] };
    }
};
