---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: lib/graph/topological_sort.cpp
    title: lib/graph/topological_sort.cpp
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/4/GRL_4_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/4/GRL_4_B
  bundledCode: "#line 1 \"test/graph/topological_sort.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/4/GRL_4_B\"\
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
    using Graph = vector<vector<edge<T>>>;\n\n\n#line 2 \"lib/graph/topological_sort.cpp\"\
    \n\nvoid topological_sort(const vector<vector<int>>& G, vector<int>& ord)\n{\n\
    \    int n = G.size();\n    vector<int> num(n, 0);\n    ord.assign(n, 0);\n  \
    \  for (int i = 0; i < n; ++i) {\n        for (auto u : G[i]) {\n            ++num[u];\n\
    \        }\n    }\n    stack<int> st;\n    for(int i = 0; i < n; ++i) {\n    \
    \    if (num[i] == 0) {\n            st.push(i);\n        }\n    }\n    for (int\
    \ k = 0; !st.empty(); ++k) {\n        int i = st.top(); st.pop();\n        ord[k]\
    \ = i;\n        for (auto u : G[i]) {\n            if (--num[u] == 0) {\n    \
    \            st.push(u);\n            }\n        }\n    }\n}\n#line 4 \"test/graph/topological_sort.cpp\"\
    \n\nint main() {\n    int V, E; cin >> V >> E;\n    vector<vector<int>> G(V);\n\
    \    for (int i = 0; i < E; ++i) {\n        int s, t; cin >> s >> t;\n       \
    \ G[s].push_back(t);\n    }\n    vector<int> ord;\n    topological_sort(G, ord);\n\
    \    for (auto v : ord) {\n        cout << v << endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/4/GRL_4_B\"\
    \n\n#include \"../../lib/graph/topological_sort.cpp\"\n\nint main() {\n    int\
    \ V, E; cin >> V >> E;\n    vector<vector<int>> G(V);\n    for (int i = 0; i <\
    \ E; ++i) {\n        int s, t; cin >> s >> t;\n        G[s].push_back(t);\n  \
    \  }\n    vector<int> ord;\n    topological_sort(G, ord);\n    for (auto v : ord)\
    \ {\n        cout << v << endl;\n    }\n}\n"
  dependsOn:
  - lib/graph/topological_sort.cpp
  - lib/graph/template.cpp
  - lib/template.cpp
  isVerificationFile: false
  path: test/graph/topological_sort.cpp
  requiredBy: []
  timestamp: '2020-05-06 01:41:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: test/graph/topological_sort.cpp
layout: document
redirect_from:
- /library/test/graph/topological_sort.cpp
- /library/test/graph/topological_sort.cpp.html
title: test/graph/topological_sort.cpp
---
