#include<bits/stdc++.h>
using namespace std;
#define ll long long
/**
Generalized CRT
solves for x where
x = r1 mod m1
x = r2 mod m2
x = r3 mod m3
.............
.............
*/

const int N = 505;
int GCD(int a, int b) {
    return __gcd(a,b);
}
int LCM(int a, int b) {
    return (a/__gcd(a,b))*b;
}
long long normalize(long long x, long long mod) {
    x %= mod;
    if (x < 0) x += mod;
    return x;
}
struct GCD_type {
    long long x, y, d;
};
GCD_type ex_GCD(long long a, long long b) {
    if (b == 0) return {1, 0, a};
    GCD_type pom = ex_GCD(b, a % b);
    return {pom.y, pom.x - a / b * pom.y, pom.d};
}



ll CRT(vector<ll>&r,vector<ll>&m){
    for(int i=0;i<r.size();i++){
        r[i] = normalize(r[i],m[i]);
    }
    ll ans = r[0];
    ll lcmm = m[0];
    for(int i = 1; i < r.size(); i++) {
        auto pom = ex_GCD(lcmm, m[i]);
        int x1 = pom.x;
        int d = pom.d;
        if((r[i] - ans) % d != 0) {
            return -1;
        }
        ans = normalize(ans+x1*(r[i]-ans)/d%(m[i]/d)*lcmm,
                        lcmm*m[i]/d);
        lcmm = LCM(lcmm, m[i]);
    }
    return ans;
}

void solve() {
    int t;
    cin >> t;
    vector<ll> n(t),a(t);
    for(int i = 0; i < t; i++) {
        cin>>n[i]>>a[i];
        if(  i%2 == 1 ){
            a[i] = (n[i]-a[i])%n[i];
        }
    }
    ll ans = CRT(a,n);
    if( ans == -1 ) cout<<"Impossible"<<endl;
    else cout << ans << endl;
}
signed main() {
    int tc;
    cin>>tc;
    while(tc--) solve();
}

// https://open.kattis.com/problems/gears
