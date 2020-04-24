#include "template.cpp"

template<typename T>
void warshall_floyd(vector<vector<T>> &g) {
    const auto INF = numeric_limits<T>::max();
    int n = g.size();
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(g[i][k] == INF || g[k][j] == INF) continue;
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
}
