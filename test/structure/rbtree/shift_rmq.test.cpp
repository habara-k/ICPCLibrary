#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1508"

#include "../../../lib/structure/rbtree.cpp"

using M = int;
using OM = int;
M f(M a, M b) { return min(a,b); }
M e() { return INF; }
OM id() { return INF; }
OM h(OM a, OM b) {
    if (a==id()) return b;
    if (b==id()) return a;
    return b;
}
M g(M a, OM b) {
    if (b==id()) return a;
    return b;
}

int main() {
    int n, q; cin >> n >> q;
    vi a(n); REP(i, n) cin >> a[i];
    RBTree<M,f,e,OM,g,h,id,500000> tree;
    tree.build(a);
    while (q--) {
        int t; cin >> t;
        if (t == 0) {
            int l, r; cin >> l >> r;
            M val = tree.erase(r);
            tree.insert(l, val);
        }
        if (t == 1) {
            int l, r; cin >> l >> r;
            cout << tree.prod(l, r+1) << endl;
        }
        if (t == 2) {
            int pos, val; cin >> pos >> val;
            tree.apply(pos, pos+1, val);
        }
    }
    return 0;
}
