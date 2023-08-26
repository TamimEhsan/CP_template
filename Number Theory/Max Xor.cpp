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
//#define M 1000000007
#define M 998244353
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
#define take(x) scanf("%d",&x)
#define DE(x) printf("\ndebug %d\n",x);
#define vout(x) for(int i=0;i<x.size();i++) printf("%d ",x[i]);
#define pie acos(-1)
#define MOD 998244353
int findmsb(int n){
    int pos = 0;
    while(n){
        n/=2;
        pos++;
    }
    return pos;
}
int main(){
    int n;
    cin>>n;
    int basis[35] = {0};
    while(n--){
        int num;
        cin>>num;
        while(num){
            int pos = findmsb(num);
            if( basis[pos] == 0 ){
                basis[pos] = num;
                num = 0;
            }else{
                num = num^basis[pos];
            }
        }
    }
    int xorr = 0;
    for(int i=33;i>0;i--){
        if( (xorr^basis[i])>xorr ) xorr = xorr^basis[i];
    }
    cout<<xorr<<endl;
}
