#include "./extended_gcd.cpp"

pair<ll, ll> crt(ll a1, ll m1, ll a2, ll m2) {
  ll p, q;
  ll g = extended_gcd(m1, m2, p, q);
  if ((a1 - a2) % g) return make_pair(0, -1);
  return make_pair(a1 + m1 * (a2 - a1) / g * p % (m2 / g), m1 * (m2 / g));
}

pair<ll, ll> crt(const vector<ll> &a, const vector<ll> &m) {
  ll r = 0, mod = 1;
  REP(i, SZ(a)) {
    ll p, q;
    ll g = extended_gcd(mod, m[i], p, q);
    if ((a[i] - r) % g) return make_pair(0, -1);
    ll tmp = (a[i] - r) / g * p % (m[i] / g);
    r += mod * tmp;
    mod *= m[i] / g;
  }
  return make_pair(r % mod, mod);
}
