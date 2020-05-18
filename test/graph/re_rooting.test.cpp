#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_A"

#include "../../lib/graph/re_rooting.cpp"

int main() {
    int n; cin >> n;
    using T = pair<int,int>; // 頂点が持つべきデータ
    using Data = int;        // 親が子を引っ張り上げるときに必要なデータ

    ReRooting<Data,T> tr(
            n,
            [](T a, T b){
                vector<int> v{a.first,a.second,b.first,b.second};
                sort(v.rbegin(),v.rend());
                return T{v[0],v[1]};
                },                       // 子をマージする演算
            [](T a, Data w){
                return T{a.first+w, 0};
                },                       // 子を引っ張り上げる演算
            vector<T>(n, T{0, 0}),       // 頂点が持つデータの初期値
            T{0,0}                       // 子をマージする演算の単位元
            );

    for (int i = 0; i < n-1; ++i) {
        int s, t, w; cin >> s >> t >> w;
        tr.add_edge(s, t, Data{w}, Data{w});
    }

    int ans = 0;
    for (auto& p : tr.solve()) {
        chmax(ans, p.first);
    }

    cout << ans << endl;
}
