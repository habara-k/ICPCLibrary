#include "mod.cpp"

vector<ll> fact;
void init_fact(int n, ll m) {
    fact.assign(n+1, 1);
    for (int i = 2; i <= n; ++i) {
        (fact[i] = fact[i-1] * i) %= m;
    }
}

// require init_fact(GREATER THAN OR EQUAL TO n, m)
ll C(ll n, ll r, ll m) {
    return (fact[n] * invm((fact[r] * fact[n-r]) % m, m)) % m;
}

// Stirling number
// Stirling(n, k) := the number of cases
//            to split n balls(distinguished)
//            into k boxes(not distinguished)
//            s.t. each box contains at least one ball.
//
// require init_fact(GREATER THAN OR EQUAL TO k, m)
ll Stirling(ll n, ll k, ll m) {
    ll ret = 0;
    for (ll l = 0; l <= k; ++l) {
        ll tmp = (C(k, l, m) * powm((k-l) % m, n, m)) % m;
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
ll Bell(ll n, ll k, ll m) {
    ll ret = 0;
    for (ll l = 0; l <= k; ++l) {
        (ret += Stirling(n, l, m)) %= m;
    }
    return ret;
}

// Partition function
// Partition[k][n] := the number of cases
//            to split n balls(not distinguished)
//            into k boxes(not distinguished)
vector<vector<ll>> Part;
void init_partition(ll k, ll n, ll m) {
    Part.assign(k+1, vector<ll>(n+1, 0));
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
