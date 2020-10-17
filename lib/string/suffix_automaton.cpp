// https://codeforces.com/gym/102428/submission/90057804 (by kanra824)
// ↑テスト　使ってるだけ 2019-2020 ACM-ICPC Latin American Regional Programming Contest

// 参考: https://w.atwiki.jp/uwicoder/pages/2842.html

struct state {
  int len, link;
  map<char, int> next;
};
 
const int MAXLEN = 200010;
state st[MAXLEN * 2];
int sz, last;
 
void sa_init() {
  sz = last = 0;
  st[0].len = 0;
  st[0].link = -1;
  sz++;
}
 

void sa_extend(char c) {
  int cur = sz++;
  st[cur].len = st[last].len + 1;
  int p;
  for (p = last; p != -1 && !st[p].next.count(c); p = st[p].link) {
    st[p].next[c] = cur;
  }
  if (p == -1) {
    st[cur].link = 0;
  } else {
    int q = st[p].next[c];
    if (st[p].len + 1 == st[q].len) {
      st[cur].link = q;
    } else {
      int clone = sz++;
      st[clone].len = st[p].len + 1;
      st[clone].next = st[q].next;
      st[clone].link = st[q].link;
      for (; p != -1 && st[p].next[c] == q; p = st[p].link) {
        st[p].next[c] = clone;
      }
      st[q].link = st[cur].link = clone;
    }
  }
  last = cur;
}

/* つかいかた
 *
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);

  sa_init();
  string c;
  cin >> c;
  REP(i, SZ(c)) {
    sa_extend(c[i]);
  }

  int n;
  cin >> n;
  REP(i, n) {
    int pos = 0;
    int cnt = 1;
    string s;
    cin >> s;

    bool linked = true;
    bool ok = true;
    REP(j, SZ(s)) {
      if (!ok) break;
      FOR(k, j, SZ(s)) {
        if (st[pos].next[s[k]] == 0) {
          if (pos == 0) {
            ok = false;
          }
          cnt++;
          pos = 0;
          j = k - 1;
          break;
        } else {
          pos = st[pos].next[s[k]];
          if (k == SZ(s) - 1) j = k;
        }
      }
    }
    if (!ok) cout << -1 << endl;
    else cout << cnt << endl;
  }


}
 */