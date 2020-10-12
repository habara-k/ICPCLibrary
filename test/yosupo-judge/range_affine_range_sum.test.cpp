#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"

#include "../../lib/structure/lazy_segment_tree.cpp"
#include "../../lib/number/mint.cpp"


using Mint = mint<998244353>;

struct S {
    Mint val;
};

struct T {
    Mint b;
    Mint c;

    bool operator==(const T &rhs) const {
        return b.x == rhs.b.x && c.x == rhs.c.x;
    }
};

int main() {
    int N, Q;
    cin >> N >> Q;

    LazySegmentTree<S, T> segt(
            N,
            [](S a, S b) { return S{a.val + b.val}; },
            [](S l, T r, int w) { return S{l.val * r.b + r.c * w}; },
            [](T l, T r) { return T{l.b * r.b, r.b * l.c + r.c}; },
            S{0}, T{1, 0});

    vector <S> a(N);
    REP(i, N) {
        int tmp;
        cin >> tmp;
        a[i] = {tmp};
    }

    segt.build(a);

    while (Q--) {
        int t;
        cin >> t;
        if (t == 0) {
            ll l, r, b, c;
            cin >> l >> r >> b >> c;
            segt.update(l, r, {b, c});
        } else {
            ll l, r;
            cin >> l >> r;
            Mint val = segt.query(l, r).val;
            cout << val << endl;
        }
    }

    return 0;
}
