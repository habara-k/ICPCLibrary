#include "../template.cpp"

// GET A[i]: the longest common prefix size of S and S[i:n-1]
template<typename S>
void z_algorithm(const S& s, vector<int>& A) {
    int n = s.size();
    A.resize(n);
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
}
