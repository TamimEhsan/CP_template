mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll MAXN=1000001,hp=31+rng()%20,mod=1000004023;
ll power[MAXN],ipower[MAXN];
void power_build();
ll bigmod(ll a,ll b){ll ans=1;
    while(b>0){if(b&1)ans=(ans*a)%mod;b=b>>1;a=(a*a)%mod;}
    return ans;}
void ipower_build();
class Hush
{
public:
    ll *hf;string str;
    Hush(string &str): str(str)
    {hf=new ll[str.length()];hf[0]=str[0]-'a'+1;
    for(ll i=1;i<str.length();i++)hf[i]=(hf[i-1]+(str[i]-'a'+1)*power[i])%mod;}
    ll getHash(){return hf[str.length()-1];}
    ll getHash(ll i1,ll i2){if(i1==0)return hf[i2];
        return ((hf[i2]-hf[i1-1]+mod)*ipower[i1])%mod;}};
