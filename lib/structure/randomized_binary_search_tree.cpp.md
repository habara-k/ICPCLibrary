---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/template.cpp
    title: lib/template.cpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: lib/structure/multi_set.cpp
    title: "\u5024\u306E\u633F\u5165\u3092\u884C\u3046. O(log n)"
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: "\u914D\u5217\u3067\u521D\u671F\u5316\u3059\u308B. O(n)"
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
    \   // cin.rdbuf(in.rdbuf());\n\n    return 0;\n}\n*/\n\n\n#line 2 \"lib/structure/randomized_binary_search_tree.cpp\"\
    \n\n/**\n * @brief\n * \u5217\u3092\u7BA1\u7406\u3059\u308B\u5E73\u8861\u4E8C\u5206\
    \u6728\n * \u4EFB\u610F\u7B87\u6240\u306E\u8981\u7D20\u306E\u66F4\u65B0\u30FB\u53D6\
    \u5F97\u30FB\u633F\u5165\u30FB\u524A\u9664\u3092O(log n)\u3067\u884C\u3046.\n\
    \ * @author habara-k\n * @date 2020/05/05\n */\n\ntemplate<typename T>\nstruct\
    \ RandomizedBinarySearchTree {\n\n    struct Node {\n        Node *lch, *rch;\n\
    \        int sz;\n        T data;\n        Node(const T& data) :\n           \
    \     lch(nullptr), rch(nullptr), sz(1),\n                data(data) {}\n    };\n\
    \n    RandomizedBinarySearchTree() : root(nullptr) {}\n\n    /**\n    * @brief\
    \ \u914D\u5217\u3067\u521D\u671F\u5316\u3059\u308B. O(n)\n    */\n    void build(const\
    \ vector<T>& v) { root = build(v, 0, v.size()); }\n\n    /**\n    * @brief \u6728\
    \u306E\u30B5\u30A4\u30BA\u3092\u8FD4\u3059. O(1)\n    */\n    inline int size()\
    \ {\n        return size(root);\n    }\n\n    /**\n    * @brief \u8981\u7D20\u306E\
    \u66F4\u65B0\u3092\u884C\u3046. O(log n)\n    * @param[in] i: \u8981\u7D20\u306E\
    index\n    * @param[in] q: x \u3092q(x) \u3067\u66F4\u65B0\u3059\u308B.\n    */\n\
    \    template<class UpdateQuery>\n    void update(int i, const UpdateQuery& q)\
    \ {\n        auto p0 = split(root, i);\n        auto p1 = split(p0.second, 1);\n\
    \        p1.first->data = q(p1.first->data);\n        root = merge(p0.first, merge(p1.first,\
    \ p1.second));\n    }\n\n    /**\n    * @brief \u8981\u7D20\u306E\u53D6\u5F97\u3092\
    \u884C\u3046. O(log n)\n    * @param[in] i: \u53D6\u5F97\u3057\u305F\u3044\u8981\
    \u7D20\u306Eindex\n    * @return \u53D6\u5F97\u3057\u305F\u5024\n    */\n    T\
    \ operator[](int i) {\n        auto p0 = split(root, i);\n        auto p1 = split(p0.second,\
    \ 1);\n        T ret = p1.first->data;\n        root = merge(p0.first, merge(p1.first,\
    \ p1.second));\n        return ret;\n    }\n\n    /**\n    * @brief \u8981\u7D20\
    \u306E\u633F\u5165\u3092\u884C\u3046. O(log n)\n    * @param[in] i: \u633F\u5165\
    \u3057\u305F\u3044index\n    * @param[in] data: \u633F\u5165\u3057\u305F\u3044\
    \u5024\n    */\n    void insert(int i, const T& data) {\n        auto q = _new(data);\n\
    \        auto p = split(root, i);\n        root = merge(merge(p.first, q), p.second);\n\
    \    }\n\n    /**\n    * @brief \u8981\u7D20\u306E\u524A\u9664\u3092\u884C\u3046\
    . O(log n)\n    * @param[in] i: \u633F\u5165\u3057\u305F\u3044index\n    */\n\
    \    T erase(int i) {\n        auto p = split(root, i);\n        auto q = split(p.second,\
    \ 1);\n        T ret = q.first->data;\n        root = merge(p.first, q.second);\n\
    \        return ret;\n    }\n\n    /**\n    * @brief vector \u307F\u305F\u3044\
    \u306B\u51FA\u529B.\n    */\n    friend ostream& operator<<(ostream& os,\n   \
    \                            RandomizedBinarySearchTree& tr) {\n        os <<\
    \ \"[\";\n        for (int i = 0; i < tr.size(); ++i) {\n            if (i) os\
    \ << \" \";\n            os << tr[i];\n        }\n        return os << \"]\";\n\
    \    }\n\nprotected:\n    Node* root;\n\n    inline int size(Node* t) const {\
    \ return t ? t->sz : 0; }\n\n    Node* merge(Node *l, Node *r) {\n        if (!l)\
    \ return r;\n        if (!r) return l;\n        if (xor128() % (size(l) + size(r))\
    \ < size(l)) {\n            l->rch = merge(l->rch, r);\n            return modify(l);\n\
    \        } else {\n            r->lch = merge(l, r->lch);\n            return\
    \ modify(r);\n        }\n    }\n\n    pair<Node*, Node*> split(Node* t, int k)\
    \ {\n        if (!t) return {t, t};\n        if (k > size(t->lch)) {\n       \
    \     auto p = split(t->rch, k-size(t->lch)-1);\n            t->rch = p.first;\n\
    \            return {modify(t), p.second};\n        } else {\n            auto\
    \ p = split(t->lch, k);\n            t->lch = p.second;\n            return {p.first,\
    \ modify(t)};\n        }\n    }\n\nprivate:\n    inline int xor128() {\n     \
    \   static int x = 123456789;\n        static int y = 362436069;\n        static\
    \ int z = 521288629;\n        static int w = 88675123;\n        int t;\n\n   \
    \     t = x ^ (x << 11);\n        x = y;\n        y = z;\n        z = w;\n   \
    \     return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));\n    }\n\n    Node* build(const\
    \ vector<T>& v, int l, int r) {\n        if (l + 1 >= r) return _new(v[l]);\n\
    \        return merge(build(v, l, (l + r) >> 1),\n                     build(v,\
    \ (l + r) >> 1, r));\n    }\n\n    inline Node* _new(const T& data) const { return\
    \ new Node(data); }\n\n    inline Node* modify(Node *t) {\n        t->sz = size(t->lch)\
    \ + size(t->rch) + 1;\n        return t;\n    }\n};\n"
  code: "#include \"../template.cpp\"\n\n/**\n * @brief\n * \u5217\u3092\u7BA1\u7406\
    \u3059\u308B\u5E73\u8861\u4E8C\u5206\u6728\n * \u4EFB\u610F\u7B87\u6240\u306E\u8981\
    \u7D20\u306E\u66F4\u65B0\u30FB\u53D6\u5F97\u30FB\u633F\u5165\u30FB\u524A\u9664\
    \u3092O(log n)\u3067\u884C\u3046.\n * @author habara-k\n * @date 2020/05/05\n\
    \ */\n\ntemplate<typename T>\nstruct RandomizedBinarySearchTree {\n\n    struct\
    \ Node {\n        Node *lch, *rch;\n        int sz;\n        T data;\n       \
    \ Node(const T& data) :\n                lch(nullptr), rch(nullptr), sz(1),\n\
    \                data(data) {}\n    };\n\n    RandomizedBinarySearchTree() : root(nullptr)\
    \ {}\n\n    /**\n    * @brief \u914D\u5217\u3067\u521D\u671F\u5316\u3059\u308B\
    . O(n)\n    */\n    void build(const vector<T>& v) { root = build(v, 0, v.size());\
    \ }\n\n    /**\n    * @brief \u6728\u306E\u30B5\u30A4\u30BA\u3092\u8FD4\u3059\
    . O(1)\n    */\n    inline int size() {\n        return size(root);\n    }\n\n\
    \    /**\n    * @brief \u8981\u7D20\u306E\u66F4\u65B0\u3092\u884C\u3046. O(log\
    \ n)\n    * @param[in] i: \u8981\u7D20\u306Eindex\n    * @param[in] q: x \u3092\
    q(x) \u3067\u66F4\u65B0\u3059\u308B.\n    */\n    template<class UpdateQuery>\n\
    \    void update(int i, const UpdateQuery& q) {\n        auto p0 = split(root,\
    \ i);\n        auto p1 = split(p0.second, 1);\n        p1.first->data = q(p1.first->data);\n\
    \        root = merge(p0.first, merge(p1.first, p1.second));\n    }\n\n    /**\n\
    \    * @brief \u8981\u7D20\u306E\u53D6\u5F97\u3092\u884C\u3046. O(log n)\n   \
    \ * @param[in] i: \u53D6\u5F97\u3057\u305F\u3044\u8981\u7D20\u306Eindex\n    *\
    \ @return \u53D6\u5F97\u3057\u305F\u5024\n    */\n    T operator[](int i) {\n\
    \        auto p0 = split(root, i);\n        auto p1 = split(p0.second, 1);\n \
    \       T ret = p1.first->data;\n        root = merge(p0.first, merge(p1.first,\
    \ p1.second));\n        return ret;\n    }\n\n    /**\n    * @brief \u8981\u7D20\
    \u306E\u633F\u5165\u3092\u884C\u3046. O(log n)\n    * @param[in] i: \u633F\u5165\
    \u3057\u305F\u3044index\n    * @param[in] data: \u633F\u5165\u3057\u305F\u3044\
    \u5024\n    */\n    void insert(int i, const T& data) {\n        auto q = _new(data);\n\
    \        auto p = split(root, i);\n        root = merge(merge(p.first, q), p.second);\n\
    \    }\n\n    /**\n    * @brief \u8981\u7D20\u306E\u524A\u9664\u3092\u884C\u3046\
    . O(log n)\n    * @param[in] i: \u633F\u5165\u3057\u305F\u3044index\n    */\n\
    \    T erase(int i) {\n        auto p = split(root, i);\n        auto q = split(p.second,\
    \ 1);\n        T ret = q.first->data;\n        root = merge(p.first, q.second);\n\
    \        return ret;\n    }\n\n    /**\n    * @brief vector \u307F\u305F\u3044\
    \u306B\u51FA\u529B.\n    */\n    friend ostream& operator<<(ostream& os,\n   \
    \                            RandomizedBinarySearchTree& tr) {\n        os <<\
    \ \"[\";\n        for (int i = 0; i < tr.size(); ++i) {\n            if (i) os\
    \ << \" \";\n            os << tr[i];\n        }\n        return os << \"]\";\n\
    \    }\n\nprotected:\n    Node* root;\n\n    inline int size(Node* t) const {\
    \ return t ? t->sz : 0; }\n\n    Node* merge(Node *l, Node *r) {\n        if (!l)\
    \ return r;\n        if (!r) return l;\n        if (xor128() % (size(l) + size(r))\
    \ < size(l)) {\n            l->rch = merge(l->rch, r);\n            return modify(l);\n\
    \        } else {\n            r->lch = merge(l, r->lch);\n            return\
    \ modify(r);\n        }\n    }\n\n    pair<Node*, Node*> split(Node* t, int k)\
    \ {\n        if (!t) return {t, t};\n        if (k > size(t->lch)) {\n       \
    \     auto p = split(t->rch, k-size(t->lch)-1);\n            t->rch = p.first;\n\
    \            return {modify(t), p.second};\n        } else {\n            auto\
    \ p = split(t->lch, k);\n            t->lch = p.second;\n            return {p.first,\
    \ modify(t)};\n        }\n    }\n\nprivate:\n    inline int xor128() {\n     \
    \   static int x = 123456789;\n        static int y = 362436069;\n        static\
    \ int z = 521288629;\n        static int w = 88675123;\n        int t;\n\n   \
    \     t = x ^ (x << 11);\n        x = y;\n        y = z;\n        z = w;\n   \
    \     return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));\n    }\n\n    Node* build(const\
    \ vector<T>& v, int l, int r) {\n        if (l + 1 >= r) return _new(v[l]);\n\
    \        return merge(build(v, l, (l + r) >> 1),\n                     build(v,\
    \ (l + r) >> 1, r));\n    }\n\n    inline Node* _new(const T& data) const { return\
    \ new Node(data); }\n\n    inline Node* modify(Node *t) {\n        t->sz = size(t->lch)\
    \ + size(t->rch) + 1;\n        return t;\n    }\n};\n"
  dependsOn:
  - lib/template.cpp
  isVerificationFile: false
  path: lib/structure/randomized_binary_search_tree.cpp
  requiredBy:
  - lib/structure/multi_set.cpp
  timestamp: '2020-05-06 01:41:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/structure/randomized_binary_search_tree.cpp
layout: document
redirect_from:
- /library/lib/structure/randomized_binary_search_tree.cpp
- /library/lib/structure/randomized_binary_search_tree.cpp.html
title: "\u914D\u5217\u3067\u521D\u671F\u5316\u3059\u308B. O(n)"
---
