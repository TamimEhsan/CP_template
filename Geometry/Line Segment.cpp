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
#define T ll
struct PT {
    ll x, y;
    PT operator+(PT p) {return {x+p.x, y+p.y};}
    PT operator-(PT p) {return {x-p.x, y-p.y};}
    PT operator*(T d) {return {x*d, y*d};}
    PT operator/(T d) {return {x/d, y/d};}
    long long CrossProd(const PT &p) const {
        return x * (long long)p.y - y * (long long)p.x;
    }
    bool operator<(const PT &p) const {
        return make_pair(x, y) < make_pair(p.x, p.y);
    }
};
bool operator==(PT a, PT b) {return a.x == b.x && a.y == b.y;}
bool operator!=(PT a, PT b) {return !(a == b);}
T sq(PT p) {return p.x*p.x + p.y*p.y;}
double abs(PT p) {return sqrt(sq(p));}
ll dot(PT v, PT w) {return v.x*w.x + v.y*w.y;}
T cross(PT v, PT w) {return v.x*w.y - v.y*w.x;}
double dist(PT a,PT b){
    double dis = (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
    return sqrt(dis);
}
struct line {
    PT v; T c;
    // From direction vector v and offset c
    line(PT v, T c) : v(v), c(c) {}
    // From equation ax+by=c
    line(T a, T b, T c) : v({b,-a}), c(c) {}
    // From points P and Q
    line(PT p, PT q) : v(q-p), c(cross(v,p)) {}
    // Will be defined later:
    // - these work with T = int


    //line perpThrough(PT p);

    //line translate(PT t);
    // - these require T = double
    //void shiftLeft(double dist);
    //PT proj(PT p);
    //PT refl(PT p);
    T side(PT p) {return cross(v,p)-c;}
    T sq(PT p) {return p.x*p.x + p.y*p.y;}
    double dist(PT p) {return abs(side(p)) / abs(v);}
    bool cmpProj(PT p, PT q) {
        return dot(v,p) < dot(v,q);
    }
};






// segment AB and point P
double segmentToPointDistance(PT a, PT b, PT p) {
    if (a != b) {
        line l(a,b);
        if (l.cmpProj(a,p) && l.cmpProj(p,b)) // if closest to projection
            return l.dist(p); // output distance to line
    }
    return min(abs(p-a), abs(p-b)); // otherwise distance to A or B
}

void solve(){
    PT a,b,c;
    int l;
    cin>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y>>l;
    double mn = segmentToPointDistance(a,b,c);
    if( mn<=l ) cout<<0<<endl;
    else cout<<mn-l<<endl;
    double d = max(abs(a-c), abs(b-c));
    if( d<=l ) cout<<0<<endl;
    else cout<<d-l<<endl;

}

int main(){

    FASTIO;
   // int tc;
  //  cin>>tc;
  cout<<fixed<<setprecision(2);
  //  for(int t=1;t<=tc;t++) {
 //       cout<<"Case "<<t<<": ";
        solve();
  //  }

}

// https://acm.timus.ru/problem.aspx?space=1&num=1207


//  268522JW
