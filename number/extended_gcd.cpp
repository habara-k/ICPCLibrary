#include "../template.cpp"

ll extended_gcd(ll a, ll b, ll& x, ll& y) {
    // solve ax + by = gcd(a, b)
    if (b == 0) { x = 1; y = 0; return a; }
    ll X, Y;
    ll g = extended_gcd(b, a % b, X, Y);
    x = Y; y = X - a/b * Y;
    return g;
}
