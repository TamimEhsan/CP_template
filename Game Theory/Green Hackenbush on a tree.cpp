#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


// complexity

const int N = 1000005;
vector<int> adj[N];


// green hackenbush

int dfs(int u,int p){
    int nimsum = 0;
    for(auto v:adj[u]){
        if( v == p ) continue;
        int ret = dfs(v,u);
        nimsum^=ret;
    }
    nimsum++;
    return nimsum;

}


void solve(){
    int n;
    cin>>n;
    for(int i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    int ret = dfs(1,0); ret--;
    //cout<<ret<<endl;
    if( ret ) cout<<"Alice";
    else cout<<"Bob";
}

int main(){
    FASTIO;
    int tc= 1;
    //cin>>tc;
    for(int t=1;t<=tc;t++){
       // cout<<"Case "<<t<<": ";
        solve();
    }
}

// https://atcoder.jp/contests/agc017/tasks/agc017_d
