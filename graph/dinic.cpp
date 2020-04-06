#include "template.cpp"

/**
 * @brief
 * Dinic法(最大流)
 * 始点から終点までフローを流したときの最大流量を求める
 * O(EV^2) （だいたいもっとはやい）
 * ほぼこれhttps://ei1333.github.io/luzhiled/snippets/graph/dinic.html
 * @author Md
 * @date 2019/12
 * @detail
 * 2020/04/07 コメント追加 by Md
 */

template<typename T>
struct Dinic {
    const T INF;

    struct edge {
        int to;
        T cap;
        int rev;
        bool isrev;
    };

    vector<vector<edge>> g;
    vector<int> level, iter;

    /**
     * @param V ネットワークの頂点数
     */
    Dinic(int V) : INF(numeric_limits<T>::max()), g(V) {}

    /**
     * @brief ネットワークに辺を追加
     * @param from 始点
     * @param to 終点
     * @param cap 容量
     */
    void add_edge(int from, int to, T cap) {
        g[from].push_back({to, cap, (int)g[to].size(), false});
        g[to].push_back({from, 0, (int)g[from].size()-1, true});
    }

    /**
     * @brief 始点と終点を決めて最大流を求める
     * @param s 始点
     * @param t 終点
     * @return T 流量
     */
    T max_flow(int s, int t) {
        T flow = 0;
        while (bfs(s, t)) {
            iter.assign((int)(g.size()), 0);
            T f = 0;
            while((f = dfs(s, t, INF)) > 0) flow += f;
        }
        return flow;
    }

private:
    bool bfs(int s, int t) {
        level.assign((int)(g.size()), -1);
        queue<int> que;
        level[s] = 0;
        que.push(s);
        while (!que.empty()) {
            int v = que.front();
            que.pop();
            for (auto &e : g[v]) {
                if (e.cap > 0 && level[e.to] == -1) {
                    level[e.to] = level[v] + 1;
                    que.push(e.to);
                }
            }
        }
        return level[t] != -1;
    }

    T dfs(int v, const int t, T flow) {
        if (v == t) return flow;
        for (int &i = iter[v]; i < (int)(g[v].size()); i++) {
            edge &e = g[v][i];
            if (e.cap > 0 && level[v] < level[e.to]) {
                T d = dfs(e.to, t, min(flow, e.cap));
                if (d > 0) {
                    e.cap -= d;
                    g[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }
};
