---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/structure/binary_indexed_tree.cpp
    title: lib/structure/binary_indexed_tree.cpp
  - icon: ':question:'
    path: lib/template.cpp
    title: lib/template.cpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: test/structure/bit_range_add.cpp
    title: test/structure/bit_range_add.cpp
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
    \   // cin.rdbuf(in.rdbuf());\n\n    return 0;\n}\n*/\n\n\n#line 2 \"lib/structure/binary_indexed_tree.cpp\"\
    \n\ntemplate<typename T>\nstruct BIT {\n    vector<T> bit;\n    int sz;\n    BIT(int\
    \ n) : sz(n+1), bit(n+1) {}\n    void add(int i, T x) {\n        i += 1;\n   \
    \     while (i < sz) { bit[i] += x; i += i & -i; }\n    }\n    T sum(int i) {\n\
    \        i += 1; T s = 0;\n        while (i > 0) { s += bit[i]; i -= i & -i; }\n\
    \        return s;\n    }\n};\n#line 2 \"lib/structure/bit_range_add.cpp\"\n\n\
    /**\n * \u533A\u9593add\u533A\u9593sum\n */\n\ntemplate<typename T>\nstruct RangeAdd\
    \ {\n  BIT<T> bit1, bit2;\n\n  RangeAdd(int n): bit1(BIT<T>(n+1)), bit2(BIT<T>(n+1))\
    \ {\n  }\n\n  // [l, r)\u306Bval\u3092\u52A0\u7B97\n  void add(int l, int r, T\
    \ val) {\n    bit1.add(l, -l*val);\n    bit1.add(r, r*val);\n    bit2.add(l, val);\n\
    \    bit2.add(r, -val);\n  }\n\n  // [0, idx)\u306E\u548C\u3092\u53D6\u5F97\n\
    \  T sum(int idx) {\n    return bit1.sum(idx) + idx * bit2.sum(idx);\n  }\n};\n"
  code: "#include \"binary_indexed_tree.cpp\"\n\n/**\n * \u533A\u9593add\u533A\u9593\
    sum\n */\n\ntemplate<typename T>\nstruct RangeAdd {\n  BIT<T> bit1, bit2;\n\n\
    \  RangeAdd(int n): bit1(BIT<T>(n+1)), bit2(BIT<T>(n+1)) {\n  }\n\n  // [l, r)\u306B\
    val\u3092\u52A0\u7B97\n  void add(int l, int r, T val) {\n    bit1.add(l, -l*val);\n\
    \    bit1.add(r, r*val);\n    bit2.add(l, val);\n    bit2.add(r, -val);\n  }\n\
    \n  // [0, idx)\u306E\u548C\u3092\u53D6\u5F97\n  T sum(int idx) {\n    return\
    \ bit1.sum(idx) + idx * bit2.sum(idx);\n  }\n};\n"
  dependsOn:
  - lib/structure/binary_indexed_tree.cpp
  - lib/template.cpp
  isVerificationFile: false
  path: lib/structure/bit_range_add.cpp
  requiredBy:
  - test/structure/bit_range_add.cpp
  timestamp: '2020-09-02 09:09:59+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/structure/bit_range_add.cpp
layout: document
redirect_from:
- /library/lib/structure/bit_range_add.cpp
- /library/lib/structure/bit_range_add.cpp.html
title: lib/structure/bit_range_add.cpp
---
