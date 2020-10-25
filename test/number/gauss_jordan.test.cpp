#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1308"
#define ERROR "1e-8"

#include "../../lib/number/gauss_jordan.cpp"


int main() {

    cout << fixed << setprecision(10);

    while (true) {
        int n, s, t; cin >> n >> s >> t;
        --s, --t;
        if (n == 0) break;
        vi q(n); REP(i, n) cin >> q[i];
        vvi a(n, vi(n)); REP(i, n) REP(j, n) cin >> a[i][j];

        vi dist(n, INF), cand(n, 1);
        dist[t] = 0;

        REP(i, n) {
            int mi = -1, min_dist = INF;
            REP(u, n) {
                if (cand[u]) {
                    if (chmin(min_dist, dist[u])) mi = u;
                }
            }
            cand[mi] = 0;
            REP(v, n) {
                if (a[mi][v] == 0) continue;
                chmin(dist[v], dist[mi] + a[mi][v]);
            }
        }

        if (dist[s] == INF) {
            cout << "impossible" << endl;
            continue;
        }

        Matrix<double> A(n, vector<double>(n));
        vector<double> b(n);
        REP(u, n) {
            if (u == t) {
                A[u][u] = 1;
                continue;
            }
            vi neighbors;
            REP(v, n) {
                if (a[u][v] == 0) continue;
                if (q[u] == 1 and dist[u] != dist[v] + a[u][v]) continue;
                neighbors.emplace_back(v);
            }
            for (int v : neighbors) {
                A[u][v] -= 1;
                b[u] += a[u][v];
            }
            A[u][u] += neighbors.size();
        }

        auto res = linear_equation(A, b);
        cout << res[s] << endl;
    }

    return 0;
}

