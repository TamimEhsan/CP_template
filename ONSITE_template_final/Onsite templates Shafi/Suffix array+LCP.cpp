#include<bits/stdc++.h>
using namespace std;
char str[1000002];
int c[1000002],temp[1000002];
vector<int> sa,csort[1000002];
int lcp[1000002];
void build_suffix_array(int n) ///O(nlogn)
{vector<pair<int,int>> ipos;
for(int i=0;i<n;i++)ipos.push_back(make_pair(str[i],i));
sort(ipos.begin(),ipos.end());
for(auto itr: ipos)sa.push_back(itr.second);
c[sa[0]]=0;
for(int i=1;i<n;i++){c[sa[i]]=c[sa[i-1]];
if(str[sa[i]]!=str[sa[i-1]])c[sa[i]]++;}
for(int k=0;(1<<k)<=n;k++){for(int i=0;i<n;i++){
sa[i]=(sa[i]-(1<<k)+n)%n;csort[c[sa[i]]].push_back(sa[i]);}
sa.clear();
for(int i=0;i<n;i++){for(auto itr: csort[i])
sa.push_back(itr);csort[i].clear();}
temp[sa[0]]=0;
for(int i=1;i<n;i++){temp[sa[i]]=temp[sa[i-1]];
if(!(c[sa[i]]==c[sa[i-1]] && c[(sa[i]+(1<<k))%n]==c[(sa[i-1]+(1<<k))%n]))
temp[sa[i]]++;}
for(int i=0;i<n;i++)c[i]=temp[i];}}
void kasai(int n, vector<int> &sa)
{int k=0;vector<int> ran(n,0);
for(int i=0; i<n; i++) ran[sa[i]]=i;
for(int i=0; i<n; i++, k?k--:0){
if(ran[i]==n-1) {k=0; continue;}
int j=sa[ran[i]+1];
while(i+k<n && j+k<n && str[i+k]==str[j+k]) k++;lcp[ran[i]]=k;}}
