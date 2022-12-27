#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
#define endl '\n'

const int MAX = 1000005;

int  mob[MAX];
// phi = Euler Phi function
// dvc = divisor count ot sigma 0
// sig = sigma, the sum of the divisors of n. Also called sigma_1
// mob = mobius function
int least[MAX];
vector<int> primes;

void RunLinearSieve() {
    int n = MAX-1;
    for(int i = 0; i <= n; i++) least[i] = 0;

    primes.clear();
    mob[1] = 1;

    for(int i = 2; i <= n; i++){
        if(least[i] == 0){
            least[i] = i;
            mob[i] = -1;
            primes.push_back(i);
        }
        for(int x : primes){
            if(x > least[i] || i * x > n) break;
            least[i * x] = x;

            if(least[i] == x){
                mob[i * x] = 0;
            }else{
                mob[i * x] = -mob[i];
            }
        }
    }
}

void solve() {
    ll n,k;
    cin>>n>>k;
    ll gcdd[n+1] = {0};
    for(int k=1;k<=n;k++){
        for(int v = 1;v<=n/k;v++){
            gcdd[k]+= ( n/(v*k) ) * ( n/(v*k) ) * mob[v];
        }
        gcdd[k]--;
        gcdd[k]/=2;
    }
    ll rem = k;
    ll res = 0;
    for(int i=n;i>1;i--){
        if( gcdd[i]<i-1 ) continue;
        ll canbe = gcdd[i]/(i-1);
        ll needs = rem/(i-1);
        ll nn = min(canbe,needs);
        rem-=nn*(i-1);
        res+=nn*i;
    }
    if( rem!=0 ) cout<<-1<<endl;
    else cout<<res<<endl;
}

int main(){
  // FASTIO;
    RunLinearSieve();

    int tc;
    cin>>tc;
    while(tc--) solve();
}
// https://csacademy.com/contest/archive/task/and-closure/statement/
