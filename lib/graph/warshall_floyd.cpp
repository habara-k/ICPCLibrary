#include "template.cpp"

/**
 * @brief
 * 全点対間最短経路(ワーシャルフロイド)
 * O(V^3)
 * @author ?
 * @date ?
 *
 * @param[in] g グラフ(隣接行列)
 * @param[in] inf 到達不可能を表す無限値
 * @param[out] g 最短距離(隣接行列)
 *
 * @details
 * 2020/05/04 コメント追加, inf に使う値を明示的に渡す. by habara-k
 */

template<typename T>
void warshall_floyd(vector<vector<T>> &g, T inf) {
    int n = g.size();
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (g[i][k] == inf or g[k][j] == inf) continue;
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
}
