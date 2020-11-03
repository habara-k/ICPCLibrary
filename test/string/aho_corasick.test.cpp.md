---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/number/mint.cpp
    title: lib/number/mint.cpp
  - icon: ':heavy_check_mark:'
    path: lib/string/aho_corasick.cpp
    title: Trie
  - icon: ':heavy_check_mark:'
    path: lib/template.cpp
    title: lib/template.cpp
  - icon: ':heavy_check_mark:'
    path: lib/template.cpp
    title: lib/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2257
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2257
  bundledCode: "#line 1 \"test/string/aho_corasick.test.cpp\"\n#define PROBLEM \"\
    http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2257\"\n\n#line 1 \"\
    lib/template.cpp\"\n\n\n\n#include <bits/stdc++.h>\n\nusing namespace std;\n\n\
    #define REP(i, n) for (int i=0; i<(n); ++i)\n#define RREP(i, n) for (int i=(int)(n)-1;\
    \ i>=0; --i)\n#define FOR(i, a, n) for (int i=(a); i<(n); ++i)\n#define RFOR(i,\
    \ a, n) for (int i=(int)(n)-1; i>=(a); --i)\n\n#define SZ(x) ((int)(x).size())\n\
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
    \n    return 0;\n}\n*/\n\n\n#line 2 \"lib/number/mint.cpp\"\n\ntemplate<int m>\n\
    struct mint {\n    int x;\n    mint(ll x = 0) : x(((x % m) + m) % m) {}\n    mint\
    \ operator-() const { return x ? m-x : 0; }\n    mint &operator+=(mint r) {\n\
    \        if ((x += r.x) >= m) x -= m;\n        return *this;\n    }\n    mint\
    \ &operator-=(mint r) {\n        if ((x -= r.x) < 0) x += m;\n        return *this;\n\
    \    }\n    mint &operator*=(mint r) {\n        x = ((ll)x * r.x) % m;\n     \
    \   return *this;\n    }\n    mint inv() const { return pow(m-2); }\n    mint\
    \ &operator/=(mint r) { return *this *= r.inv(); }\n\n    friend mint operator+(mint\
    \ l, mint r) { return l += r; }\n    friend mint operator-(mint l, mint r) { return\
    \ l -= r; }\n    friend mint operator*(mint l, mint r) { return l *= r; }\n  \
    \  friend mint operator/(mint l, mint r) { return l /= r; }\n    mint pow(ll n)\
    \ const {\n        mint ret = 1, tmp = *this;\n        while (n) {\n         \
    \   if (n & 1) ret *= tmp;\n            tmp *= tmp, n >>= 1;\n        }\n    \
    \    return ret;\n    }\n    friend bool operator==(mint l, mint r) { return l.x\
    \ == r.x; }\n    friend bool operator!=(mint l, mint r) { return l.x != r.x; }\n\
    \    friend ostream &operator<<(ostream &os, mint a) {\n        return os << a.x;\n\
    \    }\n    friend istream &operator>>(istream &is, mint& a) {\n        ll x;\
    \ is >> x; a = x; return is;\n    }\n};\n\n#line 2 \"lib/string/aho_corasick.cpp\"\
    \n\n/**\n * @brief Trie\n * @author habara-k\n * @tparam char_size \u6587\u5B57\
    \u306E\u7A2E\u985E\u6570. ASCII\u3067\u9023\u7D9A\u3057\u3066\u3044\u308B\u3053\
    \u3068.\n * @tparam margin 0\u756A\u76EE\u306E\u6587\u5B57 (e.g. 'a')\n * @usage\n\
    \ * AhoCorasick<26,'a'> PMA;\n * PMA.add(\"pattern\");\n * int now = PMA.root;\n\
    \ * string s;\n * for (char c : s) {\n *     while (PMA.nodes[now].nxt[c - 'a']\
    \ == -1) {\n *         now = PMA.nodes[now].nxt[FAIL];\n *     }\n *     now =\
    \ PMA.nodes[now].nxt[c - 'a'];\n *     // now\u306Fs\u3092c\u307E\u3067\u8AAD\u3093\
    \u3060\u3068\u304D\u306E\u30CE\u30FC\u30C9.\n *     // \u3053\u3053\u3067PMA.nodes[now].accept\u3068\
    \u304B\u3092\u5229\u7528\u3057\u3066\u3044\u308D\u3044\u308D\u3084\u308B\n * }\n\
    \ */\ntemplate<int char_size, int margin>\nstruct AhoCorasick {\n    const int\
    \ root = 0, FAIL = char_size;\n    /**\n     * \u69CB\u7BC9\u5F8C\u306E\u5404\u30E1\
    \u30F3\u30D0\u306E\u5024\n     * nxt[FAIL]:\n     *   \u6B21\u306E\u6587\u5B57\
    \u306B\u5BFE\u5FDC\u3059\u308B\u9077\u79FB\u5148\u304C\u306A\u3044\u5834\u5408\
    ,\n     *   nxt[FAIL]\u306B\u79FB\u52D5\u3057\u3066\u304B\u3089\u6B21\u306E\u6587\
    \u5B57\u306B\u9077\u79FB\u3059\u308B\n     * accept[id]:\n     *   \u4ECA\u898B\
    \u3066\u308B\u6587\u5B57\u3067\u3061\u3087\u3046\u3069\u30DE\u30C3\u30C1\u3057\
    \u305F\u30D1\u30BF\u30FC\u30F3\u306Eid\u3092\u30AB\u30A6\u30F3\u30C8\u3057\u305F\
    map\n     */\n    struct Node {\n        vector<int> nxt;\n        map<int,int>\
    \ accept;\n        Node() : nxt(char_size + 1, -1) {}\n    };\n    vector<Node>\
    \ nodes = {Node()};\n\n    /**\n     * @brief \u30D1\u30BF\u30FC\u30F3\u306E\u8FFD\
    \u52A0 O(|s|)\n     * @param s \u8FFD\u52A0\u3059\u308B\u30D1\u30BF\u30FC\u30F3\
    \n     * @param id \u30D1\u30BF\u30FC\u30F3\u306Eid. s\u306E\u7D42\u7AEF\u306B\
    \u5BFE\u5FDC\u3059\u308B\u30CE\u30FC\u30C9\u306Eaccept\u306B\u8FFD\u52A0\u3055\
    \u308C\u308B.\n     */\n    void add(const string& s, int id = 0) {\n        int\
    \ now = root;\n        for (char c : s) {\n            if (nodes[now].nxt[c -\
    \ margin] == -1) {\n                nodes[now].nxt[c - margin] = nodes.size();\n\
    \                nodes.push_back(Node());\n            }\n            now = nodes[now].nxt[c\
    \ - margin];\n        }\n        ++nodes[now].accept[id];\n    }\n\n    /**\n\
    \     * @brief PMA\u306E\u69CB\u7BC9.\n     */\n    void build() {\n        queue<int>\
    \ que;\n        for (int i = 0; i < char_size; ++i) {\n            if (nodes[root].nxt[i]\
    \ == -1) {\n                nodes[root].nxt[i] = root;\n            } else {\n\
    \                que.push(nodes[root].nxt[i]);\n                nodes[nodes[root].nxt[i]].nxt[FAIL]\
    \ = root;\n            }\n        }\n        while (!que.empty()) {\n        \
    \    int now = que.front(); que.pop();\n            for (int i = 0; i < char_size;\
    \ ++i) {\n                if (nodes[now].nxt[i] == -1) continue;\n           \
    \     int fail = nodes[now].nxt[FAIL];\n                while (nodes[fail].nxt[i]\
    \ == -1) {\n                    fail = nodes[fail].nxt[FAIL];\n              \
    \  }\n                nodes[nodes[now].nxt[i]].nxt[FAIL] = nodes[fail].nxt[i];\n\
    \                for (const auto& tp : nodes[nodes[fail].nxt[i]].accept) {\n \
    \                   nodes[nodes[now].nxt[i]].accept[tp.first] += tp.second;\n\
    \                }\n                que.push(nodes[now].nxt[i]);\n           \
    \ }\n        }\n    }\n\n    /**\n     * @brief \u30C7\u30D0\u30C3\u30B0\n   \
    \  * <node> ::= {id #:<fail\u5148\u306Eid>, a:<(a\u306E\u9077\u79FB\u5148\u306E\
    )node>, ..., z:<(z\u306E\u9077\u79FB\u5148\u306E)node>}\n     */\n    friend ostream&\
    \ operator<<(ostream& os, const AhoCorasick& pma) {\n        const int n = pma.nodes.size();\n\
    \        vector<bool> used(n);\n        function<void(int)> dfs = [&](int now)\
    \ {\n            used[now] = true;\n            os << \"{\" << now << \" \" <<\
    \ \"#:\" << pma.nodes[now].nxt[pma.FAIL];\n            for (int i = 0; i < char_size;\
    \ ++i) {\n                int nxt = pma.nodes[now].nxt[i];\n                if\
    \ (nxt != -1) {\n                    os << \", \" << (char)(i + margin) << \"\
    :\";\n                    if (!used[nxt]) dfs(nxt);\n                    else\
    \ os << nxt;\n                }\n            }\n            os << \"}\";\n   \
    \     };\n        dfs(pma.root);\n        return os;\n    }\n};\n\n#line 5 \"\
    test/string/aho_corasick.test.cpp\"\n\nint main() {\n    using Int = mint<MOD>;\n\
    \n    while (true) {\n        int N, M, K; cin >> N >> M >> K;\n        if (N\
    \ == 0) break;\n        map<string,int> str_ord;\n        map<string,vector<string>>\
    \ g;\n        for (int i = 0; i < N; ++i) {\n            string from, to;\n  \
    \          cin >> from >> to;\n            g[from].push_back(to);\n          \
    \  str_ord[from] = str_ord[to] = -1;\n        }\n        for (const auto& tp :\
    \ str_ord) {\n            g[\"\"].push_back(tp.first);\n        }\n        str_ord[\"\
    \"] = -1;\n        int cnt = 0;\n        for (auto& tp : str_ord) {\n        \
    \    tp.second = cnt++;\n        }\n        vector<string> strs;\n        for\
    \ (const auto& tp : str_ord) {\n            strs.push_back(tp.first);\n      \
    \  }\n\n        AhoCorasick<26,'a'> pma;\n        for (int i = 0; i < K; ++i)\
    \ {\n            string sw; cin >> sw;\n            pma.add(sw, i);\n        }\n\
    \        pma.build();\n        const int FAIL = 26;\n\n        using vvI = vector<map<int,Int>>;\n\
    \        using vvvI = vector<vvI>;\n        using vvvvI = vector<vvvI>;\n    \
    \    const int sz = pma.nodes.size();\n        vvvvI dp(2, vvvI(M+1, vvI(cnt)));\n\
    \        dp[0][0][0][0] = 1;\n\n        REP(k, 2) {\n            REP(i, M) {\n\
    \                REP(from, cnt) {\n                    for (const auto& tp : dp[k][i][from])\
    \ {\n                        int now = tp.first;\n                        if (dp[k][i][from][now]\
    \ == 0) continue;\n                        for (const string& s : g[strs[from]])\
    \ {\n                            int len = i + s.size();\n                   \
    \         if (len > M) continue;\n                            int to = str_ord[s];\n\
    \n                            int node = now;\n                            int\
    \ scnt = k;\n                            for (char c : s) {\n                \
    \                while (pma.nodes[node].nxt[c - 'a'] == -1) {\n              \
    \                      node = pma.nodes[node].nxt[FAIL];\n                   \
    \             }\n                                node = pma.nodes[node].nxt[c\
    \ - 'a'];\n                                for (auto& tp : pma.nodes[node].accept)\
    \ {\n                                    scnt += tp.second;\n                \
    \                }\n                            }\n                          \
    \  if (scnt >= 2) continue;\n\n                            dp[scnt][len][to][node]\
    \ += dp[k][i][from][now];\n                        }\n                    }\n\
    \                }\n            }\n        }\n\n        Int ans = 0;\n       \
    \ REP(i, cnt) {\n            for (const auto& tp : dp[1][M][i]) {\n          \
    \      int now = tp.first;\n                ans += dp[1][M][i][now];\n       \
    \     }\n        }\n        cout << ans << endl;\n    }\n\n    return 0;\n}\n\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2257\"\
    \n\n#include \"../../lib/number/mint.cpp\"\n#include \"../../lib/string/aho_corasick.cpp\"\
    \n\nint main() {\n    using Int = mint<MOD>;\n\n    while (true) {\n        int\
    \ N, M, K; cin >> N >> M >> K;\n        if (N == 0) break;\n        map<string,int>\
    \ str_ord;\n        map<string,vector<string>> g;\n        for (int i = 0; i <\
    \ N; ++i) {\n            string from, to;\n            cin >> from >> to;\n  \
    \          g[from].push_back(to);\n            str_ord[from] = str_ord[to] = -1;\n\
    \        }\n        for (const auto& tp : str_ord) {\n            g[\"\"].push_back(tp.first);\n\
    \        }\n        str_ord[\"\"] = -1;\n        int cnt = 0;\n        for (auto&\
    \ tp : str_ord) {\n            tp.second = cnt++;\n        }\n        vector<string>\
    \ strs;\n        for (const auto& tp : str_ord) {\n            strs.push_back(tp.first);\n\
    \        }\n\n        AhoCorasick<26,'a'> pma;\n        for (int i = 0; i < K;\
    \ ++i) {\n            string sw; cin >> sw;\n            pma.add(sw, i);\n   \
    \     }\n        pma.build();\n        const int FAIL = 26;\n\n        using vvI\
    \ = vector<map<int,Int>>;\n        using vvvI = vector<vvI>;\n        using vvvvI\
    \ = vector<vvvI>;\n        const int sz = pma.nodes.size();\n        vvvvI dp(2,\
    \ vvvI(M+1, vvI(cnt)));\n        dp[0][0][0][0] = 1;\n\n        REP(k, 2) {\n\
    \            REP(i, M) {\n                REP(from, cnt) {\n                 \
    \   for (const auto& tp : dp[k][i][from]) {\n                        int now =\
    \ tp.first;\n                        if (dp[k][i][from][now] == 0) continue;\n\
    \                        for (const string& s : g[strs[from]]) {\n           \
    \                 int len = i + s.size();\n                            if (len\
    \ > M) continue;\n                            int to = str_ord[s];\n\n       \
    \                     int node = now;\n                            int scnt =\
    \ k;\n                            for (char c : s) {\n                       \
    \         while (pma.nodes[node].nxt[c - 'a'] == -1) {\n                     \
    \               node = pma.nodes[node].nxt[FAIL];\n                          \
    \      }\n                                node = pma.nodes[node].nxt[c - 'a'];\n\
    \                                for (auto& tp : pma.nodes[node].accept) {\n \
    \                                   scnt += tp.second;\n                     \
    \           }\n                            }\n                            if (scnt\
    \ >= 2) continue;\n\n                            dp[scnt][len][to][node] += dp[k][i][from][now];\n\
    \                        }\n                    }\n                }\n       \
    \     }\n        }\n\n        Int ans = 0;\n        REP(i, cnt) {\n          \
    \  for (const auto& tp : dp[1][M][i]) {\n                int now = tp.first;\n\
    \                ans += dp[1][M][i][now];\n            }\n        }\n        cout\
    \ << ans << endl;\n    }\n\n    return 0;\n}\n\n"
  dependsOn:
  - lib/number/mint.cpp
  - lib/template.cpp
  - lib/string/aho_corasick.cpp
  - lib/template.cpp
  isVerificationFile: true
  path: test/string/aho_corasick.test.cpp
  requiredBy: []
  timestamp: '2020-11-04 01:34:29+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/string/aho_corasick.test.cpp
layout: document
redirect_from:
- /verify/test/string/aho_corasick.test.cpp
- /verify/test/string/aho_corasick.test.cpp.html
title: test/string/aho_corasick.test.cpp
---
