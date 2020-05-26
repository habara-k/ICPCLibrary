#include "../template.cpp"

/**
* @brief FFT
* @author habara-k
* @date 2020/05/27
* @verify https://atcoder.jp/contests/atc001/submissions/13627626
* @details 使い方
*   e.g. 多項式の積
*
*   vector<complex<double>> a(2*n+1), b(2*n+1);
*
*   auto A = FFT<double>(a).solve();
*   auto B = FFT<double>(b).solve();
*
*   vector<complex<double>> C(A.size());
*   REP(i, C.size()) C[i] = A[i] * B[i];
*
*   auto c = FFT<double>(C).solve(true);
*/


template<typename T>
struct FFT {

    /**
    * @brief コンストラクタ. O(n)
    * @param[in] a_: 多項式の係数
    */
    FFT(const vector<complex<T>>& a_) : a(a_), n(1) {
        while (n < a.size()) n <<= 1;
        a.resize(n);
    }

    /**
    * @brief FFTの実行. O(nlog n)
    * @param[in] inverse: 逆変換のフラグ.
    * @return FFT or inverse-FFT
    */
    vector<complex<T>> solve(bool inverse = false) {
        return fft(0, 0, inverse);
    }

private:
    vector<complex<T>> a;
    int n;
    const T PI = acos(-1);

    vector<complex<T>> fft(int d, int bit, bool inverse) {
        int sz = n >> d;
        if (sz == 1) return {a[bit] / (inverse ? static_cast<T>(n) : 1.0)};

        auto f0 = fft(d+1, bit, inverse);
        auto f1 = fft(d+1, bit | 1<<d, inverse);
        vector<complex<T>> f(sz);
        for (int i = 0; i < sz; ++i) {
            f[i] = f0[i % (sz / 2)] +
                   std::polar(1.0, 2*PI / sz * i * (inverse ? -1 : 1)) *
                   f1[i % (sz / 2)];
        }
        return f;
    }
};
