#include "./template.cpp"

template<typename T>
struct LowLink {
    const int inf = 1000000000;
    int sz;
    std::vector<int> pre, low;
    std::vector<bool> sel;
    std::vector<std::pair<int, int>> bridge;
    std::vector<int> articulation;

    LowLink(const Graph<T> &g) {
        sz = g.size();
        pre.resize(sz, inf);
        low.resize(sz, inf);
        sel.resize(sz, false);
        int cnt = 0;
        dfs(g, 0, -1, cnt);
    }

    void dfs(const Graph<T> &g, int now, int prev, int &cnt) {
        if(pre[now] != inf) {
            low[prev] = min(low[prev], pre[now]);
            return;
        }
        pre[now] = cnt;
        low[now] = cnt;
        cnt++;
        for(int i=0;i<(int)(g[now].size());++i) {
            int nxt = g[now][i].to;
            //if g is an undirected graph
            if(nxt == prev) continue;
            dfs(g, nxt, now, cnt);
        }
        if(prev != -1) low[prev] = min(low[prev], low[now]);
        if(prev != -1 && pre[prev] < low[now]) {
            bridge.emplace_back(make_pair(prev, now));
        }
    }

    void get_articulation(const Graph<T> &g, int now, int prev) {
        sel[now] = true;
        int art = 0;
        for(int i=0;i<(int)(g[now].size());++i) {
            int nxt = g[now][i].to;
            //cout << now << ":" << nxt << endl;
            if(sel[nxt]) continue;
            // if g is an undirected graph
            if(nxt == prev) continue;
            if(now == 0 || pre[now] <= low[nxt]) art++;
            get_articulation(g, nxt, now);
        }
        if((now == 0 && art >= 2) || (now != 0 && art >= 1)) {
            articulation.push_back(now);
        }
    }
};
