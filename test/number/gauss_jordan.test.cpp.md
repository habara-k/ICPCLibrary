---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/number/gauss_jordan.cpp
    title: lib/number/gauss_jordan.cpp
  - icon: ':heavy_check_mark:'
    path: lib/template.cpp
    title: lib/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1308
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1308
  bundledCode: "#line 1 \"test/number/gauss_jordan.test.cpp\"\n#define PROBLEM \"\
    http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1308\"\n\n#line 1 \"\
    lib/template.cpp\"\n\n\n\n#include <bits/stdc++.h>\n\nusing namespace std;\n\n\
    #define REP(i, n) for (int i=0; i<(n); ++i)\n#define RREP(i, n) for (int i=(int)(n)-1;\
    \ i>=0; --i)\n#define FOR(i, a, n) for (int i=(a); i<(n); ++i)\n#define RFOR(i,\
    \ a, n) for (int i=(int)(n)-1; i>=(a); --i)\n\n#define SZ(x) ((int)(x).size())\n\
    #define ALL(x) (x).begin(),(x).end()\n\n#define DUMP(x) cerr<<#x<<\" = \"<<(x)<<endl\n\
    #define DEBUG(x) cerr<<#x<<\" = \"<<(x)<<\" (L\"<<__LINE__<<\")\"<<endl;\n\ntemplate<class\
    \ T>\nostream &operator<<(ostream &os, const vector <T> &v) {\n    os << \"[\"\
    ;\n    REP(i, SZ(v)) {\n        if (i) os << \", \";\n        os << v[i];\n  \
    \  }\n    return os << \"]\";\n}\n\ntemplate<class T, class U>\nostream &operator<<(ostream\
    \ &os, const pair <T, U> &p) {\n    return os << \"(\" << p.first << \" \" <<\
    \ p.second << \")\";\n}\n\ntemplate<class T>\nbool chmax(T &a, const T &b) {\n\
    \    if (a < b) {\n        a = b;\n        return true;\n    }\n    return false;\n\
    }\n\ntemplate<class T>\nbool chmin(T &a, const T &b) {\n    if (b < a) {\n   \
    \     a = b;\n        return true;\n    }\n    return false;\n}\n\nusing ll =\
    \ long long;\nusing ull = unsigned long long;\nusing ld = long double;\nusing\
    \ P = pair<int, int>;\nusing vi = vector<int>;\nusing vll = vector<ll>;\nusing\
    \ vvi = vector<vi>;\nusing vvll = vector<vll>;\n\nconst ll MOD = 1e9 + 7;\nconst\
    \ int INF = INT_MAX / 2;\nconst ll LINF = LLONG_MAX / 2;\nconst ld eps = 1e-9;\n\
    \n/*\nint main() {\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n    cout\
    \ << fixed << setprecision(10);\n\n    // ifstream in(\"in.txt\");\n    // cin.rdbuf(in.rdbuf());\n\
    \n    return 0;\n}\n*/\n\n\n#line 2 \"lib/number/gauss_jordan.cpp\"\n\n/**\n *\
    \ @brief\n * \u30AC\u30A6\u30B9\u306E\u6D88\u53BB\u6CD5\n * \u884C\u5217\u3092\
    \u30E9\u30F3\u30AF\u3092\u6C42\u3081\u305F\u308A\u3001Ax = b \u3092\u89E3\u3044\
    \u305F\u308A\u3059\u308B\n * @author habara-k\n * @date 2020/4\n * @param[in]\
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
    \   return (rank);\n}\n#line 4 \"test/number/gauss_jordan.test.cpp\"\n\nstruct\
    \ GF2 {\n    int x;\n    bool operator==(int a) { return x == a; }\n    bool operator!=(int\
    \ a) { return !(*this == a); }\n    GF2(int x=0) : x(x) {}\n    GF2 &operator/=(GF2\
    \ a) {\n        assert(a != 0);\n        x /= a.x;\n        return *this;\n  \
    \  }\n    GF2 &operator-=(GF2 a) {\n        x ^= a.x;\n        return *this;\n\
    \    }\n    GF2 operator*(GF2 a) {\n        return GF2(x * a.x);\n    }\n    friend\
    \ istream& operator>>(istream& is, GF2& a) {\n        int tmp; is >> tmp;\n  \
    \      a = tmp;\n        return is;\n    }\n};\n\nint main() {\n\n    for (;;)\
    \ {\n        int m, n, d;\n        cin >> m >> n >> d;\n        if (m == 0) break;\n\
    \n        vector<vector<GF2>> mat(n*m, vector<GF2>(n*m+1));\n\n        REP(i,\
    \ n) REP(j, m) cin >> mat[i*m + j][n*m];\n\n        REP(i, n) REP(j, m) {\n  \
    \          mat[i*m + j][i*m + j] = 1;\n            REP(y, n) REP(x, m) {\n   \
    \             if (abs(y - i) + abs(x - j) == d) {\n                    mat[i*m\
    \ + j][y*m + x] = 1;\n                }\n            }\n        }\n\n        GaussJordanElimination(mat);\n\
    \n        int ans = true;\n        REP(i, n * m) {\n            int allZero =\
    \ true;\n            REP(j, n * m) {\n                if (mat[i][j] != 0) {\n\
    \                    allZero = false;\n                    break;\n          \
    \      }\n            }\n            if (allZero and mat[i][n * m] == 1) {\n \
    \               ans = false;\n                break;\n            }\n        }\n\
    \        cout << ans << endl;\n    }\n\n    return 0;\n}\n\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1308\"\
    \n\n#include \"../../lib/number/gauss_jordan.cpp\"\n\nstruct GF2 {\n    int x;\n\
    \    bool operator==(int a) { return x == a; }\n    bool operator!=(int a) { return\
    \ !(*this == a); }\n    GF2(int x=0) : x(x) {}\n    GF2 &operator/=(GF2 a) {\n\
    \        assert(a != 0);\n        x /= a.x;\n        return *this;\n    }\n  \
    \  GF2 &operator-=(GF2 a) {\n        x ^= a.x;\n        return *this;\n    }\n\
    \    GF2 operator*(GF2 a) {\n        return GF2(x * a.x);\n    }\n    friend istream&\
    \ operator>>(istream& is, GF2& a) {\n        int tmp; is >> tmp;\n        a =\
    \ tmp;\n        return is;\n    }\n};\n\nint main() {\n\n    for (;;) {\n    \
    \    int m, n, d;\n        cin >> m >> n >> d;\n        if (m == 0) break;\n\n\
    \        vector<vector<GF2>> mat(n*m, vector<GF2>(n*m+1));\n\n        REP(i, n)\
    \ REP(j, m) cin >> mat[i*m + j][n*m];\n\n        REP(i, n) REP(j, m) {\n     \
    \       mat[i*m + j][i*m + j] = 1;\n            REP(y, n) REP(x, m) {\n      \
    \          if (abs(y - i) + abs(x - j) == d) {\n                    mat[i*m +\
    \ j][y*m + x] = 1;\n                }\n            }\n        }\n\n        GaussJordanElimination(mat);\n\
    \n        int ans = true;\n        REP(i, n * m) {\n            int allZero =\
    \ true;\n            REP(j, n * m) {\n                if (mat[i][j] != 0) {\n\
    \                    allZero = false;\n                    break;\n          \
    \      }\n            }\n            if (allZero and mat[i][n * m] == 1) {\n \
    \               ans = false;\n                break;\n            }\n        }\n\
    \        cout << ans << endl;\n    }\n\n    return 0;\n}\n\n"
  dependsOn:
  - lib/number/gauss_jordan.cpp
  - lib/template.cpp
  isVerificationFile: true
  path: test/number/gauss_jordan.test.cpp
  requiredBy: []
  timestamp: '2020-05-06 01:41:24+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/number/gauss_jordan.test.cpp
layout: document
redirect_from:
- /verify/test/number/gauss_jordan.test.cpp
- /verify/test/number/gauss_jordan.test.cpp.html
title: test/number/gauss_jordan.test.cpp
---
