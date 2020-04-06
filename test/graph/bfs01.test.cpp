#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A"

#include "../../graph/bfs01.cpp"

int main() {
    int V, E, R;
    cin >> V >> E >> R;
    Graph<int> g(V);
    for (int i = 0; i < E; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({a,b,c});
    }
    for (auto &dist : dijkstra(g, R)) {
        if (dist == numeric_limits<int>::max()) puts("INF");
        else cout << dist << endl;
    }
}
