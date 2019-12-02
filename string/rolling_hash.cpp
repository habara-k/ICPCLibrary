#include "../template.cpp"

struct RollingHash {
    const int base = 9973;
    const int mod[2] = {999999937, 1000000007};
    vector<int> s;
    vector<ll> hash[2], pow[2];

    RollingHash(const vector<int> &cs) : s(cs) {
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
    ll get(int l, int r, int id = 0) {
        ll res = hash[id][r] - hash[id][l] * pow[id][r-l] % mod[id];
        if (res < 0) res += mod[id];
        return res;
    }
};
