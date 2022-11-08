#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define F first
#define S second
#define ll long long
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
#define endl '\n'



ll coprimeCount(ll n){
    ll res = n;
    for(ll i=2;i*i<=n;i++){
        if( n%i == 0 ){
            res = res/i;
            res = res*(i-1);
            while(n%i == 0) n/=i;
        }
    }
    if( n!=1 ){
        res = res/n;
        res = res*(n-1);
    }
    return res;
}


int main(){

    FASTIO;
    for(int i=1;i<100;i++) cout<<i<<" "<<coprimeCount(i)<<endl;

}




