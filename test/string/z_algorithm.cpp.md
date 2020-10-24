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
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/abc141/tasks/abc141_e
  bundledCode: "#line 1 \"test/string/z_algorithm.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/abc141/tasks/abc141_e\"\
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
    \n    return 0;\n}\n*/\n\n\n#line 2 \"lib/string/z_algorithm.cpp\"\n\n/**\n *\
    \ @brief Z Algorithm O(|s|)\n * @param s: \u6587\u5B57\u5217(or vector)\n * @return\
    \ A[i]: S\u3068S[i:n] \u306ELCP\u306E\u9577\u3055\n */\ntemplate<typename T>\n\
    vector<int> z_algorithm(const T& s) {\n    int n = s.size();\n    vector<int>\
    \ A(n);\n    A[0] = n;\n    int i = 1, j = 0;\n    while (i < n) {\n        while\
    \ (i+j < n && s[j] == s[i+j]) ++j;\n        A[i] = j;\n        if (j == 0) { ++i;\
    \ continue; }\n        int k = 1;\n        while (i+k < n && k+A[k] < j) { A[i+k]\
    \ = A[k]; ++k; }\n        i += k; j -= k;\n    }\n    return A;\n}\n\n#line 4\
    \ \"test/string/z_algorithm.cpp\"\n\nint main() {\n    int n; cin >> n;\n    string\
    \ s; cin >> s;\n\n    int ans = 0;\n\n    for (int i = 0; i < n; ++i) {\n    \
    \    vector<int> a;\n        z_algorithm(s.substr(i, n-i), a);\n        for (int\
    \ j = 0; j < a.size(); ++j) {\n            if (a[j] <= j) {\n                ans\
    \ = max(ans, a[j]);\n            }\n        }\n    }\n\n    cout << ans << endl;\n\
    }\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc141/tasks/abc141_e\"\n\n\
    #include \"../../lib/string/z_algorithm.cpp\"\n\nint main() {\n    int n; cin\
    \ >> n;\n    string s; cin >> s;\n\n    int ans = 0;\n\n    for (int i = 0; i\
    \ < n; ++i) {\n        vector<int> a;\n        z_algorithm(s.substr(i, n-i), a);\n\
    \        for (int j = 0; j < a.size(); ++j) {\n            if (a[j] <= j) {\n\
    \                ans = max(ans, a[j]);\n            }\n        }\n    }\n\n  \
    \  cout << ans << endl;\n}\n"
  dependsOn:
  - lib/string/z_algorithm.cpp
  - lib/template.cpp
  isVerificationFile: false
  path: test/string/z_algorithm.cpp
  requiredBy: []
  timestamp: '2020-10-17 10:09:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: test/string/z_algorithm.cpp
layout: document
redirect_from:
- /library/test/string/z_algorithm.cpp
- /library/test/string/z_algorithm.cpp.html
title: test/string/z_algorithm.cpp
---