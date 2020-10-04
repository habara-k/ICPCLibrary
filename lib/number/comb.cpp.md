---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/template.cpp
    title: lib/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
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
    \   // cin.rdbuf(in.rdbuf());\n\n    return 0;\n}\n*/\n\n\n#line 2 \"lib/number/comb.cpp\"\
    \n\n#define SNIPPET_ONLY\n\ntemplate<typename Field>\nstruct Combination {\n \
    \   int _n = 1;\n    vector<Field> _fact{1}, _rfact{1}, _inv{1};\n\n    void extend(int\
    \ n) {\n        _fact.resize(n);\n        _rfact.resize(n);\n        _inv.resize(n);\n\
    \        for (int i = _n; i < n; ++i) _fact[i] = _fact[i - 1] * i;\n        _rfact[n\
    \ - 1] = 1 / _fact[n - 1];\n        for (int i = n - 1; i > _n; --i) _rfact[i\
    \ - 1] = _rfact[i] * i;\n        for (int i = _n; i < n; ++i) _inv[i] = _rfact[i]\
    \ * _fact[i - 1];\n        _n = n;\n    }\n\n    Field fact(int k) {\n       \
    \ if (_n <= k) extend(k + 1);\n        return _fact.at(k);\n    }\n\n    Field\
    \ rfact(int k) {\n        if (_n <= k) extend(k + 1);\n        return _rfact.at(k);\n\
    \    }\n\n    Field inv(int k) {\n        assert(k != 0);\n        if (_n <= k)\
    \ extend(k + 1);\n        return _inv.at(k);\n    }\n\n    Field P(int n, int\
    \ r) {\n        if (r < 0 or n < r) return 0;\n        return fact(n) * rfact(n\
    \ - r);\n    }\n\n    Field C(int n, int r) {\n        if (r < 0 or n < r) return\
    \ 0;\n        return fact(n) * rfact(r) * rfact(n - r);\n    }\n\n    Field H(int\
    \ n, int r) {\n        return (n == 0 and r == 0) ? 1 : C(n + r - 1, r);\n   \
    \ }\n};\n\n"
  code: "#include \"../template.cpp\"\n\n#define SNIPPET_ONLY\n\ntemplate<typename\
    \ Field>\nstruct Combination {\n    int _n = 1;\n    vector<Field> _fact{1}, _rfact{1},\
    \ _inv{1};\n\n    void extend(int n) {\n        _fact.resize(n);\n        _rfact.resize(n);\n\
    \        _inv.resize(n);\n        for (int i = _n; i < n; ++i) _fact[i] = _fact[i\
    \ - 1] * i;\n        _rfact[n - 1] = 1 / _fact[n - 1];\n        for (int i = n\
    \ - 1; i > _n; --i) _rfact[i - 1] = _rfact[i] * i;\n        for (int i = _n; i\
    \ < n; ++i) _inv[i] = _rfact[i] * _fact[i - 1];\n        _n = n;\n    }\n\n  \
    \  Field fact(int k) {\n        if (_n <= k) extend(k + 1);\n        return _fact.at(k);\n\
    \    }\n\n    Field rfact(int k) {\n        if (_n <= k) extend(k + 1);\n    \
    \    return _rfact.at(k);\n    }\n\n    Field inv(int k) {\n        assert(k !=\
    \ 0);\n        if (_n <= k) extend(k + 1);\n        return _inv.at(k);\n    }\n\
    \n    Field P(int n, int r) {\n        if (r < 0 or n < r) return 0;\n       \
    \ return fact(n) * rfact(n - r);\n    }\n\n    Field C(int n, int r) {\n     \
    \   if (r < 0 or n < r) return 0;\n        return fact(n) * rfact(r) * rfact(n\
    \ - r);\n    }\n\n    Field H(int n, int r) {\n        return (n == 0 and r ==\
    \ 0) ? 1 : C(n + r - 1, r);\n    }\n};\n\n"
  dependsOn:
  - lib/template.cpp
  isVerificationFile: false
  path: lib/number/comb.cpp
  requiredBy: []
  timestamp: '2020-10-03 18:19:10+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/number/comb.cpp
layout: document
redirect_from:
- /library/lib/number/comb.cpp
- /library/lib/number/comb.cpp.html
title: lib/number/comb.cpp
---
