#include "../template.cpp"

/**
* @brief FFT
* @author habara-k
* @date 2020/05/19
* @verify https://atcoder.jp/contests/atc001/submissions/13384565
* @details 使い方
*   e.g. 多項式の積
*
*   vector<complex<double>> a(n+1), b(n+1);
*   auto A = FFT(a, 2*n+1).solve();
*   auto B = FFT(b, 2*n+1).solve();
*
*   vector<complex<double>> C(A.size());
*   REP(i, C.size()) C[i] = A[i] * B[i];
*
*   auto c = FFT(C, 2*n+1).solve(true);
*/

struct FFT {


    /**
    * @brief コンストラクタ. O(n)
    * @param[in] f_ 多項式の係数
    * @param[in] n_ 必要な点の数
    */
    FFT(const vector<complex<double>>& f_, int n_) : f(f_), n(1) {
        while (n < n_) n <<= 1;
        f.resize(n);
    }

    /**
    * @brief FFTの実行. O(nlog n)
    * @param[in] inverse 逆変換のフラグ.
    * @return f のFFT or inverse-FFT
    */
    vector<complex<double>> solve(bool inverse = false) {
        return fft(0, 0, inverse);
    }

private:
    vector<complex<double>> f;
    int n;
    const double PI = acos(-1);

    vector<complex<double>> fft(int d, int bit, bool inverse) {
        int sz = n >> d;
        if (sz == 1) return {f[bit] / (inverse ? (double)n : 1.0)};

        auto F0 = fft(d+1, bit, inverse);
        auto F1 = fft(d+1, bit | 1<<d, inverse);
        vector<complex<double>> F(sz);
        for (int i = 0; i < sz; ++i) {
            F[i] = F0[i % (sz / 2)] +
                    std::polar(1.0, 2*PI / sz * i * (inverse ? -1 : 1)) * F1[i % (sz / 2)];
        }
        return F;
    }
};
