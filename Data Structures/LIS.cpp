

#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int lis(vector<int> const& a) {
    int n = a.size();
    vector<int> v;
    for(int i=0;i<n;i++){
        if( v.empty() || v.back() <a[i] ) v.push_back(a[i]);
        else *lower_bound(v.begin(),v.end(),a[i]) = a[i];
    }
    return v.size();
}



void solve() {

    int n;
    cin>>n;
    pair<int,int> para[n];
    for(int i=0; i<n; i++) cin>>para[i].first;
    for(int i=0; i<n; i++) cin>>para[i].second;
    sort(para,para+n);
    const int INF = 1e9;
    vector<int> d;
    for(int i=0;i<n;i++) d.push_back(para[i].second);
    cout<<n+lis(d)<<endl;

}
int main() {
    int tc=1;
    // cin>>tc;
    while(tc--) solve();
}
