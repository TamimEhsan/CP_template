#include<bits/stdc++.h>
using namespace std;
#define INF 2147483647
#define INFL 9223372036854775807
#define pii pair<int,int>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define ll long long
#define ull unsigned long long
#define M 1000000007
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
#define take(x) scanf("%d",&x)
#define DE(x) printf("\ndebug %d\n",x);
#define vout(x) for(int i=0;i<x.size();i++) printf("%d ",x[i]);
#define pie acos(-1)
#define MOD 998244353

vector<vector<int>> adj;
vector<int> first; // first position of a node
vector< pii > euler; // .F = height; .S = node
unordered_map<int,int>vis;
void dfs(int u,int height = 0){
    first[u] = euler.size();
    vis[u] = 1;
    euler.pb(mp(height,u));
    for(int v:adj[u]){
        if( !vis[v] ){
            dfs(v,h+1);
            euler.pb(mp{height,u});
        }
    }
}

template <class T>
class STable
{
    int n;
    pair<int,int> *cal;
    vector<T> *SparseTable;
    T (*comp)(T,T);
    void initialize()
    {
        int i,j;
        cal[1].second=1;
        for(i=1,j=1<<i; j<=n; i++,j=1<<i)
        {
            cal[j].first=1;
            cal[j].second=j;
        }
        for(i=2; i<=n; i++)
        {
            cal[i].first=cal[i].first+cal[i-1].first;
            if(cal[i].second==0) cal[i].second=cal[i-1].second;
        }
    }
public:
    STable(vector<T> &arr,T (*f)(T,T))
    {
        n=arr.size();
        comp=f;
        cal=new pair<int,int>[n+1];
        initialize();
        SparseTable=new vector<T>[n];
        int i,j,m;
        for(i=0,j=0; i<n; i++)
        {
            SparseTable[i].push_back(arr[i]);
        }
        for(j=0,m=1<<j; m<n; j++,m=1<<j)
        {
            for(i=0; i+m<n; i++)
            {
                SparseTable[i].push_back(comp(SparseTable[i][j],SparseTable[i+m][SparseTable[i+m].size()-1]));
            }
        }
    }
    T query(int l,int r)
    {
        int difference=(r-l+1);
        return comp(SparseTable[l][cal[difference].first],SparseTable[r-cal[difference].second+1][cal[difference].first]);
    }
    ~STable()
    {
        int i;
        for(i=0;i<n;i++)
        {
            SparseTable[i].clear();
        }
        delete []SparseTable;
        delete []cal;
        comp=0;
    }
};
pair<char,int> minimum(pair<char,int> a,pair<char,int> b)
{
    return min(a,b);
}
int main(){
    // input the graph
    // call dfs for any node
    STable<pair<int,int> > find_lca(Paths,minimum);
    // int lca = find_lca.query( min( first[x], first[y]), max( first[x],first[y]) ).S;
}

