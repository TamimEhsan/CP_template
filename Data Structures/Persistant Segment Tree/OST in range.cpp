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



/**
    K-th ordered Statistics on a range
    No updates
    0-indexed
    for getting kth value in range [l,r]
        find_kth(roots[l], roots[r+1], tl, tr, k)
    tr = Max value stored in the array + 5
*/

struct Vertex {
    Vertex *l, *r;
    int sum;

    Vertex(int val) : l(nullptr), r(nullptr), sum(val) {}
    Vertex(Vertex *l, Vertex *r) : l(l), r(r), sum(0) {
        if (l) sum += l->sum;
        if (r) sum += r->sum;
    }
};

Vertex* build(int tl, int tr) {
    if (tl == tr)
        return new Vertex(0);
    int tm = (tl + tr) / 2;
    return new Vertex(build(tl, tm), build(tm+1, tr));
}

Vertex* update(Vertex* v, int tl, int tr, int pos) {
    if (tl == tr)
        return new Vertex(v->sum+1);
    int tm = (tl + tr) / 2;
    if (pos <= tm)
        return new Vertex(update(v->l, tl, tm, pos), v->r);
    else
        return new Vertex(v->l, update(v->r, tm+1, tr, pos));
}

int find_kth(Vertex* vl, Vertex *vr, int tl, int tr, int k) {
    if (tl == tr)
        return tl;
    int tm = (tl + tr) / 2, left_count = vr->l->sum - vl->l->sum;
    if (left_count >= k)
        return find_kth(vl->l, vr->l, tl, tm, k);
    return find_kth(vl->r, vr->r, tm+1, tr, k-left_count);
}



int main(){
    FASTIO;
    int n,q;
    cin>>n>>q;
    int ara[n];
    set<int> s;
    for(int i=0;i<n;i++){
         cin>>ara[i];
         s.insert(ara[i]);
    }
    map<int,int> compress;
    int cnt = 1;
    for(auto val:s){
        compress[val] = cnt++;
    }
    int decompose[cnt+5] = {0};
    for(int i=0;i<n;i++){
        decompose[ compress[ara[i] ] ] = ara[i];
        ara[i] = compress[ ara[i] ];
    }
   // for(int i=0;i<n;i++) cout<<ara[i]<<" "; cout<<endl;
    int tl = 0, tr = 1e5 + 5;
    std::vector<Vertex*> roots;
    roots.push_back(build(tl, tr));
    for (int i = 0; i < n; i++) {
        roots.push_back(update(roots.back(), tl, tr, ara[i]));
    }

    while(q--){
        int l,r,k;
        cin>>l>>r>>k;
        l--;r--;
        int result = find_kth(roots[l], roots[r+1], tl, tr, k);
        cout<<decompose[result]<<endl;
    }
    // find the 5th smallest number from the subarray [a[2], a[3], ..., a[19]]

}

/* https://www.spoj.com/problems/MKTHNUM/en/ */
