---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: lib/template.cpp
    title: lib/template.cpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: lib/number/fps.cpp
    title: "\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/number/fps/exp.test.cpp
    title: test/number/fps/exp.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/number/fps/inv.test.cpp
    title: test/number/fps/inv.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/number/fps/log.test.cpp
    title: test/number/fps/log.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/number/fps/pow.test.cpp
    title: test/number/fps/pow.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-judge/convolution.test.cpp
    title: test/yosupo-judge/convolution.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: NTT
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
    \   // cin.rdbuf(in.rdbuf());\n\n    return 0;\n}\n*/\n\n\n#line 2 \"lib/number/ntt.cpp\"\
    \n\n/*\n * @brief NTT\n * @author habara-k\n * @usage\n *   vector<NTT<>::Int>\
    \ a, b;\n *   NTT<> ntt;\n *   auto c = ntt.multiply(a, b);\n * \u6709\u540D\u306A\
    mod, root\u306E\u7D44\n * 998244353, 3\n * 163577857, 23\n * 167772161, 3\n *\
    \ 469762049, 3\n */\ntemplate<int mod=998244353, int root=3>\nstruct NTT {\n \
    \   using Int = mint<mod>;\n    int n;\n    Int r;\n    void ensure(int need)\
    \ {\n        n = 1;\n        while (n < need) n <<= 1;\n        r = Int{root}.pow((mod-1)\
    \ / n);\n    }\n\n    vector<Int> multiply(vector<Int> a, vector<Int> b) {\n \
    \       int need = SZ(a) + SZ(b) - 1;\n        ensure(need);\n        ntt(a);\n\
    \        ntt(b);\n        REP(i, n) (a[i] *= b[i]) /= n;\n        reverse(a.begin()\
    \ + 1, a.end());\n        ntt(a); a.resize(need);\n        return a;\n    }\n\n\
    \    void ntt(vector<Int>& a) {\n        a.resize(n);\n        int p = 0;\n  \
    \      FOR(i, 1, n-1) {\n            for (int k = n >> 1; k > (p ^= k); k >>=\
    \ 1);\n            if (i < p) swap(a[i], a[p]);\n        }\n        for (int k\
    \ = 1; k < n; k <<= 1) {\n            Int base = r.pow(n / (2*k));\n         \
    \   Int z = 1;\n            REP(j, k) {\n                for (int i = j; i < n;\
    \ i += 2*k) {\n                    Int v = a[i+k] * z;\n                    a[i+k]\
    \ = a[i] - v;\n                    a[i] += v;\n                }\n           \
    \     z *= base;\n            }\n        }\n    }\n};\n\n"
  code: "#include \"../template.cpp\"\n\n/*\n * @brief NTT\n * @author habara-k\n\
    \ * @usage\n *   vector<NTT<>::Int> a, b;\n *   NTT<> ntt;\n *   auto c = ntt.multiply(a,\
    \ b);\n * \u6709\u540D\u306Amod, root\u306E\u7D44\n * 998244353, 3\n * 163577857,\
    \ 23\n * 167772161, 3\n * 469762049, 3\n */\ntemplate<int mod=998244353, int root=3>\n\
    struct NTT {\n    using Int = mint<mod>;\n    int n;\n    Int r;\n    void ensure(int\
    \ need) {\n        n = 1;\n        while (n < need) n <<= 1;\n        r = Int{root}.pow((mod-1)\
    \ / n);\n    }\n\n    vector<Int> multiply(vector<Int> a, vector<Int> b) {\n \
    \       int need = SZ(a) + SZ(b) - 1;\n        ensure(need);\n        ntt(a);\n\
    \        ntt(b);\n        REP(i, n) (a[i] *= b[i]) /= n;\n        reverse(a.begin()\
    \ + 1, a.end());\n        ntt(a); a.resize(need);\n        return a;\n    }\n\n\
    \    void ntt(vector<Int>& a) {\n        a.resize(n);\n        int p = 0;\n  \
    \      FOR(i, 1, n-1) {\n            for (int k = n >> 1; k > (p ^= k); k >>=\
    \ 1);\n            if (i < p) swap(a[i], a[p]);\n        }\n        for (int k\
    \ = 1; k < n; k <<= 1) {\n            Int base = r.pow(n / (2*k));\n         \
    \   Int z = 1;\n            REP(j, k) {\n                for (int i = j; i < n;\
    \ i += 2*k) {\n                    Int v = a[i+k] * z;\n                    a[i+k]\
    \ = a[i] - v;\n                    a[i] += v;\n                }\n           \
    \     z *= base;\n            }\n        }\n    }\n};\n\n"
  dependsOn:
  - lib/template.cpp
  isVerificationFile: false
  path: lib/number/ntt.cpp
  requiredBy:
  - lib/number/fps.cpp
  timestamp: '2020-10-23 18:09:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo-judge/convolution.test.cpp
  - test/number/fps/pow.test.cpp
  - test/number/fps/exp.test.cpp
  - test/number/fps/inv.test.cpp
  - test/number/fps/log.test.cpp
documentation_of: lib/number/ntt.cpp
layout: document
redirect_from:
- /library/lib/number/ntt.cpp
- /library/lib/number/ntt.cpp.html
title: NTT
---
