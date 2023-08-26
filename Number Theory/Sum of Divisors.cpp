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
#define MOD 1000000007
#define MAX 1000005

// approach 1 ==============================
int divisors[N+5];
int ans[N+5];
void Divisors()//efficient
{
    int n= N;
    int i;
    int j;
    for(i = 1; i*i <= n; i++)
    {
        for(j = i*i; j <= n; j += i)
        {
            divisors[j]+=i;
            if(i!=j/i)
                divisors[j]+=(j/i);
        }
    }
}

// approach 2 ===============================
// works twice faster for 10^7
const int N = 10000007;
vector<int> is_prime(N+1, 0);
vector<ll> primes;
ull SUM[N];
void seive(){
    is_prime[0] = is_prime[1] = false;
    is_prime[2] = 0;

    for (int j = 2 * 2; j <= N; j += 2)
        is_prime[j] = 2;

    for (int i = 3; i * i <= N; i+=2) {
        if (is_prime[i] == 0) {
            for (int j = i * i; j <= N; j += i)
                is_prime[j] = i;
        }
    }
}
void precalculate(){
    SUM[1] = 1;
    for(int i=2;i<N;i++){
        if( is_prime[i] == 0 ){
            SUM[i] = i+1;
            continue;
        }

        int val = i;
        int cnt = 1;
        while( val%is_prime[i] == 0 ){
            val/=is_prime[i];
            cnt*=is_prime[i];
        }
        if( val == 1 ){
            SUM[i] = ((ll)i*is_prime[i]-1)/(is_prime[i]-1);
            continue;
        }
        SUM[i] = SUM[val]*SUM[cnt];
    }
}
