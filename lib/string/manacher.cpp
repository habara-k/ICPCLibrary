#include "../template.cpp"

/*
 * @brief 文字列の各位置を中心とする回文長をO(|S|)で求める
 * @detail 偶数長の回文について同じことをしたいときははabcde -> $a$b$c$d$e$ みたいな変換をして使う
 * @author Md
 * @date 2020/07/10
 */
vi Manacher(string s) {
  int c = 0, n = SZ(s); // c: すでに見つけた回文のうち、右端が最も右に有るようなもの
  vi r(n, 1);
  REP(i, n) {
    int l = c - (i - c);
    if(i + r[l] < c + r[c]) { // 位置cの回文に位置lの回文が含まれていれば、r[l]とr[i]は一致する
      r[i] = r[l];
    } else {
      int j = c + r[c] - i; // cに含まれている部分は大丈夫(そうでなければif節に行くはず
      while(i - j >= 0 && i + j < n && s[i-j] == s[i+j]) ++j; // 愚直に求める
      r[i] = j;
      c = i;
    }
  }
  return r;
}
