#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
#define endl '\n'


const int N = 12;
const int M1 = 105;
const int M2 = 105;

int dp[N][M1][M2][2];

string s;
int K;

int getAns(int x){
   // if( x == 0 ) return 0;
   // this also takes account 0, so keep in mind that. in this case ans[b]-ans[a-1] has both
   // zero case so it is omitted by default. Else handle carefully
    s = to_string(x);
    int n = s.size();
    for(int i=0;i<N;i++){
        for(int j=0;j<M1;j++){
            for(int k=0;k<M2;k++){
                for(int f=0;f<2;f++){
                    dp[i][j][k][f] = 0;
                }
            }
        }
    }
    dp[0][0][0][1] = 1;

    s = "#"+s;
    for(int i=1;i<=n;i++){
        for(int j=0;j<K;j++){
            for(int k=0;k<K;k++){
                for(int f=0;f<2;f++){
                    // if( dp[i-1][j][f] == 0 ) continue;
                    // i is the current index
                    // j is the value of previous state
                    // k is the sum of previous digits
                    // f is the sate of being same of previous state


                    // previous states have at least one digit which is less that s
                    // so we can put any digits here when f
                    int dd = s[i]-'0';
                    int up = 9;
                    // previous states has all digits same as s, so we cant go upper that
                    // s[i]
                    if(f == 1) up = dd;
                    for(int d=0;d<=up;d++){
                        // we maintain prefix equality when f is 1 and d = s[i]
                        int nf = f && (d == int(s[i] - '0'));
                        dp[i][(j*10+d)%K][(k+d)%K][nf]+=dp[i-1][j][k][f];
                    }

                }
            }
        }
    }
    return dp[n][0][0][0]+dp[n][0][0][1];
}
void solve(){
    int a,b;
    cin>>a>>b>>K;
    if( K > 100 ) {
        cout<<0<<endl;
        return;
    }
    cout<<getAns(b)-getAns(a-1)<<endl;;
}

int main(){
    FASTIO;
    int tc;
    cin>>tc;
    for(int t=1;t<=tc;t++){
        cout<<"Case "<<t<<": ";
        solve();
    }
}

// https://lightoj.com/problem/investigation
