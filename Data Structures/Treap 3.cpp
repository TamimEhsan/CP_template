#include <bits/stdc++.h>
using namespace std;

#define INF 2000000000
#define INFL 200000000000000000LL

using ll = long long int;
using vi = vector<ll>;
using ii = pair<ll,ll>;
using iii = pair<ii,ll>;
using vii = vector<ii>;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef
tree < int, null_type ,less<ll>,
rb_tree_tag,
tree_order_statistics_node_update > ordered_set;

#define getbit(n,i) (((n)&(1LL<<(i)))!=0)
#define setbit0(n,i) ((n)&(~(1LL<<(i))))
#define setbit1(n,i) ((n)|(1LL<<(i)))
#define lastone(n) ((n)&(-(n)))

#define fi first
#define se second
#define PI (acos(-1))
#define mod (1000000007)

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template<class T,class V> ostream& operator<<(ostream &s,pair<T,V> a)
{
    s<<a.fi<<' '<<a.se;
    return s;
}

const int N = 1e6+3, K = 26;

int ara[N];
unordered_map<ll,ll> ump;
ll getrn()
{
    ll x;
    while(ump[x=rng()]==1);
    ump[x]=1;
    return x;
}
struct vert
{
    ll mn = 0,val = 0;
    vert (ll _v=0){
        val = mn = _v;
    }
    void reset()
    {
        mn = val;
    }
    void comb(vert l,vert r)
    {
        mn = min(l.mn,r.mn);
    }
};
class item
{
public:
    ll sz,prior;
    vert val;
    int lz;
    item *l,*r;
    item(vert t=vert(),ll c=1,ll _p=getrn(),item* _l=NULL,item* _r=NULL):val(t),sz(c),prior(_p),l(_l),r(_r),lz(0){}
};
typedef item* pitem;
class Treap
{
public:
    pitem root;
    Treap():root(NULL){}
    ll get_sz(pitem t)
    {
        if(t)return t->sz;
        return 0;
    }
    void upd_sz(pitem t)
    {
        if(t)t->sz=get_sz(t->l)+get_sz(t->r)+1;
    }
    void reset(pitem t)
    {
        if(t)t->val.reset();
    }
    void combine(pitem &t,pitem l,pitem r)
    {
        if(!l||!r)t=(l?l:r);
        else t->val.comb(l->val,r->val);
    }
    void proc(pitem t)
    {
        if(!t)return;
        reset(t);
        combine(t,t->l,t);
        combine(t,t,t->r);
    }
    void prop(pitem t){
		if(!t || t -> lz == 0)return;
		t -> lz = 0;
		swap(t->r,t->l);
		if(t->r)t -> r -> lz ^=1;
		if(t->l)t -> l -> lz ^=1;
	}
    void split(pitem t,pitem &l,pitem &r,int key,int add=0)
    {
		prop(t);
        if(!t)return void(l=r=NULL);
        int cur_pos=add+get_sz(t->l);
        if(key<=cur_pos)split(t->l,l,t->l,key,add),r=t;
        else split(t->r,t->r,r,key,cur_pos+1),l=t;
        upd_sz(t);
        proc(t);
    }
    void merge(pitem &t,pitem l,pitem r)
    {
		prop(l),prop(r);
        if(!l||!r)return void(t=(l?l:r));
        if(l->prior<r->prior)merge(r->l,l,r->l),t=r;
        else merge(l->r,l->r,r),t=l;
        upd_sz(t);
        proc(t);
    }
    void build(int ss,int sf,pitem &t)
    {
        if(ss>sf)return;
        if(ss==sf)return void(t=new item(vert(ara[ss])));
        int mid=(ss+sf)/2;
        t=new item(vert(ara[mid]));
        pitem a=NULL,b=NULL;
        build(ss,mid-1,a);
        build(mid+1,sf,b);
        merge(a,a,t);
        merge(t,a,b);
    }
    void build(int ss,int sf){build(ss,sf,root);}
    void insert(vert v,int pos)
    {
        if(!root)return void(root=new item(v));
        pitem l,r;
        l=r=NULL;
        split(root,l,r,pos-1);
        merge(l,l,new item(v));
        merge(root,l,r);
    }
    void erase(int pos,pitem &t,int add=0)
    {
        if(!t)return;
        if(get_sz(t->l)+add+1==pos)merge(t,t->l,t->r),proc(t);
        else if(get_sz(t->l)+add>=pos)erase(pos,t->l,add);
        else erase(pos,t->r,add+get_sz(t->l)+1);
    }
    void erase(int pos){
        if(!root)return;
        pitem l=NULL,r=NULL;
        split(root,l,r,pos);
        pitem w=NULL;
        split(l,l,w,pos-1);
        delete w;
        merge(root,l,r);
    }
    void replace(int pos,vert v)
    {
        if(!root)return;
        pitem l=NULL,r=NULL;
        split(root,l,r,pos);
        pitem w=NULL;
        split(l,l,w,pos-1);
        w->val=v;
        merge(l,l,w);
        merge(root,l,r);
    }
    vert find(int pos,pitem t,int add=0)
    {
        prop(t);
        if(get_sz(t->l)+add+1==pos)return t->val;
        else if(get_sz(t->l)+add>=pos)return find(pos,t->l,add);
        else return find(pos,t->r,add+get_sz(t->l)+1);
    }
    vert find(int pos){return find(pos,root);}
    int find2(int v,pitem t){
        prop(t);
        if(t->val.val == v)return get_sz(t->l) + 1;
        if(t->l != NULL && t->l->val.mn == v)return find2(v,t->l);
        return get_sz(t->l) + 1 + find2(v,t->r);
    }
    int find2(int v){
        return find2(v,root);
    }
    void update(int l,int r, pitem t){
		pitem L=NULL,mid=NULL,R=NULL;
        split(t,L,mid,l-1);
        split(mid,t,R,r-l+1);
        t -> lz ^= 1;
        merge(mid,L,t);
        merge(t,mid,R);
	}
    void update(int l,int r){
		update(l,r,root);
	}
    vert query(int l,int r,pitem t)
    {
        pitem L=NULL,mid=NULL,R=NULL;
        split(t,L,mid,l-1);
        split(mid,t,R,r-l+1);
        vert ans=t->val;
        merge(mid,L,t);
        merge(t,mid,R);
        return ans;
    }
    vert query(int l,int r){return query(l,r,root);}
    size_t size(){
        return get_sz(root);
    }
};



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T=1;
    //cin>>T;

    for(int qq=1; qq<=T; qq++)
    {
		int n;
        cin>>n;
        for(int i=1;i<=n;i++)cin>>ara[i],ara[i];
        vii ans;
        Treap t;
        t.build(1,n);
        for(int i=1;i<=n;i++){
            int p = t.find2(i);
            if(p != 1){
                ans.emplace_back(i,i + p - 1);
                t.update(1,p);
            }
            t.erase(1);
        }
        cout<<ans.size()<<endl;
        for(auto x:ans)cout<<x<<endl;
    }
}
