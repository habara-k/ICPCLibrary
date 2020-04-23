#include "../template.cpp"

template<class T>
using Matrix = vector<vector<T>>;

template<class T>
Matrix<T> operator*(const Matrix<T>& A, const Matrix<T>& B) {
    assert(A[0].size() == B.size());
    int n = A.size(), m = B[0].size(), p = A[0].size();
    Matrix<T> C(n, vector<T>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            for (int k = 0; k < p; ++k)
                C[i][j] += A[i][k] * B[k][j];
    return C;
}

template<class T>
Matrix<T> pow(Matrix<T> a, ll k) {
    int n = a.size(), m = a[0].size();
    Matrix<T> ret(n, vector<T>(m));
    REP(i, n) ret[i][i] = 1;
    while (k) {
        if (k & 1) ret = ret * a;
        a = a * a; k >>= 1;
    }
    return ret;
}
