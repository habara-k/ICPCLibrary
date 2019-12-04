#include "template.cpp"

template<typename flow_t, typename cost_t>
struct PrimalDual {
    const cost_t INF;

    struct edge {
        int to;
        flow_t cap;
        cost_t cost;
        int rev;
    };
    vector<vector<edge>> g;
    vector<cost_t> h, d;
    vector<int> prevv, preve;

    PrimalDual(int V) : g(V), INF(numeric_limits< cost_t >::max()) {}

    void add_edge(int from, int to, flow_t cap, cost_t cost) {
        g[from].push_back({to, cap, cost, (int)g[to].size()});
        g[to].push_back({from, 0, -cost, (int)g[from].size()-1});
    }

    cost_t min_cost_flow(int s, int t, flow_t f) {
        int V = (int)g.size();
        cost_t ret = 0;
        using Pi = pair<cost_t, int>;
        priority_queue<Pi, vector<Pi>, greater<Pi>> que;
        h.assign(V, 0);
        preve.assign(V, -1);
        prevv.assign(V, -1);

        while (f > 0) {
            d.assign(V, INF);
            que.emplace(0, s);
            d[s] = 0;
            while (!que.empty()) {
                Pi p = que.top(); que.pop();
                if (d[p.second] < p.first) continue;
                for (int i = 0; i < g[p.second].size(); i++) {
                    edge &e = g[p.second][i];
                    cost_t nextCost = d[p.second] + e.cost +
                        h[p.second] - h[e.to];
                    if (e.cap > 0 && d[e.to] > nextCost) {
                        d[e.to] = nextCost;
                        prevv[e.to] = p.second, preve[e.to] = i;
                        que.emplace(d[e.to], e.to);
                    }
                }
            }
            if (d[t] == INF) return -1;
            for (int v = 0; v < V; v++) h[v] += d[v];
            flow_t addflow = f;
            for (int v = t; v != s; v = prevv[v]) {
                addflow = min(addflow, g[prevv[v]][preve[v]].cap);
            }
            f -= addflow;
            ret += addflow * h[t];
            for (int v = t; v != s; v = prevv[v]) {
                edge &e = g[prevv[v]][preve[v]];
                e.cap -= addflow;
                g[v][e.rev].cap += addflow;
            }
        }
        return ret;
    }
};
