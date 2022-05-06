#include<bits/stdc++.h>
using namespace std;
#define INF 2047483647
#define INFL 9223372036854775807
#define ll long long
#define pii pair<ll,ll>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define ull unsigned long long
//#define M 1000000007
#define M 998244353
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
#define take(x) scanf("%d",&x)
#define DE(x) printf("\ndebug %d\n",x);
#define vout(x) for(int i=0;i<x.size();i++) printf("%d ",x[i]);
#define pie acos(-1)
#define MOD 998244353

const int N = 2000007;
int ara[N],segtree[4*N],lazy[4*N];
// max Segtree with lazy updates
// will find maximum of value in a range ,
void build(int pos,int l,int r){
    if( l == r ){
        segtree[pos] = ara[l];
        return;
    }
    int mid = (l+r)/2;
    build(pos*2,l,mid);
    build(pos*2+1,mid+1,r);
    segtree[pos] = max( segtree[pos*2],segtree[pos*2+1] );
}

void lazyUpdate(int pos,int l,int r){
    if( lazy[pos] ){
        segtree[pos]+=lazy[pos];
        if( l!=r ){
            lazy[pos*2]+=lazy[pos];
            lazy[pos*2+1]+=lazy[pos];
        }
        lazy[pos] = 0;
    }
}

void update(int pos,int l,int r,int L,int R,int val){
    lazyUpdate(pos,l,r);
    if( l>r  ) return;
    if( l> R or r<L ) return;
    if( l>=L and r<=R ){
        lazy[pos]+=val;
        lazyUpdate(pos,l,r);
        return;
    }
    int mid = (l+r)/2;
    update(pos*2,l,mid,L,R,val);
    update(pos*2+1,mid+1,r,L,R,val);
    segtree[pos] = max( segtree[pos*2+1], segtree[pos*2] );
}

int query(int pos,int l, int r,int L,int R){
    lazyUpdate(pos,l,r);
    if( l>r  ) return 0;
    if( l> R or r<L ) return 0;
    if( l>=L and r<=R ) return segtree[pos];
    int mid = (l+r)/2;
    int val1 = query(pos*2,l,mid,L,R);
    int val2 = query(pos*2+1,mid+1,r,L,R);
    return max(val1,val2);
}

vector< int > st[N],en[N];
int main(){
    FASTIO;
    int n;
    cin>>n;
    pii p[n];
    vector<int> sorts;
    int a;
    for(int i=0;i<n;i++){
        cin>>a>>p[i].S>>a>>p[i].F;
        sorts.pb( p[i].F ); sorts.pb( p[i].S );
    }
    sort(sorts.begin(),sorts.end());
    vector<int>::iterator ip;
    ip = std::unique(sorts.begin(), sorts.end());
    sorts.resize(std::distance(sorts.begin(), ip));
    map<int,int> m;
    for(int i=0;i<sorts.size();i++){
        m[ sorts[i] ] = i+1;
    }
    int cnt = sorts.size();

    for(int i=0;i<n;i++){
        p[i].F = m[ p[i].F ];
        p[i].S = m[ p[i].S ];
        st[ p[i].F ].pb( p[i].S );
        en[ p[i].S ].pb( p[i].F );
    }
    for(int i=0;i<n;i++){
      //  cout<<p[i].F<<" "<<p[i].S<<endl;
        update(1,1,cnt,p[i].F,p[i].S,1);
    }
    int res = 0, curr = 0;
    for(int i=1;i<=cnt;i++){
        curr+=st[ i ].size();
        for( auto v:st[i] ){
            update(1,1,cnt,i,v,-1);
        }
        //cout<<curr<<endl;
        int val = query(1,1,cnt,1,cnt);
        res = max(res,val+curr);
        curr-=en[i].size();
    }
    cout<<res<<endl;
}
/*
5
0 13 4 4
2 14 11 9
7 17 12 12
3 5 16 0
5 2 13 1
*/
