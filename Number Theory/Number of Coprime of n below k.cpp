#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define F first
#define S second
#define ll long long
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
#define endl '\n'

const ll mod = 998244353;

int getCoprimeCount(int n,int m){
    vector<int> factors;
    for(int i=2;i*i<=n;i++){
        if( n%i == 0 ){
            factors.push_back(i);
        }
        while(n%i == 0 ) n/=i;
    }
    if( n!=1 ) factors.push_back(n);
    ll res = 0;

    int b = factors.size();
    for(int i=0;i<(1<<b);i++){
        int msk = i;
        ll mul = 1;
        int cnt = 0;
        for(int j=0;j<b;j++){
            if( msk%2 == 1 ){
                cnt++;
                mul*=factors[j];
            }
            msk/=2;
        }
        if( cnt%2 == 1 ){
            res-=m/mul;
        }else{
            res+=m/mul;
        }
    }
    return res;
}


void solve(){
    ll n,m;
    cin>>n>>m;
    ll ara[n];
    for(int i=0;i<n;i++) cin>>ara[i];
    for(int i=1;i<n;i++){
        if( ara[i-1]%ara[i]!=0 ) {
            cout<<0<<endl;
            return;
        }
    }
    ll res = 1;
    for(int i=1;i<n;i++){
        ll val = ara[i-1]/ara[i];
        ll ret = getCoprimeCount(val,m/ara[i]);
        ret%=mod;
        res = res*ret;
        res%=mod;
    }
    cout<<res<<endl;
}

int main(){

    FASTIO;
    int tc;
    cin>>tc;
    while(tc--)
        solve();
}




