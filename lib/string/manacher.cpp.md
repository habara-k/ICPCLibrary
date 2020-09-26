---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/template.cpp
    title: lib/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: "\u6587\u5B57\u5217\u306E\u5404\u4F4D\u7F6E\u3092\u4E2D\u5FC3\u3068\
      \u3059\u308B\u56DE\u6587\u9577\u3092O(|S|)\u3067\u6C42\u3081\u308B"
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
    \   // cin.rdbuf(in.rdbuf());\n\n    return 0;\n}\n*/\n\n\n#line 2 \"lib/string/manacher.cpp\"\
    \n\n/*\n * @brief \u6587\u5B57\u5217\u306E\u5404\u4F4D\u7F6E\u3092\u4E2D\u5FC3\
    \u3068\u3059\u308B\u56DE\u6587\u9577\u3092O(|S|)\u3067\u6C42\u3081\u308B\n * @detail\
    \ \u5076\u6570\u9577\u306E\u56DE\u6587\u306B\u3064\u3044\u3066\u540C\u3058\u3053\
    \u3068\u3092\u3057\u305F\u3044\u3068\u304D\u306F\u306Fabcde -> $a$b$c$d$e$ \u307F\
    \u305F\u3044\u306A\u5909\u63DB\u3092\u3057\u3066\u4F7F\u3046\n * @author Md\n\
    \ * @date 2020/07/10\n */\nvi Manacher(string s) {\n  int c = 0, n = SZ(s); //\
    \ c: \u3059\u3067\u306B\u898B\u3064\u3051\u305F\u56DE\u6587\u306E\u3046\u3061\u3001\
    \u53F3\u7AEF\u304C\u6700\u3082\u53F3\u306B\u6709\u308B\u3088\u3046\u306A\u3082\
    \u306E\n  vi r(n, 1);\n  REP(i, n) {\n    int l = c - (i - c);\n    if(i + r[l]\
    \ < c + r[c]) { // \u4F4D\u7F6Ec\u306E\u56DE\u6587\u306B\u4F4D\u7F6El\u306E\u56DE\
    \u6587\u304C\u542B\u307E\u308C\u3066\u3044\u308C\u3070\u3001r[l]\u3068r[i]\u306F\
    \u4E00\u81F4\u3059\u308B\n      r[i] = r[l];\n    } else {\n      int j = c +\
    \ r[c] - i; // c\u306B\u542B\u307E\u308C\u3066\u3044\u308B\u90E8\u5206\u306F\u5927\
    \u4E08\u592B(\u305D\u3046\u3067\u306A\u3051\u308C\u3070if\u7BC0\u306B\u884C\u304F\
    \u306F\u305A\n      while(i - j >= 0 && i + j < n && s[i-j] == s[i+j]) ++j; //\
    \ \u611A\u76F4\u306B\u6C42\u3081\u308B\n      r[i] = j;\n      c = i;\n    }\n\
    \  }\n  return r;\n}\n"
  code: "#include \"../template.cpp\"\n\n/*\n * @brief \u6587\u5B57\u5217\u306E\u5404\
    \u4F4D\u7F6E\u3092\u4E2D\u5FC3\u3068\u3059\u308B\u56DE\u6587\u9577\u3092O(|S|)\u3067\
    \u6C42\u3081\u308B\n * @detail \u5076\u6570\u9577\u306E\u56DE\u6587\u306B\u3064\
    \u3044\u3066\u540C\u3058\u3053\u3068\u3092\u3057\u305F\u3044\u3068\u304D\u306F\
    \u306Fabcde -> $a$b$c$d$e$ \u307F\u305F\u3044\u306A\u5909\u63DB\u3092\u3057\u3066\
    \u4F7F\u3046\n * @author Md\n * @date 2020/07/10\n */\nvi Manacher(string s) {\n\
    \  int c = 0, n = SZ(s); // c: \u3059\u3067\u306B\u898B\u3064\u3051\u305F\u56DE\
    \u6587\u306E\u3046\u3061\u3001\u53F3\u7AEF\u304C\u6700\u3082\u53F3\u306B\u6709\
    \u308B\u3088\u3046\u306A\u3082\u306E\n  vi r(n, 1);\n  REP(i, n) {\n    int l\
    \ = c - (i - c);\n    if(i + r[l] < c + r[c]) { // \u4F4D\u7F6Ec\u306E\u56DE\u6587\
    \u306B\u4F4D\u7F6El\u306E\u56DE\u6587\u304C\u542B\u307E\u308C\u3066\u3044\u308C\
    \u3070\u3001r[l]\u3068r[i]\u306F\u4E00\u81F4\u3059\u308B\n      r[i] = r[l];\n\
    \    } else {\n      int j = c + r[c] - i; // c\u306B\u542B\u307E\u308C\u3066\u3044\
    \u308B\u90E8\u5206\u306F\u5927\u4E08\u592B(\u305D\u3046\u3067\u306A\u3051\u308C\
    \u3070if\u7BC0\u306B\u884C\u304F\u306F\u305A\n      while(i - j >= 0 && i + j\
    \ < n && s[i-j] == s[i+j]) ++j; // \u611A\u76F4\u306B\u6C42\u3081\u308B\n    \
    \  r[i] = j;\n      c = i;\n    }\n  }\n  return r;\n}\n"
  dependsOn:
  - lib/template.cpp
  isVerificationFile: false
  path: lib/string/manacher.cpp
  requiredBy: []
  timestamp: '2020-07-10 01:09:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/string/manacher.cpp
layout: document
redirect_from:
- /library/lib/string/manacher.cpp
- /library/lib/string/manacher.cpp.html
title: "\u6587\u5B57\u5217\u306E\u5404\u4F4D\u7F6E\u3092\u4E2D\u5FC3\u3068\u3059\u308B\
  \u56DE\u6587\u9577\u3092O(|S|)\u3067\u6C42\u3081\u308B"
---
