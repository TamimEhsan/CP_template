#include "bits/stdc++.h"
using namespace std;
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define F first
#define S second

/*
Heavy light decomposition divides the tree into logn paths
Each path only moves downward ( or upward )
So, for querying on any property of the nodes (or paths) from a to b
we can query the properties of path from a to LCA(a,b) and from b to LCA(a,b) and merge them
We create seperate segment tree for each path.
Here actually an array of euler path is taken on nodes. So we assign the property of the node
to the euler id of the node and create segment tree with that. And as for a path the euler path id
is increasing so, if we can somehow breakdown the problem where we can use the property on some
segment tree we can solve the problem.
Here, some properties can be minimum, maximum value of nodes, sum of values of nodes, xor, etc etc
*/
/*
PS. There are other applications where the lca can be found within the HLD.
But I couldn't understand what was happing, so am using my LCA template here
*/

//<<<<<<<<<<<<<<<<<<<<<<<Lowest Common Ancestor Template>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\\


//<<<<<<<<<<<<<<<<<<<<<<<Sparse Table Template>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\\

template <class T>
class STable {
    int n;
    pair<int,int> *cal;
    vector<T> *SparseTable;
    T (*comp)(T,T);
    void initialize() {
        int i,j;
        cal[1].second=1;
        for(i=1,j=1<<i; j<=n; i++,j=1<<i) {
            cal[j].first=1;
            cal[j].second=j;
        }
        for(i=2; i<=n; i++) {
            cal[i].first=cal[i].first+cal[i-1].first;
            if(cal[i].second==0) cal[i].second=cal[i-1].second;
        }
    }
public:
    STable() {

    }
    STable(vector<T> &arr,T (*f)(T,T)) {
        n=arr.size();
        comp=f;
        cal=new pair<int,int>[n+1];
        initialize();
        SparseTable=new vector<T>[n];
        int i,j,m;
        for(i=0,j=0; i<n; i++) {
            SparseTable[i].push_back(arr[i]);
        }
        for(j=0,m=1<<j; m<n; j++,m=1<<j) {
            for(i=0; i+m<n; i++) {
                SparseTable[i].push_back(comp(SparseTable[i][j],SparseTable[i+m][SparseTable[i+m].size()-1]));
            }
        }
    }
    void inits(vector<T> &arr,T (*f)(T,T)) {
        n=arr.size();
        comp=f;
        cal=new pair<int,int>[n+1];
        initialize();
        SparseTable=new vector<T>[n];
        int i,j,m;
        for(i=0,j=0; i<n; i++) {
            SparseTable[i].push_back(arr[i]);
        }
        for(j=0,m=1<<j; m<n; j++,m=1<<j) {
            for(i=0; i+m<n; i++) {
                SparseTable[i].push_back(comp(SparseTable[i][j],SparseTable[i+m][SparseTable[i+m].size()-1]));
            }
        }
    };
    T query(int l,int r) {
        int difference=(r-l+1);
        return comp(SparseTable[l][cal[difference].first],SparseTable[r-cal[difference].second+1][cal[difference].first]);
    }
    ~STable() {
        int i;
        for(i=0; i<n; i++) {
            SparseTable[i].clear();
        }
        delete []SparseTable;
        delete []cal;
        comp=0;
    }
};
pii minimum(pii a,pii b) {
    return min(a,b);
}

//<<<<<<<<<<<<<<<<<<<<<<<Sparse Table Template Ended>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\\


class LCA {

public:


    vector<vector<int>> adj;
    vector<int> first,dis; // first position of a node
    vector< pii > euler; // .F = height; .S = node
    unordered_map<int,int>vis;
    STable<pair<int,int> > stableLca;

    LCA() {
        adj.clear();
        first.clear();
        dis.clear();
        euler.clear();
        vis.clear();
    }
    LCA(int n) {
        init(n);
    }
    void init(int n) {
        adj.clear();
        first.clear();
        dis.clear();
        euler.clear();
        vis.clear();
        adj.resize(n,vector<int>());
        first.resize(n,0);
        dis.resize(n,0);
    }
    void createLCA() {
        dfs(1);
        stableLca.inits(euler,minimum);
    }
    void dfs(int u,int height = 0) {
        first[u] = euler.size();
        vis[u] = 1;
        dis[u] = height;
        euler.pb(mp(height,u));
        for(int v:adj[u]) {
            if( !vis[v] ) {
                dfs(v,height+1);
                euler.pb(mp(height,u));
            }
        }
    }

