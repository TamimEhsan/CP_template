vector<int> where_floor_changes(int n){
 int now=1;
 vector<int>v;
 while(now<=n) {
  v.push_back(now);
  now=n/(n/now)+1;
 }
 return v;
}
vector<pair<int,int>> where_ceil_changes(int m){
 vector<pair<int,int>>v;
 int l=1;
 while(l<=m) {
  if(l==m) {
   v.push_back({m,m});
   break;
  }
  int cl=(m+l-1)/l;
  int r=(m+cl-2)/(cl-1)-1;
  r=min(r,m);
  r=max(r,l);
  v.push_back({l,r});
  if(r==m)
   break;
  l=r+1;
 }
 return v;
}
