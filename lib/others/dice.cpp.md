---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/template.cpp
    title: lib/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/others/dice.test.cpp
    title: test/others/dice.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
    struct Dice {\n  vi face = {1, 3, 2, 4, 5, 6};\n\n  vector<string> cand = {\n\
    \      \"124536\",\n      \"132456\",\n      \"145326\",\n      \"153246\",\n\
    \      \"213645\",\n      \"236415\",\n      \"241365\",\n      \"264135\",\n\
    \      \"315624\",\n      \"321564\",\n      \"356214\",\n      \"362154\",\n\
    \      \"412653\",\n      \"426513\",\n      \"451263\",\n      \"465123\",\n\
    \      \"514632\",\n      \"531462\",\n      \"546312\",\n      \"563142\",\n\
    \      \"623541\",\n      \"635421\",\n      \"642351\",\n      \"654231\"\n \
    \ };\n\n  void init(vi v) {\n    swap(face, v);\n  }\n\n  // \u4E0A\u3068\u624B\
    \u524D\u306E\u5024\u304B\u3089\u69CB\u7BC9\n  bool init(int top, int front) {\n\
    \    if(top == front || top + front == 7) return false;\n    for(auto &v: cand)\
    \ {\n      if(top == v[0] - '0' && front == v[1] - '0') {\n        REP(i, 6) {\n\
    \          face[i] = v[i] - '0';\n        }\n        break;\n      }\n    }\n\
    \    return true;\n  }\n\n  // \u5DE6\u306B\u8EE2\u304C\u3059\n  void rotl() {\n\
    \    vi newface = {face[4], face[1], face[0], face[3], face[5], face[2]};\n  \
    \  swap(face, newface);\n  }\n\n  // \u53F3\u306B\u8EE2\u304C\u3059\n  void rotr()\
    \ {\n    vi newface = {face[2], face[1], face[5], face[3], face[0], face[4]};\n\
    \    swap(face, newface);\n  }\n\n  // \u5965\u306B\u8EE2\u304C\u3059\n  void\
    \ rotb() {\n    vi newface = {face[1], face[5], face[2], face[0], face[4], face[3]};\n\
    \    swap(face, newface);\n  }\n\n  // \u624B\u524D\u306B\u8EE2\u304C\u3059\n\
    \  void rotf() {\n    vi newface = {face[3], face[0], face[2], face[5], face[4],\
    \ face[1]};\n    swap(face, newface);\n  }\n\n  // \u6B63\u9762\u3092\u5DE6\u9762\
    \u3078(\u4E0A\u304B\u3089\u307F\u3066\u6642\u8A08\u56DE\u308A)\n  void rotc()\
    \ {\n    vi newface = {face[0], face[4], face[1], face[2], face[3], face[5]};\n\
    \    swap(face, newface);\n  }\n\n  // \u6B63\u9762\u3092\u53F3\u9762\u3078(\u4E0A\
    \u304B\u3089\u898B\u3066\u53CD\u6642\u8A08\u56DE\u308A)\n  void rotcc() {\n  \
    \  vi newface = {face[0], face[2], face[3], face[4], face[1], face[5]};\n    swap(face,\
    \ newface);\n  }\n\n  bool operator==(const Dice &d) const {\n    return face\
    \ == d.face;\n  }\n\n  bool operator<(const Dice &d) const {\n    return face\
    \ < d.face;\n  }\n\n  int& operator[](int i) {\n    return face[i];\n  }\n};\n"
  code: "#include \"../template.cpp\"\n\n// 0: \u4E0A, 1: \u624B\u524D, 2: \u5DE6\
    , 3: \u5965, 4: \u53F3, 5: \u4E0B\nstruct Dice {\n  vi face = {1, 3, 2, 4, 5,\
    \ 6};\n\n  vector<string> cand = {\n      \"124536\",\n      \"132456\",\n   \
    \   \"145326\",\n      \"153246\",\n      \"213645\",\n      \"236415\",\n   \
    \   \"241365\",\n      \"264135\",\n      \"315624\",\n      \"321564\",\n   \
    \   \"356214\",\n      \"362154\",\n      \"412653\",\n      \"426513\",\n   \
    \   \"451263\",\n      \"465123\",\n      \"514632\",\n      \"531462\",\n   \
    \   \"546312\",\n      \"563142\",\n      \"623541\",\n      \"635421\",\n   \
    \   \"642351\",\n      \"654231\"\n  };\n\n  void init(vi v) {\n    swap(face,\
    \ v);\n  }\n\n  // \u4E0A\u3068\u624B\u524D\u306E\u5024\u304B\u3089\u69CB\u7BC9\
    \n  bool init(int top, int front) {\n    if(top == front || top + front == 7)\
    \ return false;\n    for(auto &v: cand) {\n      if(top == v[0] - '0' && front\
    \ == v[1] - '0') {\n        REP(i, 6) {\n          face[i] = v[i] - '0';\n   \
    \     }\n        break;\n      }\n    }\n    return true;\n  }\n\n  // \u5DE6\u306B\
    \u8EE2\u304C\u3059\n  void rotl() {\n    vi newface = {face[4], face[1], face[0],\
    \ face[3], face[5], face[2]};\n    swap(face, newface);\n  }\n\n  // \u53F3\u306B\
    \u8EE2\u304C\u3059\n  void rotr() {\n    vi newface = {face[2], face[1], face[5],\
    \ face[3], face[0], face[4]};\n    swap(face, newface);\n  }\n\n  // \u5965\u306B\
    \u8EE2\u304C\u3059\n  void rotb() {\n    vi newface = {face[1], face[5], face[2],\
    \ face[0], face[4], face[3]};\n    swap(face, newface);\n  }\n\n  // \u624B\u524D\
    \u306B\u8EE2\u304C\u3059\n  void rotf() {\n    vi newface = {face[3], face[0],\
    \ face[2], face[5], face[4], face[1]};\n    swap(face, newface);\n  }\n\n  //\
    \ \u6B63\u9762\u3092\u5DE6\u9762\u3078(\u4E0A\u304B\u3089\u307F\u3066\u6642\u8A08\
    \u56DE\u308A)\n  void rotc() {\n    vi newface = {face[0], face[4], face[1], face[2],\
    \ face[3], face[5]};\n    swap(face, newface);\n  }\n\n  // \u6B63\u9762\u3092\
    \u53F3\u9762\u3078(\u4E0A\u304B\u3089\u898B\u3066\u53CD\u6642\u8A08\u56DE\u308A\
    )\n  void rotcc() {\n    vi newface = {face[0], face[2], face[3], face[4], face[1],\
    \ face[5]};\n    swap(face, newface);\n  }\n\n  bool operator==(const Dice &d)\
    \ const {\n    return face == d.face;\n  }\n\n  bool operator<(const Dice &d)\
    \ const {\n    return face < d.face;\n  }\n\n  int& operator[](int i) {\n    return\
    \ face[i];\n  }\n};"
  dependsOn:
  - lib/template.cpp
  isVerificationFile: false
  path: lib/others/dice.cpp
  requiredBy: []
  timestamp: '2020-10-24 20:43:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/others/dice.test.cpp
documentation_of: lib/others/dice.cpp
layout: document
redirect_from:
- /library/lib/others/dice.cpp
- /library/lib/others/dice.cpp.html
title: lib/others/dice.cpp
---
