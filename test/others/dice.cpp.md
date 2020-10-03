---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: lib/others/dice.cpp
    title: lib/others/dice.cpp
  - icon: ':heavy_check_mark:'
    path: lib/template.cpp
    title: lib/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://onlinejudge.u-aizu.ac.jp/challenges/search/titles/1290
  bundledCode: "#line 1 \"test/others/dice.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/challenges/search/titles/1290\"\
    \n#line 1 \"lib/template.cpp\"\n\n\n\n#include <bits/stdc++.h>\n\nusing namespace\
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
    \ face;\n  void init() {\n    face.resize(6);\n  }\n\n  // \u5DE6\u306B\u8EE2\u304C\
    \u3059\n  void rotl() {\n    vi newface = {face[4], face[1], face[0], face[3],\
    \ face[5], face[2]};\n    swap(face, newface);\n  }\n\n  // \u53F3\u306B\u8EE2\
    \u304C\u3059\n  void rotr() {\n    vi newface = {face[2], face[1], face[5], face[3],\
    \ face[0], face[4]};\n    swap(face, newface);\n  }\n\n  // \u5965\u306B\u8EE2\
    \u304C\u3059\n  void rotu() {\n    vi newface = {face[1], face[5], face[2], face[0],\
    \ face[4], face[3]};\n    swap(face, newface);\n  }\n\n  // \u624B\u524D\u306B\
    \u8EE2\u304C\u3059\n  void rotd() {\n    vi newface = {face[3], face[0], face[2],\
    \ face[5], face[4], face[1]};\n    swap(face, newface);\n  }\n};\n\nbool operator==(Dice\
    \ d1, Dice d2) {\n  return d1.face == d2.face;\n}\n\nbool operator<(Dice d1, Dice\
    \ d2) {\n  return d1.face < d2.face;\n}\n#line 3 \"test/others/dice.cpp\"\n\n\n\
    \nstruct Elm {\n  Dice dice;\n  int r, c;\n  int pos;\n  int d;\n};\n\nbool operator<(Elm\
    \ e1, Elm e2) {\n  return make_tuple(e1.d, e1.r, e1.c, e1.dice, e1.pos) < make_tuple(e2.d,\
    \ e2.r, e2.c, e2.dice, e2.pos);\n}\n\nvi dr = {0, 0, -1, 1};\nvi dc = {-1, 1,\
    \ 0, 0};\n\nbool solve() {\n  int h, w; cin >> w >> h;\n  if(h == 0) return false;\n\
    \  vector<string> g(h);\n  map<char, P> mp;\n  P st;\n  REP(i, h) {\n    cin >>\
    \ g[i];\n    REP(j, w) {\n      switch(g[i][j]) {\n        case '#':\n       \
    \   st = {i, j};\n          g[i][j] = 'w';\n          break;\n        case 'w':\n\
    \          break;\n        case 'k':\n          break;\n        default:\n   \
    \       mp[g[i][j]] = {i, j};\n          break;\n      }\n    }\n  }\n\n  string\
    \ s; cin >> s;\n  map<char, int> ord;\n  REP(i, 6) {\n    ord[s[i]] = i;\n  }\n\
    \n  queue<Elm> que;\n\n  Dice dice;\n  dice.face = {0, 1, 2, 3, 4, 5};\n  string\
    \ dicenum = \"rmygbc\";\n\n  vector<vector<vector<map<Dice, int>>>> d(7, vector<vector<map<Dice,\
    \ int>>>(\n    h, vector<map<Dice, int>>(w)));\n  d[0][st.first][st.second][dice]\
    \ = 0;\n  que.push({dice, st.first, st.second, 0, 0});\n  while(!que.empty())\
    \ {\n    auto now = que.front(); que.pop();\n    int nowd = now.d;\n    now.d\
    \ = 0;\n    if(d[now.pos][now.r][now.c].find(now.dice) != d[now.pos][now.r][now.c].end()\
    \ && d[now.pos][now.r][now.c][now.dice] < nowd) continue;\n\n    //cout << now.r\
    \ << \" \" << now.c << \" \" << now.pos << \" \" << nowd << endl;\n\n    REP(i,\
    \ 4) {\n      int nr = now.r + dr[i], nc = now.c + dc[i];\n      Elm nxt = now;\n\
    \      switch(i) {\n        case 0:\n          nxt.dice.rotl();\n          break;\n\
    \        case 1:\n          nxt.dice.rotr();\n          break;\n        case 2:\n\
    \          nxt.dice.rotu();\n          break;\n        default:\n          nxt.dice.rotd();\n\
    \          break;\n      }\n      if(!(0 <= nr && nr < h && 0 <= nc && nc < w))\
    \ continue;\n      nxt.r = nr;\n      nxt.c = nc;\n      if(g[nr][nc] == 'w')\
    \ {\n        if(d[nxt.pos][nxt.r][nxt.c].find(nxt.dice) == d[nxt.pos][nxt.r][nxt.c].end()\
    \ || d[nxt.pos][nxt.r][nxt.c][nxt.dice] > nowd + 1) {\n          d[nxt.pos][nxt.r][nxt.c][nxt.dice]\
    \ = nowd + 1;\n          nxt.d = nowd + 1;\n          que.push(nxt);\n       \
    \ }\n      } else if(ord[g[nr][nc]] == now.pos && dicenum[nxt.dice.face[0]] ==\
    \ g[nr][nc]) {\n        nxt.pos++;\n        if(d[nxt.pos][nxt.r][nxt.c].find(nxt.dice)\
    \ == d[nxt.pos][nxt.r][nxt.c].end() || d[nxt.pos][nxt.r][nxt.c][nxt.dice] > nowd\
    \ + 1) {\n          d[nxt.pos][nxt.r][nxt.c][nxt.dice] = nowd + 1;\n         \
    \ nxt.d = nowd + 1;\n          que.push(nxt);\n        }\n      }\n    }\n  }\n\
    \n  int mi = INF;\n  for(auto &e: d[6][mp[s[5]].first][mp[s[5]].second]) {\n \
    \   chmin(mi, e.second);\n  }\n\n  if(mi == INF) cout << \"unreachable\" << endl;\n\
    \  else cout << mi << endl;\n\n  return true;\n}\n\nint main() {\n  cin.tie(0);\n\
    \  ios::sync_with_stdio(false);\n  cout << fixed << setprecision(10);\n\n  while(solve())\
    \ {}\n\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/challenges/search/titles/1290\"\
    \n#include \"../../lib/others/dice.cpp\"\n\n\n\nstruct Elm {\n  Dice dice;\n \
    \ int r, c;\n  int pos;\n  int d;\n};\n\nbool operator<(Elm e1, Elm e2) {\n  return\
    \ make_tuple(e1.d, e1.r, e1.c, e1.dice, e1.pos) < make_tuple(e2.d, e2.r, e2.c,\
    \ e2.dice, e2.pos);\n}\n\nvi dr = {0, 0, -1, 1};\nvi dc = {-1, 1, 0, 0};\n\nbool\
    \ solve() {\n  int h, w; cin >> w >> h;\n  if(h == 0) return false;\n  vector<string>\
    \ g(h);\n  map<char, P> mp;\n  P st;\n  REP(i, h) {\n    cin >> g[i];\n    REP(j,\
    \ w) {\n      switch(g[i][j]) {\n        case '#':\n          st = {i, j};\n \
    \         g[i][j] = 'w';\n          break;\n        case 'w':\n          break;\n\
    \        case 'k':\n          break;\n        default:\n          mp[g[i][j]]\
    \ = {i, j};\n          break;\n      }\n    }\n  }\n\n  string s; cin >> s;\n\
    \  map<char, int> ord;\n  REP(i, 6) {\n    ord[s[i]] = i;\n  }\n\n  queue<Elm>\
    \ que;\n\n  Dice dice;\n  dice.face = {0, 1, 2, 3, 4, 5};\n  string dicenum =\
    \ \"rmygbc\";\n\n  vector<vector<vector<map<Dice, int>>>> d(7, vector<vector<map<Dice,\
    \ int>>>(\n    h, vector<map<Dice, int>>(w)));\n  d[0][st.first][st.second][dice]\
    \ = 0;\n  que.push({dice, st.first, st.second, 0, 0});\n  while(!que.empty())\
    \ {\n    auto now = que.front(); que.pop();\n    int nowd = now.d;\n    now.d\
    \ = 0;\n    if(d[now.pos][now.r][now.c].find(now.dice) != d[now.pos][now.r][now.c].end()\
    \ && d[now.pos][now.r][now.c][now.dice] < nowd) continue;\n\n    //cout << now.r\
    \ << \" \" << now.c << \" \" << now.pos << \" \" << nowd << endl;\n\n    REP(i,\
    \ 4) {\n      int nr = now.r + dr[i], nc = now.c + dc[i];\n      Elm nxt = now;\n\
    \      switch(i) {\n        case 0:\n          nxt.dice.rotl();\n          break;\n\
    \        case 1:\n          nxt.dice.rotr();\n          break;\n        case 2:\n\
    \          nxt.dice.rotu();\n          break;\n        default:\n          nxt.dice.rotd();\n\
    \          break;\n      }\n      if(!(0 <= nr && nr < h && 0 <= nc && nc < w))\
    \ continue;\n      nxt.r = nr;\n      nxt.c = nc;\n      if(g[nr][nc] == 'w')\
    \ {\n        if(d[nxt.pos][nxt.r][nxt.c].find(nxt.dice) == d[nxt.pos][nxt.r][nxt.c].end()\
    \ || d[nxt.pos][nxt.r][nxt.c][nxt.dice] > nowd + 1) {\n          d[nxt.pos][nxt.r][nxt.c][nxt.dice]\
    \ = nowd + 1;\n          nxt.d = nowd + 1;\n          que.push(nxt);\n       \
    \ }\n      } else if(ord[g[nr][nc]] == now.pos && dicenum[nxt.dice.face[0]] ==\
    \ g[nr][nc]) {\n        nxt.pos++;\n        if(d[nxt.pos][nxt.r][nxt.c].find(nxt.dice)\
    \ == d[nxt.pos][nxt.r][nxt.c].end() || d[nxt.pos][nxt.r][nxt.c][nxt.dice] > nowd\
    \ + 1) {\n          d[nxt.pos][nxt.r][nxt.c][nxt.dice] = nowd + 1;\n         \
    \ nxt.d = nowd + 1;\n          que.push(nxt);\n        }\n      }\n    }\n  }\n\
    \n  int mi = INF;\n  for(auto &e: d[6][mp[s[5]].first][mp[s[5]].second]) {\n \
    \   chmin(mi, e.second);\n  }\n\n  if(mi == INF) cout << \"unreachable\" << endl;\n\
    \  else cout << mi << endl;\n\n  return true;\n}\n\nint main() {\n  cin.tie(0);\n\
    \  ios::sync_with_stdio(false);\n  cout << fixed << setprecision(10);\n\n  while(solve())\
    \ {}\n\n}\n"
  dependsOn:
  - lib/others/dice.cpp
  - lib/template.cpp
  isVerificationFile: false
  path: test/others/dice.cpp
  requiredBy: []
  timestamp: '2020-06-23 21:12:16+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: test/others/dice.cpp
layout: document
redirect_from:
- /library/test/others/dice.cpp
- /library/test/others/dice.cpp.html
title: test/others/dice.cpp
---
