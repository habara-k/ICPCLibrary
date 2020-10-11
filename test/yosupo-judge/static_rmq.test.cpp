#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include "../../lib/structure/segment_tree.cpp"

int main() {
    int n, q; cin >> n >> q;
    vector<int> a(n); REP(i, n) cin >> a[i];

    SegmentTree<int> segt(n, [](int a,int b){return min(a,b);},
            [](int a,int b){return min(a,b);}, 1e9+1);
    segt.build(a);

    while (q--) {
        int l, r; cin >> l >> r;
        cout << segt.query(l, r) << endl;
    }

    return 0;
}
