#include "binary_indexed_tree.cpp"

/**
 * 区間add区間sum
 */

template<typename T>
struct RangeAdd {
  BIT<T> bit1, bit2;

  RangeAdd(int n): bit1(BIT<T>(n+1)), bit2(BIT<T>(n+1)) {
  }

  // [l, r)にvalを加算
  void add(int l, int r, T val) {
    bit1.add(l, -l*val);
    bit1.add(r, r*val);
    bit2.add(l, val);
    bit2.add(r, -val);
  }

  // [0, idx)の和を取得
  T sum(int idx) {
    idx++;
    return bit1.sum(idx) + idx * bit2.sum(idx);
  }
};