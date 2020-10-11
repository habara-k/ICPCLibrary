---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/structure/segment_tree.cpp
    title: "\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
  - icon: ':heavy_check_mark:'
    path: lib/template.cpp
    title: lib/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"test/yosupo-judge/static_rmq.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#line 1 \"lib/template.cpp\"\
    \n\n\n\n#include <bits/stdc++.h>\n\nusing namespace std;\n\n#define REP(i, n)\
    \ for (int i=0; i<(n); ++i)\n#define RREP(i, n) for (int i=(int)(n)-1; i>=0; --i)\n\
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
    \n    return 0;\n}\n*/\n\n\n#line 2 \"lib/structure/segment_tree.cpp\"\n\n/**\n\
    * @brief \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n* @author habara-k, Md\n* @date\
    \ 2020/06/17\n*/\n\ntemplate<typename M>\nstruct SegmentTree {\n\n    /**\n  \
    \  * @brief \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF. O(n)\n    * @param[in]\
    \ n \u30BB\u30B0\u6728\u306E\u30B5\u30A4\u30BA.\n    * @param[in] f \u30E2\u30CE\
    \u30A4\u30C9\u306E\u6F14\u7B97(query).\n    * @param[in] g \u30E2\u30CE\u30A4\u30C9\
    \u306E\u6F14\u7B97(update).\n    * @param[in] e \u30E2\u30CE\u30A4\u30C9\u306E\
    \u5358\u4F4D\u5143.\n    * @details \u4F7F\u3044\u65B9\n    *   e.g. Update and\
    \ Range Minimum\n    *   SegmentTree<int> segt(\n    *            n,\n    *  \
    \          [](int a,int b){ return min(a+b); },\n    *            [](int a, int\
    \ b){ return b; },\n    *            INF);\n    *               // \u5168\u3066\
    \u5358\u4F4D\u5143\u3067\u521D\u671F\u5316\u3055\u308C\u308B.\n    */\n    SegmentTree(\n\
    \            int n,\n            const function<M(M,M)>& f,\n            const\
    \ function<M(M, M)>& g,\n            const M& e) : n(n), f(f), g(g), e(e) {\n\
    \        sz = 1;\n        while (sz < n) sz <<= 1;\n        data.assign(2 * sz,\
    \ e);\n    }\n\n    /**\n    * @brief \u5168\u4F53\u306B\u521D\u671F\u5024\u3092\
    \u5165\u308C\u308B. O(n)\n    * @param[in] v \u8981\u7D20\u30E2\u30CE\u30A4\u30C9\
    \u306Evector. \u521D\u671F\u5316\u3059\u308B.\n    * @details \u4F7F\u3044\u65B9\
    \n    *   segt.build(vector<int>(n, 0));\n    */\n    void build(const vector<M>&\
    \ v) {\n        assert(v.size() <= n);\n        for (int i = 0; i < v.size();\
    \ ++i) {\n            data[i + sz] = v[i];\n        }\n        for (int i = sz-1;\
    \ i > 0; --i) {\n            data[i] = f(data[2 * i], data[2 * i + 1]);\n    \
    \    }\n    }\n\n    /**\n     * @brief \u6307\u5B9A\u3057\u305F\u4F4D\u7F6E\u306B\
    \u66F4\u65B0\u30AF\u30A8\u30EA\u3092\u5B9F\u884C\u3059\u308B O(log n)\n     *\
    \ @param[in] idx \u4F4D\u7F6Eidx\u306B\u4F5C\u7528\u3055\u305B\u308B\n     * @param[in]\
    \ val \u5024x\u3092g(data[idx+sz], val)\u3067\u66F4\u65B0\u3059\u308B\n     */\n\
    \    void update(int idx, M val) {\n      idx += sz;\n      data[idx] = g(data[idx],\
    \ val);\n      while(idx >>= 1) {\n        data[idx] = f(data[2*idx], data[2*idx+1]);\n\
    \      }\n    }\n\n    /**\n    * @brief \u6307\u5B9A\u3057\u305F\u533A\u9593\u306B\
    \u53D6\u5F97\u30AF\u30A8\u30EA\u3092\u5B9F\u884C\u3059\u308B. O(log n)\n    *\
    \ @param[in] l, r \u533A\u9593[l, r) \u3092\u53D6\u5F97\u3059\u308B.\n    * @return\
    \ \u53D6\u5F97\u3057\u305F\u5024.\n    * @details \u4F7F\u3044\u65B9\n    *  \
    \ e.g. Range Minimum\n    *   int l, r; // \u533A\u9593[l, r) \u306Emin\u3092\u53D6\
    \u5F97\u3057\u305F\u3044.\n    *   cout << segt.query(l, r) << endl;\n    */\n\
    \    M query(int a, int b) const {\n        return query(a, b, 1, 0, sz);\n  \
    \  }\n\n    /**\n    * @brief \u6307\u5B9A\u3057\u305Findex\u306E\u8981\u7D20\u3092\
    \u53D6\u5F97. O(1)\n    * @param[in] i \u53D6\u5F97\u3057\u305F\u3044\u8981\u7D20\
    \u306Eindex\n    * @return \u53D6\u5F97\u3057\u305F\u5024.\n    */\n    M operator[](int\
    \ k) const {\n        return data[k + sz];\n    }\n\n    /**\n    * @brief vector\
    \ \u307F\u305F\u3044\u306B\u51FA\u529B.\n    */\n    friend ostream& operator<<(ostream&\
    \ os, SegmentTree& s) {\n        os << \"[\";\n        for (int i = 0; i < s.n;\
    \ ++i) {\n            if (i) os << \" \";\n            os << s[i];\n        }\n\
    \        return os << \"]\";\n    }\n\nprivate:\n    int n, sz;\n    vector<M>\
    \ data;\n    const function<M(M,M)> f, g;\n    const M e;\n\n    M query(int a,\
    \ int b, int k, int l, int r) const {\n        if (r <= a || b <= l) {\n     \
    \       return e;\n        } else if (a <= l && r <= b) {\n            return\
    \ data[k];\n        } else {\n            return f(query(a,b,2*k,  l,(l+r)/2),\n\
    \                     query(a,b,2*k+1,(l+r)/2,r));\n        }\n    }\n};\n#line\
    \ 4 \"test/yosupo-judge/static_rmq.test.cpp\"\n\nint main() {\n    int n, q; cin\
    \ >> n >> q;\n    vector<int> a(n); REP(i, n) cin >> a[i];\n\n    SegmentTree<int>\
    \ segt(n, [](int a,int b){return min(a,b);},\n            [](int a,int b){return\
    \ min(a,b);}, 1e9+1);\n    segt.build(a);\n\n    while (q--) {\n        int l,\
    \ r; cin >> l >> r;\n        cout << segt.query(l, r) << endl;\n    }\n\n    return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#include\
    \ \"../../lib/structure/segment_tree.cpp\"\n\nint main() {\n    int n, q; cin\
    \ >> n >> q;\n    vector<int> a(n); REP(i, n) cin >> a[i];\n\n    SegmentTree<int>\
    \ segt(n, [](int a,int b){return min(a,b);},\n            [](int a,int b){return\
    \ min(a,b);}, 1e9+1);\n    segt.build(a);\n\n    while (q--) {\n        int l,\
    \ r; cin >> l >> r;\n        cout << segt.query(l, r) << endl;\n    }\n\n    return\
    \ 0;\n}\n"
  dependsOn:
  - lib/structure/segment_tree.cpp
  - lib/template.cpp
  isVerificationFile: true
  path: test/yosupo-judge/static_rmq.test.cpp
  requiredBy: []
  timestamp: '2020-10-12 01:47:14+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo-judge/static_rmq.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo-judge/static_rmq.test.cpp
- /verify/test/yosupo-judge/static_rmq.test.cpp.html
title: test/yosupo-judge/static_rmq.test.cpp
---
