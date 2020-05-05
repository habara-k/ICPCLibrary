#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1508"

#include "../../lib/structure/segment_rbst.cpp"

int main() {
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    SegmentRBST<int> tree([](int a,int b){return min(a,b);}, INF);
    tree.build(a);

    while (q--) {
        int x, y, z; cin >> x >> y >> z;
        if (x == 0) {
            int val = tree.erase(z);
            tree.insert(y, val);
        }
        if (x == 1) {
            cout << tree.query(y, z+1) << endl;
        }
        if (x == 2) {
            tree.update(y, [&](int a){return z;});
        }
    }

    return 0;
}
