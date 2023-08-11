#include<bits/stdc++.h>

using namespace std;

#define INF 2047483647
#define INFL 9223372036854775807
#define ll long long
#define pii pair<int,int>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define ull unsigned long long
//#define M 1000000007
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
#define take(x) scanf("%d",&x)
#define DE(x) printf("\ndebug %d\n",x);
#define vout(x) for(int i=0;i<x.size();i++) printf("%d ",x[i]);
#define pie acos(-1)
#define MOD 998244353
#define infl 10000000000000000

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int my_rand(int l, int r){return uniform_int_distribution<int>(l,r) (rng);}

// cost function can be constant or can be calculate with segtree
// but can be done with MO too!

const int N = 100005;
int ara[N];
int freq[N];
ll cst=0; //< value of the cost function
ll dp[2][N];

int Left = 1,Right=0;

void add(int index){
    int f = freq[ara[index]]++;
    cst-= 1LL*f*(f-1)/2;
    f++;
    cst+= 1LL*f*(f-1)/2;
}

void rem(int index){
    int f = freq[ara[index]]--;
    cst-= 1LL*f*(f-1)/2;
    f--;
    cst+= 1LL*f*(f-1)/2;
}
long long cost_func(int l, int r){

    while(Left>l){
        add(--Left);
    }
    while(Right<r){
        add(++Right);
    }
    while(Left<l){
        rem(Left++);
    }

    while(Right>r){
        rem(Right--);
    }

    return cst;
}

// compute dp_cur[l], ... dp_cur[r] (inclusive)
void compute(int K,int l, int r, int optl, int optr) {
    if (l > r)
        return;

    int mid = (l + r) / 2;

    dp[K & 1][mid] = LLONG_MAX;
    int optNow = -1;
    for (int k = optl; k <= min(mid, optr); k++) {
        ll tmp = dp[ (K&1)^1 ][k-1] + cost_func(k,mid);
        if( tmp <= dp[K&1][mid] ){
            dp[K&1][mid] = tmp;
            optNow = k;
        }
    }
    compute(K,l, mid - 1, optl, optNow);
    compute(K,mid + 1, r, optNow, optr);
}

void solve() {
    int n,K;
    cin>>n>>K;

    for(int i=1;i<=n;i++) cin>>ara[i];
    for (int i = 1; i <= n; i++) dp[1][i] = cost_func(1, i);

    for (int i = 2; i <= K; i++) {
        compute(i,1, n , 1, n );
    }

    cout<<dp[K&1][n];
}

int main(){
    solve();
}

// https://codeforces.com/contest/868/problem/F
