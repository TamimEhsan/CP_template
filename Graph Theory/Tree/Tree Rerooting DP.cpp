#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
#define endl '\n'

ll mods[2] = {1000000007, 1000000009};
ll bases[2] = {137, 281};
ll invBases[2];

const int N = 200005;
vector<int> adj[N];

ll pwbase[N][2];

ll bigMod(ll n,ll r,ll mod){
    if(r==0) return 1;
    ll ret = bigMod(n, r/2, mod);
    ret = (ret*ret) % mod;
    if(r&1) ret = (ret*n)% mod;
    return ret;
}

void prec(){
    pwbase[0][0] = 1;
    pwbase[0][1] = 1;
    for(int i=1;i<N;i++){
        for(int k=0;k<2;k++){
            pwbase[i][k]=pwbase[i-1][k]*bases[k];
            pwbase[i][k]%=mods[k];
        }
    }
    invBases[0] = bigMod(bases[0],mods[0]-2,mods[0]);
    invBases[1] = bigMod(bases[1],mods[1]-2,mods[1]);
}

ll subDp[N][2],superDp[N][2];
void dfs1(int u,int p){
    subDp[u][0] = 1;
    subDp[u][1] = 1;
    for(auto v:adj[u]){
        if( v == p ) continue;
        dfs1(v,u);
        for(int k=0;k<2;k++){
            subDp[u][k]+=(subDp[v][k]*bases[k])%mods[k];
            subDp[u][k]%=mods[k];
        }
    }
}

void dfs2(int u,int p){
   /* for(int k=0;k<2;k++){
        superDp[u][k] = superDp[p][k]*bases[k];
        superDp[u][k] %= mods[k];
    }*/
    for(auto v:adj[u]){
        if( v == p ) continue;
        for(int k=0;k<2;k++){
            superDp[v][k] = superDp[u][k]*bases[k];
            superDp[v][k] %= mods[k];
            ll temp = subDp[u][k] - (subDp[v][k]*bases[k])%mods[k] + mods[k];
            temp*=bases[k];
            temp%=mods[k];
            superDp[v][k]+=temp;
            superDp[v][k] %= mods[k];
        }
        dfs2(v,u);
    }

}
void solve(){

    int n;
    cin>>n;
    int ara[n];
    ll hush[2]={0};
    for(int i=0;i<n-1;i++){
        cin>>ara[i];
        for(int k=0;k<2;k++){
            hush[k]+=pwbase[ ara[i] ][k];
        }
    }
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    set<pll> st;
    for(int i=0;i<n;i++){
        pll pp;
        pp.first = (hush[0] + pwbase[i][0] )%mods[0];
        pp.second = (hush[1] + pwbase[i][1] )%mods[1];
        //cout<<i<<" "<<pp.first<<" "<<pp.second<<endl;
        st.insert(pp);
    }
    dfs1(1,-1);
    dfs2(1,-1);
    vector<int> nodes;
    for(int i=1;i<=n;i++){
       // cout<<i<<" "<<subDp[i][0]<<" "<<superDp[i][0]<<" ";
        pll pp;
        pp.first = subDp[i][0] + superDp[i][0]; pp.first%=mods[0];
        pp.second = subDp[i][1] + superDp[i][1]; pp.second%=mods[1];
        //cout<<pp.first<<" "<<pp.second<<endl;
        if( st.count(pp) ) nodes.push_back(i);
    }
    cout<<nodes.size()<<endl;
    for(auto node:nodes) cout<<node<<" ";
}
int main(){
    prec();
    FASTIO;
    int tc=1;
   // cin>>tc;
    for(int t=1;t<=tc;t++){
      //  cout<<"Case "<<t<<": ";;
        solve();
    }

}

// https://codeforces.com/contest/1794/problem/E
