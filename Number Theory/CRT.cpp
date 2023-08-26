#include<bits/stdc++.h>
using namespace std;

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
inline long long normalize(long long x, long long mod) {
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
int testCases, t;
long long r[N], m[N], ans, lcmm;
void solve() {
    cin >> t;
    for(int i = 1; i <= t; i++) {
        cin >> r[i] >> m[i];
        normalize(r[i], m[i]);
    }
    ans = r[1];
    lcmm = m[1];
    for(int i = 2; i <= t; i++) {
        auto pom = ex_GCD(lcmm, m[i]);
        int x1 = pom.x;
        int d = pom.d;
        if((r[i] - ans) % d != 0) {
            cout<<"Impossible"<<endl;
            return;
        }
        ans = normalize(ans+x1*(r[i]-ans)/d%(m[i]/d)*lcmm,
                        lcmm*m[i]/d);
        lcmm = LCM(lcmm, m[i]);
    }
    cout << ans << endl;
}
signed main() {
    int tc;
    cin>>tc;
    while(tc--) solve();
}

// https://open.kattis.com/problems/gears
