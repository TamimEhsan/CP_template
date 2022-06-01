#include<bits/stdc++.h>
using namespace std;
const int sz=3000001;
int cpos=0;
int tree[4*sz];
int head[sz],heavy[sz],pos[sz],parent[sz],depth[sz],val[sz];
vector<int> g[sz];
inline swap(int &a,int &b){a^=b, b^=a, a^=b;}
int dfs(int a)
{int max_size=0,sum=1;for(auto v: g[a]){
	if(v!=parent[a]){parent[v]=a;depth[v]=1+depth[a];
		int siz=dfs(v);sum+=siz;
		if(siz>max_size){max_size=siz;heavy[a]=v;}}}
    return sum;}
void decompose(int a,int h)
{head[a]=h;pos[a]=cpos++;
	if(heavy[a]) decompose(heavy[a],h);
	for(auto v: g[a]){if(v!=heavy[a] && v!=parent[a])decompose(v,v);}}
int query(int a,int b,int n)
{int res=0;
    while(head[a]!=head[b]){if(depth[head[a]]>depth[head[b]]) swap(a,b);
        res+=squery(1,0,n-1,pos[head[b]],pos[b]);b=parent[head[b]];}
    if(depth[a]>depth[b]) swap(a,b);res+=squery(1,0,n-1,pos[a],pos[b]);
    return res;}
