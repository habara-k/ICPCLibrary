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

// Stirling number O(klogn)
// Stirling(n, k) := the number of cases
//            to split n balls(distinguished)
//            into k boxes(not distinguished)
//            s.t. each box contains at least one ball.
//
// S(n, k) = S(n-1, k-1) + k * S(n-1, k) : n, kまでのテーブルを作りたいときはこっち
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

// スターリング数の応用(けんちょんさんの写像12相のブログ）
// ・「各グループにつきr個以上」の制限がある場合
// S'(n, k) = C(n-1, r-1) * S'(n-r, k-1) + k * S'(n-1, k)
// 
// ・玉がn個あるうちのいくつかを選んでkグループに分ける場合
// S'(n, k) = S'(n-1, k-1) + (k+1) * S'(n-1, k)

// Bell number O(n^2)
// Bell(n, k) := the number of cases
//            to split n balls(distinguished)
//            into k boxes(not distinguished)
//
// B(n, k) = S(n, 0) + S(n, 1) + ... + S(n, k)
//
// B(n+1) := B(n+1, n+1) = Σ[i=0; n]{C(n, i) * B(i)}
//
// require init_fact(GREATER THAN OR EQUAL TO k, m)
ll Bell(ll n, ll k, ll m) {
    ll ret = 0;
    for (ll l = 0; l <= k; ++l) {
        (ret += Stirling(n, l, m)) %= m;
    }
    return ret;
}

// Partition function O(nk)
// Partition[k][n] := the number of cases
//            to split n balls(not distinguished)
//            into k boxes(not distinguished)
//
// P(n, k) = P(n, k-1) + P(n-k, k)
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

// 謎漸化式でO(n * sqrt(n))
// けんちょんさんの写像12相ブログ
vector<ll> P2;
void partition_fast(ll n, ll m) {
    P2[0] = 1;
    for(int i=1;i<100;++i) {
        for(int j=1, sign = 1; i - (j*j*3-j)/2 >= 0; ++j, sign *= -1) {
            P2[i] += P[i-(j*j*3-j)/2] * sign;
            if(i - (j*j*3+j)/2 >= 0) P[i] += P[i-(j*j*3+j)/2] * sign;
        }
    }
}
