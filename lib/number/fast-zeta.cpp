#include "../template.cpp"
/**
* @brief 高速ゼータ変換
* @author habara-k
* @date 2020/10/3
* @param[in] f: 2^n -> T
* @param[out] g: s.t. g(s) = \sum_{s \subset t} f(t)
* @details: O(nlogn)
*/
template<typename T>
vector<T> fast_zeta(const vector<T>& f) {
    int n = f.size();
    vector<T> g = f;
    for (int i = 0; (1 << i) < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!(j >> i & 1)) {
                g[j] += g[j | (1<<i)];
            }
        }
    }
    return g;
}
