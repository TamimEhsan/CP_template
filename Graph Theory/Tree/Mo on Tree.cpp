#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 3e5 + 9;

//unique elements on the path from u to v
vector<int> g[N];
int st[N], en[N], T, par[N][20], dep[N], id[N * 2];

int inDepth1[N];
int inDepth2[N];

ll Prec[N];
ll  a[N], ans;
void dfs(int u, int p = 0) {
    st[u] = ++T;
    id[T] = u;
    dep[u] = dep[p] + 1;
    Prec[u] = Prec[p] + a[u]*a[u];
    par[u][0] = p;
    for(int k = 1; k < 20; k++) par[u][k] = par[par[u][k - 1]][k - 1];
    for(auto v : g[u]) if(v != p) dfs(v, u);
    en[u] = ++T;
    id[T] = u;
}
int getLca(int u, int v) {
    if(dep[u] < dep[v]) swap(u, v);
    for(int k = 19; k >= 0; k--) if(dep[par[u][k]] >= dep[v]) u = par[u][k];
    if(u == v) return u;
    for(int k = 19; k >= 0; k--) if(par[u][k] != par[v][k]) u = par[u][k], v = par[v][k];
    return par[u][0];
}


inline void add(int x) {
    int depth = dep[x];
    if( inDepth1[depth] == 0 ) inDepth1[depth] = x;
    else if( inDepth2[depth] == 0 ) inDepth2[depth] = x;
    if( inDepth1[depth] != 0 and inDepth2[depth] != 0 ) {
        ans+= a[ inDepth1[depth] ]*a[ inDepth2[depth] ];
    }
}
inline void rem(int x) {
    int depth = dep[x];
    if( inDepth1[depth] != 0 and inDepth2[depth] != 0 ) {
        ans-= a[ inDepth1[depth] ]*a[ inDepth2[depth] ];
    }
    if( inDepth1[ depth ] == x ) inDepth1[depth] = 0;
    if( inDepth2[ depth ] == x ) inDepth2[depth] = 0;
}


bool vis[N];
inline void check(int u) {
    if(!vis[u]) add(u);
    else rem(u);
    vis[u] ^= 1;
}

const int B = 320;
struct query {
    int l, r, id;
    bool operator < (const query &x) const {
        if(l / B == x.l / B) return r < x.r;
        return l / B < x.l / B;
    }
} Q[N];

ll res[N];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> a[i];

    for(int u = 2; u <= n; u++) {
        int v;
        cin >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    T = 0;
    dfs(1);
    for(int i = 1; i <= q; i++) {
        int u, v ;
        cin >> u >> v;
        if(st[u] > st[v]) swap(u, v);
        int lc = getLca(u, v);
        if(lc == u) Q[i].l = st[u], Q[i].r = st[v];
        else Q[i].l = en[u], Q[i].r = st[v];
        Q[i].id = i;
    }
    sort(Q + 1, Q + q + 1);
    ans = 0;
    int l = 1, r = 0;
    for(int i = 1; i <= q; i++) {
        int L = Q[i].l, R = Q[i].r;
        if(R < l) {
            while (l > L) check(id[--l]);
            while (l < L) check(id[l++]);
            while (r < R) check(id[++r]);
            while (r > R) check(id[r--]);
        } else {
            while (r < R) check(id[++r]);
            while (r > R) check(id[r--]);
            while (l > L) check(id[--l]);
            while (l < L) check(id[l++]);
        }
        int u = id[l], v = id[r], lca = getLca(u, v);
        if(lca != u && lca != v) check(lca); //take care of the getLca separately
        res[Q[i].id] = ans+Prec[lca];
        if(lca != u && lca != v) check(lca);
    }
    for(int i = 1; i <= q; i++) cout << res[i] << '\n';


    return 0;
}
// https://codeforces.com/contest/1806/problem/E
