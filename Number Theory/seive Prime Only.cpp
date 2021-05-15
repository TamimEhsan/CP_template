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
    seive of erasthosomething
    time:   N = 10^7    0.155 s
            N = 10^8    1.829 s
*/

const int N = 10000000;
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

int main(){
    seive();
    cout<<primes.size();
}
