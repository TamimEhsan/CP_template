/*
    https://cses.fi/problemset/task/2187/
    Catalan's traingle C(n,k)
    C(n,n) is the Catalan's number
*/

#include<bits/stdc++.h>
using namespace std;
#define INF 2047483647
#define INFL 9223372036854775807
#define ll long long
#define pii pair<ll,ll>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define ull unsigned long long
#define M 1000000007
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
#define take(x) scanf("%d",&x)
#define DE(x) printf("\ndebug %d\n",x);
#define vout(x) for(int i=0;i<x.size();i++) printf("%d ",x[i]);
#define pie acos(-1)
#define MOD 998244353


const int N = 2000005;
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

ll CatalanTriangle(int n,int r){
    if( n<r ) return 0;
    ll val = ((fact[n+r]*inv[r])%M*inv[n+1])%M;
    val = (val*(n-r+1))%M;
    return val;
}

int main(){
    calcFact();
    int n;
    cin>>n;
    string s;
    cin>>s;
    int m = s.size();
    int bracket = 0;
    bool pos = true;
    for(char c:s){
        if( c == '(' ) bracket++;
        else bracket--;
        if( bracket<0 ){
            cout<<0;
            return 0;
        }
    }
    int nn = (n-m+bracket)/2;
    if( (n-m+bracket)%2!=0 )
        cout<<0;
    else
        cout<<CatalanTriangle(nn,nn-bracket);
}
