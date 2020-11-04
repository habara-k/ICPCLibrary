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
 * 区間篩の要領で素因数分解することもできる(例: Prime-Factor Prime ← 2つ目のテストにいれてます)
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
