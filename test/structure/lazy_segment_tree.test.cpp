#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G"

#include "../../lib/structure/lazy_segment_tree.cpp"

int main() {
    int N, Q;
    cin >> N >> Q;
    LazySegmentTree<ll> seg(
            N,
            [](ll a, ll b){ return a+b; },
            [](ll a, ll b, ll w){ return a + b*w; },
            [](ll a, ll b){ return a+b; },
            0, 0);

    while (Q--) {
        int C; cin >> C;
        if (C == 0) {
            int S, T; ll X;
            cin >> S >> T >> X;
            --S, --T;
            seg.update(S, T+1, X);
        } else {
            int S, T;
            cin >> S >> T;
            --S, --T;
            cout << seg.query(S, T+1) << endl;
        }
    }
}
