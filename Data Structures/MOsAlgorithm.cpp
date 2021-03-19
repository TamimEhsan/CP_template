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
#define M 1000000007
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
#define take(x) scanf("%d",&x)
#define DE(x) printf("\ndebug %d\n",x);
#define vout(x) for(int i=0;i<x.size();i++) printf("%d ",x[i]);
#define pie acos(-1)
#define MOD 998244353

const int N = 300007;
int BLOCK = 500;
int cnt[N];
int res = 0;
void add(int n){
    if( cnt[n] == 0 ) res++;
    cnt[n]++;
}
void rem(int n){
    cnt[n]--;
    if( cnt[n] == 0 ) res--;
}
int main(){
    FASTIO;
    int n = 10;
    //cin>>n;
    int MO[] = {1,5,2,4,1,6,7,2,2,2};
    //for(int i=0;i<n;i++) cin>>ara[i];
    int q;
    cin>>q;
    pair<pii,pii> queries[q]; // start,end,index, ans
    for(int i=0;i<q;i++){
        int a,b;
        cin>>a>>b;
        queries[i] = {{a,b},{i,0}};
    }
    sort(queries,queries+q,[](pair<pii,pii> A,pair<pii,pii> B){
         return A.F.F/BLOCK == B.F.F/BLOCK ? A.F.S<B.F.S: A.F.F<B.F.F;
         });
    int l_it =1,r_it = 0;
    for( int i=0;i<q;i++ ){
        int L = queries[i].F.F;
        int R = queries[i].F.S;
        while( r_it<R ) add( MO[++r_it] );
        while( l_it>L ) add( MO[ --l_it ] );
        while( r_it>R ) rem( MO[r_it--] );
        while( l_it<L ) rem( MO[l_it++] );
        queries[i].S.S = res;
       // cout<<res<<endl;
    }
    sort( queries,queries+q,[](pair<pii,pii> A,pair<pii,pii> B){
         return A.S.F<B.S.F;
         });
    for(int i=0;i<q;i++){
        cout<<queries[i].S.S<<endl;
    }
}
