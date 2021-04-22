/**
* Solution to https://lightoj.com/problem/race
*/

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

//====================== Stirling number of second kind
#define MOD 10056
const int N = 1005;
int stirling2[N][N];
void prec(){
    for(int i=1;i<N;i++)
        stirling2[i][0] = stirling2[0][i] = 0;
    stirling2[0][0] = 1;
    for(int i=1;i<N;i++){
        for(int j=1;j<N;j++){
            stirling2[i][j] = j*stirling2[i-1][j] + stirling2[i-1][j-1];
            if( stirling2[i][j]<0 ) cout<<'y';
            stirling2[i][j]%=MOD;
        }
    }
}

//========================
int fact[N];
void calcfact(){
    fact[0] = 1;
    for(int i=1;i<N;i++){
        fact[i] = fact[i-1]*i;
        fact[i]%=MOD;
    }

}
int main(){
    prec();
    calcfact();
    int tc;
    cin>>tc;
    for(int t=1;t<=tc;t++){
        int n;
        cin>>n;
        int res = 0;
        for(int i=1;i<=n;i++){
            res = res+ stirling2[n][i]*fact[i];
            res%=MOD;
        }
        cout<<"Case "<<t<<": "<<res<<endl;
    }
}
