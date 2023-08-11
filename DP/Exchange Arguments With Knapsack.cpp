#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define INFL 9223372036854775807
#define F first
#define S second
#define ll long long
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
#define M 998244353
#define endl '\n'

int Set(int N,int pos){return N=N | (1<<pos);}
int reset(int N,int pos){return N= N & ~(1<<pos);}
bool check(int N,int pos){return (bool)(N & (1<<pos));}


const int N = 5005;
ll dp[N][N]; // the number of things considered . the number of things taken
                // and will hold the weight of the items
struct Cell{
    int i;
    int s;
    int w;
};

bool cmp(Cell a,Cell b){
    return a.w+a.s < b.w+b.s;
}



void solve(){
    int n;
    cin>>n;
    Cell cells[n];
    for(int i=0;i<n;i++){
        cin>>cells[i].s>>cells[i].w;
        cells[i].i = i;
    }
    sort(cells,cells+n,cmp);
   // for(int i=0;i<n;i++) cout<<cells[i].i+1<<" ";
    for(int i=0;i<=n;i++) for(int j=0;j<=n;j++) dp[i][j] = -1;
    dp[0][0] = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            if( dp[i][j] == -1 ) continue;
            // if we take the current ith item
            // the weight should be less than capacity
            if( dp[i][j]<=cells[i].s ) {
                if( dp[i+1][j+1] == -1 ) dp[i+1][j+1] = dp[i][j]+cells[i].w;
                else dp[i+1][j+1] = min( dp[i+1][j+1], dp[i][j]+cells[i].w);
            }
            // if we dont take the current item
            if( dp[i+1][j] == -1 ) dp[i+1][j] = dp[i][j];
            else dp[i+1][j] = min( dp[i+1][j], dp[i][j]);
        }
    }

    for(int i=n;i>=0;i--){
        if( dp[n][i] != -1 ){
            cout<<i;
            return;
        }
    }

}
int main(){

    FASTIO;
    int tc=1;
    //cin>>tc;
    for(int t=1;t<=tc;t++){
        solve();
    }
}

// https://atcoder.jp/contests/cf17-final/tasks/cf17_final_d
