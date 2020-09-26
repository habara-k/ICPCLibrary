---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: lib/graph/maximum_clique.cpp
    title: lib/graph/maximum_clique.cpp
  - icon: ':heavy_check_mark:'
    path: lib/graph/template.cpp
    title: lib/graph/template.cpp
  - icon: ':heavy_check_mark:'
    path: lib/template.cpp
    title: lib/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc002/tasks/abc002_4
    links:
    - https://atcoder.jp/contests/abc002/tasks/abc002_4
  bundledCode: "#line 1 \"test/graph/maximum_clique.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/abc002/tasks/abc002_4\"\
    \n\n#line 1 \"lib/graph/template.cpp\"\n\n\n\n#line 1 \"lib/template.cpp\"\n\n\
    \n\n#include <bits/stdc++.h>\n\nusing namespace std;\n\n#define REP(i, n) for\
    \ (int i=0; i<(n); ++i)\n#define RREP(i, n) for (int i=(int)(n)-1; i>=0; --i)\n\
    #define FOR(i, a, n) for (int i=(a); i<(n); ++i)\n#define RFOR(i, a, n) for (int\
    \ i=(int)(n)-1; i>=(a); --i)\n\n#define SZ(x) ((int)(x).size())\n#define ALL(x)\
    \ (x).begin(),(x).end()\n\n#define DUMP(x) cerr<<#x<<\" = \"<<(x)<<endl\n#define\
    \ DEBUG(x) cerr<<#x<<\" = \"<<(x)<<\" (L\"<<__LINE__<<\")\"<<endl;\n\ntemplate<class\
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
    \n    return 0;\n}\n*/\n\n\n#line 5 \"lib/graph/template.cpp\"\n\ntemplate<typename\
    \ T>\nstruct edge {\n    int src, to;\n    T cost;\n};\n\ntemplate<typename T>\n\
    using Graph = vector<vector<edge<T>>>;\n\n\n#line 2 \"lib/graph/maximum_clique.cpp\"\
    \n\nint maximum_clique(const vector<vector<bool>>& G) {\n    // G: \u96A3\u63A5\
    \u884C\u5217, \u7121\u5411\u30B0\u30E9\u30D5\n    int n = G.size();\n    vector<int>\
    \ deg(n);\n    int M = 0;\n    for (int i = 0; i < n; ++i) {\n        for (int\
    \ j = i+1; j < n; ++j) {\n            ++deg[i], ++deg[j], ++M;\n        }\n  \
    \  }\n    vector<vector<bool>> g = G;\n    vector<bool> used(n);\n\n    int lim\
    \ = sqrt(2*M), ret = 0;\n\n    for (int t = 0; t < n; ++t) {\n        int u =\
    \ -1;\n        for (int i = 0; i < n; ++i) {\n            if (!used[i] && deg[i]\
    \ < lim) {\n                u = i;\n                used[u] = true;\n        \
    \        break;\n            }\n        }\n\n        vector<int> neighbor;\n \
    \       if (u != -1) neighbor.push_back(u);\n        for (int v = 0; v < n; ++v)\
    \ if (!used[v]) {\n            if (u == -1 || g[u][v]) {\n                neighbor.push_back(v);\n\
    \            }\n        }\n\n        int sz = neighbor.size();\n        vector<int>\
    \ bit(sz);\n        for(int i = 0; i < sz; i++) {\n            for(int j = i+1;\
    \ j < sz; j++) {\n                if(!g[neighbor[i]][neighbor[j]]) {\n       \
    \             bit[i] |= 1 << j;\n                    bit[j] |= 1 << i;\n     \
    \           }\n            }\n        }\n\n        vector<int> dp(1<<sz);\n  \
    \      dp[0] = 1;\n        for (int s = 1; s < 1<<sz; ++s) {\n            int\
    \ i = __builtin_ffs(s) - 1;\n\n            dp[s] = dp[s & ~(1<<i)] && (bit[i]\
    \ & s) == 0;\n            if (dp[s]) {\n                ret = max(ret, __builtin_popcount(s));\n\
    \            }\n        }\n\n        if (u == -1) break;\n\n        for (auto\
    \ v : neighbor) {\n            --deg[v], --deg[u];\n            g[u][v] = g[v][u]\
    \ = false;\n        }\n    }\n\n    return ret;\n}\n#line 4 \"test/graph/maximum_clique.cpp\"\
    \n\nint main() {\n    int N, M;\n    cin >> N >> M;\n    vector<vector<bool>>\
    \ G(N, vector<bool>(N));\n    for(int i = 0; i < M; i++) {\n        int x, y;\n\
    \        cin >> x >> y;\n        --x, --y;\n        G[x][y] = G[y][x] = true;\n\
    \    }\n\n    cout << maximum_clique(G) << endl;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc002/tasks/abc002_4\"\n\n\
    #include \"../../lib/graph/maximum_clique.cpp\"\n\nint main() {\n    int N, M;\n\
    \    cin >> N >> M;\n    vector<vector<bool>> G(N, vector<bool>(N));\n    for(int\
    \ i = 0; i < M; i++) {\n        int x, y;\n        cin >> x >> y;\n        --x,\
    \ --y;\n        G[x][y] = G[y][x] = true;\n    }\n\n    cout << maximum_clique(G)\
    \ << endl;\n}\n"
  dependsOn:
  - lib/graph/maximum_clique.cpp
  - lib/graph/template.cpp
  - lib/template.cpp
  isVerificationFile: false
  path: test/graph/maximum_clique.cpp
  requiredBy: []
  timestamp: '2020-05-06 01:41:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: test/graph/maximum_clique.cpp
layout: document
redirect_from:
- /library/test/graph/maximum_clique.cpp
- /library/test/graph/maximum_clique.cpp.html
title: test/graph/maximum_clique.cpp
---
