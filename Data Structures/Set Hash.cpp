#include<bits/stdc++.h>
#define eb emplace_back
#define ep emplace
#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define mt make_tuple
#define fi first
#define se second
#define fastio ios::sync_with_stdio(false);cin.tie(NULL)
#define rng_23 mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define DBG(a) cerr<< "line "<<__LINE__ <<" : "<< #a <<" --> "<<(a)<<endl
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int ,int , int > tiii;
const int INF=1e9;
const ll mod=1000004023;
const ll mod2=1000000007;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll MAXN=1000001,hp=31,hp2=127;
ll power[MAXN],ipower[MAXN];
ll power2[MAXN],ipower2[MAXN];
void power_build()
{
     power[0]=1;
     for(ll i=1;i<MAXN;i++){
         power[i]=power[i-1]*hp;
         if(power[i]>=mod)
            power[i]%=mod;
     }

     power2[0]=1;
     for(ll i=1;i<MAXN;i++){
         power2[i]=power2[i-1]*hp2;
         if(power2[i]>=mod2)
            power2[i]%=mod2;
     }
}
ll bigmod(ll a,ll b){//mod should be <32 bit
    ll ans=1;
    while(b>0){
        if(b&1)ans=(ans*a)%mod;
        b=b>>1;
        a=(a*a)%mod;
    }
    return ans;
}

ll bigmod2(ll a,ll b){//mod should be <32 bit
    ll ans=1;
    while(b>0){
        if(b&1)ans=(ans*a)%mod2;
        b=b>>1;
        a=(a*a)%mod2;
    }
    return ans;
}
void ipower_build()
{
     ipower[0]=1;
     ipower[1]=bigmod(hp,mod-2);
     for(ll i=2;i<MAXN;i++){
         ipower[i]=(ipower[i-1]*ipower[1])%mod;

     }
     ipower2[0]=1;
     ipower2[1]=bigmod2(hp2,mod2-2);
     for(ll i=2;i<MAXN;i++){
         ipower2[i]=(ipower2[i-1]*ipower2[1])%mod2;

     }
}

//  0 indexed
class Hush{
public:
    ll *hf;
    ll *hf2;
    Hush(vector<int> &vec)
    {
        hf=new ll[vec.size()];
        hf2=new ll[vec.size()];
        hf[0]=power[vec[0]];
        hf2[0]=power2[vec[0]];
        for(ll i=1;i<vec.size();i++){

            hf[i]=(hf[i-1]+power[vec[i]])%mod;
            hf2[i]=(hf2[i-1]+power2[vec[i]])%mod2;
        }

    }
    pair<ll,ll> getHash(ll i1,ll i2)
    {
        if(i2<i1) return {0,0};
        if(i1==0)
            return {hf[i2],hf2[i2]};
        return {(hf[i2]-hf[i1-1]+mod)%mod, (hf2[i2]-hf2[i1-1]+mod2)%mod2};
    }
};

void solve(){


}
int main()
{
    fastio;
    power_build();
    ipower_build();
    solve();

}
