#include "../template.cpp"
/**
* @brief 高速メビウス変換
* @author habara-k
* @date 2020/10/3
* @param[in] g: 2^n -> T
* @param[out] f: s.t. g(s) = \sum_{s \subset t} f(t)
* @details: O(nlogn)
*/
template<typename T>
vector<T> fast_mobius(const vector<T>& g) {
    int n = g.size();
    vector<T> f = g;
    for (int i = 0; (1 << i) < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!(j >> i & 1)) {
                f[j] -= f[j | (1<<i)];
            }
        }
    }
    return f;
}
