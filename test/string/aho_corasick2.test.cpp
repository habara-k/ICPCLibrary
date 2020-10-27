#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2257"

#include "../../lib/string/aho_corasick.cpp"

int main() {
    map<char,int> dy, dx;
    dy['U'] = -1, dy['R'] = 0, dy['D'] = 1, dy['L'] = 0;
    dx['U'] = 0, dx['R'] = 1, dx['D'] = 0, dx['L'] = -1;

    while (true) {
        int n, m; cin >> n >> m;
        if (n == 0) break;
        vector<string> board(n);
        int si, sj;
        for (int i = 0; i < n; ++i) {
            cin >> board[i];
            for (int j = 0; j < m; ++j) {
                if (board[i][j] == 'S') {
                    si = i, sj = j;
                }
            }
        }

        AhoCorasick<26,'A'> pma;
        int P; cin >> P;
        for (int i = 0; i < P; ++i) {
            string p; cin >> p;
            pma.add(p, i);
        }
        pma.build();

        queue<tuple<int,int,int,int>> que;
        que.emplace(si, sj, 0, pma.root);
        map<tuple<int,int,int>,bool> used;
        used[make_tuple(si, sj, pma.root)] = true;

        int ans = -1;

        while (!que.empty()) {
            int i, j, d, now;
            tie(i, j, d, now) = que.front(); que.pop();
            if (board[i][j] == 'G') {
                ans = d;
                break;
            }
            for (char dir : { 'U', 'R', 'D', 'L' }) {
                int tmp = now;
                int y = i + dy[dir], x = j + dx[dir];
                if (y < 0 or n <= y or x < 0 or m <= x or
                    board[y][x] == '#') continue;

                while (pma.nodes[tmp].nxt[dir - 'A'] == -1) {
                    tmp = pma.nodes[tmp].nxt[pma.FAIL];
                }
                tmp = pma.nodes[tmp].nxt[dir - 'A'];
                if (!pma.nodes[tmp].accept.empty()) {
                    continue;
                }
                if (!used.count(make_tuple(y, x, tmp))) {
                    used[make_tuple(y, x, tmp)] = true;
                    que.emplace(y, x, d + 1, tmp);
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}

