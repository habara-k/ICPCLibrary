#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C"

#include "../../graph/warshall_floyd.cpp"

int main() {
    int V, E;
    cin >> V >> E;

    const int INF = numeric_limits<int>::max();
    vector<vector<int>> G(V, vector<int>(V, INF));
    for (int i = 0; i < V; ++i) G[i][i] = 0;
    for (int i = 0; i < E; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        G[x][y] = z;
    }

    warshall_floyd(G);
    for (int i = 0; i < V; ++i) {
        if (G[i][i] < 0) {
            puts("NEGATIVE CYCLE");
            return 0;
        }
    }
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            if (j > 0) putchar(' ');
            if (G[i][j] == INF) printf("INF");
            else printf("%d", G[i][j]);
        }
        putchar('\n');
    }
}
