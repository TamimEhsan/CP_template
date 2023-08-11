sum over x from 0 to n in floor( (ax+b)/c )

long long FloorSumAP(long long a, long long b, long long c, long long n){
  if(!a) return ((b / c) * (n + 1))%M;
  if(a >= c or b >= c) return ( ( ( (n*(n+1))/2 )%M * (a/c) )%M + ( (n+1)*(b/c) )%M + FloorSumAP(a%c,b%c,c,n) )%M;
  long long m = (a * n + b) / c;
  return  ( ( (m*n)%M - FloorSumAP(c,c-b-1,a,m-1) )%M+M )%M ;
}
