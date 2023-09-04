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
#define endl '\n'
#define infile freopen("input.in","r",stdin);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int my_rand(int l, int r){return uniform_int_distribution<int>(l,r) (rng);}

int Set(int N,int pos){return N=N | (1<<pos);}
int reset(int N,int pos){return N= N & ~(1<<pos);}
bool check(int N,int pos){return (bool)(N & (1<<pos));}
```

 ### Pragmas

```c++
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
```

**Codeforces Version**

```c++
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
```



<!-- Check the other extensions later C:\MinGW\lib\gcc\mingw32\9.2.0\include\c++\ext\pb_ds\detail -->



## Topics

###  `Data Structures`

- Segment tree
  - 2D segment tree
  - Lazy propagation
  - Segment tree beats
  - Merge sort tree
- Fenwick Tree
  - Prefix Sum 
    - Point update, Range query
  - Distinct values in a range
- Disjoint Set Union
- Fractions
- Implicit Treap
- Matrix
- MO's Algorithm
- Ordered statistics tree
  - Built In
  - Fenwick tree
- Range Max Query Segment tree with lazy propagation
- Sparse Table for Range Query with no update
- Ternary Search
- Unordered Map with Custom Hash
- Wavelet Tree

### `Geometry`

- Convex Hull
- Line segment intersection
- Polygon area

### `Graph Theory`

#### 	Connectivity

- Articulation Point
- Bridge
  - Offline
  - Online

- Block Cut Tree
- Condensation Graph
- Dijkstra
- Dominator Tree
- Dynamic Connectivity (DSU online)
- Floyd Warshall (all pair shortest path)
- Strongly Connected Component

#### Flow

- Max Flow Min Cost
- Max Flow Min Cut (Dinic)
- Max Flow Min Cut (Push Relabel)

#### Graph

- Euler Tour 
  - Circuit Undirected
  - Circuit Directed
  - Path Directed

#### Matching

- Stable marriage
- Bipartite Matching ,Unweighted (Hopcroft Karp)
- Bipartite Matching ,Weighted (Hungarian)

#### Minimum Spanning Tree

- Kirchoff's Minimum Spanning tree number

#### Tree

- Centroid Decomposition
- Heavy Light Decomposition
- Lowest Common Ancestor 
  - Sparse table
  - Binary Lifting
- MO on Tree
- Query on Edge
- Subtree queries
- Tree Isomorphism
- Tree rerooting DP



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
  - Any mod (slower)
  - Specific mods (faster)

- Fast Walsh Hadamard Transformation
- Fibonacci Numbers
  - O(logn) recursive
  - O(logn) matrix exponentiation
- Harmonic Progression (sum over floor of n over i)
- Linear Recurrence
- Linear sieve for Multiplicative Functions
  - Prime numbers
  - Divisor Count
  - Divisor Sum
  - Mobius Function
- Basis Set
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
- Manacher
- Palindromic Tree
- Prefix function
- String Hashing (Double hashing)
- Suffix Array
  - Suffix Array Generation
  - Substring Search
  - Longest Common Prefix
- Suffix automaton
- Z function

### `DP`

- Convex Hull Trick Generalized
- Convex Hull Trick Monotonous
- Digit Dp

### `Game Theory`

- Green Hackenbush
- Grundy

