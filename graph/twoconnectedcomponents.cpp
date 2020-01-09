#include "./lowlink.cpp"

template<typename T>
struct TwoEdgeConnectedComponents: LowLink<T> {
    using lowlink = LowLink<T>;
    vector<int> comp;

    TwoEdgeConnectedComponents(const Graph<T> &g): lowlink(g) {}

    int operator[] (const int &k) {
        return comp[k];
    }

    void dfs(int idx, int par, int &k) {
        if(!par && this->pre[par] >= this->low[idx]) comp[idx] = comp[par];
        else comp[idx] == k++;
        for(auto &e: this->g[idx]) {
            if(comp[e.to] == -1) dfs(e.to, idx, k);
        }
    }

    void build(Graph<T> &t) {
        lowlink::build();
        comp.assign(this->g.size(), -1);
        int k = 0;
        for(int i=0;i<(int)(comp.size());++i) {
            if(comp[i] == -1) dfs(i, -1, k);
        }
        t.resize(k);
        for(auto &e: this->bridge) {
            int x = comp[e.first], y = comp[e.second];
            t[x].push_back(y);
            t[y].push_back(x);
        }
    }
};