---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/template.cpp
    title: lib/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/number/sieve.test.cpp
    title: test/number/sieve.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/number/sieve2.test.cpp
    title: test/number/sieve2.test.cpp
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
    \   // cin.rdbuf(in.rdbuf());\n\n    return 0;\n}\n*/\n\n\n#line 2 \"lib/number/sieve.cpp\"\
    \n\r\n/**\r\n * @brief\r\n * \u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9\
    \ O(nloglogn)\r\n *\r\n * \u30FB\u533A\u9593\u7BE9\r\n * R <= 10^9, R - L <= 10^6\
    \ \u3068\u304B\u306E\u3068\u304D\u306B\r\n * [L, R]\u306E\u7D20\u6570\u5224\u5B9A\
    \u3092\u3059\u308B\r\n * sqrt(R)\u307E\u3067\u3092\u666E\u901A\u306B\u3075\u308B\
    \u3063\u3066\u3001\u3053\u3044\u3064\u3092\u4F7F\u3063\u3066L\u304B\u3089R\u3092\
    \u3075\u308B\u3048\u3070\u3088\u3044\r\n *\r\n * \u30FB\u7D20\u56E0\u6570\u5206\
    \u89E3\r\n * \u7D20\u56E0\u6570\u5206\u89E3\u3082\u7BE9\u3067\u3084\u308B\u3053\
    \u3068\u304C\u3067\u304D\u308B(\u7BE9\u3092\u3057\u3066\u3044\u308B\u3068\u304D\
    \u306B\u3001n\u306E\u7D20\u56E0\u6570\u3092\u4E00\u3064\u3082\u305F\u305B\u308B\
    )\r\n *\r\n * \u533A\u9593\u7BE9\u306E\u8981\u9818\u3067\u7D20\u56E0\u6570\u5206\
    \u89E3\u3059\u308B\u3053\u3068\u3082\u3067\u304D\u308B(\u4F8B: Prime-Factor Prime\
    \ \u2190 2\u3064\u76EE\u306E\u30C6\u30B9\u30C8\u306B\u3044\u308C\u3066\u307E\u3059\
    )\r\n *\r\n * @author Md\r\n * @date 2020/11/04\r\n */\r\n\r\nvector<bool> sieve(int\
    \ n) {\r\n  vector<bool> prime(n+1, true);\r\n  prime[0] = false;\r\n  prime[1]\
    \ = false;\r\n  for(int i=2;i<=n;++i) {\r\n    if(prime[i]) {\r\n      for(int\
    \ j=2*i;j<=n;j+=i) {\r\n        prime[j] = false;\r\n      }\r\n    }\r\n  }\r\
    \n  return prime;\r\n}\r\n"
  code: "#include \"../template.cpp\"\r\n\r\n/**\r\n * @brief\r\n * \u30A8\u30E9\u30C8\
    \u30B9\u30C6\u30CD\u30B9\u306E\u7BE9 O(nloglogn)\r\n *\r\n * \u30FB\u533A\u9593\
    \u7BE9\r\n * R <= 10^9, R - L <= 10^6 \u3068\u304B\u306E\u3068\u304D\u306B\r\n\
    \ * [L, R]\u306E\u7D20\u6570\u5224\u5B9A\u3092\u3059\u308B\r\n * sqrt(R)\u307E\
    \u3067\u3092\u666E\u901A\u306B\u3075\u308B\u3063\u3066\u3001\u3053\u3044\u3064\
    \u3092\u4F7F\u3063\u3066L\u304B\u3089R\u3092\u3075\u308B\u3048\u3070\u3088\u3044\
    \r\n *\r\n * \u30FB\u7D20\u56E0\u6570\u5206\u89E3\r\n * \u7D20\u56E0\u6570\u5206\
    \u89E3\u3082\u7BE9\u3067\u3084\u308B\u3053\u3068\u304C\u3067\u304D\u308B(\u7BE9\
    \u3092\u3057\u3066\u3044\u308B\u3068\u304D\u306B\u3001n\u306E\u7D20\u56E0\u6570\
    \u3092\u4E00\u3064\u3082\u305F\u305B\u308B)\r\n *\r\n * \u533A\u9593\u7BE9\u306E\
    \u8981\u9818\u3067\u7D20\u56E0\u6570\u5206\u89E3\u3059\u308B\u3053\u3068\u3082\
    \u3067\u304D\u308B(\u4F8B: Prime-Factor Prime \u2190 2\u3064\u76EE\u306E\u30C6\
    \u30B9\u30C8\u306B\u3044\u308C\u3066\u307E\u3059)\r\n *\r\n * @author Md\r\n *\
    \ @date 2020/11/04\r\n */\r\n\r\nvector<bool> sieve(int n) {\r\n  vector<bool>\
    \ prime(n+1, true);\r\n  prime[0] = false;\r\n  prime[1] = false;\r\n  for(int\
    \ i=2;i<=n;++i) {\r\n    if(prime[i]) {\r\n      for(int j=2*i;j<=n;j+=i) {\r\n\
    \        prime[j] = false;\r\n      }\r\n    }\r\n  }\r\n  return prime;\r\n}\r\
    \n"
  dependsOn:
  - lib/template.cpp
  isVerificationFile: false
  path: lib/number/sieve.cpp
  requiredBy: []
  timestamp: '2020-11-04 03:03:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/number/sieve2.test.cpp
  - test/number/sieve.test.cpp
documentation_of: lib/number/sieve.cpp
layout: document
redirect_from:
- /library/lib/number/sieve.cpp
- /library/lib/number/sieve.cpp.html
title: lib/number/sieve.cpp
---
