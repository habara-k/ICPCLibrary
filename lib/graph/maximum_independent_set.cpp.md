---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: lib/template.cpp
    title: lib/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/maximum_independent_set.test.cpp
    title: test/graph/maximum_independent_set.test.cpp
  - icon: ':x:'
    path: test/yosupo-judge/maximum_independent_set.test.cpp
    title: test/yosupo-judge/maximum_independent_set.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
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
    \   // cin.rdbuf(in.rdbuf());\n\n    return 0;\n}\n*/\n\n\n#line 2 \"lib/graph/maximum_independent_set.cpp\"\
    \n\n// \u6700\u5927\u72EC\u7ACB\u96C6\u5408 40\u9802\u70B9\u306F\u884C\u3051\u308B\
    \ \u305D\u308C\u4EE5\u4E0A\u306F\u308F\u304B\u3089\u3093\n// g\u306F\u96A3\u63A5\
    \u884C\u5217 \u5404\u884C\u306Fbit\u3067\u3082\u3064\n// \u547C\u3076\u3068\u304D\
    \u306Fnow\u3092n\u9802\u70B9\u306Ebit\u304C\u7ACB\u3063\u305F\u72B6\u614B\u306B\
    \u3059\u308B\uFF08(1ll<<n)-1)\n// author: Md\n// date: 2020/10/17\nll maximum_independent_set(int\
    \ n, ll now, const vector<ll> &g) {\n  if(now == 0) return 0;\n\n  REP(i, n) {\n\
    \    if((now>>i)&1) {\n      int d = __builtin_popcountll(g[i] & now);\n     \
    \ if(d <= 1) return maximum_independent_set(n, now & ~(1ll<<i) & ~g[i], g) | (1ll<<i);\n\
    \    }\n  }\n\n  int max_degree = 0;\n  int argma = -1;\n  REP(i, n) {\n    if((now>>i)&1)\
    \ {\n      bool upd = chmax(max_degree, __builtin_popcountll(g[i] & now));\n \
    \     if(upd) argma = i;\n    }\n  }\n\n  if(max_degree == 2) {\n    return maximum_independent_set(n,\
    \ now & ~(1ll<<argma) & ~g[argma], g) | (1ll<<argma);\n  }\n\n  ll tmp1 = maximum_independent_set(n,\
    \ now & ~(1ll<<argma) & ~g[argma], g) | (1ll<<argma);\n  ll tmp2 = maximum_independent_set(n,\
    \ now & ~(1ll<<argma), g);\n  ll cnt1 = __builtin_popcountll(tmp1);\n  ll cnt2\
    \ = __builtin_popcountll(tmp2);\n\n  return cnt1 > cnt2 ? tmp1 : tmp2;\n}\n"
  code: "#include \"../template.cpp\"\n\n// \u6700\u5927\u72EC\u7ACB\u96C6\u5408 40\u9802\
    \u70B9\u306F\u884C\u3051\u308B \u305D\u308C\u4EE5\u4E0A\u306F\u308F\u304B\u3089\
    \u3093\n// g\u306F\u96A3\u63A5\u884C\u5217 \u5404\u884C\u306Fbit\u3067\u3082\u3064\
    \n// \u547C\u3076\u3068\u304D\u306Fnow\u3092n\u9802\u70B9\u306Ebit\u304C\u7ACB\
    \u3063\u305F\u72B6\u614B\u306B\u3059\u308B\uFF08(1ll<<n)-1)\n// author: Md\n//\
    \ date: 2020/10/17\nll maximum_independent_set(int n, ll now, const vector<ll>\
    \ &g) {\n  if(now == 0) return 0;\n\n  REP(i, n) {\n    if((now>>i)&1) {\n   \
    \   int d = __builtin_popcountll(g[i] & now);\n      if(d <= 1) return maximum_independent_set(n,\
    \ now & ~(1ll<<i) & ~g[i], g) | (1ll<<i);\n    }\n  }\n\n  int max_degree = 0;\n\
    \  int argma = -1;\n  REP(i, n) {\n    if((now>>i)&1) {\n      bool upd = chmax(max_degree,\
    \ __builtin_popcountll(g[i] & now));\n      if(upd) argma = i;\n    }\n  }\n\n\
    \  if(max_degree == 2) {\n    return maximum_independent_set(n, now & ~(1ll<<argma)\
    \ & ~g[argma], g) | (1ll<<argma);\n  }\n\n  ll tmp1 = maximum_independent_set(n,\
    \ now & ~(1ll<<argma) & ~g[argma], g) | (1ll<<argma);\n  ll tmp2 = maximum_independent_set(n,\
    \ now & ~(1ll<<argma), g);\n  ll cnt1 = __builtin_popcountll(tmp1);\n  ll cnt2\
    \ = __builtin_popcountll(tmp2);\n\n  return cnt1 > cnt2 ? tmp1 : tmp2;\n}"
  dependsOn:
  - lib/template.cpp
  isVerificationFile: false
  path: lib/graph/maximum_independent_set.cpp
  requiredBy: []
  timestamp: '2020-10-17 10:05:08+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yosupo-judge/maximum_independent_set.test.cpp
  - test/graph/maximum_independent_set.test.cpp
documentation_of: lib/graph/maximum_independent_set.cpp
layout: document
redirect_from:
- /library/lib/graph/maximum_independent_set.cpp
- /library/lib/graph/maximum_independent_set.cpp.html
title: lib/graph/maximum_independent_set.cpp
---
