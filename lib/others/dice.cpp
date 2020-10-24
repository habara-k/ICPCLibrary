#include "../template.cpp"

// 0: 上, 1: 手前, 2: 左, 3: 奥, 4: 右, 5: 下
struct Dice {
  vi face = {1, 3, 2, 4, 5, 6};

  vector<string> cand = {
      "124536",
      "132456",
      "145326",
      "153246",
      "213645",
      "236415",
      "241365",
      "264135",
      "315624",
      "321564",
      "356214",
      "362154",
      "412653",
      "426513",
      "451263",
      "465123",
      "514632",
      "531462",
      "546312",
      "563142",
      "623541",
      "635421",
      "642351",
      "654231"
  };

  void init(vi v) {
    swap(face, v);
  }

  // 上と手前の値から構築
  bool init(int top, int front) {
    if(top == front || top + front == 7) return false;
    for(auto &v: cand) {
      if(top == v[0] - '0' && front == v[1] - '0') {
        REP(i, 6) {
          face[i] = v[i] - '0';
        }
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
  void rotb() {
    vi newface = {face[1], face[5], face[2], face[0], face[4], face[3]};
    swap(face, newface);
  }

  // 手前に転がす
  void rotf() {
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