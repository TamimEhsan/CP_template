#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define ll long long
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
#define endl '\n'

const int N = 200005;

int getLuck(int x){
    string s = to_string(x);
    sort(s.begin(),s.end());
    return s[s.size()-1]-s[0];
}

int get_min(string &s){

    int mn = s[0] - '0';
    for(int i=0;i<s.size();i++) mn = min( mn, s[i]-'0' );
    return mn;

}

int get_max(string &s){

    int mx = s[0] - '0';
    for(int i=0;i<s.size();i++) mx = max( mx, s[i]-'0' );
    return mx;

}

void solve(){
    string sl,sr;
    cin>>sl>>sr;

    int mn = get_max(sl) - get_min(sl);
    string res = sl;
    int temp = get_max(sr) - get_min(sr);
    if( temp<mn ){
        mn = temp;
        res = sr;
    }
    // case 1: l has less digits than r, so we can change each digits of l to any digit
    if( sl.size()<sr.size() ){
        for(int i=0;i<sl.size();i++) cout<<9;
        cout<<endl;
        return;
    }
    // else we have some prefix of l and r to be same, so, those must be same for our answer too
    int firstDif = -1;
    for(int i=0;i<sl.size();i++){
        if( sl[i]!=sr[i] ){
            firstDif = i;
            break;
        }
    }
    // now firstDif has the first index where the digits are different
    // case 2: all are same ie l = r
    if( firstDif == -1 ){
        cout<<sl<<endl;
        return;
    }
    // case 3: first diff,fd position will have digit strictly greater than sl[fd]
    // and strictly less than sr[fd], remaining digits can be anything,
    // just make them equal to res[fd]
    for(int d=sl[firstDif]-'0'+1;d<sr[firstDif]-'0';d++){
        string tres = sl;
        for(int j=firstDif;j<sl.size();j++)
            tres[j] = d+'0';
        int temp = get_max(tres) - get_min(tres);
        if( temp<mn ){
            mn = temp;
            res = tres;
        }
    }
    // case 4: prefix of tres is same as sl and the next digit is strictly greater than that of sl
    // other digits can be anything, thus make them equal
    for(int i=firstDif+1;i<sl.size();i++){
        for(int d=sl[i]-'0'+1;d<10;d++){
            string tres = sl;
            for(int j=i;j<sl.size();j++){
                tres[j] = d+'0';
            }
            int temp = get_max(tres) - get_min(tres);
            if( temp<mn ){
                mn = temp;
                res = tres;
            }
        }
    }
    // case 5: prefix of tres is same as sr and the next digit is strictly smaller than that of sr
    // other digits can be anything, thus make them equal
    for(int i=firstDif+1;i<sr.size();i++){
        for(int d=sr[i]-'0'-1;d>=0;d--){
            string tres = sr;
            for(int j=i;j<sr.size();j++){
                tres[j] = d+'0';
            }
            int temp = get_max(tres) - get_min(tres);
            if( temp<mn ){
                mn = temp;
                res = tres;
            }
        }
    }
    cout<<res<<endl;
}

int main(){
    FASTIO;
    int tc=1;
    cin>>tc;

    while(tc--){
        solve();
    }
}

// https://codeforces.com/contest/1808/problem/C

/*
2
2 2
..
*.
2 4
*..*
*.*.

*/