    int findLca(int x,int y) {
        int lca = stableLca.query( min( first[x], first[y]), max( first[x],first[y]) ).S;
        return lca;
    }

    int findDistance(int u,int v) {
        int l = findLca(u,v);
        return dis[u] + dis[v] - 2*dis[l];
    }

    bool isAncestor(int u,int v) {
        return findLca(u,v) == u;
    }
};

//<<<<<<<<<<<<<<<<<<<<<<<Lowest Common Ancestor Template Ended>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\\


const int N = 2e5+5;
const int D = 19;
const int S = (1<<D);

int n, q, v[N];
vector<int> adj[N];

int sz[N], p[N], dep[N];
int st[S], id[N], tp[N];

void update(int idx, int val) {
	st[idx += n] = val;
	for (idx /= 2; idx; idx /= 2)
		st[idx] = max(st[2 * idx], st[2 * idx + 1]);
}

int query(int lo, int hi) {
	int ra = 0, rb = 0;  //<< Don't forget to pre initialize the starting value
	for (lo += n, hi += n + 1; lo < hi; lo /= 2, hi /= 2) {
		if (lo & 1)
			ra = max(ra, st[lo++]);
		if (hi & 1)
			rb = max(rb, st[--hi]);
	}
	return max(ra, rb);
}

int dfs_sz(int cur, int par) {
	sz[cur] = 1;
	p[cur] = par;
	for(int chi : adj[cur]) {
		if(chi == par) continue;
		dep[chi] = dep[cur] + 1;
		p[chi] = cur;
		sz[cur] += dfs_sz(chi, cur);
	}
	return sz[cur];
}

int ct = 1;

void dfs_hld(int cur, int par, int top) {
	id[cur] = ct++;
	tp[cur] = top;
	update(id[cur], v[cur]);  //< We update the property against the euler id
	int h_chi = -1, h_sz = -1;
	for(int chi : adj[cur]) {
		if(chi == par) continue;
		if(sz[chi] > h_sz) {
			h_sz = sz[chi];
			h_chi = chi;
		}
	}
	if(h_chi == -1) return;
	dfs_hld(h_chi, cur, top);
	for(int chi : adj[cur]) {
		if(chi == par || chi == h_chi) continue;
		dfs_hld(chi, cur, chi);
	}
}

int path(int x, int y){
	int ret = 0;
	while(tp[x] != tp[y]){
		if(dep[tp[x]] < dep[tp[y]])swap(x,y);
		ret = max(ret, query(id[tp[x]],id[x]));
		x = p[tp[x]];
	}
	if(dep[x] > dep[y])swap(x,y);
	ret = max(ret, query(id[x],id[y]));
	return ret;
}

int main() {
	scanf("%d%d", &n, &q);
	LCA lca(n+5);
	for(int i=1; i<=n; i++) scanf("%d", &v[i]);  //< Property on nodes
	for(int i=2; i<=n; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
		lca.adj[a].push_back(b);
		lca.adj[b].push_back(a);
	}

	lca.createLCA();
	dfs_sz(1, 1);  //< 1 indexed system  ; The LCA here is also 1 indexed
	dfs_hld(1, 1, 1);
	while(q--) {
		int t;
		scanf("%d", &t);
		if(t == 1) {
			int s, x;
			scanf("%d%d", &s, &x);
			v[s] = x;
			update(id[s], v[s]);  //< We update the property against the euler id
		} else {
			int a, b;
			scanf("%d%d", &a, &b);
			int l = lca.findLca(a,b);
			int res = max(path(a,l),path(b,l));   //<Here we divide the path into 2 secgment. From a to LCA(a,b) and then to b to LCA(a,b) and merge the result
			printf("%d\n ", res);
		}
	}
}

// https://cses.fi/problemset/task/2134/
