---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: lib/template.cpp
    title: lib/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/heavy_light_decomposition/hld.test.cpp
    title: test/graph/heavy_light_decomposition/hld.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/heavy_light_decomposition/lca.test.cpp
    title: test/graph/heavy_light_decomposition/lca.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "HL\u5206\u89E3"
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
    \   // cin.rdbuf(in.rdbuf());\n\n    return 0;\n}\n*/\n\n\n#line 2 \"lib/graph/heavy_light_decomposition.cpp\"\
    \n\n/**\n* @brief HL\u5206\u89E3\n* @author habara-k\n* @date 2020/04/26\n* @details\
    \ \u4F7F\u3044\u65B9\n*   vector<vector<int>> g(n); // tree\n*\n*   HLDecomposition\
    \ hld(g);\n*   hld.build(); // \u5FC5\u305Abuild\u3059\u308B!\n*/\n\nstruct HLDecomposition\
    \ {\n\n    /**\n    * @brief \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF. O(|V|).\n\
    \    * @param[in] g HL\u5206\u89E3\u3059\u308B\u6728.\n    */\n    HLDecomposition(const\
    \ vector<vector<int>>& g) :\n        g(g), par(g.size()), size(g.size()), depth(g.size()),\n\
    \        head(g.size()), vid(g.size()) {}\n\n    /**\n    * @brief HL\u5206\u89E3\
    \u3092\u884C\u3046. O(|V|).\n    * @param[in] root \u6839\u3092\u6307\u5B9A\u3059\
    \u308B. \u30C7\u30D5\u30A9\u30EB\u30C8\u306F0\n    */\n    void build(int root\
    \ = 0) {\n        dfs(root, -1, 0);\n        int k = 0;\n        hld(root, root,\
    \ k);\n    }\n\n    /**\n    * @brief HL\u5206\u89E3\u3092\u884C\u3046. O(log|V|).\n\
    \    * @param[in] u, v lca\u3092\u6C42\u3081\u305F\u30442\u9802\u70B9\n    * @return\
    \ 2\u9802\u70B9u, v \u306Elca\n    */\n    int lca(int u, int v) const {\n   \
    \     for (;; v = par[head[v]]) {\n            if (depth[head[u]] > depth[head[v]])\
    \ swap(u, v);\n            if (head[u] == head[v]) {\n                if (depth[u]\
    \ > depth[v]) swap(u, v);\n                return u;\n            }\n        }\n\
    \    }\n\n    /**\n    * @brief \u6307\u5B9A\u3057\u305F2\u9802\u70B9\u9593\u306E\
    \u30D1\u30B9\u4E0A\u3067\u66F4\u65B0\u30AF\u30A8\u30EA\u3092\u5B9F\u884C\u3059\
    \u308B. O(log|V|) * O(q).\n    * @param[in] u, v \u66F4\u65B0\u30AF\u30A8\u30EA\
    \u3092\u5B9F\u884C\u3059\u308B\u30D1\u30B9\u306E\u4E21\u7AEF.\n    * @param[in]\
    \ q \u5B9F\u884C\u3059\u308B\u66F4\u65B0\u30AF\u30A8\u30EA.\n    * @param[in]\
    \ edge \u8FBA\u30AF\u30A8\u30EA\u304B\u9802\u70B9\u30AF\u30A8\u30EA\u304B. \u30C7\
    \u30D5\u30A9\u30EB\u30C8\u306F\u9802\u70B9\u30AF\u30A8\u30EA.\n    *   \u8FBA\u30AF\
    \u30A8\u30EA:\n    *     \u6728\u4E0A\u306E\u8FBA\u306B\u5BFE\u3057\u3066\u30AF\
    \u30A8\u30EA\u3092\u51E6\u7406\u3059\u308B.\n    *     \u8FBA\u306E\u30C7\u30FC\
    \u30BF\u306F\u5B50\u9802\u70B9\u306Eindex\u306B\u5BFE\u5FDC\u3057\u3066\u3044\u308B\
    .\n    *     \u89AA\u9802\u70B9\u306Eindex\u306B\u5BFE\u5FDC\u3059\u308B\u8FBA\
    \u306F\u7121\u3044.\n    *   \u9802\u70B9\u30AF\u30A8\u30EA:\n    *     \u6728\
    \u4E0A\u306E\u9802\u70B9\u306B\u5BFE\u3057\u3066\u30AF\u30A8\u30EA\u3092\u51E6\
    \u7406\u3059\u308B.\n    *\n    * @details \u4F7F\u3044\u65B9\n    *     e.g.\
    \ Range Update Query\n    *     LazySegmentTree<int> segt;\n    *            //\
    \ \u6728\u306B\u5BFE\u5FDC\u3059\u308B\u9045\u5EF6\u30BB\u30B0\u30E1\u30F3\u30C8\
    \u6728.\n    *            // \u6728\u306E\u9802\u70B9\u304C\u305D\u306E\u307E\u307E\
    segt\u306Eindex\u306B\u306A\u308B\u308F\u3051\u3067\u306F\u7121\u3044\u306E\u3067\
    \u6CE8\u610F.\n    *     int u, v, x;\n    *            // u, v \u9593\u306E\u30D1\
    \u30B9\u4E0A\u306B\u3042\u308B\u5168\u3066\u306E\u9802\u70B9\u306E\u5024\u3092\
    x \u306B\u5909\u66F4\u3057\u305F\u3044.\n    *     hld.update(u, v, [&](int s,int\
    \ t){ segt.update(s, t, x); });\n    *            // u, v \u9593\u306E\u30D1\u30B9\
    \u3092\u5C0F\u5206\u3051\u306B\u3057\u305F\u533A\u9593\u5168\u4F53\u306B\n   \
    \ *            // \u7B2C\u4E09\u5F15\u6570\u306E\u95A2\u6570\u304C\u5B9F\u884C\
    \u3055\u308C\u308B.\n    */\n    template<class UpdateQuery>\n    void update(int\
    \ u, int v, const UpdateQuery& q, bool edge = false) const {\n        for (;;\
    \ v = par[head[v]]) {\n            if (depth[head[u]] > depth[head[v]]) swap(u,\
    \ v);\n            if (head[u] == head[v]) {\n                if (vid[u] > vid[v])\
    \ swap(u, v);\n                q(vid[u] + edge, vid[v] + 1);\n               \
    \ break;\n            } else {\n                q(vid[head[v]], vid[v] + 1);\n\
    \            }\n        }\n    }\n\n    /**\n    * @brief \u6307\u5B9A\u3057\u305F\
    2\u9802\u70B9\u9593\u306E\u30D1\u30B9\u4E0A\u3067\u53D6\u5F97\u30AF\u30A8\u30EA\
    \u3092\u5B9F\u884C. O(log|V|) * (O(q)+O(f)).\n    * @param[in] u, v \u53D6\u5F97\
    \u30AF\u30A8\u30EA\u3092\u5B9F\u884C\u3059\u308B\u30D1\u30B9\u306E\u4E21\u7AEF\
    .\n    * @param[in] q \u5B9F\u884C\u3059\u308B\u53D6\u5F97\u30AF\u30A8\u30EA.\n\
    \    * @param[in] f \u5C0F\u5206\u3051\u306B\u3057\u305F\u533A\u9593\u304B\u3089\
    \u53D6\u5F97\u3057\u305F\u5024\u3092\u30DE\u30FC\u30B8\u3059\u308B\u65B9\u6CD5\
    .\n    * @param[in] ident f\u306E\u5358\u4F4D\u5143.\n    * @param[in] edge \u8FBA\
    \u30AF\u30A8\u30EA\u304B\u9802\u70B9\u30AF\u30A8\u30EA\u304B. \u30C7\u30D5\u30A9\
    \u30EB\u30C8\u306F\u9802\u70B9\u30AF\u30A8\u30EA.\n    * @return \u53D6\u5F97\u3057\
    \u305F\u5024.\n    *\n    * @details \u4F7F\u3044\u65B9\n    *     e.g. Range\
    \ Minimum Query\n    *     SegmentTree<int> segt;\n    *            // \u6728\u306B\
    \u5BFE\u5FDC\u3059\u308B\u30BB\u30B0\u30E1\u30F3\u30C8\u6728.\n    *         \
    \   // \u6728\u306E\u9802\u70B9\u304C\u305D\u306E\u307E\u307Esegt\u306Eindex\u306B\
    \u306A\u308B\u308F\u3051\u3067\u306F\u7121\u3044\u306E\u3067\u6CE8\u610F.\n  \
    \  *     int u, v;\n    *            // u, v \u9593\u306E\u30D1\u30B9\u4E0A\u306B\
    \u3042\u308B\u5168\u3066\u306E\u9802\u70B9\u306E\u5024\u306Emin\u3092\u53D6\u5F97\
    \u3057\u305F\u3044.\n    *     hld.query(u, v,\n    *          [&](int s,int t){\
    \ return segt.query(s,t); },\n    *          [&](int a,int b){ return min(a,b);\
    \ }, INF);\n    *            // u, v \u9593\u306E\u30D1\u30B9\u3092\u5C0F\u5206\
    \u3051\u306B\u3057\u305F\u533A\u9593\u5168\u4F53\u306B\n    *            // \u7B2C\
    \u4E09\u5F15\u6570\u306E\u95A2\u6570\u304C\u5B9F\u884C\u3055\u308C\u308B.\n  \
    \  *            // \u5404\u533A\u9593\u304B\u3089\u53D6\u5F97\u3057\u305F\u5024\
    \u306F, \u7B2C\u56DB\u5F15\u6570\u306E\u95A2\u6570\u306B\u3088\u3063\u3066\u30DE\
    \u30FC\u30B8\u3055\u308C\u308B.\n    *            // min\u306E\u5358\u4F4D\u5143\
    INF\u3092\u7B2C\u4E94\u5F15\u6570\u306B\u6E21\u3059.\n    */\n    template<class\
    \ Query, class MergeFunc, typename T>\n    T query(int u, int v,\n           \
    \ const Query& q, const MergeFunc& f,\n            const T& ident, bool edge =\
    \ false) const {\n        T ret = ident;\n        for (;; v = par[head[v]]) {\n\
    \            if (depth[head[u]] > depth[head[v]]) swap(u, v);\n            if\
    \ (head[u] == head[v]) {\n                if (vid[u] > vid[v]) swap(u, v);\n \
    \               return f(ret, q(vid[u] + edge, vid[v] + 1));\n            } else\
    \ {\n                ret = f(ret, q(vid[head[v]], vid[v] + 1));\n            }\n\
    \        }\n    }\n\nprivate:\n    const vector<vector<int>>& g;\n    vector<int>\
    \ par, size, depth, head, vid;\n    // par[v] := \u9802\u70B9v \u306E\u89AA\u9802\
    \u70B9.\n    // size[v] := \u9802\u70B9v \u3092\u6839\u3068\u3057\u305F\u90E8\u5206\
    \u6728\u306E\u9802\u70B9\u6570.\n    // depth[v] := \u9802\u70B9v \u306E\u6DF1\
    \u3055. \u6839\u306E\u6DF1\u3055\u306F0.\n    // head[v] := HL\u5206\u89E3\u3057\
    \u305F\u969B\u306B, \u9802\u70B9v \u3092\u542B\u3080\u533A\u9593\u306E\u5148\u982D\
    \u306B\u4F4D\u7F6E\u3059\u308B\u9802\u70B9.\n    // vid[v] := \u9802\u70B9v \u306B\
    \u5BFE\u5FDC\u3059\u308B\u5185\u90E8index.\n    //           HL\u5206\u89E3\u3057\
    \u305F\u5F8C\u306E\u5404\u533A\u9593\u4E0A\u3067, vid\u306F\u9023\u7D9A\u3057\u3066\
    \u3044\u308B.\n\n    void dfs(int v, int p, int d) {\n        par[v] = p; depth[v]\
    \ = d; size[v] = 1;\n        for (int u : g[v]) {\n            if (u == p) continue;\n\
    \            dfs(u, v, d+1);\n            size[v] += size[u];\n        }\n   \
    \ }\n    void hld(int v, int h, int& k) {\n        head[v] = h; vid[v] = k++;\n\
    \        int ma = 0, id = -1;\n        for (int u : g[v]) {\n            if (u\
    \ == par[v]) continue;\n            if (chmax(ma, size[u])) id = u;\n        }\n\
    \        if (id == -1) return;\n        hld(id, h, k);\n        for (int u : g[v])\
    \ {\n            if (u == id or u == par[v]) continue;\n            hld(u, u,\
    \ k);\n        }\n    }\n};\n"
  code: "#include \"../template.cpp\"\n\n/**\n* @brief HL\u5206\u89E3\n* @author habara-k\n\
    * @date 2020/04/26\n* @details \u4F7F\u3044\u65B9\n*   vector<vector<int>> g(n);\
    \ // tree\n*\n*   HLDecomposition hld(g);\n*   hld.build(); // \u5FC5\u305Abuild\u3059\
    \u308B!\n*/\n\nstruct HLDecomposition {\n\n    /**\n    * @brief \u30B3\u30F3\u30B9\
    \u30C8\u30E9\u30AF\u30BF. O(|V|).\n    * @param[in] g HL\u5206\u89E3\u3059\u308B\
    \u6728.\n    */\n    HLDecomposition(const vector<vector<int>>& g) :\n       \
    \ g(g), par(g.size()), size(g.size()), depth(g.size()),\n        head(g.size()),\
    \ vid(g.size()) {}\n\n    /**\n    * @brief HL\u5206\u89E3\u3092\u884C\u3046.\
    \ O(|V|).\n    * @param[in] root \u6839\u3092\u6307\u5B9A\u3059\u308B. \u30C7\u30D5\
    \u30A9\u30EB\u30C8\u306F0\n    */\n    void build(int root = 0) {\n        dfs(root,\
    \ -1, 0);\n        int k = 0;\n        hld(root, root, k);\n    }\n\n    /**\n\
    \    * @brief HL\u5206\u89E3\u3092\u884C\u3046. O(log|V|).\n    * @param[in] u,\
    \ v lca\u3092\u6C42\u3081\u305F\u30442\u9802\u70B9\n    * @return 2\u9802\u70B9\
    u, v \u306Elca\n    */\n    int lca(int u, int v) const {\n        for (;; v =\
    \ par[head[v]]) {\n            if (depth[head[u]] > depth[head[v]]) swap(u, v);\n\
    \            if (head[u] == head[v]) {\n                if (depth[u] > depth[v])\
    \ swap(u, v);\n                return u;\n            }\n        }\n    }\n\n\
    \    /**\n    * @brief \u6307\u5B9A\u3057\u305F2\u9802\u70B9\u9593\u306E\u30D1\
    \u30B9\u4E0A\u3067\u66F4\u65B0\u30AF\u30A8\u30EA\u3092\u5B9F\u884C\u3059\u308B\
    . O(log|V|) * O(q).\n    * @param[in] u, v \u66F4\u65B0\u30AF\u30A8\u30EA\u3092\
    \u5B9F\u884C\u3059\u308B\u30D1\u30B9\u306E\u4E21\u7AEF.\n    * @param[in] q \u5B9F\
    \u884C\u3059\u308B\u66F4\u65B0\u30AF\u30A8\u30EA.\n    * @param[in] edge \u8FBA\
    \u30AF\u30A8\u30EA\u304B\u9802\u70B9\u30AF\u30A8\u30EA\u304B. \u30C7\u30D5\u30A9\
    \u30EB\u30C8\u306F\u9802\u70B9\u30AF\u30A8\u30EA.\n    *   \u8FBA\u30AF\u30A8\u30EA\
    :\n    *     \u6728\u4E0A\u306E\u8FBA\u306B\u5BFE\u3057\u3066\u30AF\u30A8\u30EA\
    \u3092\u51E6\u7406\u3059\u308B.\n    *     \u8FBA\u306E\u30C7\u30FC\u30BF\u306F\
    \u5B50\u9802\u70B9\u306Eindex\u306B\u5BFE\u5FDC\u3057\u3066\u3044\u308B.\n   \
    \ *     \u89AA\u9802\u70B9\u306Eindex\u306B\u5BFE\u5FDC\u3059\u308B\u8FBA\u306F\
    \u7121\u3044.\n    *   \u9802\u70B9\u30AF\u30A8\u30EA:\n    *     \u6728\u4E0A\
    \u306E\u9802\u70B9\u306B\u5BFE\u3057\u3066\u30AF\u30A8\u30EA\u3092\u51E6\u7406\
    \u3059\u308B.\n    *\n    * @details \u4F7F\u3044\u65B9\n    *     e.g. Range\
    \ Update Query\n    *     LazySegmentTree<int> segt;\n    *            // \u6728\
    \u306B\u5BFE\u5FDC\u3059\u308B\u9045\u5EF6\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\
    .\n    *            // \u6728\u306E\u9802\u70B9\u304C\u305D\u306E\u307E\u307E\
    segt\u306Eindex\u306B\u306A\u308B\u308F\u3051\u3067\u306F\u7121\u3044\u306E\u3067\
    \u6CE8\u610F.\n    *     int u, v, x;\n    *            // u, v \u9593\u306E\u30D1\
    \u30B9\u4E0A\u306B\u3042\u308B\u5168\u3066\u306E\u9802\u70B9\u306E\u5024\u3092\
    x \u306B\u5909\u66F4\u3057\u305F\u3044.\n    *     hld.update(u, v, [&](int s,int\
    \ t){ segt.update(s, t, x); });\n    *            // u, v \u9593\u306E\u30D1\u30B9\
    \u3092\u5C0F\u5206\u3051\u306B\u3057\u305F\u533A\u9593\u5168\u4F53\u306B\n   \
    \ *            // \u7B2C\u4E09\u5F15\u6570\u306E\u95A2\u6570\u304C\u5B9F\u884C\
    \u3055\u308C\u308B.\n    */\n    template<class UpdateQuery>\n    void update(int\
    \ u, int v, const UpdateQuery& q, bool edge = false) const {\n        for (;;\
    \ v = par[head[v]]) {\n            if (depth[head[u]] > depth[head[v]]) swap(u,\
    \ v);\n            if (head[u] == head[v]) {\n                if (vid[u] > vid[v])\
    \ swap(u, v);\n                q(vid[u] + edge, vid[v] + 1);\n               \
    \ break;\n            } else {\n                q(vid[head[v]], vid[v] + 1);\n\
    \            }\n        }\n    }\n\n    /**\n    * @brief \u6307\u5B9A\u3057\u305F\
    2\u9802\u70B9\u9593\u306E\u30D1\u30B9\u4E0A\u3067\u53D6\u5F97\u30AF\u30A8\u30EA\
    \u3092\u5B9F\u884C. O(log|V|) * (O(q)+O(f)).\n    * @param[in] u, v \u53D6\u5F97\
    \u30AF\u30A8\u30EA\u3092\u5B9F\u884C\u3059\u308B\u30D1\u30B9\u306E\u4E21\u7AEF\
    .\n    * @param[in] q \u5B9F\u884C\u3059\u308B\u53D6\u5F97\u30AF\u30A8\u30EA.\n\
    \    * @param[in] f \u5C0F\u5206\u3051\u306B\u3057\u305F\u533A\u9593\u304B\u3089\
    \u53D6\u5F97\u3057\u305F\u5024\u3092\u30DE\u30FC\u30B8\u3059\u308B\u65B9\u6CD5\
    .\n    * @param[in] ident f\u306E\u5358\u4F4D\u5143.\n    * @param[in] edge \u8FBA\
    \u30AF\u30A8\u30EA\u304B\u9802\u70B9\u30AF\u30A8\u30EA\u304B. \u30C7\u30D5\u30A9\
    \u30EB\u30C8\u306F\u9802\u70B9\u30AF\u30A8\u30EA.\n    * @return \u53D6\u5F97\u3057\
    \u305F\u5024.\n    *\n    * @details \u4F7F\u3044\u65B9\n    *     e.g. Range\
    \ Minimum Query\n    *     SegmentTree<int> segt;\n    *            // \u6728\u306B\
    \u5BFE\u5FDC\u3059\u308B\u30BB\u30B0\u30E1\u30F3\u30C8\u6728.\n    *         \
    \   // \u6728\u306E\u9802\u70B9\u304C\u305D\u306E\u307E\u307Esegt\u306Eindex\u306B\
    \u306A\u308B\u308F\u3051\u3067\u306F\u7121\u3044\u306E\u3067\u6CE8\u610F.\n  \
    \  *     int u, v;\n    *            // u, v \u9593\u306E\u30D1\u30B9\u4E0A\u306B\
    \u3042\u308B\u5168\u3066\u306E\u9802\u70B9\u306E\u5024\u306Emin\u3092\u53D6\u5F97\
    \u3057\u305F\u3044.\n    *     hld.query(u, v,\n    *          [&](int s,int t){\
    \ return segt.query(s,t); },\n    *          [&](int a,int b){ return min(a,b);\
    \ }, INF);\n    *            // u, v \u9593\u306E\u30D1\u30B9\u3092\u5C0F\u5206\
    \u3051\u306B\u3057\u305F\u533A\u9593\u5168\u4F53\u306B\n    *            // \u7B2C\
    \u4E09\u5F15\u6570\u306E\u95A2\u6570\u304C\u5B9F\u884C\u3055\u308C\u308B.\n  \
    \  *            // \u5404\u533A\u9593\u304B\u3089\u53D6\u5F97\u3057\u305F\u5024\
    \u306F, \u7B2C\u56DB\u5F15\u6570\u306E\u95A2\u6570\u306B\u3088\u3063\u3066\u30DE\
    \u30FC\u30B8\u3055\u308C\u308B.\n    *            // min\u306E\u5358\u4F4D\u5143\
    INF\u3092\u7B2C\u4E94\u5F15\u6570\u306B\u6E21\u3059.\n    */\n    template<class\
    \ Query, class MergeFunc, typename T>\n    T query(int u, int v,\n           \
    \ const Query& q, const MergeFunc& f,\n            const T& ident, bool edge =\
    \ false) const {\n        T ret = ident;\n        for (;; v = par[head[v]]) {\n\
    \            if (depth[head[u]] > depth[head[v]]) swap(u, v);\n            if\
    \ (head[u] == head[v]) {\n                if (vid[u] > vid[v]) swap(u, v);\n \
    \               return f(ret, q(vid[u] + edge, vid[v] + 1));\n            } else\
    \ {\n                ret = f(ret, q(vid[head[v]], vid[v] + 1));\n            }\n\
    \        }\n    }\n\nprivate:\n    const vector<vector<int>>& g;\n    vector<int>\
    \ par, size, depth, head, vid;\n    // par[v] := \u9802\u70B9v \u306E\u89AA\u9802\
    \u70B9.\n    // size[v] := \u9802\u70B9v \u3092\u6839\u3068\u3057\u305F\u90E8\u5206\
    \u6728\u306E\u9802\u70B9\u6570.\n    // depth[v] := \u9802\u70B9v \u306E\u6DF1\
    \u3055. \u6839\u306E\u6DF1\u3055\u306F0.\n    // head[v] := HL\u5206\u89E3\u3057\
    \u305F\u969B\u306B, \u9802\u70B9v \u3092\u542B\u3080\u533A\u9593\u306E\u5148\u982D\
    \u306B\u4F4D\u7F6E\u3059\u308B\u9802\u70B9.\n    // vid[v] := \u9802\u70B9v \u306B\
    \u5BFE\u5FDC\u3059\u308B\u5185\u90E8index.\n    //           HL\u5206\u89E3\u3057\
    \u305F\u5F8C\u306E\u5404\u533A\u9593\u4E0A\u3067, vid\u306F\u9023\u7D9A\u3057\u3066\
    \u3044\u308B.\n\n    void dfs(int v, int p, int d) {\n        par[v] = p; depth[v]\
    \ = d; size[v] = 1;\n        for (int u : g[v]) {\n            if (u == p) continue;\n\
    \            dfs(u, v, d+1);\n            size[v] += size[u];\n        }\n   \
    \ }\n    void hld(int v, int h, int& k) {\n        head[v] = h; vid[v] = k++;\n\
    \        int ma = 0, id = -1;\n        for (int u : g[v]) {\n            if (u\
    \ == par[v]) continue;\n            if (chmax(ma, size[u])) id = u;\n        }\n\
    \        if (id == -1) return;\n        hld(id, h, k);\n        for (int u : g[v])\
    \ {\n            if (u == id or u == par[v]) continue;\n            hld(u, u,\
    \ k);\n        }\n    }\n};\n"
  dependsOn:
  - lib/template.cpp
  isVerificationFile: false
  path: lib/graph/heavy_light_decomposition.cpp
  requiredBy: []
  timestamp: '2020-05-06 01:41:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/heavy_light_decomposition/hld.test.cpp
  - test/graph/heavy_light_decomposition/lca.test.cpp
documentation_of: lib/graph/heavy_light_decomposition.cpp
layout: document
redirect_from:
- /library/lib/graph/heavy_light_decomposition.cpp
- /library/lib/graph/heavy_light_decomposition.cpp.html
title: "HL\u5206\u89E3"
---
