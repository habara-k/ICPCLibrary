---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/string/z_algorithm.cpp
    title: lib/string/z_algorithm.cpp
  - icon: ':heavy_check_mark:'
    path: lib/template.cpp
    title: lib/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/zalgorithm
    links:
    - https://judge.yosupo.jp/problem/zalgorithm
  bundledCode: "#line 1 \"test/yosupo-judge/z_algorithm.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/zalgorithm\"\r\n\r\n#line 1 \"lib/template.cpp\"\
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
    \n    return 0;\n}\n*/\n\n\n#line 2 \"lib/string/z_algorithm.cpp\"\n\n// GET A[i]:\
    \ the longest common prefix size of S and S[i:n-1]\ntemplate<typename S>\nvoid\
    \ z_algorithm(const S& s, vector<int>& A) {\n    int n = s.size();\n    A.resize(n);\n\
    \    A[0] = n;\n    int i = 1, j = 0;\n    while (i < n) {\n        while (i+j\
    \ < n && s[j] == s[i+j]) ++j;\n        A[i] = j;\n        if (j == 0) { ++i; continue;\
    \ }\n        int k = 1;\n        while (i+k < n && k+A[k] < j) { A[i+k] = A[k];\
    \ ++k; }\n        i += k; j -= k;\n    }\n}\n#line 4 \"test/yosupo-judge/z_algorithm.test.cpp\"\
    \n\r\nint main() {\r\n  string s; cin >> s;\r\n  vi a(SZ(s));\r\n  z_algorithm(s,\
    \ a);\r\n  REP(i, SZ(s)) {\r\n    cout << a[i];\r\n    if(i == SZ(s)-1) cout <<\
    \ endl;\r\n    else cout << \" \";\r\n  }\r\n}\r\n\r\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\r\n\r\n#include\
    \ \"../../lib/string/z_algorithm.cpp\"\r\n\r\nint main() {\r\n  string s; cin\
    \ >> s;\r\n  vi a(SZ(s));\r\n  z_algorithm(s, a);\r\n  REP(i, SZ(s)) {\r\n   \
    \ cout << a[i];\r\n    if(i == SZ(s)-1) cout << endl;\r\n    else cout << \" \"\
    ;\r\n  }\r\n}\r\n\r\n"
  dependsOn:
  - lib/string/z_algorithm.cpp
  - lib/template.cpp
  isVerificationFile: true
  path: test/yosupo-judge/z_algorithm.test.cpp
  requiredBy: []
  timestamp: '2020-10-17 05:27:18+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo-judge/z_algorithm.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo-judge/z_algorithm.test.cpp
- /verify/test/yosupo-judge/z_algorithm.test.cpp.html
title: test/yosupo-judge/z_algorithm.test.cpp
---
