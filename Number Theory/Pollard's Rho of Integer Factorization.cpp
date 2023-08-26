//Complexity : O(sqrt(Smallest Prime Factor of n)) = O(n^(1/4))
// can handle numbers upto 20 digits
// must use c++ 14 or higher to use __int128_t
// if number is less than 15 digits use ll as long long
#include<bits/stdc++.h>
using namespace std;
#define ll __int128_t
#define pii pair<ll,int>

ll Mul(ll a,ll b,ll Mod){
    ll Ans=0;
    while(b){
        if(b&1) {Ans+=a; if(Ans>=Mod) Ans-=Mod;}
        a+=a; if(a>=Mod) a-=Mod;
        b>>=1;
    }
    return Ans;
}

ll bigMod(ll n,ll r,ll Mod){
    if(r==0) return 1LL;
    ll ret=bigMod(n,r/2,Mod);
    ret=Mul(ret,ret,Mod);
    if(r%2==1) ret=Mul(ret,n,Mod);
    return ret;
}

ll _abs(ll a){
    if( a<0 ) return -a;
    return a;
}

ll read() {
    ll x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
void print(ll x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}


//Miller-Rabin
bool witness(ll wit,ll n){
  if(wit>=n) return false;

  int s=0; ll t=n-1;
  while(t%2==0) s++,t/=2;

  wit=bigMod(wit,t,n);
  if(wit==1 || wit==n-1) return false;

  for(int i=1;i<s;i++){
    wit=Mul(wit,wit,n);
    if(wit==1) return true;
    if(wit==n - 1) return false;
  }
  return true;
}

//Is n prime?
bool miller(ll n){
  if(n==2) return true;
  if(n%2==0 || n<2) return false;
  if(witness(2,n) || witness(7,n) || witness(61,n)) return false;
  return true;
}

// Pollard's Rho
// a must not equal 0 or -2.
// returns a divisor, a proper one when succeeded, equal to n if failed
// in case of failure, change a
ll rho(ll n,ll a) {
  auto f=[&](ll x) {return (Mul(x,x,n)+a)%n; };
  ll x=2,y=2;
  for(int i=1;;i++){
    x=f(x); y=f(f(y));
    ll d=__gcd(n,_abs(x-y));
    if(d!=1) return d;
  }
  return n;
}

ll get_factor(ll n){
  if(n%2==0) return 2;
  if(n%3==0) return 3;
  if(n%5==0) return 5;
  while(true){
    ll a=2+rand()%100;
    ll d=rho(n,a);
    if(d!=n) return d;
  }
  return n;
}

void factorize(ll n,vector<ll> &x) {
  if(n==1) return;
  else if(miller(n)) x.push_back(n);
  else{
    ll d=get_factor(n);
    factorize(d,x);
    factorize(n/d,x);
  }
}

vector<ll>factorize(ll n) {vector<ll>x; factorize(n, x); return x;}

vector<pii>Factors;
vector<ll>Divisors;
void findDiv(int pos,ll val){
    if(pos<0) {Divisors.push_back(val); return;}
    ll Now=1;
    for(int i=0;i<=Factors[pos].second;i++){
        findDiv(pos-1,val*Now);
        Now=Now*Factors[pos].first;
    }
}

void findAllDiv(ll n){
    vector<ll>now=factorize(n);
    sort(now.begin(),now.end());

    Factors.clear();
    Divisors.clear();
    int Count=1;
    for(int i=1;i<now.size();i++){
        if(now[i]==now[i-1]) Count++;
        else {Factors.push_back({now[i-1],Count}); Count=1;}
    }
    Factors.push_back({now.back(),Count});
    findDiv(Factors.size()-1,1);
}


int main(){
    ll n;
    vector<ll> facts;
    while(n=read()){
        facts.clear();
        factorize(n,facts);
        sort(facts.begin(),facts.end());
        int cnt = 1;
        for(int i=1;i<facts.size();i++){
            if( facts[i] == facts[i-1] ) cnt++;
            else{
                print(facts[i-1]);
                cout<<"^"<<cnt<<" ";
                cnt = 1;
            }
        }
        print(facts.back());
        cout<<"^"<<cnt;
        cout<<endl;
    }
}

// https://www.spoj.com/problems/FACT0/
// https://www.spoj.com/problems/FACT1/
