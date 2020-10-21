#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include "../../../lib/structure/rbtree.cpp"

using M = int;
using OM = bool;
M f(M a, M b) { return min(a,b); }
M e() { return INF; }
M g(M a, OM b) { return a; }
OM h(OM a, OM b) { return 0; }
OM id() { return 0; }


int main() {
    int n, q; cin >> n >> q;
    vi a(n); REP(i, n) cin >> a[i];
    RBTree<M,f,e,OM,g,h,id,2000000> tree;
    tree.build(a);
    while (q--) {
        int l, r; cin >> l >> r;
        cout << tree.prod(l,r) << endl;
    }

    return 0;
}

