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


const int MAXN = 100005;

int A[MAXN];
vector<int>tree[MAXN*5];

#define Left (node*2)
#define Right (node*2+1)
#define mid ((lo+hi)/2)

void build(int node, int lo, int hi){
    if(lo==hi) {tree[node].push_back(A[lo]); return;}
    build(Left,lo,mid);
    build(Right,mid+1,hi);
    merge(tree[Left].begin(),tree[Left].end(),tree[Right].begin(),tree[Right].end(),back_inserter(tree[node]));
}

int query(int node, int lo, int hi, int i, int j, int x){
    if(i>hi || j<lo) return 0;
    if(lo>=i && hi<=j) return lower_bound(tree[node].begin(),tree[node].end(),x) - tree[node].begin();
    int p1 = query(Left,lo,mid,i,j,x);
    int p2 = query(Right,mid+1,hi,i,j,x);
    return p1+p2;
}
int main(){
    FASTIO;
    int n,q;
    cin>>n>>q;
    for(int i=0;i<n;i++){
         cin>>A[i];
    }
    build(1,0,n-1);


    while(q--){
        int l,r,k;
        cin>>l>>r>>k;
        l--;r--;
        int hi = 1e9;
        int lo = -1e9;
        while(lo<=hi){
            int md = (hi+lo)/2;
            int val = query(1,0,n-1,l,r,md+1);
           // cout<<mid<<" "<<val<<endl;
            if( val<k ) lo = mid+1;
            else hi = mid-1;
        }
        cout<<lo<<endl;
    }
    // find the 5th smallest number from the subarray [a[2], a[3], ..., a[19]]

}
