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
#define endl '\n'
struct Node{
    ll sum;
    Node* lft;
    Node* rht;
    Node(){
        lft=rht=NULL;
        sum=0;
    }
    Node(ll s,Node* llft,Node* rrht){
        sum=s;
        lft=llft;
        rht=rrht;
    }
};
int value[200005];
void build(Node* v,int vl,int vr){
    if(vl==vr){
        v->sum=value[vl];
        return;
    }
    int mid=(vl+vr)/2;
    v->lft=new Node();
    v->rht=new Node();
    build(v->lft,vl,mid);
    build(v->rht,mid+1,vr);
    v->sum=v->lft->sum+v->rht->sum;
}

ll query(Node* v,int vl,int vr,int l,int r){
    if(vl==l&&vr==r){
        return v->sum;
    }
    int mid=(vl+vr)/2;
    if(r<=mid){
        return query(v->lft,vl,mid,l,r);
    } else if(l>mid){
        return query(v->rht,mid+1,vr,l,r);
    } else {
        return query(v->lft,vl,mid,l,mid)+query(v->rht,mid+1,vr,mid+1,r);
    }
}
void update(Node* vold,Node* vnew,int vl,int vr,int pos,int el) {
    if(vl==vr){
        vnew->sum=el;
        return;
    }
    int mid=(vl+vr)/2;
    if(pos<=mid) {
        vnew->rht=vold->rht;
        vnew->lft=new Node();
        update(vold->lft,vnew->lft,vl,mid,pos,el);
    }else{
        vnew->lft=vold->lft;
        vnew->rht=new Node();
        update(vold->rht,vnew->rht,mid+1,vr,pos,el);
    }
    vnew->sum=vnew->lft->sum+vnew->rht->sum;
}

void solve(){
    vector<Node*>roots;
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>value[i];
    }
    Node* root = new Node();
    build(root,1,n);
    roots.push_back(root);
    while(q--){
        int type;
        cin>>type;
        if( type == 1 ){
            int k,a,x;
            cin>>k>>a>>x;
            k--;
            Node* newRoot = new Node(); //< important to create a new node to be assigned root
            update(roots[k],newRoot,1,n,a,x);
            roots[k] = newRoot;
        }else if( type == 2 ){
            int k,a,b;
            cin>>k>>a>>b;
            k--;
            cout<<query(roots[k],1,n,a,b)<<endl;;
        }else{
            int k;
            cin>>k;
            k--;
            roots.push_back(roots[k]);
        }
    }


}
int main(){
    FASTIO;
    int tc=1;
    //cin>>tc;
    for(int t=1;t<=tc;t++){
        //cout<<"Case "<<t<<":"<<endl;
        solve();
    }
}

// https://cses.fi/problemset/task/1737/


