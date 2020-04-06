#include "template.cpp"

// verify: https://codeforces.com/contest/590/problem/C

/**
 * @brief
 * 01-BFS
 * 辺の重みが01の時にO(E+V)で単一始点最短路をやる
 * @author Md
 * @date 2019/12
 * @param[in] g グラフ
 * @param[in] s 始点
 * @return vector<T> sからそれぞれの頂点への最短路
 * 
 * @details
 * 2020/04/07
 * ソースコード修正、コメント追加、テスト追加 by Md
 * テストはdijkstraのものを流用(01-BFSでしか通らない問題、あるか？)
 */

template <typename T>
std::vector<T> bfs01(const Graph<T> &g, int s) {
    const T INF = numeric_limits<T>::max();
    std::vector<T> res(SZ(g), INF);
    deque<pair<T, int>> deq;
    res[s] = 0;
    deq.push_back({0, s});
    while(!deq.empty()) {
        auto elm = deq.front(); deq.pop_front();
        T cost = elm.first;
        int now = elm.second;
        if(cost > res[now]) continue;

        for(auto &ne: g[now]) {
            int nxt = ne.to;
            if(res[nxt] > cost + ne.cost) {
                res[nxt] = cost + ne.cost;
                if(ne.cost == 0) {
                    deq.push_front({res[nxt], nxt});
                } else {
                    deq.push_back({res[nxt], nxt});
                }
            }
        }
    }
    
    return res;
}