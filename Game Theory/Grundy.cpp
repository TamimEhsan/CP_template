#include<bits/stdc++.h>
using namespace std;
//#define INF 2147483647
#define INFL 9223372036854775807
#define pii pair<int,int>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define ll long long
#define ull unsigned long long
#define M 1000000007
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
#define take(x) scanf("%d",&x)
#define DE(x) printf("\ndebug %d\n",x);
#define vout(x) for(int i=0;i<x.size();i++) printf("%d ",x[i]);
#define pie acos(-1)
#define MOD 998244353

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int my_rand(int l, int r){return uniform_int_distribution<int>(l,r) (rng);}

const int N = 5005;
int grundy[N];
int main(){

    // 0 means lose
    // 1 means win

    grundy[0] = 0;
    grundy[1] = 0;
    grundy[2] = 1;
    grundy[3] = 1;


    for(int n=4;n<N;n++){
        set<int> s;
        for(int i=0;i<n;i++){
            int c1 = i;
            int c2 = n-i-2;
            if( c1>c2 ) break;
            s.insert( grundy[c1]^grundy[c2] );
        }
        int mex = s.size();
        auto it = s.begin();

        for(int i=0;i<s.size();i++){
            int val = *it;
            if( val!=i ){
                mex = i;
                break;
            }
            it++;
        }
        grundy[n] = mex;

        //cout<<n<<" "<<mex<<endl;
    }
    return 0;
    for(int i=1;i<N;i++){
        if( grundy[i] == 0 ) cout<<i<<" ";
    }


    int tc;
    cin>>tc;
    while(tc--){
        int n;
        cin>>n;
        if( grundy[n] == 1 ) cout<<"Second"<<endl;
        else cout<<"First"<<endl;
    }
}
// https://codeforces.com/gym/102059/problem/I
