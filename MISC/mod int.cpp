#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
template <const int32_t MOD>
struct modint {
  int32_t value;
  modint() = default;
  modint(int32_t value_) : value(value_%MOD) {}
  modint(long long value_) : value(value_%MOD) {}
  inline modint<MOD> operator + (modint<MOD> other) const { int32_t c = this->value + other.value; return modint<MOD>(c >= MOD ? c - MOD : c); }
  inline modint<MOD> operator - (modint<MOD> other) const { int32_t c = this->value - other.value; return modint<MOD>(c <    0 ? c + MOD : c); }
  inline modint<MOD> operator * (modint<MOD> other) const { int32_t c = (int64_t)this->value * other.value % MOD; return modint<MOD>(c < 0 ? c + MOD : c); }
  inline modint<MOD> & operator += (modint<MOD> other) { this->value += other.value; if (this->value >= MOD) this->value -= MOD; return *this; }
  inline modint<MOD> & operator -= (modint<MOD> other) { this->value -= other.value; if (this->value <    0) this->value += MOD; return *this; }
  inline modint<MOD> & operator *= (modint<MOD> other) { this->value = (int64_t)this->value * other.value % MOD; if (this->value < 0) this->value += MOD; return *this; }
  inline modint<MOD> operator - () const { return modint<MOD>(this->value ? MOD - this->value : 0); }
  modint<MOD> pow(uint64_t k) const { modint<MOD> x = *this, y = 1; for (; k; k >>= 1) { if (k & 1) y *= x; x *= x; } return y; }
  modint<MOD> inv() const { return pow(MOD - 2); }  // MOD must be a prime
  inline modint<MOD> operator /  (modint<MOD> other) const { return *this *  other.inv(); }
  inline modint<MOD> operator /= (modint<MOD> other)       { return *this *= other.inv(); }
  inline modint<MOD> operator % (modint<MOD> other)   const    { return *this % other.inv(); }
  inline modint<MOD> operator %= (modint<MOD> other)       { return *this %= other.inv(); }
  inline bool operator == (modint<MOD> other) const { return value == other.value; }
  inline bool operator != (modint<MOD> other) const { return value != other.value; }
  inline bool operator < (modint<MOD> other) const { return value < other.value; }
  inline bool operator <= (modint<MOD> other) const { return value <= other.value; }
  inline bool operator > (modint<MOD> other) const { return value > other.value; }
  inline bool operator >= (modint<MOD> other) const { return value >= other.value; }
};
template <int32_t MOD> modint<MOD> operator * (int64_t value, modint<MOD> n) { return modint<MOD>(value) * n; }
template <int32_t MOD> modint<MOD> operator * (int32_t value, modint<MOD> n) { return modint<MOD>(value % MOD) * n; }
template <int32_t MOD> istream & operator >> (istream & in, modint<MOD> &n) { return in >> n.value; }
template <int32_t MOD> ostream & operator << (ostream & out, modint<MOD> n) { return out << n.value; }

using mint = modint<mod>;

const int N = 2000005;
mint fact[N],inv[N];

void calcFact(){
    fact[0] = 1;
    for(int i=1;i<N;i++){
        fact[i] = fact[i-1]*i;
    }
    inv[N-1] = fact[N-1].inv();
    for(int i=N-2;i>=0;i--){
        inv[i] = inv[i+1]*(i+1);
    }
}
mint CatalanTriangle(int n,int r){
    if( n<r ) return 0;
    mint val = fact[n+r]*inv[r]*inv[n+1]*(n-r+1);
    return val;
}
int main(){
    calcFact();
    int n;
    cin>>n;
    if( n%2 == 0 ) cout<<CatalanTriangle(n/2,n/2);
    else cout<<0;
}

// https://cses.fi/problemset/result/5214024/
