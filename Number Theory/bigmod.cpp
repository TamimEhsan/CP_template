#include<bits/stdc++.h>
using namespace std;
#define M 1000000007
#define ll long long

ll bigmod(ll x,int pow){
    if( pow == 0 ) return 1;
    ll mul = bigmod( x,pow/2 );
    if( pow%2 == 0 ) return (mul*mul)%M;
    return ((mul*mul)%M*x)%M;
}

int main(){
    cout<<bigmod(2,4);
}
