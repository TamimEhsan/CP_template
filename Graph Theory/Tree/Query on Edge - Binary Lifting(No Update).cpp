#include<bits/stdc++.h>
using namespace std;
const int MAXN=100005, LOG=20;

struct Cell{
    int to;
    int w;
};

vector<Cell> adj[MAXN];
int n;
int bparent[MAXN][LOG], depth[MAXN],vis[MAXN];
int mnValue[MAXN][LOG];
int mxValue[MAXN][LOG];

void dfs(int a){
    vis[a]=1;
    for(auto [v,w]: adj[a]){
        if(!vis[v]){
            bparent[v][0]=a;
            mnValue[v][0]=w;
            mxValue[v][0]=w;
            depth[v]=1+depth[a];
            dfs(v);
        }
    }
}
void build_ancestor(){
    dfs(1);
    for(int i=1; (1<<i)<n; i++)
        for(int j=1; j<=n; j++){
            bparent[j][i]=bparent[bparent[j][i-1]][i-1];
            mnValue[j][i] = min( mnValue[j][i-1],mnValue[bparent[j][i-1]][i-1] );
            mxValue[j][i] = max( mxValue[j][i-1],mxValue[bparent[j][i-1]][i-1] );
        }
}

int pth_ancestor(int a,int p){
    for(int i=0; (1<<i)<=p; i++)
        if((1<<i)&p)
            a=bparent[a][i];
    return a;
}

int lca(int u,int v){
    if(depth[v]>depth[u])
        v=pth_ancestor(v,depth[v]-depth[u]);
    if(depth[u]>depth[v])
        u=pth_ancestor(u,depth[u]-depth[v]);
    if(u==v)
        return u;
    //printf("%d %d\n",u,v);
    for(int i=log2(n-1); i>=0; i--){
        if(bparent[u][i]!=bparent[v][i]){
            u=bparent[u][i];
            v=bparent[v][i];
        }
    }
    return bparent[u][0];
}

int mnRes,mxRes;
int pth_query(int a,int p){
    for(int i=0; (1<<i)<=p; i++)
        if((1<<i)&p){
            mnRes = min(mnRes,mnValue[a][i]);
            mxRes = max(mxRes,mxValue[a][i]);
            a=bparent[a][i];

        }
    return a;
}

void solve(){
    int q;
    cin>>n;
    for(int i=0;i<=n;i++){
        adj[i].clear();
        depth[i] = vis[i] = 0;
        for(int j=0;j<LOG;j++){
            bparent[i][j] = 0;
        }
    }
    for(int i=2;i<=n;i++){
        int a,b,w;
        cin>>a>>b>>w;
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
    }
    build_ancestor();
    cin>>q;
    while(q--){
        int a,b;
        cin>>a>>b;
        int l = lca(a,b);

        mxRes = 0;
        mnRes = 100005;
        pth_query(a,depth[a]-depth[l]);
        pth_query(b,depth[b]-depth[l]);
        cout<<mnRes<<" "<<mxRes<<endl;
    }
}


int main(){
    int tc;
    cin>>tc;
    for(int t=1;t<=tc;t++){
        cout<<"Case "<<t<<":"<<endl;
        solve();
    }
}
// https://lightoj.com/problem/min-max-roads
