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
    \n\n/**\n* @brief 2\u6B21\u5143\u6587\u5B57\u5217\u306E\u30CF\u30C3\u30B7\u30E5\
    \u5316\n* @author habara-k\n* @date 2020/07/05\n*/\n\nstruct RollingHash2D {\n\
    \    using uint = uint64_t;\n\n    /**\n    * @brief \u30B3\u30F3\u30B9\u30C8\u30E9\
    \u30AF\u30BF. O(|vs|)\n    * @param[in] vs \u30CF\u30C3\u30B7\u30E5\u5316\u3059\
    \u308B\u6587\u5B57\u5217\u306E\u30D9\u30AF\u30C8\u30EB(or matrix).\n    * @param[in]\
    \ base1, base2 \u30CF\u30C3\u30B7\u30E5\u5316\u306B\u4F7F\u3046\u57FA\u6570. RollingHash2D::gen_base\
    \ \u3067\u4F5C\u308B.\n    * @details \u4F7F\u3044\u65B9\n    *   auto base1 =\
    \ RollingHash2D::gen_base(),\n    *        base2 = RolligHash2D::gen_base();\n\
    \    *\n    *   vector<string> t;\n    *   RollingHash2D hash(t, base1, base2);\n\
    \    */\n    template<typename VS>\n    RollingHash2D(const VS &vs, uint base1,\
    \ uint base2) {\n        int n = vs.size();\n        int m = vs[0].size();\n \
    \       hash.resize(n + 1);\n        for (int i = 0; i <= n; ++i) hash[i].resize(m\
    \ + 1);\n\n        for (int i = 0; i < n; ++i) {\n            for (int j = 0;\
    \ j < m; ++j) {\n                hash[i + 1][j + 1] = mod(mul(hash[i + 1][j],\
    \ base2) + vs[i][j]);\n            }\n        }\n        for (int i = 0; i < n;\
    \ ++i) {\n            for (int j = 0; j < m; ++j) {\n                hash[i +\
    \ 1][j + 1] = mod(mul(hash[i][j + 1], base1) + hash[i + 1][j + 1]);\n        \
    \    }\n        }\n\n        pow1.assign(n + 1, 1);\n        for (int i = 0; i\
    \ < n; ++i) {\n            pow1[i + 1] = mul(pow1[i], base1);\n        }\n   \
    \     pow2.assign(m + 1, 1);\n        for (int j = 0; j < m; ++j) {\n        \
    \    pow2[j + 1] = mul(pow2[j], base2);\n        }\n    }\n\n    /**\n    * @brief\
    \ \u30CF\u30C3\u30B7\u30E5\u3092\u8A08\u7B97\u3059\u308B. O(1)\n    * @param[in]\
    \ i0, j0, i1, j1 \u30CF\u30C3\u30B7\u30E5\u3092\u8A08\u7B97\u3057\u305F\u3044\u533A\
    \u9593.\n    * @return \u533A\u9593[(i0,j0), (i1,j1)) \u306E\u30CF\u30C3\u30B7\
    \u30E5.\n    * @details \u4F7F\u3044\u65B9\n    *   cout << hash.get(0, 0, t.size(),\
    \ t[0].size()) << endl;\n    */\n    long long get(int i0, int j0, int i1, int\
    \ j1) {\n        uint a = mod(hash[i1][j1] + MASK61 - mul(hash[i1][j0], pow2[j1\
    \ - j0]));\n        uint b = mod(hash[i0][j1] + MASK61 - mul(hash[i0][j0], pow2[j1\
    \ - j0]));\n        return mod(a + MASK61 - mul(b, pow1[i1 - i0]));\n    }\n\n\
    \    /**\n    * @brief \u57FA\u6570\u3092\u751F\u6210\u3059\u308B. O(1)\n    *\
    \ @return \u30E9\u30F3\u30C0\u30E0\u306A\u57FA\u6570.\n    * @details \u4F7F\u3044\
    \u65B9\n    *   auto base = RollingHash::gen_base();\n    */\n    static uint\
    \ gen_base() {\n        mt19937 random{random_device{}()};\n        uniform_int_distribution\
    \ <uint> dist(2, MASK61 - 2);\n        return dist(random);\n    }\n\nprivate:\n\
    \    vector<vector<uint>> hash;\n    vector<uint> pow1, pow2;\n    static const\
    \ uint MASK30 = (1LL << 30) - 1,\n            MASK31 = (1LL << 31) - 1,\n    \
    \        MASK61 = (1LL << 61) - 1;\n\n    static uint mul(uint a, uint b) {\n\
    \        uint au = a >> 31, ad = a & MASK31,\n                bu = b >> 31, bd\
    \ = b & MASK31;\n        uint m = au * bd + ad * bu;\n        uint mu = m >> 30,\
    \ md = m & MASK30;\n\n        return mod(au * bu * 2 + mu + (md << 31) + ad *\
    \ bd);\n    }\n\n    static uint mod(uint x) {\n        uint xu = x >> 61, xd\
    \ = x & MASK61;\n        uint ret = xu + xd;\n        if (ret >= MASK61) ret -=\
    \ MASK61;\n        return ret;\n    }\n};\n"
  code: "#include \"../template.cpp\"\n\n/**\n* @brief 2\u6B21\u5143\u6587\u5B57\u5217\
    \u306E\u30CF\u30C3\u30B7\u30E5\u5316\n* @author habara-k\n* @date 2020/07/05\n\
    */\n\nstruct RollingHash2D {\n    using uint = uint64_t;\n\n    /**\n    * @brief\
    \ \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF. O(|vs|)\n    * @param[in] vs \u30CF\
    \u30C3\u30B7\u30E5\u5316\u3059\u308B\u6587\u5B57\u5217\u306E\u30D9\u30AF\u30C8\
    \u30EB(or matrix).\n    * @param[in] base1, base2 \u30CF\u30C3\u30B7\u30E5\u5316\
    \u306B\u4F7F\u3046\u57FA\u6570. RollingHash2D::gen_base \u3067\u4F5C\u308B.\n\
    \    * @details \u4F7F\u3044\u65B9\n    *   auto base1 = RollingHash2D::gen_base(),\n\
    \    *        base2 = RolligHash2D::gen_base();\n    *\n    *   vector<string>\
    \ t;\n    *   RollingHash2D hash(t, base1, base2);\n    */\n    template<typename\
    \ VS>\n    RollingHash2D(const VS &vs, uint base1, uint base2) {\n        int\
    \ n = vs.size();\n        int m = vs[0].size();\n        hash.resize(n + 1);\n\
    \        for (int i = 0; i <= n; ++i) hash[i].resize(m + 1);\n\n        for (int\
    \ i = 0; i < n; ++i) {\n            for (int j = 0; j < m; ++j) {\n          \
    \      hash[i + 1][j + 1] = mod(mul(hash[i + 1][j], base2) + vs[i][j]);\n    \
    \        }\n        }\n        for (int i = 0; i < n; ++i) {\n            for\
    \ (int j = 0; j < m; ++j) {\n                hash[i + 1][j + 1] = mod(mul(hash[i][j\
    \ + 1], base1) + hash[i + 1][j + 1]);\n            }\n        }\n\n        pow1.assign(n\
    \ + 1, 1);\n        for (int i = 0; i < n; ++i) {\n            pow1[i + 1] = mul(pow1[i],\
    \ base1);\n        }\n        pow2.assign(m + 1, 1);\n        for (int j = 0;\
    \ j < m; ++j) {\n            pow2[j + 1] = mul(pow2[j], base2);\n        }\n \
    \   }\n\n    /**\n    * @brief \u30CF\u30C3\u30B7\u30E5\u3092\u8A08\u7B97\u3059\
    \u308B. O(1)\n    * @param[in] i0, j0, i1, j1 \u30CF\u30C3\u30B7\u30E5\u3092\u8A08\
    \u7B97\u3057\u305F\u3044\u533A\u9593.\n    * @return \u533A\u9593[(i0,j0), (i1,j1))\
    \ \u306E\u30CF\u30C3\u30B7\u30E5.\n    * @details \u4F7F\u3044\u65B9\n    *  \
    \ cout << hash.get(0, 0, t.size(), t[0].size()) << endl;\n    */\n    long long\
    \ get(int i0, int j0, int i1, int j1) {\n        uint a = mod(hash[i1][j1] + MASK61\
    \ - mul(hash[i1][j0], pow2[j1 - j0]));\n        uint b = mod(hash[i0][j1] + MASK61\
    \ - mul(hash[i0][j0], pow2[j1 - j0]));\n        return mod(a + MASK61 - mul(b,\
    \ pow1[i1 - i0]));\n    }\n\n    /**\n    * @brief \u57FA\u6570\u3092\u751F\u6210\
    \u3059\u308B. O(1)\n    * @return \u30E9\u30F3\u30C0\u30E0\u306A\u57FA\u6570.\n\
    \    * @details \u4F7F\u3044\u65B9\n    *   auto base = RollingHash::gen_base();\n\
    \    */\n    static uint gen_base() {\n        mt19937 random{random_device{}()};\n\
    \        uniform_int_distribution <uint> dist(2, MASK61 - 2);\n        return\
    \ dist(random);\n    }\n\nprivate:\n    vector<vector<uint>> hash;\n    vector<uint>\
    \ pow1, pow2;\n    static const uint MASK30 = (1LL << 30) - 1,\n            MASK31\
    \ = (1LL << 31) - 1,\n            MASK61 = (1LL << 61) - 1;\n\n    static uint\
    \ mul(uint a, uint b) {\n        uint au = a >> 31, ad = a & MASK31,\n       \
    \         bu = b >> 31, bd = b & MASK31;\n        uint m = au * bd + ad * bu;\n\
    \        uint mu = m >> 30, md = m & MASK30;\n\n        return mod(au * bu * 2\
    \ + mu + (md << 31) + ad * bd);\n    }\n\n    static uint mod(uint x) {\n    \
    \    uint xu = x >> 61, xd = x & MASK61;\n        uint ret = xu + xd;\n      \
    \  if (ret >= MASK61) ret -= MASK61;\n        return ret;\n    }\n};\n"
  dependsOn:
  - lib/template.cpp
  isVerificationFile: false
  path: lib/string/rolling_hash_2D.cpp
  requiredBy: []
  timestamp: '2020-07-05 15:39:35+09:00'
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
