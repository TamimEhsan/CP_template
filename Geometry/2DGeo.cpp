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
#define ld long double


struct PT {
  ld x,y;
  PT() {}
  PT(ld x,ld y) : x(x), y(y) {}
  PT(const PT &p) : x(p.x), y(p.y) {}
};

ld sq(PT p){
    return p.x*p.x + p.y*p.y;
}

ld abs(PT p){
    return sqrt(sq(p));
}

ld dot(PT a,PT b){
    return a.x*b.x + a.y*b.y;
}

ld angle(PT a,PT c){
    ld cosTheta = dot(a,c)/abs(a) / abs(c);
    return acos( max((ld)-1.0, min((ld)1.0,cosTheta) ));
}

ld angle(PT a,PT b,PT c){
    return angle( PT(a.x-b.x,a.y-b.y),PT(c.x-b.x,c.y-b.y) );
}

ld distance(PT a,PT b){
    return sqrt( (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y) );
}

void solve(){
    PT a,o,b;
    cin>>o.x>>o.y>>a.x>>a.y>>b.x>>b.y;
    cout<<distance(a,o)*angle(a,o,b)<<endl;
}
int main(){
    int tc;
    cin>>tc;
    cout<<fixed<<setprecision(8);
    for(int t=1;t<=tc;t++){
        cout<<"Case "<<t<<": ";
        solve();

    }
}
