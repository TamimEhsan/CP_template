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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int my_rand(int l, int r){return uniform_int_distribution<int>(l,r) (rng);}

int Set(int N,int pos){return N=N | (1<<pos);}
int reset(int N,int pos){return N= N & ~(1<<pos);}
bool check(int N,int pos){return (bool)(N & (1<<pos));}
```

 <!-- Check the other extensions later C:\MinGW\lib\gcc\mingw32\9.2.0\include\c++\ext\pb_ds\detail -->



## Topics

###  `Data Structures`

- Disjoint Set Union
- Fenwick Tree
  - Prefix Sum 
    - Point update, Range query
  - Distinct values in a range
- Fractions
- Implicit Treap
- Matrix
- MO's Algorithm
- Ordered statistics tree
  - Built In
  - Fenwick tree
- Range Max Query Segment tree with lazy propagation
- Sparse Table for Range Query with no update
- Segment tree
  - 2D segment tree
  - Lazy propagation

- Merge sort tree
- Unordered Map with Custom Hash

### `Geometry`

- Convex Hull
- Line segment intersection
- Polygon area

### `Graph Theory`

#### 	Connectivity

- Articulation Point
- Bridge
- Dijkstra
- Dynamic Connectivity (DSU online)
- Floyd Warshall (all pair shortest path)
- Strongly Connected Component

#### Matching

- Stable marriage

#### Minimum Spanning Tree

- Kirchoff's Minimum Spanning tree number

#### Tree

- Centroid Decomposition
- Heavy Light Decomposition
- Lowest Common Ancestor using sparse table
- Subtree queries

### `Number Theory`

- Berlekamp–Massey for finding linear recurrence
- Big Integer (unary, binary operators, binary,unary comparators,gcd)
- Bigmod
- Catalan's Number
- Derangement
- Determinant of a matrix by Gauss method for solving systems of linear equations
- Euler totient function (1-N in O(N))
- Faulhaber's triangle (Σi^k upto n)
- Fast Fourier Transformation
- Fast Walsh Hadamard Transformation
- Fibonacci Numbers
  - O(logn) recursive
  - O(logn) matrix exponentiation
- Harmonic Progression (sum over floor of n over i)
- Linear Recurrance
- Linear sieve for Multiplicative Functions
  - Prime numbers
  - Divisor Count
  - Divisor Sum
  - Mobius Function
- Maximum xor of a subset
  - With no update (offline)
  - With update (online)
- Prime Numbers
  - Sieve of Eratosthenes in O(n)
  - Miller Rabin deterministic primality test
- PIE
- C(n,r)
  - Single query  	=> recursion
  - Multiple query  => memorization
  - Lucas Theorem (NcR mod)
- Stirling number (PIE)
- Roman Arabic numeral transformation
- Sum of divisors from 1 to N

### `String`

- Aho Corasick Algorithm
- Palindromic Tree
- Prefix function
- String Hashing (Double hashing)
- Suffix Array
  - Suffix Array Generation
  - Substring Search
  - Longest Common Prefix
- Suffix automaton
- Z function