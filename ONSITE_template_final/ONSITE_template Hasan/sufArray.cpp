namespace SA{
  const int N=1e6+5;
  const int log_N=21;
  const int ALPHA= 155;
  //sa=suffix array,rnk=position array,hg=lcp array
  int sa[N],ra[N],rnk[N],hg[N],n;
  int wa[N],wb[N],wws[N],wv[N];
  int lg[N], st[N][log_N];
  int cmp(int *r,int a,int b,int l){
    return (r[a]==r[b]) && (r[a+l]==r[b+l]);
  }
  void DA(int *r,int *sa,int n,int m){
    int i,j,p,*x=wa,*y=wb,*t;
    for(i=0;i<m;i++) wws[i]=0;
    for(i=0;i<n;i++) wws[x[i]=r[i]]++;
    for(i=1;i<m;i++) wws[i]+=wws[i-1];
    for(i=n-1;i>=0;i--) sa[--wws[x[i]]]=i;
    for(j=1,p=1;p<n;j*=2,m=p) {
      for(p=0,i=n-j;i<n;i++) y[p++]=i;
      for(i=0;i<n;i++) if(sa[i]>=j) y[p++]=sa[i]-j;
      for(i=0;i<n;i++) wv[i]=x[y[i]];
      for(i=0;i<m;i++) wws[i]=0;
      for(i=0;i<n;i++) wws[wv[i]]++;
      for(i=1;i<m;i++) wws[i]+=wws[i-1];
      for(i=n-1;i>=0;i--) sa[--wws[wv[i]]]=y[i];
      for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1;i<n;i++)
        x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
    }
  }
  void init() {
    for(int i = 0; i <=n; i++) st[i][0] = hg[i+1];
    for(int j = 1; j < log_N; j++) {
      for(int i = 0; i <=n; i++) {
        if (i+(1<<j)-1 <= n) st[i][j] = min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
        else break;
      }
    }
    lg[0] = lg[1] = 0;
    for(int i = 2; i <= n; i++) {
      lg[i] = lg[i/2] + 1;
    }
  }
  void calheight(int *r,int *sa,int n){
    int i,j,k=0;
    for(i=1;i<=n;i++) rnk[sa[i]]=i;
    for(i=0;i<n;hg[rnk[i++]]=k)
      for(k?k--:0,j=sa[rnk[i]-1];r[i+k]==r[j+k];k++);
  }
  void create_sa(string  &s) {
    n = s.size();
    for(int i=0;i<max(n+1,ALPHA);i++) sa[i]=ra[i]=rnk[i]=hg[i]=wa[i]=wb[i]=wws[i]=wv[i]=0;
    for (int i = 0; i < n; i++) ra[i] = s[i];
    DA(ra,sa,n+1,ALPHA);
    calheight(ra,sa,n);
    init();
  }
  //0 indexed
  int query(int l, int r) {
    int pl=rnk[l];
    int pr=rnk[r];
    if(pl>pr)
      swap(pl,pr);
    pr--;
    int x=lg[pr-pl+1];
    return min(st[pl][x],st[pr-(1<<x)+1][x]);
  }
  long long numberOfDistinctSubString(int len)//length of string s,not s+'#'
  {
    long long ans=1ll*len*(len+1)/2;
    for(int i=1;i<=len;++i){
      ans-=SA::hg[i];
    }
    return ans;
  }
}
