#include "../template.cpp"

/**
 * @brief Z Algorithm O(|s|)
 * @param s: 文字列(or vector)
 * @return A[i]: SとS[i:n] のLCPの長さ
 */
template<typename T>
vector<int> z_algorithm(const T& s) {
    int n = s.size();
    vector<int> A(n);
    A[0] = n;
    int i = 1, j = 0;
    while (i < n) {
        while (i+j < n && s[j] == s[i+j]) ++j;
        A[i] = j;
        if (j == 0) { ++i; continue; }
        int k = 1;
        while (i+k < n && k+A[k] < j) { A[i+k] = A[k]; ++k; }
        i += k; j -= k;
    }
    return A;
}

