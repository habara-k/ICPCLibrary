#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G"

#include "../../structure/lazy_segment_tree.cpp"

int main() {
    int N, Q;
    cin >> N >> Q;
    LazySegmentTree<long long> seg(N);
    while (Q--) {
        int C; cin >> C;
        if (C == 0) {
            int S, T; long long X;
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
