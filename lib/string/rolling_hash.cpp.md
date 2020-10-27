---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/template.cpp
    title: lib/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/string/rolling_hash.test.cpp
    title: test/string/rolling_hash.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u6587\u5B57\u5217\u306E\u30CF\u30C3\u30B7\u30E5\u5316"
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
    \   // cin.rdbuf(in.rdbuf());\n\n    return 0;\n}\n*/\n\n\n#line 2 \"lib/string/rolling_hash.cpp\"\
    \n\n/**\n * @brief \u6587\u5B57\u5217\u306E\u30CF\u30C3\u30B7\u30E5\u5316\n *\
    \ @author habara-k\n * @date 2020/10/28\n * @usage\n *   auto base = RollingHash::gen_base();\n\
    \ *   string s; cin >> s;\n *   RollingHash hash(s, base);   // O(|s|)\n *   hash.get(l,\
    \ r);   // s[l,r)\u306E\u30CF\u30C3\u30B7\u30E5. O(1)\n */\nstruct RollingHash\
    \ {\n    using u64 = uint64_t;\n    using i128 = __int128_t;\n\n    template<typename\
    \ S>\n    RollingHash(const S &s, u64 base) {\n        int n = s.size();\n   \
    \     hash.assign(n+1, 0);\n        pow.assign(n+1, 1);\n        for (int i =\
    \ 0; i < n; ++i) {\n            hash[i+1] = mul(hash[i], base) + s[i];\n     \
    \       if (hash[i+1] >= MOD) hash[i+1] -= MOD;\n            pow[i+1] = mul(pow[i],\
    \ base);\n        }\n    }\n\n    u64 get(int l, int r) const {\n        u64 ret\
    \ = hash[r] + MOD - mul(hash[l], pow[r-l]);\n        return ret >= MOD ? ret -\
    \ MOD : ret;\n    }\n\n    static u64 gen_base() {\n        mt19937 random{random_device{}()};\n\
    \        uniform_int_distribution<u64> dist(2, MOD-2);\n        return dist(random);\n\
    \    }\n\nprivate:\n    vector<u64> hash, pow;\n    static const u64 MOD = (1ul\
    \ << 61) - 1;\n\n    static u64 mul(i128 a, i128 b) {\n        i128 t = a * b;\n\
    \        t = (t >> 61) + (t & MOD);\n        if (t >= MOD) t -= MOD;\n       \
    \ return t;\n    }\n};\n\n"
  code: "#include \"../template.cpp\"\n\n/**\n * @brief \u6587\u5B57\u5217\u306E\u30CF\
    \u30C3\u30B7\u30E5\u5316\n * @author habara-k\n * @date 2020/10/28\n * @usage\n\
    \ *   auto base = RollingHash::gen_base();\n *   string s; cin >> s;\n *   RollingHash\
    \ hash(s, base);   // O(|s|)\n *   hash.get(l, r);   // s[l,r)\u306E\u30CF\u30C3\
    \u30B7\u30E5. O(1)\n */\nstruct RollingHash {\n    using u64 = uint64_t;\n   \
    \ using i128 = __int128_t;\n\n    template<typename S>\n    RollingHash(const\
    \ S &s, u64 base) {\n        int n = s.size();\n        hash.assign(n+1, 0);\n\
    \        pow.assign(n+1, 1);\n        for (int i = 0; i < n; ++i) {\n        \
    \    hash[i+1] = mul(hash[i], base) + s[i];\n            if (hash[i+1] >= MOD)\
    \ hash[i+1] -= MOD;\n            pow[i+1] = mul(pow[i], base);\n        }\n  \
    \  }\n\n    u64 get(int l, int r) const {\n        u64 ret = hash[r] + MOD - mul(hash[l],\
    \ pow[r-l]);\n        return ret >= MOD ? ret - MOD : ret;\n    }\n\n    static\
    \ u64 gen_base() {\n        mt19937 random{random_device{}()};\n        uniform_int_distribution<u64>\
    \ dist(2, MOD-2);\n        return dist(random);\n    }\n\nprivate:\n    vector<u64>\
    \ hash, pow;\n    static const u64 MOD = (1ul << 61) - 1;\n\n    static u64 mul(i128\
    \ a, i128 b) {\n        i128 t = a * b;\n        t = (t >> 61) + (t & MOD);\n\
    \        if (t >= MOD) t -= MOD;\n        return t;\n    }\n};\n\n"
  dependsOn:
  - lib/template.cpp
  isVerificationFile: false
  path: lib/string/rolling_hash.cpp
  requiredBy: []
  timestamp: '2020-10-28 03:11:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/string/rolling_hash.test.cpp
documentation_of: lib/string/rolling_hash.cpp
layout: document
redirect_from:
- /library/lib/string/rolling_hash.cpp
- /library/lib/string/rolling_hash.cpp.html
title: "\u6587\u5B57\u5217\u306E\u30CF\u30C3\u30B7\u30E5\u5316"
---
