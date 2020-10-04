---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/template.cpp
    title: lib/template.cpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: test/others/dice.cpp
    title: test/others/dice.cpp
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"lib/template.cpp\"\n\n\n\n#include <bits/stdc++.h>\n\nusing\
    \ namespace std;\n\n#define REP(i, n) for (int i=0; i<(n); ++i)\n#define RREP(i,\
    \ n) for (int i=(int)(n)-1; i>=0; --i)\n#define FOR(i, a, n) for (int i=(a); i<(n);\
    \ ++i)\n#define RFOR(i, a, n) for (int i=(int)(n)-1; i>=(a); --i)\n\n#define SZ(x)\
    \ ((int)(x).size())\n#define ALL(x) (x).begin(),(x).end()\n\n#define DUMP(x) cerr<<#x<<\"\
    \ = \"<<(x)<<endl\n#define DEBUG(x) cerr<<#x<<\" = \"<<(x)<<\" (L\"<<__LINE__<<\"\
    )\"<<endl;\n\ntemplate<class T>\nostream &operator<<(ostream &os, const vector\
    \ <T> &v) {\n    os << \"[\";\n    REP(i, SZ(v)) {\n        if (i) os << \", \"\
    ;\n        os << v[i];\n    }\n    return os << \"]\";\n}\n\ntemplate<class T,\
    \ class U>\nostream &operator<<(ostream &os, const pair <T, U> &p) {\n    return\
    \ os << \"(\" << p.first << \" \" << p.second << \")\";\n}\n\ntemplate<class T>\n\
    bool chmax(T &a, const T &b) {\n    if (a < b) {\n        a = b;\n        return\
    \ true;\n    }\n    return false;\n}\n\ntemplate<class T>\nbool chmin(T &a, const\
    \ T &b) {\n    if (b < a) {\n        a = b;\n        return true;\n    }\n   \
    \ return false;\n}\n\nusing ll = long long;\nusing ull = unsigned long long;\n\
    using ld = long double;\nusing P = pair<int, int>;\nusing vi = vector<int>;\n\
    using vll = vector<ll>;\nusing vvi = vector<vi>;\nusing vvll = vector<vll>;\n\n\
    const ll MOD = 1e9 + 7;\nconst int INF = INT_MAX / 2;\nconst ll LINF = LLONG_MAX\
    \ / 2;\nconst ld eps = 1e-9;\n\n/*\nint main() {\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n\
    \    cout << fixed << setprecision(10);\n\n    // ifstream in(\"in.txt\");\n \
    \   // cin.rdbuf(in.rdbuf());\n\n    return 0;\n}\n*/\n\n\n#line 2 \"lib/others/dice.cpp\"\
    \n\n// 0: \u4E0A, 1: \u624B\u524D, 2: \u5DE6, 3: \u5965, 4: \u53F3, 5: \u4E0B\n\
    struct Dice {\n  vi face;\n  void init() {\n    face.resize(6);\n  }\n\n  // \u5DE6\
    \u306B\u8EE2\u304C\u3059\n  void rotl() {\n    vi newface = {face[4], face[1],\
    \ face[0], face[3], face[5], face[2]};\n    swap(face, newface);\n  }\n\n  //\
    \ \u53F3\u306B\u8EE2\u304C\u3059\n  void rotr() {\n    vi newface = {face[2],\
    \ face[1], face[5], face[3], face[0], face[4]};\n    swap(face, newface);\n  }\n\
    \n  // \u5965\u306B\u8EE2\u304C\u3059\n  void rotu() {\n    vi newface = {face[1],\
    \ face[5], face[2], face[0], face[4], face[3]};\n    swap(face, newface);\n  }\n\
    \n  // \u624B\u524D\u306B\u8EE2\u304C\u3059\n  void rotd() {\n    vi newface =\
    \ {face[3], face[0], face[2], face[5], face[4], face[1]};\n    swap(face, newface);\n\
    \  }\n};\n\nbool operator==(Dice d1, Dice d2) {\n  return d1.face == d2.face;\n\
    }\n\nbool operator<(Dice d1, Dice d2) {\n  return d1.face < d2.face;\n}\n"
  code: "#include \"../template.cpp\"\n\n// 0: \u4E0A, 1: \u624B\u524D, 2: \u5DE6\
    , 3: \u5965, 4: \u53F3, 5: \u4E0B\nstruct Dice {\n  vi face;\n  void init() {\n\
    \    face.resize(6);\n  }\n\n  // \u5DE6\u306B\u8EE2\u304C\u3059\n  void rotl()\
    \ {\n    vi newface = {face[4], face[1], face[0], face[3], face[5], face[2]};\n\
    \    swap(face, newface);\n  }\n\n  // \u53F3\u306B\u8EE2\u304C\u3059\n  void\
    \ rotr() {\n    vi newface = {face[2], face[1], face[5], face[3], face[0], face[4]};\n\
    \    swap(face, newface);\n  }\n\n  // \u5965\u306B\u8EE2\u304C\u3059\n  void\
    \ rotu() {\n    vi newface = {face[1], face[5], face[2], face[0], face[4], face[3]};\n\
    \    swap(face, newface);\n  }\n\n  // \u624B\u524D\u306B\u8EE2\u304C\u3059\n\
    \  void rotd() {\n    vi newface = {face[3], face[0], face[2], face[5], face[4],\
    \ face[1]};\n    swap(face, newface);\n  }\n};\n\nbool operator==(Dice d1, Dice\
    \ d2) {\n  return d1.face == d2.face;\n}\n\nbool operator<(Dice d1, Dice d2) {\n\
    \  return d1.face < d2.face;\n}"
  dependsOn:
  - lib/template.cpp
  isVerificationFile: false
  path: lib/others/dice.cpp
  requiredBy:
  - test/others/dice.cpp
  timestamp: '2020-06-23 21:12:16+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/others/dice.cpp
layout: document
redirect_from:
- /library/lib/others/dice.cpp
- /library/lib/others/dice.cpp.html
title: lib/others/dice.cpp
---
