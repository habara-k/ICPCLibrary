---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/number/matrix.cpp
    title: lib/number/matrix.cpp
  - icon: ':heavy_check_mark:'
    path: lib/template.cpp
    title: lib/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2397
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2397
  bundledCode: "#line 1 \"test/number/matrix.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2397\"\
    \n\n#line 1 \"lib/template.cpp\"\n\n\n\n#include <bits/stdc++.h>\n\nusing namespace\
    \ std;\n\n#define REP(i, n) for (int i=0; i<(n); ++i)\n#define RREP(i, n) for\
    \ (int i=(int)(n)-1; i>=0; --i)\n#define FOR(i, a, n) for (int i=(a); i<(n); ++i)\n\
    #define RFOR(i, a, n) for (int i=(int)(n)-1; i>=(a); --i)\n\n#define SZ(x) ((int)(x).size())\n\
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
    \n    return 0;\n}\n*/\n\n\n#line 2 \"lib/number/matrix.cpp\"\n\n/**\n * @brief\n\
    \ * \u884C\u5217\u7D2F\u4E57\n * @author habara-k\n * @date 2020/04/24\n * @param[in]\
    \ a \u884C\u5217\n * @param[in] k \u6307\u6570\n * @return \u884C\u5217 a^k\n\
    \ *\n * @details\n * T \u306B\u6E21\u3059\u306E\u306F\u74B0\u3067\u3042\u308A\u3001\
    operator *, += \u3092\u5B9A\u7FA9\u3059\u308B\u3053\u3068\n */\n\ntemplate<class\
    \ T>\nusing Matrix = vector<vector<T>>;\n\ntemplate<class T>\nMatrix<T> operator*(const\
    \ Matrix<T>& A, const Matrix<T>& B) {\n    assert(A[0].size() == B.size());\n\
    \    int n = A.size(), m = B[0].size(), p = A[0].size();\n    Matrix<T> C(n, vector<T>(m));\n\
    \    for (int i = 0; i < n; ++i)\n        for (int j = 0; j < m; ++j)\n      \
    \      for (int k = 0; k < p; ++k)\n                C[i][j] += A[i][k] * B[k][j];\n\
    \    return C;\n}\n\ntemplate<class T>\nMatrix<T> pow(Matrix<T> a, ll k) {\n \
    \   assert(a.size() == a[0].size());\n    int n = a.size();\n    Matrix<T> ret(n,\
    \ vector<T>(n));\n    for (int i = 0; i < n; ++i) ret[i][i] = 1;\n    while (k)\
    \ {\n        if (k & 1) ret = ret * a;\n        a = a * a; k >>= 1;\n    }\n \
    \   return ret;\n}\n#line 4 \"test/number/matrix.test.cpp\"\n\n\ntemplate<int\
    \ mod>\nstruct modint {\n    ll x;\n    modint(ll x=0) : x(x) {}\n    modint &operator+=(const\
    \ modint& a) {\n        (x += a.x) %= mod;\n        return *this;\n    }\n   \
    \ friend modint operator*(const modint& a, const modint& b) {\n        return\
    \ modint((a.x * b.x) % mod);\n    }\n    friend ostream &operator<<(ostream &os,\
    \ const modint &a) {\n        return os << a.x;\n    }\n};\n\nint main() {\n \
    \   cin.tie(0);\n    ios::sync_with_stdio(false);\n    cout << fixed << setprecision(10);\n\
    \n    for (int t = 1;; ++t) {\n        ll W, H, N;\n        cin >> W >> H >> N;\n\
    \        if (W == 0) break;\n        bool zero = false;\n        map<ll, vi> obs;\n\
    \        REP(i, N) {\n            ll x, y;\n            cin >> x >> y;\n     \
    \       --x, --y;\n            if (x == 0 and y == 0) {\n                zero\
    \ = true;\n            }\n            if (y > 0) obs[y].emplace_back(x);\n   \
    \     }\n        if (zero) {\n            cout << 0 << endl;\n            return\
    \ 0;\n        }\n\n        using Int = modint<1000000009>;\n\n        Matrix<Int>\
    \ A(W, vector<Int>(W));\n        REP(i, W) A[i][i] = 1;\n\n        Matrix<Int>\
    \ B = A;\n        REP(i, W) {\n            if (i - 1 >= 0) B[i][i - 1] = 1;\n\
    \            if (i + 1 < W) B[i][i + 1] = 1;\n        }\n\n        ll prv = 0;\n\
    \        for (auto &tp : obs) {\n            ll now = tp.first;\n\n          \
    \  A = A * pow(B, now - prv - 1);\n\n            Matrix<Int> tmp = B;\n      \
    \      for (int j : tp.second) {\n                REP(i, W) tmp[i][j] = 0;\n \
    \           }\n            A = A * tmp;\n\n            prv = now;\n\n        }\n\
    \n        A = A * pow(B, H - prv - 1);\n\n        cout << \"Case \" << t << \"\
    : \" << A[0][W - 1].x << endl;\n    }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2397\"\
    \n\n#include \"../../lib/number/matrix.cpp\"\n\n\ntemplate<int mod>\nstruct modint\
    \ {\n    ll x;\n    modint(ll x=0) : x(x) {}\n    modint &operator+=(const modint&\
    \ a) {\n        (x += a.x) %= mod;\n        return *this;\n    }\n    friend modint\
    \ operator*(const modint& a, const modint& b) {\n        return modint((a.x *\
    \ b.x) % mod);\n    }\n    friend ostream &operator<<(ostream &os, const modint\
    \ &a) {\n        return os << a.x;\n    }\n};\n\nint main() {\n    cin.tie(0);\n\
    \    ios::sync_with_stdio(false);\n    cout << fixed << setprecision(10);\n\n\
    \    for (int t = 1;; ++t) {\n        ll W, H, N;\n        cin >> W >> H >> N;\n\
    \        if (W == 0) break;\n        bool zero = false;\n        map<ll, vi> obs;\n\
    \        REP(i, N) {\n            ll x, y;\n            cin >> x >> y;\n     \
    \       --x, --y;\n            if (x == 0 and y == 0) {\n                zero\
    \ = true;\n            }\n            if (y > 0) obs[y].emplace_back(x);\n   \
    \     }\n        if (zero) {\n            cout << 0 << endl;\n            return\
    \ 0;\n        }\n\n        using Int = modint<1000000009>;\n\n        Matrix<Int>\
    \ A(W, vector<Int>(W));\n        REP(i, W) A[i][i] = 1;\n\n        Matrix<Int>\
    \ B = A;\n        REP(i, W) {\n            if (i - 1 >= 0) B[i][i - 1] = 1;\n\
    \            if (i + 1 < W) B[i][i + 1] = 1;\n        }\n\n        ll prv = 0;\n\
    \        for (auto &tp : obs) {\n            ll now = tp.first;\n\n          \
    \  A = A * pow(B, now - prv - 1);\n\n            Matrix<Int> tmp = B;\n      \
    \      for (int j : tp.second) {\n                REP(i, W) tmp[i][j] = 0;\n \
    \           }\n            A = A * tmp;\n\n            prv = now;\n\n        }\n\
    \n        A = A * pow(B, H - prv - 1);\n\n        cout << \"Case \" << t << \"\
    : \" << A[0][W - 1].x << endl;\n    }\n\n    return 0;\n}\n"
  dependsOn:
  - lib/number/matrix.cpp
  - lib/template.cpp
  isVerificationFile: true
  path: test/number/matrix.test.cpp
  requiredBy: []
  timestamp: '2020-05-06 01:41:24+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/number/matrix.test.cpp
layout: document
redirect_from:
- /verify/test/number/matrix.test.cpp
- /verify/test/number/matrix.test.cpp.html
title: test/number/matrix.test.cpp
---
