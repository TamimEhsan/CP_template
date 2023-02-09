#include<bits/stdc++.h>
using namespace std;
#define INF 2047483647
#define INFL 9223372036854775807
#define ll long long
#define pii pair<ll,ll>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define ull unsigned long long
//#define M 1000000007
#define M 998244353
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
#define take(x) scanf("%d",&x)
#define DE(x) printf("\ndebug %d\n",x);
#define vout(x) for(int i=0;i<x.size();i++) printf("%d ",x[i]);
#define pie acos(-1)
#define MOD 998244353



struct Basis{
    const int LOG_A  = 25;
    int basis[LOG_A] = {0};

    void insert(int x){
        for(int i=LOG_A-1;i>=0;i--){
            if( !basis[i] ){
                basis[i] = x;
                return;
            }
            x^=basis[i];
        }
    }
    void insert(Basis &other){
        for(int i=0;i<LOG_A;i++)
            insert(other.basis[i]);
    }

    void clear(){
        for(int i=0;i<LOG_A;i++)
            basis[i] = 0;
    }
    int getMaxXor(){
        int mxXorr = 0;
        for(int i=LOG_A-1;i>=0;i--){
            if( !basis[i] ) continue;
            if( mxXorr & (1<<i) ) continue;
            mxXorr ^= basis[i];
        }
        return mxXorr;
    }

    bool isPossibleXor(int x){
        for(int i=LOG_A;i>=0;i--){
            if( ( x & (1<<i) ) == 0 ) continue;

            if( !basis[i] ) return false;

            x ^= basis[i];

        }
        return true;
    }

    int getBasisSize(){
        int sz = 0;
        for(int i=0;i<LOG_A;i++)
            if( basis[i] ) sz++;
        return sz;
    }
};

int mergeBasis(Basis a,Basis b){
    for(int i=0;i<32;i++)
        a.insert(b.basis[i]);
    return a.xorr;
}


int main(){
    int tc;
    cin>>tc;
    while(tc--)
        solve();
}
