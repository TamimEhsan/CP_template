#include<bits/stdc++.h>
using namespace std;
#define INF 2047483647
#define INFL 9223372036854775807
#define ll long long
#define pii pair<int,int>
#define pII pair<ll,ll>
#define vi vector<int>
#define vii vector<pii>
#define vI vector<ll>
#define VII vector<pII>
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


const int N = 1000010;
vector<char> is_prime(N+1, true);
vector<ll> primes;

void seive(){
    is_prime[0] = is_prime[1] = false;
    is_prime[2] = true;
    for (int i = 3; i * i <= N; i+=2) {
        if (is_prime[i]) {
            for (int j = i * i; j <= N; j += i)
                is_prime[j] = false;
        }
    }
    primes.pb(2);
    for(int i=3;i<N;i+=2){ // if we need only the mapping then remove this
        if( is_prime[i] ) primes.pb( i );
    }
}

int calculate(ll n,ll primes[]){
    int sum = 1;
    for(int i=0;i<N && primes[i]*primes[i]<=n;i++){
        if( n%primes[i] == 0 ){
            int k = 1;
            while(n%primes[i] == 0){
                n/=primes[i];
                k++;
                if(n==0 || n==1)
                    break;
            }
            sum*=k;
        }
    }
    if( n!=1 ) sum*=2;
    return sum-1;

}
int main(){
    seive();
    FASTIO;
    ll prime[primes.size()]; //somehow arrays are twice faster :/
    for(int i=0;i<primes.size();i++)
        prime[i] = primes[i];
    int tc = 10000;
    cin>>tc;
    for(int t=1;t<=tc;t++){
        long long int n = 1e12-t,sum=1,s,k,i;
        cin>>n;
        cout<<"Case "<<t<<": "<<calculate(n,prime)<<endl;
    }
}
