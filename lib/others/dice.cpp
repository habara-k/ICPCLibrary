#include "../template.cpp"

// 0: 上, 1: 手前, 2: 左, 3: 奥, 4: 右, 5: 下
struct Dice {
  vi face = {1, 3, 2, 4, 5, 6};

  vvi cand = {
      {1, 2, 4, 5, 3, 6},
      {1, 3, 2, 4, 5, 6},
      {1, 4, 5, 3, 2, 6},
      {1, 5, 3, 2, 4, 6},
      {2, 1, 3, 6, 4, 5},
      {2, 3, 6, 4, 1, 5},
      {2, 4, 1, 3, 6, 5},
      {2, 6, 4, 1, 3, 5},
      {3, 1, 5, 6, 2, 4},
      {3, 2, 1, 5, 6, 4},
      {3, 5, 6, 2, 1, 4},
      {3, 6, 2, 1, 5, 4},
      {4, 1, 2, 6, 5, 3},
      {4, 2, 6, 5, 1, 3},
      {4, 5, 1, 2, 6, 3},
      {4, 6, 5, 1, 2, 3},
      {5, 1, 4, 6, 3, 2},
      {5, 3, 1, 4, 6, 2},
      {5, 4, 6, 3, 1, 2},
      {5, 6, 3, 1, 4, 2},
      {6, 2, 3, 5, 4, 1},
      {6, 3, 5, 4, 2, 1},
      {6, 4, 2, 3, 5, 1},
      {6, 5, 4, 2, 3, 1}
  };

  void init(vi v) {
    swap(face, v);
  }

  // 上と手前の値から構築
  bool init(int val0, int val1) {
    if(val0 == val1 || val0 + val1 == 7) return false;
    for(auto &v: cand) {
      if(val0 == v[0] && val1 == v[1]) {
        face = v;
        break;
      }
    }
    return true;
  }

  // 左に転がす
  void rotl() {
    vi newface = {face[4], face[1], face[0], face[3], face[5], face[2]};
    swap(face, newface);
  }

  // 右に転がす
  void rotr() {
    vi newface = {face[2], face[1], face[5], face[3], face[0], face[4]};
    swap(face, newface);
  }

  // 奥に転がす
  void rotu() {
    vi newface = {face[1], face[5], face[2], face[0], face[4], face[3]};
    swap(face, newface);
  }

  // 手前に転がす
  void rotd() {
    vi newface = {face[3], face[0], face[2], face[5], face[4], face[1]};
    swap(face, newface);
  }

  // 正面を左面へ
  void kaitenl() {
    vi newface = {face[0], face[4], face[1], face[2], face[3], face[5]};
    swap(face, newface);
  }

  // 正面を右面へ
  void kaitenr() {
    vi newface = {face[0], face[2], face[3], face[4], face[1], face[5]};
    swap(face, newface);
  }

  bool operator==(const Dice &d) const {
    return face == d.face;
  }

  bool operator<(const Dice &d) const {
    return face < d.face;
  }

  int& operator[](int i) {
    return face[i];
  }
};