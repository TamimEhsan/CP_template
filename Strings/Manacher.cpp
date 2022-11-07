#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define x first
#define y second
#define ll long long
#define M 1000000007
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define endl '\n'
vector<int> manacher_odd(string s) {
    int n = s.size();
    s = "$" + s + "^";
    vector<int> p(n + 2);
    int l = 1, r = 1;
    for(int i = 1; i <= n; i++) {
        p[i] = max(0, min(r - i, p[l + (r - i)]));
        while(s[i - p[i]] == s[i + p[i]]) {
            p[i]++;
        }
        if(i + p[i] > r) {
            l = i - p[i], r = i + p[i];
        }
    }
    return vector<int>(begin(p) + 1, end(p) - 1);
}

vector<int> manacher(string s) {
    string t;
    for(auto c: s) {
        t += string("#") + c;
    }
    auto res = manacher_odd(t + "#");
    return vector<int>(begin(res) + 1, end(res) - 1);
}


void solve(){
    string s;
    cin>>s;
    reverse(s.begin(),s.end());
    auto mv = manacher(s);
    int mn = s.size()*2;
    for(int i=0;i<mv.size();i++){
        int it = i/2;
        int start,length;
        if( i%2 == 0 ){
            // odd length palindrome
            start = it - (mv[i]+1)/2 + 1;
            length = ((mv[i]+1)/2)*2-1;
        }else{
            // even length palindrome
            if( mv[i] == 1 ) continue;
            start = it - (mv[i])/2 + 1;
            length = ((mv[i])/2)*2;
        }
        if(start == 0){
            int req = s.size() - length;
            mn = min(mn,length+req*2);
        }
    }
    cout<<mn<<endl;

}
int main(){
    FASTIO;
    int tc=1;
    cin>>tc;
    for(int i=1;i<=tc;i++){
        cout<<"Case "<<i<<": ";
        solve();
    }
}

// https://lightoj.com/problem/making-huge-palindromes
