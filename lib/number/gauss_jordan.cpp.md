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
    document_title: "\u30AC\u30A6\u30B9\u306E\u6D88\u53BB\u6CD5"
    links:
    - https://drken1215.hatenablog.com/entry/2019/03/20/000200
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
    \n\n/*\n * @brief \u30AC\u30A6\u30B9\u306E\u6D88\u53BB\u6CD5\n * @ref https://drken1215.hatenablog.com/entry/2019/03/20/000200\n\
    \ * @date 2020/10/26\n */\ntemplate<class T>\nusing Matrix = vector<vector<T>>;\n\
    \ntemplate<class T> int GaussJordan(Matrix<T> &A, bool is_extended = false) {\n\
    \    int m = A.size(), n = A[0].size();\n    int rank = 0;\n    for (int col =\
    \ 0; col < n; ++col) {\n        if (is_extended && col == n-1) break;\n      \
    \  int pivot = -1;\n        T ma = eps;\n        for (int row = rank; row < m;\
    \ ++row) {\n            if (abs(A[row][col]) > ma) {\n                ma = abs(A[row][col]);\n\
    \                pivot = row;\n            }\n        }\n        if (pivot ==\
    \ -1) continue;\n        swap(A[pivot], A[rank]);\n        auto fac = A[rank][col];\n\
    \        for (int col2 = 0; col2 < n; ++col2) A[rank][col2] /= fac;\n        for\
    \ (int row = 0; row < m; ++row) {\n            if (row != rank && abs(A[row][col])\
    \ > eps) {\n                auto fac = A[row][col];\n                for (int\
    \ col2 = 0; col2 < n; ++col2) {\n                    A[row][col2] -= A[rank][col2]\
    \ * fac;\n                }\n            }\n        }\n        ++rank;\n    }\n\
    \    return rank;\n}\n\n\n/*\n * @brief \u7DDA\u578B\u65B9\u7A0B\u5F0F\n * @ref\
    \ https://drken1215.hatenablog.com/entry/2019/03/20/000200\n * @date 2020/10/26\n\
    \ * @usage\n * vector<vector<double>> A(m, vector<double>(n));\n * vector<double>\
    \ b(m);\n * auto x = linear_equation(A, b);\n * if (x.empty()) {\n * // \u89E3\
    \u306A\u3057\n * } else {\n * // x\u306FAx = b\u3092\u6E80\u305F\u3059\u4E00\u3064\
    \u306E\u89E3\n * }\n */\ntemplate<class T> vector<T> linear_equation(Matrix<T>\
    \ A, vector<T> b) {\n    // extended\n    int m = A.size(), n = A[0].size();\n\
    \    Matrix<T> M(m, vector<T>(n + 1));\n    for (int i = 0; i < m; ++i) {\n  \
    \      for (int j = 0; j < n; ++j) M[i][j] = A[i][j];\n        M[i][n] = b[i];\n\
    \    }\n    int rank = GaussJordan(M, true);\n\n    // check if it has no solution\n\
    \    vector<T> res;\n    for (int row = rank; row < m; ++row) if (abs(M[row][n])\
    \ > eps) return res;\n\n    // answer\n    res.assign(n, 0);\n    int col = 0;\n\
    \    for (int i = 0; i < rank; ++i) {\n        while (abs(M[i][col]) < eps) ++col;\n\
    \        res[col] = M[i][n];\n    }\n    return res;\n}\n\n"
  code: "#include \"../template.cpp\"\n\n/*\n * @brief \u30AC\u30A6\u30B9\u306E\u6D88\
    \u53BB\u6CD5\n * @ref https://drken1215.hatenablog.com/entry/2019/03/20/000200\n\
    \ * @date 2020/10/26\n */\ntemplate<class T>\nusing Matrix = vector<vector<T>>;\n\
    \ntemplate<class T> int GaussJordan(Matrix<T> &A, bool is_extended = false) {\n\
    \    int m = A.size(), n = A[0].size();\n    int rank = 0;\n    for (int col =\
    \ 0; col < n; ++col) {\n        if (is_extended && col == n-1) break;\n      \
    \  int pivot = -1;\n        T ma = eps;\n        for (int row = rank; row < m;\
    \ ++row) {\n            if (abs(A[row][col]) > ma) {\n                ma = abs(A[row][col]);\n\
    \                pivot = row;\n            }\n        }\n        if (pivot ==\
    \ -1) continue;\n        swap(A[pivot], A[rank]);\n        auto fac = A[rank][col];\n\
    \        for (int col2 = 0; col2 < n; ++col2) A[rank][col2] /= fac;\n        for\
    \ (int row = 0; row < m; ++row) {\n            if (row != rank && abs(A[row][col])\
    \ > eps) {\n                auto fac = A[row][col];\n                for (int\
    \ col2 = 0; col2 < n; ++col2) {\n                    A[row][col2] -= A[rank][col2]\
    \ * fac;\n                }\n            }\n        }\n        ++rank;\n    }\n\
    \    return rank;\n}\n\n\n/*\n * @brief \u7DDA\u578B\u65B9\u7A0B\u5F0F\n * @ref\
    \ https://drken1215.hatenablog.com/entry/2019/03/20/000200\n * @date 2020/10/26\n\
    \ * @usage\n * vector<vector<double>> A(m, vector<double>(n));\n * vector<double>\
    \ b(m);\n * auto x = linear_equation(A, b);\n * if (x.empty()) {\n * // \u89E3\
    \u306A\u3057\n * } else {\n * // x\u306FAx = b\u3092\u6E80\u305F\u3059\u4E00\u3064\
    \u306E\u89E3\n * }\n */\ntemplate<class T> vector<T> linear_equation(Matrix<T>\
    \ A, vector<T> b) {\n    // extended\n    int m = A.size(), n = A[0].size();\n\
    \    Matrix<T> M(m, vector<T>(n + 1));\n    for (int i = 0; i < m; ++i) {\n  \
    \      for (int j = 0; j < n; ++j) M[i][j] = A[i][j];\n        M[i][n] = b[i];\n\
    \    }\n    int rank = GaussJordan(M, true);\n\n    // check if it has no solution\n\
    \    vector<T> res;\n    for (int row = rank; row < m; ++row) if (abs(M[row][n])\
    \ > eps) return res;\n\n    // answer\n    res.assign(n, 0);\n    int col = 0;\n\
    \    for (int i = 0; i < rank; ++i) {\n        while (abs(M[i][col]) < eps) ++col;\n\
    \        res[col] = M[i][n];\n    }\n    return res;\n}\n\n"
  dependsOn:
  - lib/template.cpp
  isVerificationFile: false
  path: lib/number/gauss_jordan.cpp
  requiredBy: []
  timestamp: '2020-10-28 03:09:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/number/gauss_jordan.test.cpp
documentation_of: lib/number/gauss_jordan.cpp
layout: document
redirect_from:
- /library/lib/number/gauss_jordan.cpp
- /library/lib/number/gauss_jordan.cpp.html
title: "\u30AC\u30A6\u30B9\u306E\u6D88\u53BB\u6CD5"
---
