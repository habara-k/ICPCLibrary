#include "../template.cpp"

// 0: 上, 1: 手前, 2: 左, 3: 奥, 4: 右, 5: 下
struct Dice {
  vi face;
  void init() {
    face.resize(6);
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
};

bool operator==(Dice d1, Dice d2) {
  return d1.face == d2.face;
}

bool operator<(Dice d1, Dice d2) {
  return d1.face < d2.face;
}