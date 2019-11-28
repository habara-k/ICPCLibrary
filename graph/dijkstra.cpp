#include "template.cpp"

template<typename T>
vector<T> dijkstra(Graph<T> &g, int s) {
    const auto INF = inf<T>();
    vector<T> d(g.size(), INF);

    using Pi = pair<T, int>;
    priority_queue<Pi, vector<Pi>, greater<Pi>> que;
    d[s] = 0;
    que.emplace(d[s], s);
    while (!que.empty()) {
        T cost;
        int v;
        tie(cost, v) = que.top();
        que.pop();
        if (d[v] < cost) continue;
        for (auto &e : g[v]) {
            auto nxt = cost + e.cost;
            if (d[e.to] > nxt) {
                d[e.to] = nxt;
                que.emplace(nxt, e.to);
            }
        }
    }
    return d;
}
