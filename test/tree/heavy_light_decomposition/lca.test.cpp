#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_C"

#include "../../../lib/tree/heavy_light_decomposition.cpp"

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

    HLDecomposition hld(g);

    cin >> Q;
    while (Q--) {
        int x, y; cin >> x >> y;
        printf("%d\n", hld.lca(x, y));
    }
}
