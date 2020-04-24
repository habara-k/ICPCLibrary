#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_B"

#include "../../lib/graph/primal_dual.cpp"

int main() {
    int V, E, F;
    cin >> V >> E >> F;
    PrimalDual<int, int> g(V);
    for(int i = 0; i < E; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        g.add_edge(a, b, c, d);
    }
    cout << g.min_cost_flow(0, V - 1, F) << endl;
}
