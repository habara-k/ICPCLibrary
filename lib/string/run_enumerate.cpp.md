---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/string/z_algorithm.cpp
    title: Z Algorithm O(|s|)
  - icon: ':question:'
    path: lib/template.cpp
    title: lib/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/string/run_enumerate.test.cpp
    title: test/string/run_enumerate.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Run\u5217\u6319"
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
    \   // cin.rdbuf(in.rdbuf());\n\n    return 0;\n}\n*/\n\n\n#line 2 \"lib/string/z_algorithm.cpp\"\
    \n\n/**\n * @brief Z Algorithm O(|s|)\n * @param s: \u6587\u5B57\u5217(or vector)\n\
    \ * @return A[i]: S\u3068S[i:n] \u306ELCP\u306E\u9577\u3055\n */\ntemplate<typename\
    \ T>\nvector<int> z_algorithm(const T& s) {\n    int n = s.size();\n    vector<int>\
    \ A(n);\n    A[0] = n;\n    int i = 1, j = 0;\n    while (i < n) {\n        while\
    \ (i+j < n && s[j] == s[i+j]) ++j;\n        A[i] = j;\n        if (j == 0) { ++i;\
    \ continue; }\n        int k = 1;\n        while (i+k < n && k+A[k] < j) { A[i+k]\
    \ = A[k]; ++k; }\n        i += k; j -= k;\n    }\n    return A;\n}\n\n#line 3\
    \ \"lib/string/run_enumerate.cpp\"\n\n/**\n* @brief Run\u5217\u6319\n* @maintainer\
    \ habara-k\n* @date 2020/09/19\n* @param[in] l, r, s: \u6587\u5B57\u5217(or vector)s\u306E\
    \u533A\u9593[l, r) \u306B\u304A\u3051\u308BRun\u3092\u5217\u6319\n* @param[out]\
    \ res: \u6975\u5927\u306ARun[l, r)\u306B\u5BFE\u3059\u308B\u6700\u5C0F\u5468\u671F\
    \u3092\u683C\u7D0D\u3057\u305Fmap\n* @details Z-Algorithm \u306B\u4F9D\u5B58\n\
    */\n\ntemplate<typename T>\nvoid run_enumerate(int l, int r, const T& s, map<pair<int,int>,int>&\
    \ res) {\n    if (r - l <= 1) return;\n    int m = (l + r) >> 1;\n    run_enumerate(l,\
    \ m, s, res);\n    run_enumerate(m, r, s, res);\n\n    auto func = [&](bool rev)\
    \ {\n        T t, tl, tr;\n        copy(s.begin() + l, s.begin() + r, back_inserter(t));\n\
    \        if (rev) {\n            reverse(t.begin(), t.end());\n            m =\
    \ l + r - m;\n        }\n        int len = r - l, mid = m - l;\n        copy(t.begin(),\
    \ t.begin() + mid, back_inserter(tl));\n        reverse(tl.begin(), tl.end());\n\
    \        copy(t.begin() + mid, t.end(), back_inserter(tr));\n        copy(t.begin(),\
    \ t.end(), back_inserter(tr));\n        auto zl = z_algorithm(tl), zr = z_algorithm(tr);\n\
    \        zl.push_back(0);\n        for (int k = 1; k <= mid; ++k) {\n        \
    \    int li = m - k - zl[k], ri = m + min(r - m, zr[len - k]);\n            if\
    \ (rev) {\n                swap(li, ri);\n                li = l + r - li;\n \
    \               ri = l + r - ri;\n            }\n            if (ri - li < 2 *\
    \ k) continue;\n            if (li > 0 && s[li - 1] == s[li - 1 + k]) continue;\n\
    \            if (ri < s.size() && s[ri] == s[ri - k]) continue;\n            if\
    \ (res.count({li, ri})) res[{li, ri}] = min(res[{li, ri}], k);\n            else\
    \ res[{li, ri}] = k;\n        }\n    };\n    func(0);\n    func(1);\n}\n\n"
  code: "#include \"../template.cpp\"\n#include \"z_algorithm.cpp\"\n\n/**\n* @brief\
    \ Run\u5217\u6319\n* @maintainer habara-k\n* @date 2020/09/19\n* @param[in] l,\
    \ r, s: \u6587\u5B57\u5217(or vector)s\u306E\u533A\u9593[l, r) \u306B\u304A\u3051\
    \u308BRun\u3092\u5217\u6319\n* @param[out] res: \u6975\u5927\u306ARun[l, r)\u306B\
    \u5BFE\u3059\u308B\u6700\u5C0F\u5468\u671F\u3092\u683C\u7D0D\u3057\u305Fmap\n\
    * @details Z-Algorithm \u306B\u4F9D\u5B58\n*/\n\ntemplate<typename T>\nvoid run_enumerate(int\
    \ l, int r, const T& s, map<pair<int,int>,int>& res) {\n    if (r - l <= 1) return;\n\
    \    int m = (l + r) >> 1;\n    run_enumerate(l, m, s, res);\n    run_enumerate(m,\
    \ r, s, res);\n\n    auto func = [&](bool rev) {\n        T t, tl, tr;\n     \
    \   copy(s.begin() + l, s.begin() + r, back_inserter(t));\n        if (rev) {\n\
    \            reverse(t.begin(), t.end());\n            m = l + r - m;\n      \
    \  }\n        int len = r - l, mid = m - l;\n        copy(t.begin(), t.begin()\
    \ + mid, back_inserter(tl));\n        reverse(tl.begin(), tl.end());\n       \
    \ copy(t.begin() + mid, t.end(), back_inserter(tr));\n        copy(t.begin(),\
    \ t.end(), back_inserter(tr));\n        auto zl = z_algorithm(tl), zr = z_algorithm(tr);\n\
    \        zl.push_back(0);\n        for (int k = 1; k <= mid; ++k) {\n        \
    \    int li = m - k - zl[k], ri = m + min(r - m, zr[len - k]);\n            if\
    \ (rev) {\n                swap(li, ri);\n                li = l + r - li;\n \
    \               ri = l + r - ri;\n            }\n            if (ri - li < 2 *\
    \ k) continue;\n            if (li > 0 && s[li - 1] == s[li - 1 + k]) continue;\n\
    \            if (ri < s.size() && s[ri] == s[ri - k]) continue;\n            if\
    \ (res.count({li, ri})) res[{li, ri}] = min(res[{li, ri}], k);\n            else\
    \ res[{li, ri}] = k;\n        }\n    };\n    func(0);\n    func(1);\n}\n\n"
  dependsOn:
  - lib/template.cpp
  - lib/string/z_algorithm.cpp
  isVerificationFile: false
  path: lib/string/run_enumerate.cpp
  requiredBy: []
  timestamp: '2020-10-17 10:09:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/string/run_enumerate.test.cpp
documentation_of: lib/string/run_enumerate.cpp
layout: document
redirect_from:
- /library/lib/string/run_enumerate.cpp
- /library/lib/string/run_enumerate.cpp.html
title: "Run\u5217\u6319"
---
