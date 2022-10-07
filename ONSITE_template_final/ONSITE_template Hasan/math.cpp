///***********faster linear implementation*****///
#define MAXP 100000
#define MAXN 10000000
vector<int> prime;
int lp[MAXN];//lowest prime that divide i
void LinearSeive(int n){
  memset(lp,0,sizeof(int)*n);
  for(int  i=2;i<n;++i){
    if(lp[i]==0){
      lp[i]=i;
      prime.push_back(i);
    }
    for(int j=0;j<(int)prime.size()&& prime[j]<=lp[i]&&i*prime[j]<n;++j)
    {
      lp[i*prime[j]]=prime[j];
    }
  }
}
///*******************************************///
ll modular_exp(ll a,ll b,ll mod){//mod should be <32 bit
  ll ans=1;
  while(b>0){
    if(b&1)ans=(ans*a)%mod;
    b=b>>1;
    a=(a*a)%mod;
  }
  return ans;
}
/*********finding all factor below n in O(nlogn)*********/
int *pfactor;
void build(int n){//prime factor of every number below n
  pfactor=new int[n+1];
  memset(pfactor,0,sizeof(int)*(n+1));
  int i,j;
  for(i=2;i<=n;i++){
    if(pfactor[i]==0){
      for(j=i;j<=n;j+=i){
        pfactor[j]=i;
      }
    }
  }
  return;
}
int get_p_factor(vector<int>& pf,vector<int>& pfp,int n){//pf and pfp must have size>log(n) returns number of prime factor
  int i=0;
  int j,pw;
  while(n>1){
    j=pfactor[n];
    pw=0;
    while(!(n%j)){
      n/=j;
      pw++;
    }
    pf[i]=j;
    pfp[i]=pw;
    i++;
  }
  return i;
}
int get_all_factor(vector<int>& pf,vector<int>& pfp,int sz,vector<int> &vct){
  vct[0]=1;
  int i,j,k,l,r,s=1;
  for(i=0;i<sz;i++){
    l=0;
    for(j=0;j<pfp[i];j++){
      r=s;
      for(k=l;k<r;k++,s++){
        vct[s]=(vct[k]*pf[i]);
      }
      l=r;
    }
  }
  return s;
}
/***********General multiplicative function****************/
int *mf;
int base_case(int p,int k){//base case for p^k
  return k+1;
}
void comp_mult_func(int n){
  mf=new int[n+1];
  memset(mf,-1,sizeof(int)*(n+1));
  int i,k,k2;
  ll l;
  mf[1]=1;
  for(i=2;i<=n;i++){
    if(mf[i]==-1){
      for(l=i+i;l<=n;l+=i)
        mf[l]=-i;
      l=i;
      k=1;
      while(l<=(ll)n){
        mf[l]=base_case(i,k);
        k++;
        l*=i;
      }
    }
  }
  for(i=2;i<=n;i++){
    if(mf[i]<0){
      mf[i]=-mf[i];
      k=i;
      while(!(k%mf[i])){
        k/=mf[i];
      }
      mf[i]=mf[k]*mf[i/k];
    }
  }
  return;
}
/*********mobius function************/
int mob[1000001];
void mobius(){
  memset(mob,-1,sizeof(mob));
  mob[1]=1;
  for(int i=2;i<1000001;++i)
    for(int j=i*2;j<1000001;j+=i)
      mob[j]-=mob[i];
}
