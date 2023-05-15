#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
#define endl '\n'



const int N = 200005;
vector<int> adj[N];



int subDp[N],superDp[N];
int dis[N];
void dfs1(int u,int p){
    subDp[u] = 0;
    dis[u] = dis[p]+1;
    for(auto v:adj[u]){
        if( v == p ) continue;
        dfs1(v,u);
        subDp[u]=max(subDp[v]+1,subDp[u]);
    }
}

void dfs2(int u,int p){
    multiset<int> ms;

    for(int v:adj[u]){
        if( v == p ) continue;
        ms.insert(subDp[v]);
    }
    for(int v:adj[u]){
        if( v == p ) continue;
        ms.erase(ms.find(subDp[v]));

        int big = -1;
        if( ms.size() != 0 ) big = *ms.rbegin();
        superDp[v] = max(big+2,superDp[u]+1);
        dfs2(v,u);
        ms.insert(subDp[v]);
    }
}
void solve(){

    int n;
    ll k,c;
    cin>>n>>k>>c;
    for(int i=0;i<=n;i++){
        adj[i].clear();
    }
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dis[0] = -1;
    dfs1(1,0);
    superDp[1] = 0;
    dfs2(1,0);
    ll res = k*subDp[1];
    for(int i=1;i<=n;i++) {
        res = max(res, k*max(subDp[i],superDp[i])-c*dis[i] );
       // cout<<i<<" "<<subDp[i]<<" "<<superDp[i]<<" "<<max(subDp[i],superDp[i])*k-c*dis[i]<<endl;
    }
    cout<<res<<endl;
}
int main(){

    FASTIO;
    int tc=1;
    cin>>tc;
    for(int t=1;t<=tc;t++){
      //  cout<<"Case "<<t<<": ";;
        solve();
    }

}

// solution for https://codeforces.com/contest/1822/problem/F

// More problems
// https://codeforces.com/contest/1794/problem/E
