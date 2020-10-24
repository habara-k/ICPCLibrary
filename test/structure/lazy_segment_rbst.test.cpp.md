---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/structure/lazy_segment_rbst.cpp
    title: "\u914D\u5217\u3067\u521D\u671F\u5316\u3059\u308B. O(n)"
  - icon: ':question:'
    path: lib/template.cpp
    title: lib/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G
  bundledCode: "#line 1 \"test/structure/lazy_segment_rbst.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G\"\n\n#line\
    \ 1 \"lib/template.cpp\"\n\n\n\n#include <bits/stdc++.h>\n\nusing namespace std;\n\
    \n#define REP(i, n) for (int i=0; i<(n); ++i)\n#define RREP(i, n) for (int i=(int)(n)-1;\
    \ i>=0; --i)\n#define FOR(i, a, n) for (int i=(a); i<(n); ++i)\n#define RFOR(i,\
    \ a, n) for (int i=(int)(n)-1; i>=(a); --i)\n\n#define SZ(x) ((int)(x).size())\n\
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
    \n    return 0;\n}\n*/\n\n\n#line 2 \"lib/structure/lazy_segment_rbst.cpp\"\n\n\
    /**\n * @brief\n * \u5217\u3092\u7BA1\u7406\u3059\u308B\u5E73\u8861\u4E8C\u5206\
    \u6728\n * \u4EFB\u610F\u7B87\u6240\u306E\u8981\u7D20\u306E\u66F4\u65B0\u30FB\u53D6\
    \u5F97\u30FB\u633F\u5165\u30FB\u524A\u9664\u3092O(log n)\u3067\u884C\u3046.\n\
    \ * \u30E2\u30CE\u30A4\u30C9\u304C\u4E57\u308B. \u533A\u9593\u53D6\u5F97\u3092\
    O(log n) \u3067\u884C\u3046.\n * \u9045\u5EF6\u51E6\u7406\u304C\u4E57\u308B.\n\
    \ * @author habara-k\n * @date 2020/05/05\n */\n\ntemplate<typename M, typename\
    \ OM = M>\nstruct LazySegmentRBST {\n\n    struct Node {\n        Node *lch, *rch;\n\
    \        int sz;\n        M data, sum;\n        OM lazy;\n        Node(const M&\
    \ data, const OM& lazy) :\n            lch(nullptr), rch(nullptr), sz(1),\n  \
    \          data(data), sum(data), lazy(lazy) {}\n    };\n\n    using F = function<M(M,M)>;\n\
    \    using G = function<M(M,OM,int)>;\n    using H = function<OM(OM,OM)>;\n\n\
    \    LazySegmentRBST(const F& f, const G& g, const H& h, M e, OM oe) :\n     \
    \   f(f), g(g), h(h), e(e), oe(oe), root(nullptr) {}\n\n    /**\n    * @brief\
    \ \u914D\u5217\u3067\u521D\u671F\u5316\u3059\u308B. O(n)\n    */\n    void build(const\
    \ vector<M>& v) { root = build(v, 0, v.size()); }\n\n    /**\n    * @brief \u6728\
    \u306E\u30B5\u30A4\u30BA\u3092\u8FD4\u3059. O(1)\n    */\n    inline int size()\
    \ {\n        return size(root);\n    }\n\n    /**\n    * @brief \u533A\u9593update.\
    \ O(log n)\n    * @param[in] a, b: update\u3059\u308B\u533A\u9593\n    * @param[in]\
    \ lazy: \u4F5C\u7528\u306E\u8981\u7D20\n    */\n    void update(int a, int b,\
    \ const OM& lazy) {\n        auto p0 = split(root, a);\n        auto p1 = split(p0.second,\
    \ b-a);\n        p1.first->lazy = h(p1.first->lazy, lazy);\n        p1.first =\
    \ propagate(p1.first);\n        root = merge(p0.first, merge(p1.first, p1.second));\n\
    \    }\n\n    /**\n    * @brief \u8981\u7D20\u306E\u53D6\u5F97\u3092\u884C\u3046\
    . O(log n)\n    * @param[in] a, b: \u53D6\u5F97\u3057\u305F\u3044\u533A\u9593\n\
    \    * @return \u53D6\u5F97\u3057\u305F\u5024\n    */\n    M query(int a, int\
    \ b) {\n        auto p0 = split(root, a);\n        auto p1 = split(p0.second,\
    \ b - a);\n        p1.first = propagate(p1.first);\n        M ret = sum(p1.first);\n\
    \        root = merge(p0.first, merge(p1.first, p1.second));\n        return ret;\n\
    \    }\n\n    /**\n    * @brief \u8981\u7D20\u306E\u53D6\u5F97\u3092\u884C\u3046\
    . O(log n)\n    * @param[in] i: \u53D6\u5F97\u3057\u305F\u3044\u8981\u7D20\u306E\
    index\n    * @return \u53D6\u5F97\u3057\u305F\u5024\n    */\n    M operator[](int\
    \ i) {\n        return query(i, i + 1);\n    }\n\n    /**\n    * @brief \u8981\
    \u7D20\u306E\u633F\u5165\u3092\u884C\u3046. O(log n)\n    * @param[in] i: \u633F\
    \u5165\u3057\u305F\u3044index\n    * @param[in] data: \u633F\u5165\u3057\u305F\
    \u3044\u5024\n    */\n    void insert(int i, const M& data) {\n        auto q\
    \ = _new(data);\n        auto p = split(root, i);\n        root = merge(merge(p.first,\
    \ q), p.second);\n    }\n\n    /**\n    * @brief \u8981\u7D20\u306E\u524A\u9664\
    \u3092\u884C\u3046. O(log n)\n    * @param[in] i: \u633F\u5165\u3057\u305F\u3044\
    index\n    */\n    M erase(int i) {\n        auto p = split(root, i);\n      \
    \  auto q = split(p.second, 1);\n        M ret = q.first->data;\n        root\
    \ = merge(p.first, q.second);\n        return ret;\n    }\n\n    /**\n    * @brief\
    \ vector \u307F\u305F\u3044\u306B\u51FA\u529B.\n    */\n    friend ostream& operator<<(ostream&\
    \ os,\n                               LazySegmentRBST& tr) {\n        os << \"\
    [\";\n        for (int i = 0; i < tr.size(); ++i) {\n            if (i) os <<\
    \ \" \";\n            os << tr[i];\n        }\n        return os << \"]\";\n \
    \   }\n\nprotected:\n    Node* root;\n\n    inline int size(Node* t) const { return\
    \ t ? t->sz : 0; }\n    inline M sum(Node* t) const { return t ? t->sum : e; }\n\
    \    inline OM lazy(Node* t) const { return t ? t->lazy : oe; }\n\n    Node* merge(Node\
    \ *l, Node *r) {\n        if (!l) return r;\n        if (!r) return l;\n     \
    \   if (xor128() % (size(l) + size(r)) < size(l)) {\n            l = propagate(l);\n\
    \            l->rch = merge(l->rch, r);\n            return modify(l);\n     \
    \   } else {\n            r = propagate(r);\n            r->lch = merge(l, r->lch);\n\
    \            return modify(r);\n        }\n    }\n\n    pair<Node*, Node*> split(Node*\
    \ t, int k) {\n        if (!t) return {t, t};\n        t = propagate(t);\n   \
    \     if (k > size(t->lch)) {\n            auto p = split(t->rch, k-size(t->lch)-1);\n\
    \            t->rch = p.first;\n            return {modify(t), p.second};\n  \
    \      } else {\n            auto p = split(t->lch, k);\n            t->lch =\
    \ p.second;\n            return {p.first, modify(t)};\n        }\n    }\n\nprivate:\n\
    \    const F f;\n    const G g;\n    const H h;\n    const M e;\n    const OM\
    \ oe;\n\n    inline int xor128() {\n        static int x = 123456789;\n      \
    \  static int y = 362436069;\n        static int z = 521288629;\n        static\
    \ int w = 88675123;\n        int t;\n\n        t = x ^ (x << 11);\n        x =\
    \ y;\n        y = z;\n        z = w;\n        return w = (w ^ (w >> 19)) ^ (t\
    \ ^ (t >> 8));\n    }\n\n    Node* build(const vector<M>& v, int l, int r) {\n\
    \        if (l + 1 >= r) return _new(v[l]);\n        return merge(build(v, l,\
    \ (l + r) >> 1),\n                     build(v, (l + r) >> 1, r));\n    }\n\n\
    \    inline Node* _new(const M& data) const { return new Node(data, oe); }\n\n\
    \    inline Node* modify(Node *t) {\n        t->sz = size(t->lch) + size(t->rch)\
    \ + 1;\n        t->sum = f(f(sum(t->lch), t->data), sum(t->rch));\n        return\
    \ t;\n    }\n\n    Node* propagate(Node* t) {\n        if (!t) return t;\n   \
    \     if (lazy(t) == oe) return t;\n        if (t->lch != nullptr) {\n       \
    \     t->lch->lazy = h(lazy(t->lch), lazy(t));\n            t->lch->sum = g(sum(t->lch),\
    \ lazy(t), size(t->lch));\n        }\n        if (t->rch != nullptr) {\n     \
    \       t->rch->lazy = h(lazy(t->rch), lazy(t));\n            t->rch->sum = g(sum(t->rch),\
    \ lazy(t), size(t->rch));\n        }\n        t->data = g(t->data, lazy(t), 1);\n\
    \        t->lazy = oe;\n        return modify(t);\n    }\n};\n#line 4 \"test/structure/lazy_segment_rbst.test.cpp\"\
    \n\nint main() {\n    int N, Q;\n    cin >> N >> Q;\n    LazySegmentRBST<ll> tree(\n\
    \            [](ll a, ll b){ return a+b; },\n            [](ll a, ll b, ll w){\
    \ return a + b*w; },\n            [](ll a, ll b){ return a+b; },\n           \
    \ 0, 0);\n\n    tree.build(vector<ll>(N, 0));\n\n    while (Q--) {\n        int\
    \ C; cin >> C;\n        if (C == 0) {\n            int S, T; ll X;\n         \
    \   cin >> S >> T >> X;\n            --S, --T;\n            tree.update(S, T+1,\
    \ X);\n        } else {\n            int S, T;\n            cin >> S >> T;\n \
    \           --S, --T;\n            cout << tree.query(S, T+1) << endl;\n     \
    \   }\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G\"\
    \n\n#include \"../../lib/structure/lazy_segment_rbst.cpp\"\n\nint main() {\n \
    \   int N, Q;\n    cin >> N >> Q;\n    LazySegmentRBST<ll> tree(\n           \
    \ [](ll a, ll b){ return a+b; },\n            [](ll a, ll b, ll w){ return a +\
    \ b*w; },\n            [](ll a, ll b){ return a+b; },\n            0, 0);\n\n\
    \    tree.build(vector<ll>(N, 0));\n\n    while (Q--) {\n        int C; cin >>\
    \ C;\n        if (C == 0) {\n            int S, T; ll X;\n            cin >> S\
    \ >> T >> X;\n            --S, --T;\n            tree.update(S, T+1, X);\n   \
    \     } else {\n            int S, T;\n            cin >> S >> T;\n          \
    \  --S, --T;\n            cout << tree.query(S, T+1) << endl;\n        }\n   \
    \ }\n}\n"
  dependsOn:
  - lib/structure/lazy_segment_rbst.cpp
  - lib/template.cpp
  isVerificationFile: true
  path: test/structure/lazy_segment_rbst.test.cpp
  requiredBy: []
  timestamp: '2020-05-06 01:41:24+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/structure/lazy_segment_rbst.test.cpp
layout: document
redirect_from:
- /verify/test/structure/lazy_segment_rbst.test.cpp
- /verify/test/structure/lazy_segment_rbst.test.cpp.html
title: test/structure/lazy_segment_rbst.test.cpp
---