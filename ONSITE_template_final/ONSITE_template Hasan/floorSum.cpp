typedef long long LL;
LL mod(LL a, LL m) {
  LL ans = a%m;
  return ans < 0 ? ans+m : ans;}
///Sum(floor((ax+b)/m)) for i=0 to n-1, (n,m >= 0)
LL floorSum(LL n, LL m, LL a, LL b) {
  LL ra = mod(a, m), rb = mod(b, m), k = (ra*n+rb);
  LL ans = ((a-ra)/m) * n*(n-1)/2 + ((b-rb)/m) * n;
  if (k < m)  return ans;
  return ans + floorSum(k/m, ra, m, k%m);}
