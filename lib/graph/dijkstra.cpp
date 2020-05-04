#include "template.cpp"

/**
 * @brief
 * 単一始点最短路(ダイクストラ)
 * 二分ヒープ(priority_queue)を使ってO((E+V)logV)
 * @author ?
 * @date 2019/12
 *
 * @param[in] g グラフ
 * @param[in] s 始点
 * @param[in] inf 到達不可能を表す無限値
 * @return vector<T> sからそれぞれの頂点への最短路
 *
 * @details
 * 2020/04/07 コメント追加、テスト有無のチェック by Md
 * 2020/05/04 inf に使う値を明示的に渡す. by haraba-k
 */

template<typename T>
vector<T> dijkstra(const Graph<T> &g, int s, T inf) {
    vector<T> d(g.size(), inf);

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
