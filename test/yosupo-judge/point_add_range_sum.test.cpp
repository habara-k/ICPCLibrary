#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include "../../lib/structure/segment_tree.cpp"

int main() {
    int n, q; cin >> n >> q;
    SegmentTree<ll> segt(n, [](ll a,ll b){return a+b;},
            [](ll a,ll b){return a+b;}, 0);
    vector<ll> a(n); REP(i, n) cin >> a[i];
    segt.build(a);

    while (q--) {
        int type; cin >> type;
        if (type == 0) {
            int p; ll x;
            cin >> p >> x;
            segt.update(p, x);
        } else {
            int l, r; cin >> l >> r;
            cout << segt.query(l, r) << endl;
        }
    }

    return 0;
}
