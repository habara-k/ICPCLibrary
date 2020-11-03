#include "../template.cpp"

/**
 * @brief
 * エラトステネスの篩 O(nloglogn)
 *
 * ・区間篩
 * R <= 10^9, R - L <= 10^6 とかのときに
 * [L, R]の素数判定をする
 * sqrt(R)までを普通にふるって、こいつを使ってLからRをふるえばよい
 *
 * ・素因数分解
 * 素因数分解も篩でやることができる(篩をしているときに、nの素因数を一つもたせる)
 *
 * 区間篩の要領で素因数分解することもできる(Prime-Factor Prime: 下の方にコード例を載せておく)
 *
 * @author Md
 * @date 2020/11/04
 */

vector<bool> sieve(int n) {
  vector<bool> prime(n+1, true);
  prime[0] = false;
  prime[1] = false;
  for(int i=2;i<=n;++i) {
    if(prime[i]) {
      for(int j=2*i;j<=n;j+=i) {
        prime[j] = false;
      }
    }
  }
  return prime;
}

/* 区間に対して素因数分解
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);

  int l, r;
  cin >> l >> r;
  if (r == 1) {
    cout << 0 << endl;
    return 0;
  } else if (l == 1) {
    l++;
  }

  ll ma = 1;
  while (ma * ma <= r) ma++;

  vector<bool> v = sieve(ma);
  vector<int> primes;
  for (int i = 2; i <= ma; ++i) {
    if (v[i]) primes.push_back(i);
  }


  vvi v2(r - l + 1);
  for (auto &p: primes) {
    int j = (l / p) * p;
    while(j < l) j += p;
    for (; j <= r; j+=p) {
      v2[j - l].push_back(p);
    }
  }

  vi cnt(r - l + 1);
  for (int j = l; j <= r; ++j) {
    int val = j;
    for(auto &e: v2[j-l]) {
      while(val % e == 0) {
        val /= e;
        cnt[j-l]++;
      }
    }
    if(val != 1) cnt[j-l]++;
  }


  int ans = 0;
  REP(i, r-l+1) {
    ans += v[cnt[i]];
  }
  cout << ans << endl;

  return 0;
}
 */
