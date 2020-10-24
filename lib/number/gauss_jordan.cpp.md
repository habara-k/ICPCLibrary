---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/template.cpp
    title: lib/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/number/gauss_jordan.test.cpp
    title: test/number/gauss_jordan.test.cpp
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
    \   // cin.rdbuf(in.rdbuf());\n\n    return 0;\n}\n*/\n\n\n#line 2 \"lib/number/gauss_jordan.cpp\"\
    \n\n/**\n * @brief\n * \u30AC\u30A6\u30B9\u306E\u6D88\u53BB\u6CD5\n * \u884C\u5217\
    \u3092\u30E9\u30F3\u30AF\u3092\u6C42\u3081\u305F\u308A\u3001Ax = b \u3092\u89E3\
    \u3044\u305F\u308A\u3059\u308B\n * @author habara-k\n * @date 2020/4\n * @param[in]\
    \ mat \u884C\u5217\n * @return int mat \u306E\u30E9\u30F3\u30AF\n */\n\ntemplate<class\
    \ T>\nint GaussJordanElimination(vector<vector<T>>& mat) {\n    int H = mat.size(),\
    \ W = mat[0].size(), rank = 0;\n    for (int col = 0; col < W; ++col) {\n    \
    \    int pivot = -1;\n        for (int row = rank; row < H; ++row) {\n       \
    \     if (mat[row][col] != 0) {\n                pivot = row;\n              \
    \  break;\n            }\n        }\n        if (pivot == -1) continue;\n    \
    \    swap(mat[rank], mat[pivot]);\n        T topLeft = mat[rank][col];\n     \
    \   for (int c = col; c < W; ++c) {\n            mat[rank][c] /= topLeft;\n  \
    \      }\n        for (int row = rank+1; row < H; ++row) {\n            T ratio\
    \ = mat[row][col];\n            for (int c = col; c < W; ++c)\n              \
    \  mat[row][c] -= ratio * mat[rank][c];\n        }\n        ++rank;\n    }\n \
    \   return (rank);\n}\n"
  code: "#include \"../template.cpp\"\n\n/**\n * @brief\n * \u30AC\u30A6\u30B9\u306E\
    \u6D88\u53BB\u6CD5\n * \u884C\u5217\u3092\u30E9\u30F3\u30AF\u3092\u6C42\u3081\u305F\
    \u308A\u3001Ax = b \u3092\u89E3\u3044\u305F\u308A\u3059\u308B\n * @author habara-k\n\
    \ * @date 2020/4\n * @param[in] mat \u884C\u5217\n * @return int mat \u306E\u30E9\
    \u30F3\u30AF\n */\n\ntemplate<class T>\nint GaussJordanElimination(vector<vector<T>>&\
    \ mat) {\n    int H = mat.size(), W = mat[0].size(), rank = 0;\n    for (int col\
    \ = 0; col < W; ++col) {\n        int pivot = -1;\n        for (int row = rank;\
    \ row < H; ++row) {\n            if (mat[row][col] != 0) {\n                pivot\
    \ = row;\n                break;\n            }\n        }\n        if (pivot\
    \ == -1) continue;\n        swap(mat[rank], mat[pivot]);\n        T topLeft =\
    \ mat[rank][col];\n        for (int c = col; c < W; ++c) {\n            mat[rank][c]\
    \ /= topLeft;\n        }\n        for (int row = rank+1; row < H; ++row) {\n \
    \           T ratio = mat[row][col];\n            for (int c = col; c < W; ++c)\n\
    \                mat[row][c] -= ratio * mat[rank][c];\n        }\n        ++rank;\n\
    \    }\n    return (rank);\n}\n"
  dependsOn:
  - lib/template.cpp
  isVerificationFile: false
  path: lib/number/gauss_jordan.cpp
  requiredBy: []
  timestamp: '2020-05-06 01:41:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/number/gauss_jordan.test.cpp
documentation_of: lib/number/gauss_jordan.cpp
layout: document
redirect_from:
- /library/lib/number/gauss_jordan.cpp
- /library/lib/number/gauss_jordan.cpp.html
title: lib/number/gauss_jordan.cpp
---
