#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"

#include "../../../lib/structure/rbtree.cpp"

using Int = ll;
struct M {
    Int a;
    int sz;
};
struct OM {
    Int b, c;
    bool operator==(const OM& other) {
        return b == other.b and c == other.c;
    }
};
ll mod = 998244353;
M f(M l, M r) { ll a = l.a + r.a; if (a >= mod) a -= mod; return M{a, l.sz + r.sz}; }
M e() { return M{0, 0}; }
M g(M l, OM r) { return M{(l.a * r.b + l.sz * r.c) % mod, l.sz}; }
OM h(OM l, OM r) { return OM{(l.b * r.b) % mod, (r.b * l.c + r.c) % mod};}
OM id() { return OM{1, 0}; }


int main() {

    int n, q; cin >> n >> q;
    vector<M> a(n);
    REP(i, n) {
        Int val; cin >> val;
        a[i] = {val, 1};
    }
    RBTree<M,f,e,OM,g,h,id,2000000> tree;
    tree.build(a);
    while (q--) {
        int t; cin >> t;
        if (t == 0) {
            int l, r; Int b, c;
            cin >> l >> r >> b >> c;
            tree.apply(l, r, OM{b, c});
        } else {
            int l, r; cin >> l >> r;
            cout << tree.prod(l, r).a << endl;
        }
    }

    return 0;
}

