template<typename T>
struct SCC {
    int sz, cnt, num;
    vi post, comp;
    vector<pair<int, int>> vp;
    vector<bool> sel;
    Graph<T> revg;

    SCC(const Graph<T> &g) {
        sz = g.size();
        cnt = 0;
        num = 0;
        post.resize(sz, -1);
        comp.resize(sz, -1);
        sel.resize(sz, false);
        revg.resize(sz);
    }

    void build(const Graph<T> &g) {
        for(int i=0;i<sz;++i) {
            if(sel[i]) continue;
            sel[i] = true;
            dfs1(g, i);
        }
        
        rev(g, revg);
        
        for(int i=0;i<sz;++i) {
            vp.emplace_back(make_pair(post[i], i));
        }
        sort(vp.begin(), vp.end());
        reverse(vp.begin(), vp.end());
        sel.clear();
        sel.resize(sz, false);
        for(int i=0;i<sz;++i) {
            if(sel[vp[i].second]) continue;
            sel[vp[i].second] = true;
            comp[vp[i].second] = num;
            dfs2(revg, vp[i].second);
            num++;
        }
    }

    vi get_comp() {return comp;}

    Graph<T> build_graph(const Graph<T> &g) {
        build(g);
        vector<set<int>> s(sz);
        Graph<T> res(sz);
        for(int i=0;i<sz;++i) {
            for(int j=0;j<(int)(g[i].size());++j) {
                s[comp[i]].insert(comp[g[i][j].to]);
            }
        }
        for(int i=0;i<sz;++i) {
            for(auto j: s[i]) {
                if(i != j) res[i].push_back(edge<int>(i, j, 1));
            }
        }
        return res;
    }

    void dfs1(const Graph<T> &g, int now) {
        for(int i=0;i<(int)(g[now].size());++i) {
            int nxt = g[now][i].to;
            if(sel[nxt]) continue;
            sel[nxt] = true;
            dfs1(g, nxt);
        }
        post[now] = cnt;
        cnt++;
    }

    void rev(const Graph<T> &g, Graph<T> &revg) {
        for(int i=0;i<sz;++i) {
            for(int j=0;j<(int)(g[i].size());++j) {
                revg[g[i][j].to].emplace_back(edge<T>(g[i][j].to, g[i][j].src, g[i][j].cost));
            }
        }
    }

    void dfs2(const Graph<T> &revg, int now) {
        for(int i=0;i<(int)(revg[now].size());++i) {
            int nxt = revg[now][i].to;
            if(sel[nxt]) continue;
            sel[nxt] = true;
            comp[nxt] = num;
            dfs2(revg, nxt);
        }
    }
};