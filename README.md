# CP Templates

This is my templates and cheat codes for CP. Started working on this from February 2021.

```c++
#include<bits/stdc++.h>
using namespace std;
#define INF 2047483647
#define INFL 9223372036854775807
#define ll long long
#define pii pair<int,int>
#define pII pair<ll,ll>
#define vi vector<int>
#define vii vector<pii>
#define vI vector<ll>
#define VII vector<pII>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define ull unsigned long long
#define M 1000000007
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
#define take(x) scanf("%d",&x)
#define DE(x) printf("\ndebug %d\n",x);
#define vout(x) for(int i=0;i<x.size();i++) printf("%d ",x[i]);
#define pie acos(-1)
#define MOD 998244353
```



## Topics

####  Data Structures

- MO's Algorithm
- Ordered statistics tree
- Range Max Query Segment tree with lazy propagation
- Sparse Table for Range Query with no update

#### Graph Theory

- Dynamic Connectivity
- Lowest Common Ancestor using sparse table
- Kirchoff's Minimum Spanning tree number

#### Number Theory

- Big Integer (unary, binary operators, binary,unary comparators,gcd)
- Bigmod
- Derangement
- Determinant of a matrix by Gauss method for solving systems of linear equations
- Euler totient function (1-N in O(N))
- Faulhaber's triangle (Σi^k upto n)
- Fibonacci Numbers
  - O(logn) recursive
  - O(logn) matrix exponentiation
- Maximum xor of a subset
  - With no update (offline)
  - With update (online)
- Prime Numbers
  - Sieve of eratosthenes in O(n)
  - Miller Rabin deterministic primality test
- C(n,r)
  - Single query  	=> recursion
  - Multiple query  => memorization
- Stirling number (PIE)
- Roman Arabic numeral transformation

#### String

- Aho Corasick Algorithm
- Suffix Array
  - Suffix Array Generation
  - Substring Search
  - Lowest Common Prefix