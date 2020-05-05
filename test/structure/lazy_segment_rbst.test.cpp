#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G"

#include "../../lib/structure/lazy_segment_rbst.cpp"

int main() {
    int N, Q;
    cin >> N >> Q;
    LazySegmentRBST<ll> tree(
            [](ll a, ll b){ return a+b; },
            [](ll a, ll b, ll w){ return a + b*w; },
            [](ll a, ll b){ return a+b; },
            0, 0);

    tree.build(vector<ll>(N, 0));

    while (Q--) {
        int C; cin >> C;
        if (C == 0) {
            int S, T; ll X;
            cin >> S >> T >> X;
            --S, --T;
            tree.update(S, T+1, X);
        } else {
            int S, T;
            cin >> S >> T;
            --S, --T;
            cout << tree.query(S, T+1) << endl;
        }
    }
}
