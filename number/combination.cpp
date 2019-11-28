#include "mod.cpp"

vector<int64_t> fact;
void init_fact(int n, int64_t mod) {
    fact.assign(n+1, 1);
    for (int i = 2; i <= n; ++i) {
        (fact[i] = fact[i-1] * i) %= mod;
    }
}

// require init_fact(GREATER THAN OR EQUAL TO n, mod)
int64_t C(int64_t n, int64_t r, int64_t mod) {
    return (fact[n] * invm((fact[r] * fact[n-r]) % mod, mod)) % mod;
}
