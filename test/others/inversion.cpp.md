---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: lib/others/inversion.cpp
    title: lib/others/inversion.cpp
  - icon: ':heavy_check_mark:'
    path: lib/structure/binary_indexed_tree.cpp
    title: lib/structure/binary_indexed_tree.cpp
  - icon: ':question:'
    path: lib/template.cpp
    title: lib/template.cpp
  - icon: ':question:'
    path: lib/template.cpp
    title: lib/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/agc034/tasks/agc034_b
  bundledCode: "#line 1 \"test/others/inversion.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/agc034/tasks/agc034_b\"\
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
    \n    return 0;\n}\n*/\n\n\n#line 2 \"lib/others/inversion.cpp\"\n\n#line 2 \"\
    lib/structure/binary_indexed_tree.cpp\"\n\ntemplate<typename T>\nstruct BIT {\n\
    \    vector<T> bit;\n    int sz;\n    BIT(int n) : sz(n+1), bit(n+1) {}\n    void\
    \ add(int i, T x) {\n        i += 1;\n        while (i < sz) { bit[i] += x; i\
    \ += i & -i; }\n    }\n    T sum(int i) {\n        i += 1; T s = 0;\n        while\
    \ (i > 0) { s += bit[i]; i -= i & -i; }\n        return s;\n    }\n};\n#line 4\
    \ \"lib/others/inversion.cpp\"\n\ntemplate<typename T>\nll inversion(const vector<T>&\
    \ a)\n{\n    map<T,int> mp;\n    for (auto e : a) mp[e] = -1;\n    int sz = 0;\n\
    \    for (auto &q : mp) {\n        q.second = sz++;\n    }\n\n    BIT<int> bit(sz+1);\n\
    \    ll res = 0;\n    for (int i = 0; i < a.size(); ++i) {\n        res += i -\
    \ bit.sum(mp[a[i]]);\n        bit.add(mp[a[i]], 1);\n    }\n    return res;\n\
    }\n#line 4 \"test/others/inversion.cpp\"\n\nint main()\n{\n    string s; cin >>\
    \ s;\n\n    vector<vector<int>> vs;\n    vector<int> v;\n    for (int i = 0; i\
    \ <= s.size(); ++i) {\n        if (i == s.size()) {\n            if (v.size())\
    \ vs.push_back(v);\n            v.clear();\n        } else if (s[i] == 'A') {\n\
    \            v.push_back(1);\n        } else if (i+1 < s.size() && s[i] == 'B'\
    \ && s[i+1] == 'C') {\n            v.push_back(0);\n            ++i;\n       \
    \ } else {\n            if (v.size()) vs.push_back(v);\n            v.clear();\n\
    \        }\n    }\n\n    ll ans = 0;\n    for (auto v : vs) {\n        ans +=\
    \ inversion(v);\n    }\n    cout << ans << endl;\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/agc034/tasks/agc034_b\"\n\n\
    #include \"../../lib/others/inversion.cpp\"\n\nint main()\n{\n    string s; cin\
    \ >> s;\n\n    vector<vector<int>> vs;\n    vector<int> v;\n    for (int i = 0;\
    \ i <= s.size(); ++i) {\n        if (i == s.size()) {\n            if (v.size())\
    \ vs.push_back(v);\n            v.clear();\n        } else if (s[i] == 'A') {\n\
    \            v.push_back(1);\n        } else if (i+1 < s.size() && s[i] == 'B'\
    \ && s[i+1] == 'C') {\n            v.push_back(0);\n            ++i;\n       \
    \ } else {\n            if (v.size()) vs.push_back(v);\n            v.clear();\n\
    \        }\n    }\n\n    ll ans = 0;\n    for (auto v : vs) {\n        ans +=\
    \ inversion(v);\n    }\n    cout << ans << endl;\n\n    return 0;\n}\n"
  dependsOn:
  - lib/others/inversion.cpp
  - lib/template.cpp
  - lib/structure/binary_indexed_tree.cpp
  - lib/template.cpp
  isVerificationFile: false
  path: test/others/inversion.cpp
  requiredBy: []
  timestamp: '2020-05-06 01:41:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: test/others/inversion.cpp
layout: document
redirect_from:
- /library/test/others/inversion.cpp
- /library/test/others/inversion.cpp.html
title: test/others/inversion.cpp
---
