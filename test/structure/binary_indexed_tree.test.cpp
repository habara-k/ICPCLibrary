#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B"

#include "../../structure/binary_indexed_tree.cpp"

int main() {
    int N, Q;
    cin >> N >> Q;
    BIT<int> bit(N);
    while (Q--) {
        int T, X, Y;
        cin >> T >> X >> Y;
        if (T == 0) bit.add(X - 1, Y);
        else printf("%d\n", bit.sum(Y - 1) - bit.sum(X - 2));
    }
}
