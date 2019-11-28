#include "mod.cpp"

vector<long long> fact;
void init_fact(int n, long long mod) {
    fact.assign(n+1, 1);
    for (int i = 2; i <= n; ++i) {
        (fact[i] = fact[i-1] * i) %= mod;
    }
}

// require init_fact(GREATER THAN OR EQUAL TO n, mod)
long long C(long long n, long long r, long long mod) {
    return (fact[n] * invm((fact[r] * fact[n-r]) % mod, mod)) % mod;
}
