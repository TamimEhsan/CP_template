#include<bits/stdc++.h>
using namespace std;

/**
1 indexed
*/
const int MAXN=200005, LOG=20;
vector<int> adj[MAXN];

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
void build_ancestor(int n){
    dfs(1);
    for(int i=1; i < LOG; i++)
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
    for(int i=LOG-1; i>=0; i--){
        if(bparent[u][i]!=bparent[v][i]){
            u=bparent[u][i];
            v=bparent[v][i];
        }
    }
    return bparent[u][0];
}

int dist(int u, int v) {
    int l = lca(u, v);
    return depth[u] + depth[v] - 2*depth[l];
}

// finds if path (s,t) and (u,v) has at least 1 common vertex
bool check_overlap(int s, int t, int u, int v) {
    int min_dist = dist(s, t) + dist(u, v);
    int o1 = dist(s, u) + dist(v, t);
    int o2 = dist(s, v) + dist(u, t);
    return !( (min_dist < o1) and (min_dist < o2) );
}

int main(){
    int n,q;
    cin>>n>>q;
    for(int i=2;i<=n;i++){
        int p;
        cin>>p;
        adj[p].push_back(i);
    }
    build_ancestor(n);
    while(q--){
        int a,b;
        cin>>a>>b;
        cout<<lca(a,b)<<endl;
    }
}

// https://cses.fi/problemset/task/1688/
