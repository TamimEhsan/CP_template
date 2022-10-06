#include<bits/stdc++.h>
#define inf 1000000000
#define eb emplace_back
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
int n;
const int sz=200001;
vector<int> tree[sz],ctree[sz];
int sub[sz],vis[sz],cparent[sz];
void dfs(int a,int p)
{
    sub[a]=1;
    //printf("loop\n");
    for(auto v: tree[a]){
        if(v!=p && vis[v]==0){
            dfs(v,a);
            sub[a]+=sub[v];
        }
    }
    //cout<<a<<" "<<sub[a]<<endl;
}
int findCentroid(int a,int p,int num)
{
    //printf("loop\n");
    bool sig=true;
    while(sig){
        sig=false;
        for(auto v: tree[a]){
            if(v!=p && vis[v]==0 && 2*sub[v]>num){
                p=a;
                a=v;
                sig=true;
                break;
            }
        }
    }

    return a;
}
int Decompose(int a,int p,int num)
{
    dfs(a,p);
    int centroid=findCentroid(a,p,num);
    vis[centroid]=1;
    //printf("%d\n",centroid);
    for(auto v: tree[centroid]){
        if(vis[v]==0){
        if(sub[v]>sub[centroid])
            ctree[centroid].pb(Decompose(v,centroid,num-sub[centroid]));
        else
            ctree[centroid].pb(Decompose(v,centroid,sub[v]));
        cparent[ctree[centroid].back()]=centroid;
        }
    }
    return centroid;
}
