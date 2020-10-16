#include "../template.cpp"

struct MaximumIndependentSet {
  int n;
  int ma = 0;
  ll ans = 0;
  vector<P> d;
  vector<P> smalld;
  vector<ll> g;

  // g: 隣接行列 行はbitでもつ
  MaximumIndependentSet(const vector<ll> &g) : n(SZ(g)), g(g) {
    REP(i, n) {
      P tmp;
      tmp.second = i;
      tmp.first = __builtin_popcountll(g[i]);
      if (tmp.first <= 1) {
        smalld.emplace_back(tmp);
      } else {
        d.emplace_back(tmp);
      }
    }
  }

  // maに最大独立集合のサイズ、ansに集合を表すbitが格納される
  int maximum_independent_set() {
    ll now = (1ll << n) - 1;
    ll sel = 0;
    REP(i, SZ(smalld)) {
      int val, idx;
      tie(val, idx) = smalld[i];
      if (!((now >> idx) & 1)) continue;
      sel |= (1ll << idx);
      now &= ~(1ll << idx);
      now &= ~(g[idx]);
    }
    dfs(0, now, sel);
    return ma;
  }

private:

  void dfs(int k, ll now, ll sel) {
    if (k == SZ(d)) {
      bool upd = chmax(ma, __builtin_popcountll(sel));
      if (upd) ans = sel;
      return;
    }
    int val, idx;
    tie(val, idx) = d[k];
    if (!((now >> idx) & 1)) {
      dfs(k + 1, now, sel);
      return;
    }
    now &= ~(1ll << idx);
    dfs(k + 1, now, sel);
    sel |= (1ll << idx);
    now &= ~(g[idx]);
    dfs(k + 1, now, sel);
  }
};

/*
 * (参考）
 * kyopro_friendsさんの実装
 * https://judge.yosupo.jp/submission/5455
 * どうしても定数倍が間に合わないときに借ります
 *
ll minindset(ll g,ll*d){
	//minindsetに属する頂点をbitで返す
	if(g==0)return 0;
	//次数1以下の頂点があればそれは無条件で使ってよい
	for(ll t=g;t;t&=t-1){
		int v=__builtin_ctzll(t);
		int deg=__builtin_popcountll(d[v]&g);
		if(deg<=1)return minindset(g&~(1LL<<v)&~d[v],d)|(1LL<<v);
	}

	//なければ次数最大の頂点に着目する
	int M=0,Mv;
	for(ll t=g;t;t&=t-1){
		int v=__builtin_ctzll(t);
		int deg=__builtin_popcountll(d[v]&g);
		if(deg>M){
			M=deg;
			Mv=v;
		}
	}

	//もし最大次数が2なら、グラフはサイクルたちからなるので
	//使う頂点を勝手に1つ決めて良い
	if(M==2)return minindset(g&~(1LL<<Mv)&~d[Mv],d)|(1LL<<Mv);

	//そうでない場合、その頂点を使うか使わないか両方探索
	ll ans0=minindset(g&~(1LL<<Mv),d);
	ll cnt0=__builtin_popcountll(ans0);
	ll ans1=minindset(g&~(1LL<<Mv)&~d[Mv],d)|(1LL<<Mv);
	ll cnt1=__builtin_popcountll(ans1);

	if(cnt0>=cnt1)return ans0;
	else return ans1;
}

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	ll d[45]={};//隣接行列
	rep(i,0,m){
		int s,g;
		scanf("%d%d",&s,&g);
		d[s]|=1LL<<g;
		d[g]|=1LL<<s;
	}

	ll ans=minindset((1LL<<n)-1,d);
	printf("%d\n",__builtin_popcountll(ans));
	for(ll t=ans;t;t&=t-1)printf("%d ",__builtin_ctzll(t));
}
 */