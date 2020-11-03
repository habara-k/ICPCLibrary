#include "../template.cpp"

/**
 * @brief Trie
 * @author habara-k
 * @tparam char_size 文字の種類数. ASCIIで連続していること.
 * @tparam margin 0番目の文字 (e.g. 'a')
 * @usage
 * AhoCorasick<26,'a'> PMA;
 * PMA.add("pattern");
 * int now = PMA.root;
 * string s;
 * for (char c : s) {
 *     while (PMA.nodes[now].nxt[c - 'a'] == -1) {
 *         now = PMA.nodes[now].nxt[FAIL];
 *     }
 *     now = PMA.nodes[now].nxt[c - 'a'];
 *     // nowはsをcまで読んだときのノード.
 *     // ここでPMA.nodes[now].acceptとかを利用していろいろやる
 * }
 */
template<int char_size, int margin>
struct AhoCorasick {
    const int root = 0, FAIL = char_size;
    /**
     * 構築後の各メンバの値
     * nxt[FAIL]:
     *   次の文字に対応する遷移先がない場合,
     *   nxt[FAIL]に移動してから次の文字に遷移する
     * accept[id]:
     *   今見てる文字でちょうどマッチしたパターンのidをカウントしたmap
     */
    struct Node {
        vector<int> nxt;
        map<int,int> accept;
        Node() : nxt(char_size + 1, -1) {}
    };
    vector<Node> nodes = {Node()};

    /**
     * @brief パターンの追加 O(|s|)
     * @param s 追加するパターン
     * @param id パターンのid. sの終端に対応するノードのacceptに追加される.
     */
    void add(const string& s, int id = 0) {
        int now = root;
        for (char c : s) {
            if (nodes[now].nxt[c - margin] == -1) {
                nodes[now].nxt[c - margin] = nodes.size();
                nodes.push_back(Node());
            }
            now = nodes[now].nxt[c - margin];
        }
        ++nodes[now].accept[id];
    }

    /**
     * @brief PMAの構築.
     */
    void build() {
        queue<int> que;
        for (int i = 0; i < char_size; ++i) {
            if (nodes[root].nxt[i] == -1) {
                nodes[root].nxt[i] = root;
            } else {
                que.push(nodes[root].nxt[i]);
                nodes[nodes[root].nxt[i]].nxt[FAIL] = root;
            }
        }
        while (!que.empty()) {
            int now = que.front(); que.pop();
            for (int i = 0; i < char_size; ++i) {
                if (nodes[now].nxt[i] == -1) continue;
                int fail = nodes[now].nxt[FAIL];
                while (nodes[fail].nxt[i] == -1) {
                    fail = nodes[fail].nxt[FAIL];
                }
                nodes[nodes[now].nxt[i]].nxt[FAIL] = nodes[fail].nxt[i];
                for (const auto& tp : nodes[nodes[fail].nxt[i]].accept) {
                    nodes[nodes[now].nxt[i]].accept[tp.first] += tp.second;
                }
                que.push(nodes[now].nxt[i]);
            }
        }
    }

    /**
     * @brief デバッグ
     * <node> ::= {id #:<fail先のid>, a:<(aの遷移先の)node>, ..., z:<(zの遷移先の)node>}
     */
    friend ostream& operator<<(ostream& os, const AhoCorasick& pma) {
        const int n = pma.nodes.size();
        vector<bool> used(n);
        function<void(int)> dfs = [&](int now) {
            used[now] = true;
            os << "{" << now << " " << "#:" << pma.nodes[now].nxt[pma.FAIL];
            for (int i = 0; i < char_size; ++i) {
                int nxt = pma.nodes[now].nxt[i];
                if (nxt != -1) {
                    os << ", " << (char)(i + margin) << ":";
                    if (!used[nxt]) dfs(nxt);
                    else os << nxt;
                }
            }
            os << "}";
        };
        dfs(pma.root);
        return os;
    }
};

