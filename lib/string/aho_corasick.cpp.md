---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/template.cpp
    title: lib/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/string/aho_corasick.test.cpp
    title: test/string/aho_corasick.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/string/aho_corasick2.test.cpp
    title: test/string/aho_corasick2.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Trie
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
    \   // cin.rdbuf(in.rdbuf());\n\n    return 0;\n}\n*/\n\n\n#line 2 \"lib/string/aho_corasick.cpp\"\
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
    \     };\n        dfs(pma.root);\n        return os;\n    }\n};\n\n"
  code: "#include \"../template.cpp\"\n\n/**\n * @brief Trie\n * @author habara-k\n\
    \ * @tparam char_size \u6587\u5B57\u306E\u7A2E\u985E\u6570. ASCII\u3067\u9023\u7D9A\
    \u3057\u3066\u3044\u308B\u3053\u3068.\n * @tparam margin 0\u756A\u76EE\u306E\u6587\
    \u5B57 (e.g. 'a')\n * @usage\n * AhoCorasick<26,'a'> PMA;\n * PMA.add(\"pattern\"\
    );\n * int now = PMA.root;\n * string s;\n * for (char c : s) {\n *     while\
    \ (PMA.nodes[now].nxt[c - 'a'] == -1) {\n *         now = PMA.nodes[now].nxt[FAIL];\n\
    \ *     }\n *     now = PMA.nodes[now].nxt[c - 'a'];\n *     // now\u306Fs\u3092\
    c\u307E\u3067\u8AAD\u3093\u3060\u3068\u304D\u306E\u30CE\u30FC\u30C9.\n *     //\
    \ \u3053\u3053\u3067PMA.nodes[now].accept\u3068\u304B\u3092\u5229\u7528\u3057\u3066\
    \u3044\u308D\u3044\u308D\u3084\u308B\n * }\n */\ntemplate<int char_size, int margin>\n\
    struct AhoCorasick {\n    const int root = 0, FAIL = char_size;\n    /**\n   \
    \  * \u69CB\u7BC9\u5F8C\u306E\u5404\u30E1\u30F3\u30D0\u306E\u5024\n     * nxt[FAIL]:\n\
    \     *   \u6B21\u306E\u6587\u5B57\u306B\u5BFE\u5FDC\u3059\u308B\u9077\u79FB\u5148\
    \u304C\u306A\u3044\u5834\u5408,\n     *   nxt[FAIL]\u306B\u79FB\u52D5\u3057\u3066\
    \u304B\u3089\u6B21\u306E\u6587\u5B57\u306B\u9077\u79FB\u3059\u308B\n     * accept[id]:\n\
    \     *   \u4ECA\u898B\u3066\u308B\u6587\u5B57\u3067\u3061\u3087\u3046\u3069\u30DE\
    \u30C3\u30C1\u3057\u305F\u30D1\u30BF\u30FC\u30F3\u306Eid\u3092\u30AB\u30A6\u30F3\
    \u30C8\u3057\u305Fmap\n     */\n    struct Node {\n        vector<int> nxt;\n\
    \        map<int,int> accept;\n        Node() : nxt(char_size + 1, -1) {}\n  \
    \  };\n    vector<Node> nodes = {Node()};\n\n    /**\n     * @brief \u30D1\u30BF\
    \u30FC\u30F3\u306E\u8FFD\u52A0 O(|s|)\n     * @param s \u8FFD\u52A0\u3059\u308B\
    \u30D1\u30BF\u30FC\u30F3\n     * @param id \u30D1\u30BF\u30FC\u30F3\u306Eid. s\u306E\
    \u7D42\u7AEF\u306B\u5BFE\u5FDC\u3059\u308B\u30CE\u30FC\u30C9\u306Eaccept\u306B\
    \u8FFD\u52A0\u3055\u308C\u308B.\n     */\n    void add(const string& s, int id\
    \ = 0) {\n        int now = root;\n        for (char c : s) {\n            if\
    \ (nodes[now].nxt[c - margin] == -1) {\n                nodes[now].nxt[c - margin]\
    \ = nodes.size();\n                nodes.push_back(Node());\n            }\n \
    \           now = nodes[now].nxt[c - margin];\n        }\n        ++nodes[now].accept[id];\n\
    \    }\n\n    /**\n     * @brief PMA\u306E\u69CB\u7BC9.\n     */\n    void build()\
    \ {\n        queue<int> que;\n        for (int i = 0; i < char_size; ++i) {\n\
    \            if (nodes[root].nxt[i] == -1) {\n                nodes[root].nxt[i]\
    \ = root;\n            } else {\n                que.push(nodes[root].nxt[i]);\n\
    \                nodes[nodes[root].nxt[i]].nxt[FAIL] = root;\n            }\n\
    \        }\n        while (!que.empty()) {\n            int now = que.front();\
    \ que.pop();\n            for (int i = 0; i < char_size; ++i) {\n            \
    \    if (nodes[now].nxt[i] == -1) continue;\n                int fail = nodes[now].nxt[FAIL];\n\
    \                while (nodes[fail].nxt[i] == -1) {\n                    fail\
    \ = nodes[fail].nxt[FAIL];\n                }\n                nodes[nodes[now].nxt[i]].nxt[FAIL]\
    \ = nodes[fail].nxt[i];\n                for (const auto& tp : nodes[nodes[fail].nxt[i]].accept)\
    \ {\n                    nodes[nodes[now].nxt[i]].accept[tp.first] += tp.second;\n\
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
    \     };\n        dfs(pma.root);\n        return os;\n    }\n};\n\n"
  dependsOn:
  - lib/template.cpp
  isVerificationFile: false
  path: lib/string/aho_corasick.cpp
  requiredBy: []
  timestamp: '2020-11-04 01:34:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/string/aho_corasick2.test.cpp
  - test/string/aho_corasick.test.cpp
documentation_of: lib/string/aho_corasick.cpp
layout: document
redirect_from:
- /library/lib/string/aho_corasick.cpp
- /library/lib/string/aho_corasick.cpp.html
title: Trie
---
