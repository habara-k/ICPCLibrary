#include "mod.cpp"

vector<int64_t> fact;
void init_fact(int n, int64_t m) {
    fact.assign(n+1, 1);
    for (int i = 2; i <= n; ++i) {
        (fact[i] = fact[i-1] * i) %= m;
    }
}

// require init_fact(GREATER THAN OR EQUAL TO n, m)
int64_t C(int64_t n, int64_t r, int64_t m) {
    return (fact[n] * invm((fact[r] * fact[n-r]) % m, m)) % m;
}

// Stirling number
// Stirling(n, k) := the number of cases
//            to split n balls(distinguished)
//            into k boxes(not distinguished)
//            s.t. each box contains at least one ball.
//
// require init_fact(GREATER THAN OR EQUAL TO k, m)
int64_t Stirling(int64_t n, int64_t k, int64_t m) {
    int64_t ret = 0;
    for (int64_t l = 0; l <= k; ++l) {
        int64_t tmp = (C(k, l, m) * powm((k-l) % m, n, m)) % m;
        if (l & 1) tmp = (-tmp + m) % m;
        (ret += tmp) %= m;
    }
    return (ret *= invm(fact[k], m)) %= m;
}

// Bell number
// Bell(n, k) := the number of cases
//            to split n balls(distinguished)
//            into k boxes(not distinguished)
//
// require init_fact(GREATER THAN OR EQUAL TO k, m)
int64_t Bell(int64_t n, int64_t k, int64_t m) {
    int64_t ret = 0;
    for (int64_t l = 0; l <= k; ++l) {
        (ret += Stirling(n, l, m)) %= m;
    }
    return ret;
}

// Partition function
// Partition[k][n] := the number of cases
//            to split n balls(not distinguished)
//            into k boxes(not distinguished)
vector<vector<int64_t>> Part;
void init_partition(int64_t k, int64_t n, int64_t m) {
    Part.assign(k+1, vector<int64_t>(n+1, 0));
    Part[0][0] = 1;
    for (int i = 1; i <= k; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (j-i >= 0) {
                Part[i][j] = (Part[i-1][j] + Part[i][j-i]) % m;
            } else {
                Part[i][j] = Part[i-1][j];
            }
        }
    }
}
