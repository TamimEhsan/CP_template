#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define F first
#define S second
#define ll long long
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
#define endl '\n'
#define eps 0.00000001
#define pie acos(-1)
//#define pie 3.1415926535

struct PT {
    ll x, y;
    int id;
    long long CrossProd(const PT &p) const {
        return x * (long long)p.y - y * (long long)p.x;
    }
    bool operator<(const PT &p) const {
        return make_pair(x, y) < make_pair(p.x, p.y);
    }
};



bool polarSort(PT a, PT b)  {
    const PT origin{0, 0};
    bool ba = a < origin, bb = b < origin;
    if (ba != bb) { return ba < bb; }
    return a.CrossProd(b) > 0;
}


void solve(){
    int n;
    cin>>n;
    PT pts[n];
    for(int i=0;i<n;i++){
        ll a,b;
        cin>>a>>b;
        pts[i] = {a,b,i};
    }
    sort(pts,pts+n);
    for(int i=1;i<n;i++){
        pts[i].x-=pts[0].x;
        pts[i].y-=pts[0].y;
    }
    sort(pts+1,pts+n,polarSort);
    cout<<pts[0].id+1<<" "<<pts[n/2].id+1;
}

int main(){

    FASTIO;
   // int tc;
  //  cin>>tc;
  cout<<fixed<<setprecision(3);
  //  for(int t=1;t<=tc;t++) {
 //       cout<<"Case "<<t<<": ";
        solve();
  //  }

}

// https://acm.timus.ru/problem.aspx?space=1&num=1207


//  268522JW
