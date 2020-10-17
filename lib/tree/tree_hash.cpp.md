---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: lib/template.cpp
    title: lib/template.cpp
  - icon: ':heavy_check_mark:'
    path: lib/tree/centroid.cpp
    title: "\u6728\u306E\u91CD\u5FC3\u5217\u6319. O(n)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/tree/tree_hash.test.cpp
    title: test/tree/tree_hash.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u6728\u306E\u30CF\u30C3\u30B7\u30E5\u5316"
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
    \   // cin.rdbuf(in.rdbuf());\n\n    return 0;\n}\n*/\n\n\n#line 2 \"lib/tree/centroid.cpp\"\
    \n\n/**\n * @brief \u6728\u306E\u91CD\u5FC3\u5217\u6319. O(n)\n * @author habara-k\n\
    \ * @date 2020/10/14\n */\nvector<int> centroid(const vector<vector<int>>& g)\
    \ {\n    const int n = g.size();\n    vector<int> sz(n,1), ret;\n    function<int(int,int)>\
    \ dfs = [&](int u,int p) {\n        bool isCent = true;\n        for (int v :\
    \ g[u]) {\n            if (v == p) continue;\n            sz[u] += dfs(v, u);\n\
    \            if (sz[v] > n / 2) isCent = false;\n        }\n        if (n - sz[u]\
    \ > n / 2) isCent = false;\n        if (isCent) ret.emplace_back(u);\n       \
    \ return sz[u];\n    };\n    dfs(0, -1);\n    return ret;\n}\n\n#line 3 \"lib/tree/tree_hash.cpp\"\
    \n\n/**\n * @brief \u6728\u306E\u30CF\u30C3\u30B7\u30E5\u5316\n * @author habara-k\n\
    \ * @date 2020/10/14\n * @details \u4F7F\u3044\u65B9\n *   vector<vector<int>>\
    \ g;\n *   int seed = 0;\n *   auto hash = RootedTreeHash(g, seed).get();\n */\n\
    struct TreeHash {\n    using uint = uint64_t;\n\n    /**\n     * @brief \u30B3\
    \u30F3\u30B9\u30C8\u30E9\u30AF\u30BF. O(|n|)\n     * @param[in] g \u30CF\u30C3\
    \u30B7\u30E5\u5316\u3059\u308B\u6728\n     * @param[in] seed \u30CF\u30C3\u30B7\
    \u30E5\u5316\u306B\u4F7F\u3046\u30B7\u30FC\u30C9\n     */\n    TreeHash(const\
    \ vector<vector<int>>& g, int seed=0) : g(g) {\n        int n = g.size();\n  \
    \      mt19937 random(seed);\n        uniform_int_distribution<uint> dist(2, MASK61\
    \ - 2);\n        for (int i = 0; i < n; ++i) base.emplace_back(dist(random));\n\
    \    }\n\n    /**\n     * @brief \u30CF\u30C3\u30B7\u30E5\u306E\u8A08\u7B97. O(|n|)\n\
    \     */\n    uint get() {\n        vector<uint> hash;\n        for (int root\
    \ : centroid(g)) {\n            hash.emplace_back(dfs(root, -1, 0));\n       \
    \ }\n        return *min_element(hash.begin(), hash.end());\n    }\n\nprivate:\n\
    \    vector<uint> base;\n    vector<vector<int>> g;\n    static const uint MASK30\
    \ = (1LL << 30) - 1,\n            MASK31 = (1LL << 31) - 1,\n            MASK61\
    \ = (1LL << 61) - 1;\n\n    static uint mul(uint a, uint b) {\n        uint au\
    \ = a >> 31, ad = a & MASK31,\n                bu = b >> 31, bd = b & MASK31;\n\
    \        uint m = au * bd + ad * bu;\n        uint mu = m >> 30, md = m & MASK30;\n\
    \n        return mod(au * bu * 2 + mu + (md << 31) + ad * bd);\n    }\n\n    static\
    \ uint mod(uint x) {\n        uint xu = x >> 61, xd = x & MASK61;\n        uint\
    \ ret = xu + xd;\n        if (ret >= MASK61) ret -= MASK61;\n        return ret;\n\
    \    }\n\n    uint dfs(int u, int p, int d) {\n        uint hash = 1;\n      \
    \  for (int v : g[u]) {\n            if (v == p) continue;\n            hash =\
    \ mul(hash, dfs(v, u, d+1));\n        }\n        return mod(hash + base[d]);\n\
    \    }\n};\n\n"
  code: "#include \"../template.cpp\"\n#include \"centroid.cpp\"\n\n/**\n * @brief\
    \ \u6728\u306E\u30CF\u30C3\u30B7\u30E5\u5316\n * @author habara-k\n * @date 2020/10/14\n\
    \ * @details \u4F7F\u3044\u65B9\n *   vector<vector<int>> g;\n *   int seed =\
    \ 0;\n *   auto hash = RootedTreeHash(g, seed).get();\n */\nstruct TreeHash {\n\
    \    using uint = uint64_t;\n\n    /**\n     * @brief \u30B3\u30F3\u30B9\u30C8\
    \u30E9\u30AF\u30BF. O(|n|)\n     * @param[in] g \u30CF\u30C3\u30B7\u30E5\u5316\
    \u3059\u308B\u6728\n     * @param[in] seed \u30CF\u30C3\u30B7\u30E5\u5316\u306B\
    \u4F7F\u3046\u30B7\u30FC\u30C9\n     */\n    TreeHash(const vector<vector<int>>&\
    \ g, int seed=0) : g(g) {\n        int n = g.size();\n        mt19937 random(seed);\n\
    \        uniform_int_distribution<uint> dist(2, MASK61 - 2);\n        for (int\
    \ i = 0; i < n; ++i) base.emplace_back(dist(random));\n    }\n\n    /**\n    \
    \ * @brief \u30CF\u30C3\u30B7\u30E5\u306E\u8A08\u7B97. O(|n|)\n     */\n    uint\
    \ get() {\n        vector<uint> hash;\n        for (int root : centroid(g)) {\n\
    \            hash.emplace_back(dfs(root, -1, 0));\n        }\n        return *min_element(hash.begin(),\
    \ hash.end());\n    }\n\nprivate:\n    vector<uint> base;\n    vector<vector<int>>\
    \ g;\n    static const uint MASK30 = (1LL << 30) - 1,\n            MASK31 = (1LL\
    \ << 31) - 1,\n            MASK61 = (1LL << 61) - 1;\n\n    static uint mul(uint\
    \ a, uint b) {\n        uint au = a >> 31, ad = a & MASK31,\n                bu\
    \ = b >> 31, bd = b & MASK31;\n        uint m = au * bd + ad * bu;\n        uint\
    \ mu = m >> 30, md = m & MASK30;\n\n        return mod(au * bu * 2 + mu + (md\
    \ << 31) + ad * bd);\n    }\n\n    static uint mod(uint x) {\n        uint xu\
    \ = x >> 61, xd = x & MASK61;\n        uint ret = xu + xd;\n        if (ret >=\
    \ MASK61) ret -= MASK61;\n        return ret;\n    }\n\n    uint dfs(int u, int\
    \ p, int d) {\n        uint hash = 1;\n        for (int v : g[u]) {\n        \
    \    if (v == p) continue;\n            hash = mul(hash, dfs(v, u, d+1));\n  \
    \      }\n        return mod(hash + base[d]);\n    }\n};\n\n"
  dependsOn:
  - lib/template.cpp
  - lib/tree/centroid.cpp
  isVerificationFile: false
  path: lib/tree/tree_hash.cpp
  requiredBy: []
  timestamp: '2020-10-15 21:18:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/tree/tree_hash.test.cpp
documentation_of: lib/tree/tree_hash.cpp
layout: document
redirect_from:
- /library/lib/tree/tree_hash.cpp
- /library/lib/tree/tree_hash.cpp.html
title: "\u6728\u306E\u30CF\u30C3\u30B7\u30E5\u5316"
---
