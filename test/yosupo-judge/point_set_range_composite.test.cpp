#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"

#include "../../lib/number/mint.cpp"
#include "../../lib/structure/segment_tree.cpp"

int main() {
    int n, q; cin >> n >> q;
    using Int = mint<998244353>;
    using T = pair<Int,Int>;

    SegmentTree<T> segt(n,
            [](T a,T b){return T{a.first*b.first, b.first*a.second + b.second};},
            [](T a,T b){return b;}, T{1,0});

    vector<T> init(n);
    REP(i, n) {
        int a, b; cin >> a >> b;
        init[i] = {a, b};
    }
    segt.build(init);

    while (q--) {
        int type; cin >> type;
        if (type == 0) {
            int p, c, d; cin >> p >> c >> d;
            segt.update(p, T{c, d});
        } else {
            int l, r, x; cin >> l >> r >> x;
            auto f = segt.query(l, r);
            cout << f.first * x + f.second << endl;
        }
    }


    return 0;
}
