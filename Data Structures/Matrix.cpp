#include<bits/stdc++.h>
using namespace std;
#define INF 2147483647
#define INFL 9223372036854775807
#define pii pair<int,int>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define ll long long
#define ull unsigned long long
#define M 1000'000'007
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
#define take(x) scanf("%d",&x)
#define DE(x) printf("\ndebug %d\n",x);
#define vout(x) for(int i=0;i<x.size();i++) printf("%d ",x[i]);
#define pie acos(-1)
//#define MOD 998244353
#define FILEOUT {ofstream cout; cout.open ("example.txt");}



/**
    1-indexed
    but the sizes can be initialized with n,m (handled internally as n+1,m+1)
*/

ll MOD = 1000003;
const ll MOD2 = MOD * MOD * 3;

int Set(int N,int pos){return N=N | (1<<pos);}
int reset(int N,int pos){return N= N & ~(1<<pos);}
bool check(int N,int pos){return (bool)(N & (1<<pos));}

const int MAX = 105;


inline ll bigMod(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1) res=(res*a)%MOD;
        a=(a*a)%MOD; b>>=1;
    }
    return res;
}

struct Matrix{
    int row, col;
    ll m[MAX][MAX];
    Matrix() {memset(m,0,sizeof(m));}
    void Set(int r,int c) {row = r; col = c;}
    Matrix(int r,int c) {memset(m,0,sizeof(m)); Set(r,c);}
    void normalize(){
        for(int i=1; i<=row; i++){
            for(int j=1; j<=col; j++){
                m[i][j] %= MOD;
                if(m[i][j] < 0) m[i][j] += MOD;
            }
        }
    }
};

Matrix Multiply(Matrix A,Matrix B){
    Matrix ans(A.row,B.col);

    for(int i=1;i<=A.row;i++){
        for(int j=1;j<=B.col;j++){
            ans.m[i][j]=0;
            ll sm = 0;
            for(int k=1;k<=A.col;k++){
                sm+=(A.m[i][k]*B.m[k][j]);
                if(sm >= MOD2) sm -= MOD2;
            }
            ans.m[i][j] = sm % MOD;
        }
    }

    return ans;
}

Matrix Power(Matrix mat,ll p){

    Matrix res(mat.row , mat.col);
    Matrix ans(mat.row , mat.col);
    int n = ans.row;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            ans.m[i][j]=0;
            res.m[i][j]=mat.m[i][j];
        }
        ans.m[i][i]=1;
    }
    while(p){
        if(p&1) ans=Multiply(ans,res);
        res=Multiply(res,res);
        p=p/2;
    }

    return ans;
}


int main(){
    int n,w,h;
    cin>>n>>w>>h;


    Matrix mult2(w+1,w+1),mult1(1,w+1);
    for(int i=1;i<=w+1;i++){
        mult1.m[1][i+1] = 0;
    }
    mult1.m[1][1] = 1;
     for(int i=0;i<=w;i++) for(int j=0;j<=w;j++) {
        if( j == 0 ) mult2.m[i+1][j+1] = 1;
        else if( j==i+1 ) mult2.m[i+1][j+1] = h;
     }


    /*for(int i=0;i<=w;i++){
        for(int j=0;j<=w;j++) cout<<mult2.m[i+1][j+1]<<" ";
        cout<<endl;
    }
    cout<<endl;
    for(int i=0;i<1;i++) for(int j=0;j<=w;j++) cout<<mult1.m[i+1][j+1]<<" "; cout<<endl;*/
      cout<<Multiply(mult1,Power(mult2,n+1)).m[1][1]<<endl;;

}
