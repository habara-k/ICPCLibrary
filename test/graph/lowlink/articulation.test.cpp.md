---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/graph/lowlink.cpp
    title: lib/graph/lowlink.cpp
  - icon: ':heavy_check_mark:'
    path: lib/graph/template.cpp
    title: lib/graph/template.cpp
  - icon: ':heavy_check_mark:'
    path: lib/template.cpp
    title: lib/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/3/GRL_3_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/3/GRL_3_A
  bundledCode: "#line 1 \"test/graph/lowlink/articulation.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/3/GRL_3_A\"\n\n#line\
    \ 1 \"lib/graph/template.cpp\"\n\n\n\n#line 1 \"lib/template.cpp\"\n\n\n\n#include\
    \ <bits/stdc++.h>\n\nusing namespace std;\n\n#define REP(i, n) for (int i=0; i<(n);\
    \ ++i)\n#define RREP(i, n) for (int i=(int)(n)-1; i>=0; --i)\n#define FOR(i, a,\
    \ n) for (int i=(a); i<(n); ++i)\n#define RFOR(i, a, n) for (int i=(int)(n)-1;\
    \ i>=(a); --i)\n\n#define SZ(x) ((int)(x).size())\n#define ALL(x) (x).begin(),(x).end()\n\
    \n#define DUMP(x) cerr<<#x<<\" = \"<<(x)<<endl\n#define DEBUG(x) cerr<<#x<<\"\
    \ = \"<<(x)<<\" (L\"<<__LINE__<<\")\"<<endl;\n\ntemplate<class T>\nostream &operator<<(ostream\
    \ &os, const vector <T> &v) {\n    os << \"[\";\n    REP(i, SZ(v)) {\n       \
    \ if (i) os << \", \";\n        os << v[i];\n    }\n    return os << \"]\";\n\
    }\n\ntemplate<class T, class U>\nostream &operator<<(ostream &os, const pair <T,\
    \ U> &p) {\n    return os << \"(\" << p.first << \" \" << p.second << \")\";\n\
    }\n\ntemplate<class T>\nbool chmax(T &a, const T &b) {\n    if (a < b) {\n   \
    \     a = b;\n        return true;\n    }\n    return false;\n}\n\ntemplate<class\
    \ T>\nbool chmin(T &a, const T &b) {\n    if (b < a) {\n        a = b;\n     \
    \   return true;\n    }\n    return false;\n}\n\nusing ll = long long;\nusing\
    \ ull = unsigned long long;\nusing ld = long double;\nusing P = pair<int, int>;\n\
    using vi = vector<int>;\nusing vll = vector<ll>;\nusing vvi = vector<vi>;\nusing\
    \ vvll = vector<vll>;\n\nconst ll MOD = 1e9 + 7;\nconst int INF = INT_MAX / 2;\n\
    const ll LINF = LLONG_MAX / 2;\nconst ld eps = 1e-9;\n\n/*\nint main() {\n   \
    \ cin.tie(0);\n    ios::sync_with_stdio(false);\n    cout << fixed << setprecision(10);\n\
    \n    // ifstream in(\"in.txt\");\n    // cin.rdbuf(in.rdbuf());\n\n    return\
    \ 0;\n}\n*/\n\n\n#line 5 \"lib/graph/template.cpp\"\n\ntemplate<typename T>\n\
    struct edge {\n    int src, to;\n    T cost;\n};\n\ntemplate<typename T>\nusing\
    \ Graph = vector<vector<edge<T>>>;\n\n\n#line 2 \"lib/graph/lowlink.cpp\"\n\n\
    /**\n * @brief\n * \u6A4B\u3068\u95A2\u7BC0\u70B9\u3092O(n+m)\u3067\u5217\u6319\
    \n * \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\u306B\u30B0\u30E9\u30D5\u3092\u6295\
    \u3052\u8FBC\u3080\u3068bridge\u3068articulation\u304C\u66F4\u65B0\u3055\u308C\
    \u308B\n * @author Md\n * @date 2020/10/20\n */\n\nstruct Lowlink {\n  vvi g;\n\
    \  int n;\n  vi ord, low;\n  vector<P> bridge;\n  vector<int> articulation;\n\
    \  int t = 0;\n\n  Lowlink(const vvi &G): g(G) {\n    n = SZ(g);\n    ord.resize(n,\
    \ INF);\n    low.resize(n, INF);\n\n    REP(i, n) {\n      if(ord[i] == INF) {\n\
    \        dfs(i, -1);\n      }\n    }\n  }\n\n  void dfs(int now, int prev) {\n\
    \    ord[now] = t;\n    low[now] = ord[now];\n    t++;\n    int d = 0;\n    bool\
    \ ar = false;\n    for(auto &nxt: g[now]) {\n      if(nxt == prev) continue;\n\
    \      if(ord[nxt] == INF) {\n        d++;\n        dfs(nxt, now);\n        chmin(low[now],\
    \ low[nxt]);\n        ar |= prev != -1 && ord[now] <= low[nxt];\n        if(ord[now]\
    \ < low[nxt]) {\n          if(now < nxt) bridge.emplace_back(now, nxt);\n    \
    \      else bridge.emplace_back(nxt, now);\n        }\n      } else {\n      \
    \  chmin(low[now], ord[nxt]);\n      }\n    }\n    ar |= prev == -1 && d >= 2;\n\
    \    if(ar) articulation.push_back(now);\n  }\n};\n#line 4 \"test/graph/lowlink/articulation.test.cpp\"\
    \n\nint main() {\n  int n, m; cin >> n >> m;\n  vvi g(n);\n  REP(i, m) {\n   \
    \ int u, v; cin >> u >> v;\n    g[u].push_back(v);\n    g[v].push_back(u);\n \
    \ }\n\n  Lowlink lowlink(g);\n\n  sort(ALL(lowlink.articulation));\n  for(auto\
    \ &e: lowlink.articulation) {\n    cout << e << endl;\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/3/GRL_3_A\"\
    \n\n#include \"../../../lib/graph/lowlink.cpp\"\n\nint main() {\n  int n, m; cin\
    \ >> n >> m;\n  vvi g(n);\n  REP(i, m) {\n    int u, v; cin >> u >> v;\n    g[u].push_back(v);\n\
    \    g[v].push_back(u);\n  }\n\n  Lowlink lowlink(g);\n\n  sort(ALL(lowlink.articulation));\n\
    \  for(auto &e: lowlink.articulation) {\n    cout << e << endl;\n  }\n\n  return\
    \ 0;\n}\n"
  dependsOn:
  - lib/graph/lowlink.cpp
  - lib/graph/template.cpp
  - lib/template.cpp
  isVerificationFile: true
  path: test/graph/lowlink/articulation.test.cpp
  requiredBy: []
  timestamp: '2020-10-20 22:22:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/lowlink/articulation.test.cpp
layout: document
redirect_from:
- /verify/test/graph/lowlink/articulation.test.cpp
- /verify/test/graph/lowlink/articulation.test.cpp.html
title: test/graph/lowlink/articulation.test.cpp
---
