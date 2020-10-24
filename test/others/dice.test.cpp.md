---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: lib/others/dice.cpp
    title: lib/others/dice.cpp
  - icon: ':question:'
    path: lib/template.cpp
    title: lib/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1181
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1181
  bundledCode: "#line 1 \"test/others/dice.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1181\"\
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
    \n    return 0;\n}\n*/\n\n\n#line 2 \"lib/others/dice.cpp\"\n\n// 0: \u4E0A, 1:\
    \ \u624B\u524D, 2: \u5DE6, 3: \u5965, 4: \u53F3, 5: \u4E0B\nstruct Dice {\n  vi\
    \ face = {1, 3, 2, 4, 5, 6};\n\n  vector<string> cand = {\n      \"124536\",\n\
    \      \"132456\",\n      \"145326\",\n      \"153246\",\n      \"213645\",\n\
    \      \"236415\",\n      \"241365\",\n      \"264135\",\n      \"315624\",\n\
    \      \"321564\",\n      \"356214\",\n      \"362154\",\n      \"412653\",\n\
    \      \"426513\",\n      \"451263\",\n      \"465123\",\n      \"514632\",\n\
    \      \"531462\",\n      \"546312\",\n      \"563142\",\n      \"623541\",\n\
    \      \"635421\",\n      \"642351\",\n      \"654231\"\n  };\n\n  void init(vi\
    \ v) {\n    swap(face, v);\n  }\n\n  // \u4E0A\u3068\u624B\u524D\u306E\u5024\u304B\
    \u3089\u69CB\u7BC9\n  bool init(int top, int front) {\n    if(top == front ||\
    \ top + front == 7) return false;\n    for(auto &v: cand) {\n      if(top == v[0]\
    \ - '0' && front == v[1] - '0') {\n        REP(i, 6) {\n          face[i] = v[i]\
    \ - '0';\n        }\n        break;\n      }\n    }\n    return true;\n  }\n\n\
    \  // \u5DE6\u306B\u8EE2\u304C\u3059\n  void rotl() {\n    vi newface = {face[4],\
    \ face[1], face[0], face[3], face[5], face[2]};\n    swap(face, newface);\n  }\n\
    \n  // \u53F3\u306B\u8EE2\u304C\u3059\n  void rotr() {\n    vi newface = {face[2],\
    \ face[1], face[5], face[3], face[0], face[4]};\n    swap(face, newface);\n  }\n\
    \n  // \u5965\u306B\u8EE2\u304C\u3059\n  void rotb() {\n    vi newface = {face[1],\
    \ face[5], face[2], face[0], face[4], face[3]};\n    swap(face, newface);\n  }\n\
    \n  // \u624B\u524D\u306B\u8EE2\u304C\u3059\n  void rotf() {\n    vi newface =\
    \ {face[3], face[0], face[2], face[5], face[4], face[1]};\n    swap(face, newface);\n\
    \  }\n\n  // \u6B63\u9762\u3092\u5DE6\u9762\u3078\n  void kaitenl() {\n    vi\
    \ newface = {face[0], face[4], face[1], face[2], face[3], face[5]};\n    swap(face,\
    \ newface);\n  }\n\n  // \u6B63\u9762\u3092\u53F3\u9762\u3078\n  void kaitenr()\
    \ {\n    vi newface = {face[0], face[2], face[3], face[4], face[1], face[5]};\n\
    \    swap(face, newface);\n  }\n\n  bool operator==(const Dice &d) const {\n \
    \   return face == d.face;\n  }\n\n  bool operator<(const Dice &d) const {\n \
    \   return face < d.face;\n  }\n\n  int& operator[](int i) {\n    return face[i];\n\
    \  }\n};\n#line 4 \"test/others/dice.test.cpp\"\n\nbool solve() {\n  int n; cin\
    \ >> n;\n  if(n == 0) return false;\n\n  vector<vector<P>> g(201, vector<P>(201,\
    \ {0, 0}));\n\n  int dr[5] = {0, 1, 0, -1, 0};\n  int dc[5] = {0, 0, -1, 0, 1};\n\
    \n  REP(i, n) {\n    int a, b; cin >> a >> b;\n    Dice dice;\n    dice.init(a,\
    \ b);\n\n    int nowr = 100, nowc = 100;\n    while(1) {\n      vector<P> tmp\
    \ = {{dice[1], 1}, {dice[2], 2}, {dice[3], 3}, {dice[4], 4}};\n      sort(tmp.rbegin(),\
    \ tmp.rend());\n      bool upd = false;\n      for(auto &e: tmp) {\n        if(e.first\
    \ <= 3) break;\n        int nr = nowr + dr[e.second], nc = nowc + dc[e.second];\n\
    \        if(g[nr][nc].second < g[nowr][nowc].second) {\n          upd = true;\n\
    \          nowr = nr;\n          nowc = nc;\n          switch(e.second) {\n  \
    \          case 1:\n              dice.rotd();\n              break;\n       \
    \     case 2:\n              dice.rotl();\n              break;\n            case\
    \ 3:\n              dice.rotu();\n              break;\n            case 4:\n\
    \              dice.rotr();\n              break;\n            default:\n    \
    \          assert(false);\n          }\n          break;\n        }\n      }\n\
    \      if(!upd) {\n        g[nowr][nowc] = {dice[0], g[nowr][nowc].second + 1};\n\
    \        break;\n      }\n    }\n  }\n\n  vi ans(7);\n  REP(i, 201) {\n    REP(j,\
    \ 201) {\n      ans[g[i][j].first]++;\n    }\n  }\n\n  for(int i=1;i<=6;++i) {\n\
    \    cout << ans[i];\n    if(i == 6) cout << endl;\n    else cout << \" \";\n\
    \  }\n\n  return true;\n}\n\nint main() {\n  cin.tie(0);\n  ios::sync_with_stdio(false);\n\
    \  cout << fixed << setprecision(10);\n\n  while(solve()) {}\n\n\n  return 0;\n\
    }\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1181\"\
    \n\n#include \"../../lib/others/dice.cpp\"\n\nbool solve() {\n  int n; cin >>\
    \ n;\n  if(n == 0) return false;\n\n  vector<vector<P>> g(201, vector<P>(201,\
    \ {0, 0}));\n\n  int dr[5] = {0, 1, 0, -1, 0};\n  int dc[5] = {0, 0, -1, 0, 1};\n\
    \n  REP(i, n) {\n    int a, b; cin >> a >> b;\n    Dice dice;\n    dice.init(a,\
    \ b);\n\n    int nowr = 100, nowc = 100;\n    while(1) {\n      vector<P> tmp\
    \ = {{dice[1], 1}, {dice[2], 2}, {dice[3], 3}, {dice[4], 4}};\n      sort(tmp.rbegin(),\
    \ tmp.rend());\n      bool upd = false;\n      for(auto &e: tmp) {\n        if(e.first\
    \ <= 3) break;\n        int nr = nowr + dr[e.second], nc = nowc + dc[e.second];\n\
    \        if(g[nr][nc].second < g[nowr][nowc].second) {\n          upd = true;\n\
    \          nowr = nr;\n          nowc = nc;\n          switch(e.second) {\n  \
    \          case 1:\n              dice.rotd();\n              break;\n       \
    \     case 2:\n              dice.rotl();\n              break;\n            case\
    \ 3:\n              dice.rotu();\n              break;\n            case 4:\n\
    \              dice.rotr();\n              break;\n            default:\n    \
    \          assert(false);\n          }\n          break;\n        }\n      }\n\
    \      if(!upd) {\n        g[nowr][nowc] = {dice[0], g[nowr][nowc].second + 1};\n\
    \        break;\n      }\n    }\n  }\n\n  vi ans(7);\n  REP(i, 201) {\n    REP(j,\
    \ 201) {\n      ans[g[i][j].first]++;\n    }\n  }\n\n  for(int i=1;i<=6;++i) {\n\
    \    cout << ans[i];\n    if(i == 6) cout << endl;\n    else cout << \" \";\n\
    \  }\n\n  return true;\n}\n\nint main() {\n  cin.tie(0);\n  ios::sync_with_stdio(false);\n\
    \  cout << fixed << setprecision(10);\n\n  while(solve()) {}\n\n\n  return 0;\n\
    }"
  dependsOn:
  - lib/others/dice.cpp
  - lib/template.cpp
  isVerificationFile: true
  path: test/others/dice.test.cpp
  requiredBy: []
  timestamp: '2020-10-24 19:57:42+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/others/dice.test.cpp
layout: document
redirect_from:
- /verify/test/others/dice.test.cpp
- /verify/test/others/dice.test.cpp.html
title: test/others/dice.test.cpp
---
