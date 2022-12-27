#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define aa first
#define bb second
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
#define PIE acos(-1)
#define eps 1e-7
#define pii pair<ll,ll>
typedef long long T;
/* template<class T>
T check_sign(pair<T,T> p1,pair<T,T> p2,pair<T,T> p3){
    return (p1.first*p2.second+p2.first*p3.second+p3.first*p1.second
            -p1.second*p2.first-p2.second*p3.first-p3.second*p1.first);
}
*/

//template<class T>
ll check_sign(pair<T,T> p1,pair<T,T> p2,pair<T,T> p3){
    return (1ll*p1.first*p2.second+1ll*p2.first*p3.second+1ll*p3.first*p1.second
            -1ll*p1.second*p2.first-1ll*p2.second*p3.first-1ll*p3.second*p1.first);
}
//points must be given in anticlockwise order
//template<class T>
bool check_if_inside_polygon(vector<pair<T,T>>& points,pair<T,T> qpoint){
    int n=points.size();

    if(check_sign(points[0],points[1],qpoint)<0)
        return false;
    int l=1,r=n-1;
    while(r>l+1)
    {
        int mid=(l+r)/2;
        if(check_sign(points[0],points[mid],qpoint)>=0)
            l=mid;
        else
            r=mid;
    }
    if(check_sign(points[0],points[r],qpoint)>0||check_sign(points[l],points[r],qpoint)<0)
        return false;
    /// add these line if u want strictly inside
//    if(l==1&&check_sign(points[0],points[1],qpoint)==0)
//        return false;
//    if(r==n-1&&check_sign(points[0],points[r],qpoint)==0)
//        return false;
//    if(check_sign(points[l],points[r],qpoint)==0)
//        return false;
    return true;
}

int main(){
   // cout<<fixed<<setprecision(20);
    int n,m,k;
    cin>>n>>m>>k;
    vector<pii> poly;
    for(int i=0;i<n;i++){
        ll x,y;
        cin>>x>>y;
        poly.push_back({x,y});
    }

    int cnt = 0;
    for(int i=0;i<m;i++){
        ll x,y;
        cin>>x>>y;
      //  cout<<x<<" "<<y<<" ";
        if( check_if_inside_polygon(poly,{x,y}) ) cnt++;
      //  if( pointInConvexPolygon({x,y}) ) cout<<"YES"<<endl;
      //  else cout<<"NO"<<endl;
    }
   // cout<<cnt<<endl;
    if( cnt>=k ) cout<<"YES";
    else cout<<"NO";
}

/*
5 4 2
1 -1
1 2
0 4
-1 2
-1 -1
-2 -1
1 -1
0 1
2 3
*/
