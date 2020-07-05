#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1312"

#include "../../lib/string/rolling_hash_2D.cpp"

int main() {
    while (true) {
        int w, h, p; cin >> w >> h >> p;
        if (w == 0) break;
        vector<vector<int>> image(h), pattern(p);
        REP(i, h) {
            string str; cin >> str;
            for (char c : str) {
                int n = -1;
                if ('A' <= c and c <= 'Z') n = c - 'A';
                if ('a' <= c and c <= 'z') n = c - 'a' + 26;
                if ('0' <= c and c <= '9') n = c - '0' + 52;
                if (c == '+') n = 62;
                if (c == '/') n = 63;

                REP(j, 6) {
                    image[i].push_back(n >> (5 - j) & 1);
                }
            }
        }
        REP(i, p) {
            string str; cin >> str;
            for (char c : str) {
                int n = -1;
                if ('A' <= c and c <= 'Z') n = c - 'A';
                if ('a' <= c and c <= 'z') n = c - 'a' + 26;
                if ('0' <= c and c <= '9') n = c - '0' + 52;
                if (c == '+') n = 62;
                if (c == '/') n = 63;

                REP(j, 6) {
                    pattern[i].push_back(n >> (5 - j) & 1);
                }
            }
        }

        auto base1 = RollingHash2D::gen_base();
        auto base2 = RollingHash2D::gen_base();

        RollingHash2D Image(image, base1, base2);
        vector<long long> patternHash;

        {
            vector<vector<int>> alt(p, vector<int>(p));
            for (int i = 0; i < p; ++i) {
                for (int j = 0; j < p; ++j) {
                    alt[i][j] = pattern[i][j];
                }
            }
            patternHash.push_back(RollingHash2D(alt, base1, base2).get(0, 0, p, p));
        }
        {
            vector<vector<int>> alt(p, vector<int>(p));
            for (int i = 0; i < p; ++i) {
                for (int j = 0; j < p; ++j) {
                    alt[p-1-i][j] = pattern[i][j];
                }
            }
            patternHash.push_back(RollingHash2D(alt, base1, base2).get(0, 0, p, p));
        }
        {
            vector<vector<int>> alt(p, vector<int>(p));
            for (int i = 0; i < p; ++i) {
                for (int j = 0; j < p; ++j) {
                    alt[i][p-1-j] = pattern[i][j];
                }
            }
            patternHash.push_back(RollingHash2D(alt, base1, base2).get(0, 0, p, p));
        }
        {
            vector<vector<int>> alt(p, vector<int>(p));
            for (int i = 0; i < p; ++i) {
                for (int j = 0; j < p; ++j) {
                    alt[p-1-i][p-1-j] = pattern[i][j];
                }
            }
            patternHash.push_back(RollingHash2D(alt, base1, base2).get(0, 0, p, p));
        }
        {
            vector<vector<int>> alt(p, vector<int>(p));
            for (int i = 0; i < p; ++i) {
                for (int j = 0; j < p; ++j) {
                    alt[i][j] = pattern[j][i];
                }
            }
            patternHash.push_back(RollingHash2D(alt, base1, base2).get(0, 0, p, p));
        }
        {
            vector<vector<int>> alt(p, vector<int>(p));
            for (int i = 0; i < p; ++i) {
                for (int j = 0; j < p; ++j) {
                    alt[p-1-i][j] = pattern[j][i];
                }
            }
            patternHash.push_back(RollingHash2D(alt, base1, base2).get(0, 0, p, p));
        }
        {
            vector<vector<int>> alt(p, vector<int>(p));
            for (int i = 0; i < p; ++i) {
                for (int j = 0; j < p; ++j) {
                    alt[i][p-1-j] = pattern[j][i];
                }
            }
            patternHash.push_back(RollingHash2D(alt, base1, base2).get(0, 0, p, p));
        }
        {
            vector<vector<int>> alt(p, vector<int>(p));
            for (int i = 0; i < p; ++i) {
                for (int j = 0; j < p; ++j) {
                    alt[p-1-i][p-1-j] = pattern[j][i];
                }
            }
            patternHash.push_back(RollingHash2D(alt, base1, base2).get(0, 0, p, p));
        }

        int ans = 0;
        for (int i = 0; i + p <= h; ++i) {
            for (int j = 0; j + p <= w; ++j) {
                long long imageHash = Image.get(i, j, i + p, j + p);
                for (long long hash : patternHash) {
                    if (imageHash == hash) {
                        ++ans;
                        break;
                    }
                }
            }
        }

        cout << ans << endl;
    }
    return 0;
}
