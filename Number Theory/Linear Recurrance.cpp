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
#define ld long double
#define ull unsigned long long
//#define M 1000'000'007
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
#define take(x) scanf("%d",&x)
#define DE(x) printf("\ndebug %d\n",x);
#define vout(x) for(int i=0;i<x.size();i++) printf("%d ",x[i]);
#define pie acos(-1)
#define eps 1e-7
//#define MOD 998244353
#define FILEOUT {ofstream cout; cout.open ("example.txt");}
#define Case(x) printf("Case %d: ",x);

int Set(int N,int pos){return N=N | (1<<pos);}
int reset(int N,int pos){return N= N & ~(1<<pos);}
bool check(int N,int pos){return (bool)(N & (1<<pos));}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int my_rand(int l, int r){return uniform_int_distribution<int>(l,r) (rng);}


#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define sz(x) (int)(x).size()
const ll mod = 1000000007; // faster if const
ll modpow(ll b, ll e){
    ll ans = 1;
    for (; e; b = b * b % mod, e /= 2)
        if (e & 1) ans = ans * b % mod;
    return ans;
}

/*
    Finds a linear recurrance of n order with 2*n term
    O(n^2)
*/
vector<ll> berlekampMassey(vector<ll> s){
    int n = sz(s), L = 0, m = 0;
    vector<ll> C(n), B(n), T;
    C[0] = B[0] = 1;
    ll b = 1;
    rep(i,0,n){
        ++m;
        ll d = s[i] % mod;
        rep(j,1,L+1) d = (d + C[j] * s[i - j]) % mod;
        if (!d) continue;
        T = C;
        ll coef = d * modpow(b, mod-2) % mod;
        rep(j,m,n) C[j] = (C[j] - coef * B[j - m]) % mod;
        if (2 * L > i) continue;
        L = i + 1 - L;
        B = T; b = d; m = 0;
    }
    C.resize(L + 1);
    C.erase(C.begin());
    for (ll& x : C) x = (mod - x) % mod;
    return C;
}

/*
    Finds the kth term of a linear recurrance of nth order
    O(n^2 * log(k))
 */
ll linearRec(vector<ll> S, vector<ll> tr, ll k){
    int n = sz(tr);
    auto combine = [&](vector<ll> a, vector<ll> b){
        vector<ll> res(n * 2 + 1);
        rep(i,0,n+1) rep(j,0,n+1)
        res[i + j] = (res[i + j] + a[i] * b[j]) % mod;
        for (int i = 2 * n; i > n; --i) rep(j,0,n)
            res[i - 1 - j] = (res[i - 1 - j] + res[i] * tr[j]) % mod;
        res.resize(n + 1);
        return res;
    };
    vector<ll> pol(n + 1), e(pol);
    pol[0] = e[1] = 1;
    for (++k; k; k /= 2){
        if (k % 2) pol = combine(pol, e);
        e = combine(e, e);
    }
    ll res = 0;
    rep(i,0,n) res = (res + pol[i + 1] * S[i]) % mod;
    return res;
}
// linearRec({0,1},{1,1},3) //<= Fib

int main(){
    for(auto v: berlekampMassey({0,1,1,2})) cout<<v<<" "; //Sieve
    cout<<linearRec({0,1},{1,1},3);
    /*
        // https://lightoj.com/problem/algebraic-problem
        int tc;
        cin>>tc;
        for(int t=1;t<=tc;t++){
            ll A,AB,k;
            cin>>A>>AB>>k;
            cout<<"Case "<<t<<": "<<linearRec({2,A},{A,-AB},k)<<endl;
        }
    */
}
