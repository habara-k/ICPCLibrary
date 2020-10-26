#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_C"

#include "../../lib/graph/lowest_common_ancestor.cpp"

int main() {
    int N, Q;
    cin >> N;
    vector<vector<int>> g(N);
    for (int i = 0; i < N; ++i) {
        int k; cin >> k;
        while (k--) {
            int c; cin >> c;
            g[i].push_back(c);
        }
    }

    LCA lca(g, 0);

    cin >> Q;
    while (Q--) {
        int x, y; cin >> x >> y;
        printf("%d\n", lca.get(x, y));
    }
}
