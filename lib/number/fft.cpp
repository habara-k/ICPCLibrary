#include "../template.cpp"

/**
 * @brief FFT
 * @author habara-k
 * @usage
 *   FFT<int> fft;
 *   vector<int> a, b;
 *   auto c = fft.multiply(a, b);
 */

template<typename T>
struct FFT {
    using C = complex<double>;
    vector<T> multiply(vector<T> a, vector<T> b) {
        int need = SZ(a) + SZ(b) - 1;
        ensure(need);
        assert((n & (n-1)) == 0);

        vector<C> fa, fb;
        for (T e : a) fa.emplace_back(e, 0);
        for (T e : b) fb.emplace_back(e, 0);
        fa.resize(n);
        fb.resize(n);
        fft(fa);
        fft(fb);

        vector<C> fc(n);
        for (int i = 0; i < n; ++i) fc[i] = fa[i] * fb[i] / (double)n;
        reverse(fc.begin() + 1, fc.end());
        fft(fc);
        vector<T> c;
        for (C e : fc) {
            assert(abs(e.imag()) < eps);
            c.emplace_back(round(e.real()));
        }
        c.resize(need);
        return c;
    }

private:
    int n;
    const double PI = acos(-1);

    void ensure(int need) {
        n = 1;
        while (n < need) n <<= 1;
    }

    void fft(vector<C>& a) {
        int p = 0;
        for (int i = 1; i < n - 1; ++i) {
            for (int k = n >> 1; k > (p ^= k); k >>= 1);
            if (i < p) swap(a[i], a[p]);
        }
        for (int k = 1; k < n; k <<= 1) {
            for (int j = 0; j < k; ++j) {
                C z = polar(1.0, PI / k * j);
                for (int i = j; i < n; i += 2*k) {
                    C u = a[i], v = a[i+k] * z;
                    a[i] = u + v;
                    a[i+k] = u - v;
                }
            }
        }
    }
};

