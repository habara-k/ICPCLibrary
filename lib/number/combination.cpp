#include "mod.cpp"


// 謎漸化式でO(n * sqrt(n))
// けんちょんさんの写像12相ブログ
vector<ll> P2;
void partition_fast(ll n, ll m) {
    P2[0] = 1;
    for(int i=1;i<100;++i) {
        for(int j=1, sign = 1; i - (j*j*3-j)/2 >= 0; ++j, sign *= -1) {
            P2[i] += P2[i-(j*j*3-j)/2] * sign;
            if(i - (j*j*3+j)/2 >= 0) P2[i] += P2[i-(j*j*3+j)/2] * sign;
        }
    }
}
