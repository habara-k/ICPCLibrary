#include "../template.cpp"

/**
 * @brief
 * ガウスの消去法
 * 行列をランクを求めたり、Ax = b を解いたりする
 * @author habara-k
 * @date 2020/4
 * @param[in] mat 行列
 * @return int mat のランク
 */

template<class T>
int GaussJordanElimination(vector<vector<T>>& mat) {
    int H = mat.size(), W = mat[0].size(), rank = 0;
    for (int col = 0; col < W; ++col) {
        int pivot = -1;
        for (int row = rank; row < H; ++row) {
            if (mat[row][col] != 0) {
                pivot = row;
                break;
            }
        }
        if (pivot == -1) continue;
        swap(mat[rank], mat[pivot]);
        T topLeft = mat[rank][col];
        for (int c = col; c < W; ++c) {
            mat[rank][c] /= topLeft;
        }
        for (int row = rank+1; row < H; ++row) {
            T ratio = mat[row][col];
            for (int c = col; c < W; ++c)
                mat[row][c] -= ratio * mat[rank][c];
        }
        ++rank;
    }
    return (rank);
}
