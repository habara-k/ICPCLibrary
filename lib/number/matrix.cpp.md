---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: lib/template.cpp
    title: lib/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/number/matrix.test.cpp
    title: test/number/matrix.test.cpp
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
    \   // cin.rdbuf(in.rdbuf());\n\n    return 0;\n}\n*/\n\n\n#line 2 \"lib/number/matrix.cpp\"\
    \n\n/**\n * @brief\n * \u884C\u5217\u7D2F\u4E57\n * @author habara-k\n * @date\
    \ 2020/04/24\n * @param[in] a \u884C\u5217\n * @param[in] k \u6307\u6570\n * @return\
    \ \u884C\u5217 a^k\n *\n * @details\n * T \u306B\u6E21\u3059\u306E\u306F\u74B0\
    \u3067\u3042\u308A\u3001operator *, += \u3092\u5B9A\u7FA9\u3059\u308B\u3053\u3068\
    \n */\n\ntemplate<class T>\nusing Matrix = vector<vector<T>>;\n\ntemplate<class\
    \ T>\nMatrix<T> operator*(const Matrix<T>& A, const Matrix<T>& B) {\n    assert(A[0].size()\
    \ == B.size());\n    int n = A.size(), m = B[0].size(), p = A[0].size();\n   \
    \ Matrix<T> C(n, vector<T>(m));\n    for (int i = 0; i < n; ++i)\n        for\
    \ (int j = 0; j < m; ++j)\n            for (int k = 0; k < p; ++k)\n         \
    \       C[i][j] += A[i][k] * B[k][j];\n    return C;\n}\n\ntemplate<class T>\n\
    Matrix<T> pow(Matrix<T> a, ll k) {\n    assert(a.size() == a[0].size());\n   \
    \ int n = a.size();\n    Matrix<T> ret(n, vector<T>(n));\n    for (int i = 0;\
    \ i < n; ++i) ret[i][i] = 1;\n    while (k) {\n        if (k & 1) ret = ret *\
    \ a;\n        a = a * a; k >>= 1;\n    }\n    return ret;\n}\n"
  code: "#include \"../template.cpp\"\n\n/**\n * @brief\n * \u884C\u5217\u7D2F\u4E57\
    \n * @author habara-k\n * @date 2020/04/24\n * @param[in] a \u884C\u5217\n * @param[in]\
    \ k \u6307\u6570\n * @return \u884C\u5217 a^k\n *\n * @details\n * T \u306B\u6E21\
    \u3059\u306E\u306F\u74B0\u3067\u3042\u308A\u3001operator *, += \u3092\u5B9A\u7FA9\
    \u3059\u308B\u3053\u3068\n */\n\ntemplate<class T>\nusing Matrix = vector<vector<T>>;\n\
    \ntemplate<class T>\nMatrix<T> operator*(const Matrix<T>& A, const Matrix<T>&\
    \ B) {\n    assert(A[0].size() == B.size());\n    int n = A.size(), m = B[0].size(),\
    \ p = A[0].size();\n    Matrix<T> C(n, vector<T>(m));\n    for (int i = 0; i <\
    \ n; ++i)\n        for (int j = 0; j < m; ++j)\n            for (int k = 0; k\
    \ < p; ++k)\n                C[i][j] += A[i][k] * B[k][j];\n    return C;\n}\n\
    \ntemplate<class T>\nMatrix<T> pow(Matrix<T> a, ll k) {\n    assert(a.size() ==\
    \ a[0].size());\n    int n = a.size();\n    Matrix<T> ret(n, vector<T>(n));\n\
    \    for (int i = 0; i < n; ++i) ret[i][i] = 1;\n    while (k) {\n        if (k\
    \ & 1) ret = ret * a;\n        a = a * a; k >>= 1;\n    }\n    return ret;\n}\n"
  dependsOn:
  - lib/template.cpp
  isVerificationFile: false
  path: lib/number/matrix.cpp
  requiredBy: []
  timestamp: '2020-05-06 01:41:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/number/matrix.test.cpp
documentation_of: lib/number/matrix.cpp
layout: document
redirect_from:
- /library/lib/number/matrix.cpp
- /library/lib/number/matrix.cpp.html
title: lib/number/matrix.cpp
---
