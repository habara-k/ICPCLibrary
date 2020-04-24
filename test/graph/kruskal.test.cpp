#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A"

#include "../../lib/graph/kruskal.cpp"

int main() {
    int V, E;
    cin >> V >> E;
    vector<edge<int>> edges;
    for(int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({a, b, c});
    }
    cout << kruskal(edges, V) << endl;
}
