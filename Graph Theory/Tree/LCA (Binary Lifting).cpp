#include<bits/stdc++.h>
using namespace std;
const int MAXN=200005, LOG=20;
vector<int> adj[MAXN];
int n;
int bparent[MAXN][LOG], depth[MAXN],vis[MAXN];

void dfs(int a){
    vis[a]=1;
    for(auto v: adj[a]){
        if(!vis[v]){
            bparent[v][0]=a;
            depth[v]=1+depth[a];
            dfs(v);
        }
    }
}
void build_ancestor(){
    dfs(1);
    for(int i=1; (1<<i)<n; i++)
        for(int j=1; j<=n; j++)
            bparent[j][i]=bparent[bparent[j][i-1]][i-1];
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

int main(){
    int q;
    cin>>n>>q;
    for(int i=2;i<=n;i++){
        int p;
        cin>>p;
        adj[p].push_back(i);
    }
    build_ancestor();
    while(q--){
        int a,b;
        cin>>a>>b;
        cout<<lca(a,b)<<endl;
    }
}

// https://cses.fi/problemset/task/1688/
