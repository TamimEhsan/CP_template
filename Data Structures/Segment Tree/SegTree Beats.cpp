#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000005;
#define ll long long int
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

#define endl '\n'
int A[maxn];

struct Data{
    int fmx, smx, fmcnt; ll sum;
};

Data Merge(Data A, Data B){
    Data curr;

    curr.sum = A.sum + B.sum;
    curr.fmx = max(A.fmx, B.fmx);
    curr.smx = max(A.smx, B.smx);
    if(A.fmx != B.fmx) curr.smx = max(curr.smx, min(A.fmx, B.fmx));

    curr.fmcnt = 0;
    if(curr.fmx == A.fmx) curr.fmcnt += A.fmcnt;
    if(curr.fmx == B.fmx) curr.fmcnt += B.fmcnt;
    return curr;
}

Data tree[maxn*5];
#define Left (node * 2)
#define Right ((node << 1) ^ 1)
#define mid ((lo+hi) >> 1)

void build(int node, int lo, int hi){
    if (lo==hi) {tree[node] = {A[lo], -1, 1, A[lo]}; return;}
    build(Left,lo,mid);
    build(Right,mid+1,hi);
    tree[node] = Merge(tree[Left], tree[Right]);
}

void lazyPropagation(int node,int lo,int hi){
    if(lo == hi) return;

    int val = tree[node].fmx;
    if(tree[Left].fmx > val){
        tree[Left].sum -= (tree[Left].fmx - val) * 1LL * tree[Left].fmcnt;
        tree[Left].fmx = val;
    }

    if(tree[Right].fmx > val){
        tree[Right].sum -= (tree[Right].fmx - val) * 1LL * tree[Right].fmcnt;
        tree[Right].fmx = val;
    }
}

void updateRange(int node, int lo, int hi, int i, int j, int val){
    if(tree[node].fmx <= val) return;
    if(lo>=i && hi<=j && tree[node].smx < val){
        tree[node].sum -= (tree[node].fmx - val) * 1LL * tree[node].fmcnt;
        tree[node].fmx = val;
        return;
    }
    if(lo == hi) return;

    lazyPropagation(node,lo,hi);
    if(i <= mid) updateRange(Left,lo,mid,i,j,val);
    if(j > mid) updateRange(Right,mid+1,hi,i,j,val);
    tree[node] = Merge(tree[Left], tree[Right]);
}

ll querySum(int node,int lo,int hi,int i,int j){
    if(lo>=i && hi <= j) return tree[node].sum;

    ll ret = 0;
    lazyPropagation(node,lo,hi);
    if(i <= mid) ret += querySum(Left,lo,mid,i,j);
    if(j > mid) ret += querySum(Right,mid+1,hi,i,j);
    return ret;
}

int queryMax(int node,int lo,int hi,int i,int j){
    if(lo>=i && hi <= j) return tree[node].fmx;

    int ret = -1;
    lazyPropagation(node,lo,hi);
    if(i <= mid) ret = max(ret, queryMax(Left,lo,mid,i,j));
    if(j > mid) ret = max(ret, queryMax(Right,mid+1,hi,i,j));
    return ret;
}


void solve(){
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>A[i];
    build(1,1,n);
    while(q--){
        int type;
        cin>>type;
        if( type == 0 ){
            int l,r,x;
            cin>>l>>r>>x;
            updateRange(1,1,n,l,r,x);
        }else if( type == 1 ){
            int l,r;
            cin>>l>>r;
            cout<<queryMax(1,1,n,l,r)<<endl;
        }else{
            int l,r;
            cin>>l>>r;
            cout<<querySum(1,1,n,l,r)<<endl;
        }
    }
}

int main(){
    FASTIO;
    int tc;
    cin>>tc;
    while(tc--) solve();
}

// https://vjudge.net/problem/HDU-5306
