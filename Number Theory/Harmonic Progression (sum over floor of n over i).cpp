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
#define MM 1000000007
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
#define take(x) scanf("%d",&x)
#define DE(x) printf("\ndebug %d\n",x);
#define vout(x) for(int i=0;i<x.size();i++) printf("%d ",x[i]);
#define pie acos(-1)
#define MOD 998244353

// O(sqrt(n) )
// Sum of progression of form floor(n/1) +  floor(n/2) +  floor(n/3) + ... + floor(n/n)

ll HP(int n){
    ll sum = 0;
    int k = sqrt(n);
    for (int i = 1; i <= k; i++) {
        sum += ( n / i);
    }

    sum *= 2;
    sum -= k*k;
    return sum;
}

int main(){

    cout<<HP(5);
}
