mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll MAXN=1000001,hp=31+rng()%20, mod=1000004023;
ll power[MAXN],ipower[MAXN];
void ipower_build();
class Hush{
public:
  ll *hf;string str;
  Hush(string &str): str(str)
  {hf=new ll[str.length()];hf[0]=str[0]-'a'+1;
  for(ll i=1;i<str.length();i++)
    hf[i]=(hf[i-1]+ (str[i]-'a'+1)* power[i])%mod;}
  ll getHash(){return hf[str.length()-1];}
  ll getHash(ll i1,ll i2){
    if(i1==0)return hf[i2];
    return ((hf[i2]-hf[i1-1]+mod)* ipower[i1])%mod;
  }};
unsigned seed = chrono::system_clock::now().time_since_epoch().count();
linear_congruential_engine<uint_fast32_t, 1002517UL, 1001593UL, 2147483647UL> lcg(seed);
int primes_for_mod[]={1000019353, 1000001087, 1000020353, 1000003267, 1000000439, 1000018001, 1000019569, 1000020701, 1000016929, 1000007521,
1000007773, 1000013323, 1000018379, 1000017203, 1000006211, 1000004693, 1000013011, 1000020829, 1000011277, 1000007147};
int primes_for_base[]={1831, 1061, 5927, 6689, 7529, 9719, 3917, 271, 6029, 6091, 9719, 2819, 4877, 9679, 6373, 6101, 1039, 4591, 5531};
