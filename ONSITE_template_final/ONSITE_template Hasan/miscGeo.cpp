/// polar order
ll cross(pll a,pll b){
  return a.first*b.second-a.second*b.first;
}
int quarter(pll a){
  if(a.first>=0){
    if(a.second>=0)
      return 0;
    else
      return 3;}
  else{
    if(a.second>=0)
      return 1;
    return 2;}}
bool polar_order(pair<pll,int> & a,pair<pll,int>& b){
  if(quarter(a.first)==quarter(b.first)){
    return cross(a.first,b.first)>0;
  }
  else
    return quarter(a.first)<quarter(b.first);}
//number of point on a line segment
template <class T>
T npoint(pair<T,T> l,pair<T,T> r){
  T x=abs(l.first-r.first);
  T y=abs(l.second-r.second);
  if(x==0){
    return y+1;}
  else if(y==0){
    return x+1;}
  T g=__gcd(x,y);
  return g+1;}
//moderately tested on loj and cses
//crossing number from a point
//polygon[n]=polygon[0] where n= number of vertex in the original polygon
template<class T>
int cnPnPolygon(vector<pair<T,T> >& polygon,pair<T,T> pn){
  int n=(int)polygon.size();
  int cnt=0;
  for(int i=0;i<n-1;i++){
    if((polygon[i].second<=pn.second&& polygon[i+1].second>pn.second)
       ||(polygon[i].second>pn.second&& polygon[i+1].second<=pn.second))
    {
      T tmp=(polygon[i+1].first-polygon[i].first)* (pn.second-polygon[i].second)-
        (pn.first-polygon[i].first)* (polygon[i+1].second-polygon[i].second);
      if(polygon[i+1].second-polygon[i].second<0)
        tmp=-tmp;
      if(tmp>0)
        cnt++;}}
  return cnt;}
template<class T>
bool onBoundary(vector<pair<T,T> >&polygon,pair<T,T> pn){
  int n=(int)polygon.size();
  for(int i=0;i<n-1;i++){
    T tmp=(polygon[i].first-pn.first)* (polygon[i+1].second-pn.second)
        -(polygon[i+1].first-pn.first)* (polygon[i].second-pn.second);
    if(tmp==0
       &&((pn.first>=polygon[i].first&& pn.first<=polygon[i+1].first)|| (pn.first<=polygon[i].first&& pn.first>=polygon[i+1].first))
       &&((pn.second>=polygon[i].second&& pn.second<=polygon[i+1].second)|| (pn.second<=polygon[i].second&& pn.second>=polygon[i+1].second)))
    {
      return true;
    }}
  return false;}
template <class T>
inline
T cross(pair<T,T> p0,pair<T,T> p1,pair<T,T> p2){
  return (p1.first-p0.first)* (p2.second-p0.second)- (p1.second-p0.second)* (p2.first-p0.first);}
//winding number from a point,tested on loj timus and cses
template<class T>
int wnPnPolygon(vector<pair<T,T> >& polygon,pair<T,T> pn){
  //assuming polygon[n]=polygon[0]
  int n=(int)polygon.size();
  int wn=0;
  for(int i=0;i<n-1;i++){
    if(polygon[i].second<=pn.second){
      if(polygon[i+1].second>pn.second&& cross(pn,polygon[i],polygon[i+1])>0)
      {++wn;}}
    else if(polygon[i+1].second<=pn.second&& cross(pn,polygon[i],polygon[i+1])<0)
    {--wn;}}
  return wn;}
