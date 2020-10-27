---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/structure/union_find.cpp
    title: lib/structure/union_find.cpp
  - icon: ':heavy_check_mark:'
    path: lib/template.cpp
    title: lib/template.cpp
  - icon: ':heavy_check_mark:'
    path: lib/template.cpp
    title: lib/template.cpp
  - icon: ':heavy_check_mark:'
    path: lib/tree/centroid.cpp
    title: "\u6728\u306E\u91CD\u5FC3\u5217\u6319. O(n)"
  - icon: ':heavy_check_mark:'
    path: lib/tree/tree_hash.cpp
    title: "\u6728\u306E\u30CF\u30C3\u30B7\u30E5\u5316"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2821
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2821
  bundledCode: "#line 1 \"test/tree/tree_hash.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2821\"\
    \n\n#line 1 \"lib/template.cpp\"\n\n\n\n#include <bits/stdc++.h>\n\nusing namespace\
    \ std;\n\n#define REP(i, n) for (int i=0; i<(n); ++i)\n#define RREP(i, n) for\
    \ (int i=(int)(n)-1; i>=0; --i)\n#define FOR(i, a, n) for (int i=(a); i<(n); ++i)\n\
    #define RFOR(i, a, n) for (int i=(int)(n)-1; i>=(a); --i)\n\n#define SZ(x) ((int)(x).size())\n\
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
    \n    return 0;\n}\n*/\n\n\n#line 2 \"lib/tree/centroid.cpp\"\n\n/**\n * @brief\
    \ \u6728\u306E\u91CD\u5FC3\u5217\u6319. O(n)\n * @author habara-k\n * @date 2020/10/14\n\
    \ */\nvector<int> centroid(const vector<vector<int>>& g) {\n    const int n =\
    \ g.size();\n    vector<int> sz(n,1), ret;\n    function<int(int,int)> dfs = [&](int\
    \ u,int p) {\n        bool isCent = true;\n        for (int v : g[u]) {\n    \
    \        if (v == p) continue;\n            sz[u] += dfs(v, u);\n            if\
    \ (sz[v] > n / 2) isCent = false;\n        }\n        if (n - sz[u] > n / 2) isCent\
    \ = false;\n        if (isCent) ret.emplace_back(u);\n        return sz[u];\n\
    \    };\n    dfs(0, -1);\n    return ret;\n}\n\n#line 3 \"lib/tree/tree_hash.cpp\"\
    \n\n/**\n * @brief \u6728\u306E\u30CF\u30C3\u30B7\u30E5\u5316\n * @author habara-k\n\
    \ * @date 2020/10/28\n * @usage\n *   vector<vector<int>> g;\n *   int seed =\
    \ 0;\n *   auto hash = RootedTreeHash(g, seed).get();\n */\nstruct TreeHash {\n\
    \    using u64 = uint64_t;\n    using i128 = __int128_t;\n\n    TreeHash(const\
    \ vector<vector<int>>& g, int seed=0) : g(g) {\n        int n = g.size();\n  \
    \      mt19937 random(seed);\n        uniform_int_distribution<u64> dist(2, MOD-2);\n\
    \        for (int i = 0; i < n; ++i) base.emplace_back(dist(random));\n    }\n\
    \n    u64 get() {\n        vector<u64> hash;\n        for (int root : centroid(g))\
    \ {\n            hash.emplace_back(dfs(root, -1, 0));\n        }\n        return\
    \ *min_element(hash.begin(), hash.end());\n    }\n\nprivate:\n    vector<u64>\
    \ base;\n    vector<vector<int>> g;\n    static const u64 MOD = (1ul << 61) -\
    \ 1;\n\n    static u64 mul(i128 a, i128 b) {\n        i128 t = a * b;\n      \
    \  t = (t >> 61) + (t & MOD);\n        if (t >= MOD) t -= MOD;\n        return\
    \ t;\n    }\n\n    u64 dfs(int u, int p, int d) {\n        u64 hash = 1;\n   \
    \     for (int v : g[u]) {\n            if (v == p) continue;\n            hash\
    \ = mul(hash, dfs(v, u, d+1));\n        }\n        hash += base[d];\n        return\
    \ hash >= MOD ? hash - MOD : hash;\n    }\n};\n\n#line 2 \"lib/structure/union_find.cpp\"\
    \n\nstruct UnionFind\n{\n    vector<int> par, sz;\n    UnionFind(int n) : par(n),\
    \ sz(n, 1) {\n        for (int i = 0; i < n; ++i) par[i] = i;\n    }\n    int\
    \ root(int x) {\n        if (par[x] == x) return x;\n        return par[x] = root(par[x]);\n\
    \    }\n    void merge(int x, int y) {\n        x = root(x);\n        y = root(y);\n\
    \        if (x == y) return;\n        if (sz[x] < sz[y]) swap(x, y);\n       \
    \ par[y] = x;\n        sz[x] += sz[y];\n        sz[y] = 0;\n    }\n    bool issame(int\
    \ x, int y) {\n        return root(x) == root(y);\n    }\n    int size(int x)\
    \ {\n        return sz[root(x)];\n    }\n};\n#line 5 \"test/tree/tree_hash.test.cpp\"\
    \n\nint main() {\n    int n1, m1; cin >> n1 >> m1;\n    vector<vector<int>> g1(n1);\n\
    \    UnionFind uf(n1);\n    REP(i, m1) {\n        int u, v; cin >> u >> v; --u,\
    \ --v;\n        g1[u].emplace_back(v);\n        g1[v].emplace_back(u);\n     \
    \   uf.merge(u, v);\n    }\n    int n2; cin >> n2;\n    vector<vector<int>> g2(n2);\n\
    \    REP(i, n2-1) {\n        int u, v; cin >> u >> v; --u, --v;\n        g2[u].emplace_back(v);\n\
    \        g2[v].emplace_back(u);\n    }\n\n    vector<int> roots;\n    for (int\
    \ i = 0; i < n1; ++i) if (uf.root(i) == i) roots.emplace_back(i);\n\n    map<int,map<int,int>>\
    \ ord;\n    for (int i = 0; i < n1; ++i) {\n        ord[uf.root(i)][i] = -1;\n\
    \    }\n\n    map<int,vector<vector<int>>> g;\n    for (auto& tp : ord) {\n  \
    \      int cnt = 0;\n        for (auto& p : tp.second) {\n            p.second\
    \ = cnt++;\n        }\n        g[tp.first].resize(cnt);\n    }\n\n    for (int\
    \ u = 0; u < n1; ++u) {\n        int r = uf.root(u);\n        for (int v : g1[u])\
    \ {\n            g[r][ord[r][u]].emplace_back(ord[r][v]);\n        }\n    }\n\n\
    \    int ans = 0;\n    auto hash = TreeHash(g2).get();\n    for (auto &tp : g)\
    \ {\n        auto h = TreeHash(tp.second).get();\n        ans += h == hash;\n\
    \    }\n\n    cout << ans << endl;\n}\n\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2821\"\
    \n\n#include \"../../lib/tree/tree_hash.cpp\"\n#include \"../../lib/structure/union_find.cpp\"\
    \n\nint main() {\n    int n1, m1; cin >> n1 >> m1;\n    vector<vector<int>> g1(n1);\n\
    \    UnionFind uf(n1);\n    REP(i, m1) {\n        int u, v; cin >> u >> v; --u,\
    \ --v;\n        g1[u].emplace_back(v);\n        g1[v].emplace_back(u);\n     \
    \   uf.merge(u, v);\n    }\n    int n2; cin >> n2;\n    vector<vector<int>> g2(n2);\n\
    \    REP(i, n2-1) {\n        int u, v; cin >> u >> v; --u, --v;\n        g2[u].emplace_back(v);\n\
    \        g2[v].emplace_back(u);\n    }\n\n    vector<int> roots;\n    for (int\
    \ i = 0; i < n1; ++i) if (uf.root(i) == i) roots.emplace_back(i);\n\n    map<int,map<int,int>>\
    \ ord;\n    for (int i = 0; i < n1; ++i) {\n        ord[uf.root(i)][i] = -1;\n\
    \    }\n\n    map<int,vector<vector<int>>> g;\n    for (auto& tp : ord) {\n  \
    \      int cnt = 0;\n        for (auto& p : tp.second) {\n            p.second\
    \ = cnt++;\n        }\n        g[tp.first].resize(cnt);\n    }\n\n    for (int\
    \ u = 0; u < n1; ++u) {\n        int r = uf.root(u);\n        for (int v : g1[u])\
    \ {\n            g[r][ord[r][u]].emplace_back(ord[r][v]);\n        }\n    }\n\n\
    \    int ans = 0;\n    auto hash = TreeHash(g2).get();\n    for (auto &tp : g)\
    \ {\n        auto h = TreeHash(tp.second).get();\n        ans += h == hash;\n\
    \    }\n\n    cout << ans << endl;\n}\n\n"
  dependsOn:
  - lib/tree/tree_hash.cpp
  - lib/template.cpp
  - lib/tree/centroid.cpp
  - lib/structure/union_find.cpp
  - lib/template.cpp
  isVerificationFile: true
  path: test/tree/tree_hash.test.cpp
  requiredBy: []
  timestamp: '2020-10-28 03:11:36+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/tree/tree_hash.test.cpp
layout: document
redirect_from:
- /verify/test/tree/tree_hash.test.cpp
- /verify/test/tree/tree_hash.test.cpp.html
title: test/tree/tree_hash.test.cpp
---
