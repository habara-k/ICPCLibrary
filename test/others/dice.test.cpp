#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1181"

#include "../../lib/others/dice.cpp"

bool solve() {
  int n; cin >> n;
  if(n == 0) return false;

  vector<vector<P>> g(201, vector<P>(201, {0, 0}));

  int dr[5] = {0, 1, 0, -1, 0};
  int dc[5] = {0, 0, -1, 0, 1};

  REP(i, n) {
    int a, b; cin >> a >> b;
    Dice dice;
    dice.init(a, b);

    int nowr = 100, nowc = 100;
    while(1) {
      vector<P> tmp = {{dice[1], 1}, {dice[2], 2}, {dice[3], 3}, {dice[4], 4}};
      sort(tmp.rbegin(), tmp.rend());
      bool upd = false;
      for(auto &e: tmp) {
        if(e.first <= 3) break;
        int nr = nowr + dr[e.second], nc = nowc + dc[e.second];
        if(g[nr][nc].second < g[nowr][nowc].second) {
          upd = true;
          nowr = nr;
          nowc = nc;
          switch(e.second) {
            case 1:
              dice.rotf();
              break;
            case 2:
              dice.rotl();
              break;
            case 3:
              dice.rotb();
              break;
            case 4:
              dice.rotr();
              break;
            default:
              assert(false);
          }
          break;
        }
      }
      if(!upd) {
        g[nowr][nowc] = {dice[0], g[nowr][nowc].second + 1};
        break;
      }
    }
  }

  vi ans(7);
  REP(i, 201) {
    REP(j, 201) {
      ans[g[i][j].first]++;
    }
  }

  for(int i=1;i<=6;++i) {
    cout << ans[i];
    if(i == 6) cout << endl;
    else cout << " ";
  }

  return true;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);

  while(solve()) {}


  return 0;
}