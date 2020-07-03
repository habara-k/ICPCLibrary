#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/challenges/search/titles/1290"
#include "../../lib/others/dice.cpp"



struct Elm {
  Dice dice;
  int r, c;
  int pos;
  int d;
};

bool operator<(Elm e1, Elm e2) {
  return make_tuple(e1.d, e1.r, e1.c, e1.dice, e1.pos) < make_tuple(e2.d, e2.r, e2.c, e2.dice, e2.pos);
}

vi dr = {0, 0, -1, 1};
vi dc = {-1, 1, 0, 0};

bool solve() {
  int h, w; cin >> w >> h;
  if(h == 0) return false;
  vector<string> g(h);
  map<char, P> mp;
  P st;
  REP(i, h) {
    cin >> g[i];
    REP(j, w) {
      switch(g[i][j]) {
        case '#':
          st = {i, j};
          g[i][j] = 'w';
          break;
        case 'w':
          break;
        case 'k':
          break;
        default:
          mp[g[i][j]] = {i, j};
          break;
      }
    }
  }

  string s; cin >> s;
  map<char, int> ord;
  REP(i, 6) {
    ord[s[i]] = i;
  }

  queue<Elm> que;

  Dice dice;
  dice.face = {0, 1, 2, 3, 4, 5};
  string dicenum = "rmygbc";

  vector<vector<vector<map<Dice, int>>>> d(7, vector<vector<map<Dice, int>>>(
    h, vector<map<Dice, int>>(w)));
  d[0][st.first][st.second][dice] = 0;
  que.push({dice, st.first, st.second, 0, 0});
  while(!que.empty()) {
    auto now = que.front(); que.pop();
    int nowd = now.d;
    now.d = 0;
    if(d[now.pos][now.r][now.c].find(now.dice) != d[now.pos][now.r][now.c].end() && d[now.pos][now.r][now.c][now.dice] < nowd) continue;

    //cout << now.r << " " << now.c << " " << now.pos << " " << nowd << endl;

    REP(i, 4) {
      int nr = now.r + dr[i], nc = now.c + dc[i];
      Elm nxt = now;
      switch(i) {
        case 0:
          nxt.dice.rotl();
          break;
        case 1:
          nxt.dice.rotr();
          break;
        case 2:
          nxt.dice.rotu();
          break;
        default:
          nxt.dice.rotd();
          break;
      }
      if(!(0 <= nr && nr < h && 0 <= nc && nc < w)) continue;
      nxt.r = nr;
      nxt.c = nc;
      if(g[nr][nc] == 'w') {
        if(d[nxt.pos][nxt.r][nxt.c].find(nxt.dice) == d[nxt.pos][nxt.r][nxt.c].end() || d[nxt.pos][nxt.r][nxt.c][nxt.dice] > nowd + 1) {
          d[nxt.pos][nxt.r][nxt.c][nxt.dice] = nowd + 1;
          nxt.d = nowd + 1;
          que.push(nxt);
        }
      } else if(ord[g[nr][nc]] == now.pos && dicenum[nxt.dice.face[0]] == g[nr][nc]) {
        nxt.pos++;
        if(d[nxt.pos][nxt.r][nxt.c].find(nxt.dice) == d[nxt.pos][nxt.r][nxt.c].end() || d[nxt.pos][nxt.r][nxt.c][nxt.dice] > nowd + 1) {
          d[nxt.pos][nxt.r][nxt.c][nxt.dice] = nowd + 1;
          nxt.d = nowd + 1;
          que.push(nxt);
        }
      }
    }
  }

  int mi = INF;
  for(auto &e: d[6][mp[s[5]].first][mp[s[5]].second]) {
    chmin(mi, e.second);
  }

  if(mi == INF) cout << "unreachable" << endl;
  else cout << mi << endl;

  return true;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);

  while(solve()) {}

}
