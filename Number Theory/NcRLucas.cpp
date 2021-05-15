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
#define M 13
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
#define take(x) scanf("%d",&x)
#define DE(x) printf("\ndebug %d\n",x);
#define vout(x) for(int i=0;i<x.size();i++) printf("%d ",x[i]);
#define pie acos(-1)
#define MOD 998244353

const int N = M;
ll fact[N],inv[N];
ll bigmod(ll x,int pow){
    if( pow == 0 ) return 1;
    ll mul = bigmod( x,pow/2 );
    if( pow%2 == 0 ) return (mul*mul)%M;
    return ((mul*mul)%M*x)%M;
}
void calcFact(){
    fact[0] = 1;
    for(int i=1;i<N;i++){
        fact[i] = (fact[i-1]*i)%M;
    }

    inv[N-1] = bigmod(fact[N-1],M-2);
    for(int i=N-2;i>=0;i--){
        inv[i] = (inv[i+1]*(i+1))%M;
    }
}

ll NcR(int n,int r){
    if( n<r ) return 0;
    ll val = ((fact[n]*inv[r])%M*inv[n-r])%M;
    return val;
}

ll LucasNcR(ll n,ll r){
    if( n<r ) return 0;
    if( r == 0 ) return 1;
    ll no = n%M;
    ll ro = r%M;
    return (NcR(no,ro)*LucasNcR(n/M,r/M))%M;

}
int main(){
    FASTIO;
    calcFact();
    cout<<LucasNcR(1000,900);
}
