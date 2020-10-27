#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2257"

#include "../../lib/number/mint.cpp"
#include "../../lib/string/aho_corasick.cpp"

int main() {
    using Int = mint<MOD>;

    while (true) {
        int N, M, K; cin >> N >> M >> K;
        if (N == 0) break;
        map<string,int> str_ord;
        map<string,vector<string>> g;
        for (int i = 0; i < N; ++i) {
            string from, to;
            cin >> from >> to;
            g[from].push_back(to);
            str_ord[from] = str_ord[to] = -1;
        }
        for (const auto& tp : str_ord) {
            g[""].push_back(tp.first);
        }
        str_ord[""] = -1;
        int cnt = 0;
        for (auto& tp : str_ord) {
            tp.second = cnt++;
        }
        vector<string> strs;
        for (const auto& tp : str_ord) {
            strs.push_back(tp.first);
        }

        AhoCorasick<26,'a'> pma;
        for (int i = 0; i < K; ++i) {
            string sw; cin >> sw;
            pma.add(sw, i);
        }
        pma.build();
        const int FAIL = 26;

        using vvI = vector<map<int,Int>>;
        using vvvI = vector<vvI>;
        using vvvvI = vector<vvvI>;
        const int sz = pma.nodes.size();
        vvvvI dp(2, vvvI(M+1, vvI(cnt)));
        dp[0][0][0][0] = 1;

        REP(k, 2) {
            REP(i, M) {
                REP(from, cnt) {
                    for (const auto& tp : dp[k][i][from]) {
                        int now = tp.first;
                        if (dp[k][i][from][now] == 0) continue;
                        for (const string& s : g[strs[from]]) {
                            int len = i + s.size();
                            if (len > M) continue;
                            int to = str_ord[s];

                            int node = now;
                            int scnt = k;
                            for (char c : s) {
                                while (pma.nodes[node].nxt[c - 'a'] == -1) {
                                    node = pma.nodes[node].nxt[FAIL];
                                }
                                node = pma.nodes[node].nxt[c - 'a'];
                                for (auto& tp : pma.nodes[node].accept) {
                                    scnt += tp.second;
                                }
                            }
                            if (scnt >= 2) continue;

                            dp[scnt][len][to][node] += dp[k][i][from][now];
                        }
                    }
                }
            }
        }

        Int ans = 0;
        REP(i, cnt) {
            for (const auto& tp : dp[1][M][i]) {
                int now = tp.first;
                ans += dp[1][M][i][now];
            }
        }
        cout << ans << endl;
    }

    return 0;
}

