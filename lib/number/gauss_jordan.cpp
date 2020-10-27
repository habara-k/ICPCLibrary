#include "../template.cpp"

/*
 * @brief ガウスの消去法
 * @ref https://drken1215.hatenablog.com/entry/2019/03/20/000200
 * @date 2020/10/26
 */
template<class T>
using Matrix = vector<vector<T>>;

template<class T> int GaussJordan(Matrix<T> &A, bool is_extended = false) {
    int m = A.size(), n = A[0].size();
    int rank = 0;
    for (int col = 0; col < n; ++col) {
        if (is_extended && col == n-1) break;
        int pivot = -1;
        T ma = eps;
        for (int row = rank; row < m; ++row) {
            if (abs(A[row][col]) > ma) {
                ma = abs(A[row][col]);
                pivot = row;
            }
        }
        if (pivot == -1) continue;
        swap(A[pivot], A[rank]);
        auto fac = A[rank][col];
        for (int col2 = 0; col2 < n; ++col2) A[rank][col2] /= fac;
        for (int row = 0; row < m; ++row) {
            if (row != rank && abs(A[row][col]) > eps) {
                auto fac = A[row][col];
                for (int col2 = 0; col2 < n; ++col2) {
                    A[row][col2] -= A[rank][col2] * fac;
                }
            }
        }
        ++rank;
    }
    return rank;
}


/*
 * @brief 線型方程式
 * @ref https://drken1215.hatenablog.com/entry/2019/03/20/000200
 * @date 2020/10/26
 * @usage
 * vector<vector<double>> A(m, vector<double>(n));
 * vector<double> b(m);
 * auto x = linear_equation(A, b);
 * if (x.empty()) {
 * // 解なし
 * } else {
 * // xはAx = bを満たす一つの解
 * }
 */
template<class T> vector<T> linear_equation(Matrix<T> A, vector<T> b) {
    // extended
    int m = A.size(), n = A[0].size();
    Matrix<T> M(m, vector<T>(n + 1));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) M[i][j] = A[i][j];
        M[i][n] = b[i];
    }
    int rank = GaussJordan(M, true);

    // check if it has no solution
    vector<T> res;
    for (int row = rank; row < m; ++row) if (abs(M[row][n]) > eps) return res;

    // answer
    res.assign(n, 0);
    int col = 0;
    for (int i = 0; i < rank; ++i) {
        while (abs(M[i][col]) < eps) ++col;
        res[col] = M[i][n];
    }
    return res;
}

