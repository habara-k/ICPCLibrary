---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/template.cpp
    title: lib/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/string/rolling_hash_2D.test.cpp
    title: test/string/rolling_hash_2D.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "2\u6B21\u5143\u6587\u5B57\u5217\u306E\u30CF\u30C3\u30B7\u30E5\
      \u5316"
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
    \   // cin.rdbuf(in.rdbuf());\n\n    return 0;\n}\n*/\n\n\n#line 2 \"lib/string/rolling_hash_2D.cpp\"\
    \n\n/**\n * @brief 2\u6B21\u5143\u6587\u5B57\u5217\u306E\u30CF\u30C3\u30B7\u30E5\
    \u5316\n * @author habara-k\n * @date 2020/10/28\n * @usage\n *   auto base1 =\
    \ RollingHash2D::gen_base(),\n *        base2 = RolligHash2D::gen_base();\n *\
    \   vector<string> vs;\n *   RollingHash2D hash(vs, base1, base2);\n *   hash.get(i1,\
    \ j1, i2, j2);\n */\nstruct RollingHash2D {\n    using u64 = uint64_t;\n    using\
    \ i128 = __int128_t;\n\n    template<typename VS>\n    RollingHash2D(const VS\
    \ &vs, u64 base1, u64 base2) {\n        int n = vs.size();\n        int m = vs[0].size();\n\
    \        hash.assign(n+1, vector<u64>(m+1));\n\n        for (int i = 0; i < n;\
    \ ++i) {\n            for (int j = 0; j < m; ++j) {\n                hash[i+1][j+1]\
    \ = mul(hash[i+1][j], base2) + vs[i][j];\n                if (hash[i+1][j+1] >=\
    \ MOD) hash[i+1][j+1] -= MOD;\n            }\n        }\n        for (int i =\
    \ 0; i < n; ++i) {\n            for (int j = 0; j < m; ++j) {\n              \
    \  hash[i+1][j+1] = mul(hash[i][j+1], base1) + hash[i+1][j+1];\n             \
    \   if (hash[i+1][j+1] >= MOD) hash[i+1][j+1] -= MOD;\n            }\n       \
    \ }\n\n        pow1.assign(n+1, 1);\n        for (int i = 0; i < n; ++i) {\n \
    \           pow1[i + 1] = mul(pow1[i], base1);\n        }\n        pow2.assign(m+1,\
    \ 1);\n        for (int j = 0; j < m; ++j) {\n            pow2[j + 1] = mul(pow2[j],\
    \ base2);\n        }\n    }\n\n    long long get(int i0, int j0, int i1, int j1)\
    \ {\n        u64 a = hash[i1][j1] + MOD - mul(hash[i1][j0], pow2[j1-j0]);\n  \
    \      if (a >= MOD) a -= MOD;\n        u64 b = hash[i0][j1] + MOD - mul(hash[i0][j0],\
    \ pow2[j1-j0]);\n        if (b >= MOD) b -= MOD;\n        u64 ret = a + MOD -\
    \ mul(b, pow1[i1-i0]);\n        return ret >= MOD ? ret - MOD : ret;\n    }\n\n\
    \    static u64 gen_base() {\n        mt19937 random{random_device{}()};\n   \
    \     uniform_int_distribution <u64> dist(2, MOD - 2);\n        return dist(random);\n\
    \    }\n\nprivate:\n    vector<vector<u64>> hash;\n    vector<u64> pow1, pow2;\n\
    \    static const u64 MOD = (1ul << 61) - 1;\n\n    static u64 mul(i128 a, i128\
    \ b) {\n        i128 t = a * b;\n        t = (t >> 61) + (t & MOD);\n        if\
    \ (t >= MOD) t -= MOD;\n        return t;\n    }\n};\n\n"
  code: "#include \"../template.cpp\"\n\n/**\n * @brief 2\u6B21\u5143\u6587\u5B57\u5217\
    \u306E\u30CF\u30C3\u30B7\u30E5\u5316\n * @author habara-k\n * @date 2020/10/28\n\
    \ * @usage\n *   auto base1 = RollingHash2D::gen_base(),\n *        base2 = RolligHash2D::gen_base();\n\
    \ *   vector<string> vs;\n *   RollingHash2D hash(vs, base1, base2);\n *   hash.get(i1,\
    \ j1, i2, j2);\n */\nstruct RollingHash2D {\n    using u64 = uint64_t;\n    using\
    \ i128 = __int128_t;\n\n    template<typename VS>\n    RollingHash2D(const VS\
    \ &vs, u64 base1, u64 base2) {\n        int n = vs.size();\n        int m = vs[0].size();\n\
    \        hash.assign(n+1, vector<u64>(m+1));\n\n        for (int i = 0; i < n;\
    \ ++i) {\n            for (int j = 0; j < m; ++j) {\n                hash[i+1][j+1]\
    \ = mul(hash[i+1][j], base2) + vs[i][j];\n                if (hash[i+1][j+1] >=\
    \ MOD) hash[i+1][j+1] -= MOD;\n            }\n        }\n        for (int i =\
    \ 0; i < n; ++i) {\n            for (int j = 0; j < m; ++j) {\n              \
    \  hash[i+1][j+1] = mul(hash[i][j+1], base1) + hash[i+1][j+1];\n             \
    \   if (hash[i+1][j+1] >= MOD) hash[i+1][j+1] -= MOD;\n            }\n       \
    \ }\n\n        pow1.assign(n+1, 1);\n        for (int i = 0; i < n; ++i) {\n \
    \           pow1[i + 1] = mul(pow1[i], base1);\n        }\n        pow2.assign(m+1,\
    \ 1);\n        for (int j = 0; j < m; ++j) {\n            pow2[j + 1] = mul(pow2[j],\
    \ base2);\n        }\n    }\n\n    long long get(int i0, int j0, int i1, int j1)\
    \ {\n        u64 a = hash[i1][j1] + MOD - mul(hash[i1][j0], pow2[j1-j0]);\n  \
    \      if (a >= MOD) a -= MOD;\n        u64 b = hash[i0][j1] + MOD - mul(hash[i0][j0],\
    \ pow2[j1-j0]);\n        if (b >= MOD) b -= MOD;\n        u64 ret = a + MOD -\
    \ mul(b, pow1[i1-i0]);\n        return ret >= MOD ? ret - MOD : ret;\n    }\n\n\
    \    static u64 gen_base() {\n        mt19937 random{random_device{}()};\n   \
    \     uniform_int_distribution <u64> dist(2, MOD - 2);\n        return dist(random);\n\
    \    }\n\nprivate:\n    vector<vector<u64>> hash;\n    vector<u64> pow1, pow2;\n\
    \    static const u64 MOD = (1ul << 61) - 1;\n\n    static u64 mul(i128 a, i128\
    \ b) {\n        i128 t = a * b;\n        t = (t >> 61) + (t & MOD);\n        if\
    \ (t >= MOD) t -= MOD;\n        return t;\n    }\n};\n\n"
  dependsOn:
  - lib/template.cpp
  isVerificationFile: false
  path: lib/string/rolling_hash_2D.cpp
  requiredBy: []
  timestamp: '2020-10-28 03:11:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/string/rolling_hash_2D.test.cpp
documentation_of: lib/string/rolling_hash_2D.cpp
layout: document
redirect_from:
- /library/lib/string/rolling_hash_2D.cpp
- /library/lib/string/rolling_hash_2D.cpp.html
title: "2\u6B21\u5143\u6587\u5B57\u5217\u306E\u30CF\u30C3\u30B7\u30E5\u5316"
---
