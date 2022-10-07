/********************************************/
///out[i] contain length of longest increasing sequence
///ending at index i(0 based)
/********************************************/
void LIS(vector<int> & a,vector<int>& out){
  int n=a.size();
  int inf=1e9+1;
  vector<int> dp(n+1,INT_MAX);
  dp[0]=-INT_MAX;
  int i;
  for(i=0;i<n;i++){
    int j=upper_bound(dp.begin(), dp.end(), a[i])-dp.begin();
    int k=lower_bound(dp.begin(), dp.end(), a[i])-dp.begin();
    out[i]=k;
    if(dp[j-1]<a[i]&&a[i]<dp[j]){
      dp[j]=a[i];}}}
