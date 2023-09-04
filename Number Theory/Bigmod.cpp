#include<bits/stdc++.h>
using namespace std;
#define M 1000000007
#define ll long long

long long bigmod(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}


int main(){
    cout<<bigmod(2,4,M);
}


/*
    To compute A^(B^C) % MOD
    where MOD is a prime

    Result = bigmod( A, bigmod(B,C,MOD-1),MOD)

*/

/*
    To compute (a*b*c*d)^(e*f*g*h)
    mod a*b*c*d with M
    but e*f*g*h with M-1
    cause $a^b \equiv a^{b \bmod (p - 1)} \pmod{p}$
*/
