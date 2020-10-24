---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/template.cpp
    title: lib/template.cpp
  _extendedRequiredBy: []
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
    \   // cin.rdbuf(in.rdbuf());\n\n    return 0;\n}\n*/\n\n\n#line 2 \"lib/others/xorshift.cpp\"\
    \n\r\nstruct XorShift\r\n{\r\n  uint32_t w, x, y, z;\r\n  XorShift(uint32_t seed\
    \ = time(nullptr))\r\n  {\r\n    w = seed;\r\n    x = w << 13;\r\n    y = (w >>\
    \ 9) ^ (x << 6);\r\n    z = y >> 7;\r\n  }\r\n\r\n  uint32_t rand()\r\n  {\r\n\
    \    uint32_t t = x ^ (x << 11);\r\n    x = y;\r\n    y = z;\r\n    z = w;\r\n\
    \    return w = (w ^ (w >> 19) ^ (t ^ (t >> 8)));\r\n  }\r\n\r\n  // [min,max]\
    \ \u306E\u6574\u6570\u5024\u4E71\u6570\r\n  int randInt(int min = 0, int max =\
    \ 0x7FFFFFFF)\r\n  {\r\n    return rand() % (max - min + 1) + min;\r\n  }\r\n\r\
    \n  // [min,max] \u306E\u6D6E\u52D5\u5C0F\u6570\u70B9\u4E71\u6570\r\n  double\
    \ randDouble(double min = 0, double max = 1)\r\n  {\r\n    return (double)(rand()\
    \ % 0xFFFF) / 0xFFFF * (max - min) + min;\r\n  }\r\n\r\n  // \u5909\u6570\u3092\
    \u30C7\u30D5\u30A9\u30EB\u30C8\u5024\u306B\u8A2D\u5B9A\u3059\u308B\r\n  void SetDefault()\r\
    \n  {\r\n    w = 123456789;\r\n    x = 362436069;\r\n    y = 521288629;\r\n  \
    \  z = 88675123;\r\n  }\r\n};\r\n"
  code: "#include \"../template.cpp\"\r\n\r\nstruct XorShift\r\n{\r\n  uint32_t w,\
    \ x, y, z;\r\n  XorShift(uint32_t seed = time(nullptr))\r\n  {\r\n    w = seed;\r\
    \n    x = w << 13;\r\n    y = (w >> 9) ^ (x << 6);\r\n    z = y >> 7;\r\n  }\r\
    \n\r\n  uint32_t rand()\r\n  {\r\n    uint32_t t = x ^ (x << 11);\r\n    x = y;\r\
    \n    y = z;\r\n    z = w;\r\n    return w = (w ^ (w >> 19) ^ (t ^ (t >> 8)));\r\
    \n  }\r\n\r\n  // [min,max] \u306E\u6574\u6570\u5024\u4E71\u6570\r\n  int randInt(int\
    \ min = 0, int max = 0x7FFFFFFF)\r\n  {\r\n    return rand() % (max - min + 1)\
    \ + min;\r\n  }\r\n\r\n  // [min,max] \u306E\u6D6E\u52D5\u5C0F\u6570\u70B9\u4E71\
    \u6570\r\n  double randDouble(double min = 0, double max = 1)\r\n  {\r\n    return\
    \ (double)(rand() % 0xFFFF) / 0xFFFF * (max - min) + min;\r\n  }\r\n\r\n  // \u5909\
    \u6570\u3092\u30C7\u30D5\u30A9\u30EB\u30C8\u5024\u306B\u8A2D\u5B9A\u3059\u308B\
    \r\n  void SetDefault()\r\n  {\r\n    w = 123456789;\r\n    x = 362436069;\r\n\
    \    y = 521288629;\r\n    z = 88675123;\r\n  }\r\n};\r\n"
  dependsOn:
  - lib/template.cpp
  isVerificationFile: false
  path: lib/others/xorshift.cpp
  requiredBy: []
  timestamp: '2020-10-17 06:51:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/others/xorshift.cpp
layout: document
redirect_from:
- /library/lib/others/xorshift.cpp
- /library/lib/others/xorshift.cpp.html
title: lib/others/xorshift.cpp
---
