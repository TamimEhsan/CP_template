#define rng_23 mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
const ll siz=1000000;
ll moduli[siz],rem[siz];
pii egcd(ll a,ll b){
  ll r0=max(a,b),r1=min(a,b),
  s0=1,s1=0,t0=0,t1=1,q,tmp;
  while(r1){
    q=r0/r1;
    r0-=r1*q,s0-=s1*q,t0-=t1*q;
    tmp=r1,r1=r0, r0=tmp;
    tmp=s1,s1=s0,s0=tmp;
    tmp=t1,t1=t0,t0=tmp;
  }
  if(a<b)
    swap(s0,t0);
  return {s0,t0};
  //r0 is GCD
}
ll crt(ll n){
  ll n1, a1, m1, n2, a2, d, x; //x=n1*m1+a1=n2*m2+a2
  n1=moduli[0],a1=rem[0];
  for(ll i=1;i<n;i++){
		n2=moduli[i], a2=rem[i];
    d=a2-a1; //n1*m1-n2*m2=a2-a1=d
    m1=(egcd(n1, n2).fi * d/__gcd(n1, n2))%n2;
    x=n1*m1+a1;
    n1=n1/__gcd(n1, n2)*n2;
    a1=x%n1;
    if(a1<0)
      a1+=n1;
  }
  return a1;
}
