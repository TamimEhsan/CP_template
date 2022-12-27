#include<bits/stdc++.h>
using namespace std;



const int N = 1e6+5;
const int mx = 3e5+5;
ll divisors[N+5];
void Divisors()
{
    ll n= N-4;
    ll i;
    ll j;
    for(i = 1; i <= n; i++)
        for(j = i; j <= n; j += i)
            divisors[j]++;
}


 
int mo[N];
void mobius(){
    memset(mo, -1, sizeof mo);
    mu[1] = 1;
    for(int i = 2; i < N; i++)
        for(int j = (i << 1) ; j < N; j += i)mo[j] -= mo[i];
}
