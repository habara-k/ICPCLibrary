---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/string/rolling_hash.cpp
    title: "\u6587\u5B57\u5217\u306E\u30CF\u30C3\u30B7\u30E5\u5316"
  - icon: ':heavy_check_mark:'
    path: lib/template.cpp
    title: lib/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/14/ALDS1_14_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/14/ALDS1_14_B
  bundledCode: "#line 1 \"test/string/rolling_hash.test.cpp\"\n#define PROBLEM \"\
    https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/14/ALDS1_14_B\"\n\n#line\
    \ 1 \"lib/template.cpp\"\n\n\n\n#include <bits/stdc++.h>\n\nusing namespace std;\n\
    \n#define REP(i, n) for (int i=0; i<(n); ++i)\n#define RREP(i, n) for (int i=(int)(n)-1;\
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
    \n    return 0;\n}\n*/\n\n\n#line 2 \"lib/string/rolling_hash.cpp\"\n\n/**\n*\
    \ @brief \u6587\u5B57\u5217\u306E\u30CF\u30C3\u30B7\u30E5\u5316\n* @author habara-k\n\
    * @date 2020/04/26\n*/\n\nstruct RollingHash {\n    using uint = uint64_t;\n\n\
    \    /**\n    * @brief \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF. O(|s|)\n  \
    \  * @param[in] s \u30CF\u30C3\u30B7\u30E5\u5316\u3059\u308B\u6587\u5B57\u5217\
    (or vector).\n    * @param[in] base \u30CF\u30C3\u30B7\u30E5\u5316\u306B\u4F7F\
    \u3046\u57FA\u6570. RollingHash::gen_base \u3067\u4F5C\u308B.\n    * @details\
    \ \u4F7F\u3044\u65B9\n    *   auto base = RollingHash::gen_base();\n    *\n  \
    \  *   string t; cin >> t;\n    *   RollingHash hash(t, base);\n    */\n    template<typename\
    \ S>\n    RollingHash(const S& s, uint base) {\n        int n = s.size();\n  \
    \      hash.assign(n+1, 0);\n        pow.assign(n+1, 1);\n        for (int i =\
    \ 0; i < n; ++i) {\n            hash[i+1] = mod(mul(hash[i], base) + s[i]);\n\
    \            pow[i+1] = mul(pow[i], base);\n        }\n    }\n\n    /**\n    *\
    \ @brief \u30CF\u30C3\u30B7\u30E5\u3092\u8A08\u7B97\u3059\u308B. O(1)\n    * @param[in]\
    \ l, r \u30CF\u30C3\u30B7\u30E5\u3092\u8A08\u7B97\u3057\u305F\u3044\u533A\u9593\
    .\n    * @return \u533A\u9593[l, r) \u306E\u30CF\u30C3\u30B7\u30E5.\n    * @details\
    \ \u4F7F\u3044\u65B9\n    *   cout << hash.get(0, t.size()) << endl;\n    */\n\
    \    uint get(int l, int r) const {\n        return mod(hash[r] + MASK61 - mul(hash[l],\
    \ pow[r - l]));\n    }\n\n    /**\n    * @brief \u57FA\u6570\u3092\u751F\u6210\
    \u3059\u308B. O(1)\n    * @return \u30E9\u30F3\u30C0\u30E0\u306A\u57FA\u6570.\n\
    \    * @details \u4F7F\u3044\u65B9\n    *   auto base = RollingHash::gen_base();\n\
    \    */\n    static uint gen_base() {\n        mt19937 random{random_device{}()};\n\
    \        uniform_int_distribution<uint> dist(2, MASK61-2);\n        return dist(random);\n\
    \    }\n\nprivate:\n    vector<uint> hash, pow;\n    static const uint MASK30\
    \ = (1LL<<30)-1,\n                      MASK31 = (1LL<<31)-1,\n              \
    \        MASK61 = (1LL<<61)-1;\n\n    static uint mul(uint a, uint b) {\n    \
    \    uint au = a >> 31, ad = a & MASK31,\n             bu = b >> 31, bd = b &\
    \ MASK31;\n        uint m = au * bd + ad * bu;\n        uint mu = m >> 30, md\
    \ = m & MASK30;\n\n        return mod(au*bu*2 + mu + (md<<31) + ad*bd);\n    }\n\
    \    static uint mod(uint x) {\n        uint xu = x >> 61, xd = x & MASK61;\n\
    \        uint ret = xu + xd;\n        if (ret >= MASK61) ret -= MASK61;\n    \
    \    return ret;\n    }\n};\n#line 4 \"test/string/rolling_hash.test.cpp\"\n\n\
    int main() {\n    string T, P;\n    cin >> T >> P;\n    int n = T.size(), m =\
    \ P.size();\n\n    auto base = RollingHash::gen_base();\n\n    RollingHash rht(T,\
    \ base);\n    RollingHash rhp(P, base);\n\n    for (int i = 0; i+m <= n; ++i)\
    \ {\n        if (rht.get(i, i+m) == rhp.get(0, m)) {\n            cout << i <<\
    \ endl;\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/14/ALDS1_14_B\"\
    \n\n#include \"../../lib/string/rolling_hash.cpp\"\n\nint main() {\n    string\
    \ T, P;\n    cin >> T >> P;\n    int n = T.size(), m = P.size();\n\n    auto base\
    \ = RollingHash::gen_base();\n\n    RollingHash rht(T, base);\n    RollingHash\
    \ rhp(P, base);\n\n    for (int i = 0; i+m <= n; ++i) {\n        if (rht.get(i,\
    \ i+m) == rhp.get(0, m)) {\n            cout << i << endl;\n        }\n    }\n\
    }\n"
  dependsOn:
  - lib/string/rolling_hash.cpp
  - lib/template.cpp
  isVerificationFile: true
  path: test/string/rolling_hash.test.cpp
  requiredBy: []
  timestamp: '2020-05-06 01:41:24+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/string/rolling_hash.test.cpp
layout: document
redirect_from:
- /verify/test/string/rolling_hash.test.cpp
- /verify/test/string/rolling_hash.test.cpp.html
title: test/string/rolling_hash.test.cpp
---
