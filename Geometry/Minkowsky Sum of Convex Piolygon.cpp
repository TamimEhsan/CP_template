#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define aa first
#define bb second
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
#define PIE acos(-1)
struct pt{
    long long x, y;
    pt operator + (const pt & p) const {
        return pt{x + p.x, y + p.y};
    }
    pt operator - (const pt & p) const {
        return pt{x - p.x, y - p.y};
    }
    long long cross(const pt & p) const {
        return x * p.y - y * p.x;
    }
};

void reorder_polygon(vector<pt> & P){
    size_t pos = 0;
    for(size_t i = 1; i < P.size(); i++){
        if(P[i].y < P[pos].y || (P[i].y == P[pos].y && P[i].x < P[pos].x))
            pos = i;
    }
    rotate(P.begin(), P.begin() + pos, P.end());
}

vector<pt> minkowski(vector<pt> P, vector<pt> Q){
    // the first vertex must be the lowest
    reorder_polygon(P);
    reorder_polygon(Q);
    // we must ensure cyclic indexing
    P.push_back(P[0]);
    P.push_back(P[1]);
    Q.push_back(Q[0]);
    Q.push_back(Q[1]);
    // main part
    vector<pt> result;
    size_t i = 0, j = 0;
    while(i < P.size() - 2 || j < Q.size() - 2){
        result.push_back(P[i] + Q[j]);
        auto cross = (P[i + 1] - P[i]).cross(Q[j + 1] - Q[j]);
        if(cross >= 0)
            ++i;
        if(cross <= 0)
            ++j;
    }
    return result;
}

long double getLength(pt p1,pt p2){
    long double len = (p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y);
    len = sqrt(len);
    return len;
}
long double getMinDistance(pt p1,pt p2){
    long double dis = (p1.x*p2.y - p2.x*p1.y);
    if( dis<0 ) dis = -dis;
    dis = dis/getLength(p1,p2);

    return dis-60;

}

int main(){
    cout<<fixed<<setprecision(20);
    int n,m;
    cin>>n>>m;

    vector<pt> airport,cloud;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        airport.push_back({a,b});
    }
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        cloud.push_back({-a,-b});
    }
    auto mnk = minkowski(airport,cloud);
    long double mn = getMinDistance(mnk[0],mnk.back());
    for(int i=1;i<mnk.size();i++){
        mn = min(mn,getMinDistance(mnk[i-1],mnk[i]));
    }
    if( mn>0 )
        cout<<mn;
    else
        cout<<0;
}
