#include<bits/stdc++.h>
using namespace std;
#define INF 2147483647
#define INFL 9223372036854775807
#define pii pair<int,int>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define ll long long
#define ull unsigned long long
#define M 1000000007
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
#define take(x) scanf("%d",&x)
#define DE(x) printf("\ndebug %d\n",x);
#define vout(x) for(int i=0;i<x.size();i++) printf("%d ",x[i]);
#define pie acos(-1)
#define MOD 998244353

/*
    https://www.spoj.com/problems/PON/
    status: AC
    with current implementation of mulmod
    for number close to 64 bit takes about 4*10^4 calculation
    for number close to 32 bit takes about 1*10^4 calculation
    for number close to 16 bit takes about 3*10^3 calculation

    but with the commented out code of binpower 64 bit can be reduced to 700 calculations :)
    but manu compiler don't support 128 bit integer T - T
*/

/*
using u128 = __uint128_t;

u64 binpower(u64 base, u64 e, u64 mod) {
    u64 result = 1;
    base %= mod;
    while (e) {
        if (e & 1)
            result = (u128)result * base % mod;
        base = (u128)base * base % mod;
        e >>= 1;
    }
    return result;
}
*/

using u64 = uint64_t;

u64 mulmod(u64 a,u64 b,u64 c){
    u64 x = 0,y=a%c;
    while(b > 0){
        if(b%2 == 1){
            x = (x+y)%c;
        }
        y = (y*2)%c;
        b /= 2;
    }
    return x%c;
}
u64 power(u64 a,u64 b,u64 n){
	if(b==0)
		return 1;
	if(b==1) return a%n;
		u64 c=power(a,b/2,n);
		u64 p=mulmod(c%n,c%n,n);
		if(b%2==0)
			return p;
		else
			 return (mulmod(p,a,n));
}

bool check_composite(u64 n, u64 a, u64 d, int s) {
    u64 x = power(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (int r = 1; r < s; r++) {
        x = power(x, 2, n);
        if (x == n - 1)
            return false;
    }
    return true;
};

bool MillerRabin(u64 n) { // returns true if n is prime, else returns false.
    if (n < 2)
        return false;

    int r = 0;
    u64 d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        r++;
    }

    for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (n == a)
            return true;
        if (check_composite(n, a, d, r))
            return false;
    }
    return true;
}


int main(){
    int tc;
    cin>>tc;
    while(tc--){
        u64 n;
        cin>>n;
        if( MillerRabin(n) ) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

}
/*
2^56-5
72057594037927931
2^58-27
288230376151711717
2^60-93
1152921504606846883
*/
