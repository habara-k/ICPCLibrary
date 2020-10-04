---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: lib/template.cpp
    title: lib/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u9AD8\u901F\u30E1\u30D3\u30A6\u30B9\u5909\u63DB"
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
    \   // cin.rdbuf(in.rdbuf());\n\n    return 0;\n}\n*/\n\n\n#line 2 \"lib/number/fast-mobius.cpp\"\
    \n/**\n* @brief \u9AD8\u901F\u30E1\u30D3\u30A6\u30B9\u5909\u63DB\n* @author habara-k\n\
    * @date 2020/10/3\n* @param[in] g: 2^n -> T\n* @param[out] f: s.t. g(s) = \\sum_{s\
    \ \\subset t} f(t)\n* @details: O(nlogn)\n*/\ntemplate<typename T>\nvector<T>\
    \ fast_mobius(const vector<T>& g) {\n    int n = g.size();\n    vector<T> f =\
    \ g;\n    for (int i = 0; (1 << i) < n; ++i) {\n        for (int j = 0; j < n;\
    \ ++j) {\n            if (!(j >> i & 1)) {\n                f[j] -= f[j | (1<<i)];\n\
    \            }\n        }\n    }\n    return f;\n}\n"
  code: "#include \"../template.cpp\"\n/**\n* @brief \u9AD8\u901F\u30E1\u30D3\u30A6\
    \u30B9\u5909\u63DB\n* @author habara-k\n* @date 2020/10/3\n* @param[in] g: 2^n\
    \ -> T\n* @param[out] f: s.t. g(s) = \\sum_{s \\subset t} f(t)\n* @details: O(nlogn)\n\
    */\ntemplate<typename T>\nvector<T> fast_mobius(const vector<T>& g) {\n    int\
    \ n = g.size();\n    vector<T> f = g;\n    for (int i = 0; (1 << i) < n; ++i)\
    \ {\n        for (int j = 0; j < n; ++j) {\n            if (!(j >> i & 1)) {\n\
    \                f[j] -= f[j | (1<<i)];\n            }\n        }\n    }\n   \
    \ return f;\n}\n"
  dependsOn:
  - lib/template.cpp
  isVerificationFile: false
  path: lib/number/fast-mobius.cpp
  requiredBy: []
  timestamp: '2020-10-03 18:31:23+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/number/fast-mobius.cpp
layout: document
redirect_from:
- /library/lib/number/fast-mobius.cpp
- /library/lib/number/fast-mobius.cpp.html
title: "\u9AD8\u901F\u30E1\u30D3\u30A6\u30B9\u5909\u63DB"
---
