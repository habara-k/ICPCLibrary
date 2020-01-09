#define PROBLEM "https://atcoder.jp/contests/abc002/tasks/abc002_4"

#include "../../graph/maximum_clique.cpp"

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<bool>> G(N, vector<bool>(N));
    for(int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        G[x][y] = G[y][x] = true;
    }

    cout << maximum_clique(G) << endl;
}
