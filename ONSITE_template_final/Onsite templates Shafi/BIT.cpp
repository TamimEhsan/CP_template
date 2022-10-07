const int MaxIdx=1e+5;
int tree[MaxIdx+1];
int read(int idx) {int sum = 0;
  while (idx > 0) {sum += tree[idx];idx -= (idx & -idx);}
  return sum;}
void update(int idx, int val) {while (idx <= MaxIdx) {
   tree[idx] += val;idx += (idx & -idx);}}
int readSingle(int idx) {
  int sum = tree[idx];
  if (idx > 0) { int z = idx - (idx & -idx);idx--;
   while (idx != z) { sum -= tree[idx];idx -= (idx & -idx);}}
  return sum;}
int findG(int cumFre) {int idx = 0;int bitMask=(1<<16);
   while (bitMask != 0) {int tIdx = idx + bitMask;bitMask >>= 1;
   if (tIdx > MaxIdx)continue;
   if (cumFre >= tree[tIdx]) {idx = tIdx;cumFre -= tree[tIdx];}}
   if (cumFre != 0)return -1; else return idx;}

///2d version
#define MX_SIZE 1000
ll A[MX_SIZE+1][MX_SIZE+1];
void add(int i,int j,ll val){
   int k;
   for(;i<=MX_SIZE;i+=LSB(i)){
      for(k=j;k<=MX_SIZE;k+=LSB(k)){
        A[i][k]+=val;
      }
   }
}
ll sum(int i,int j){
   int k;
   ll s=0;
   for(;i>0;i-=LSB(i)){
      for(k=j;k>0;k-=LSB(k)){
        s+=A[i][k];
      }
   }
   return s;
}
