# Important Blogs

- [Linear Recurrence and Berlekamp-Massey Algorithm](https://codeforces.com/blog/entry/61306) 
- [Basic Lagrange Interpolation](https://codeforces.com/blog/entry/82953)
- [Matrix Expotentiation](https://codeforces.com/blog/entry/80195)
- Bitwise Operations
  - [Bitwise operations for beginners](https://codeforces.com/blog/entry/73490)
  - [Bitwise operations 2 — popcount & bitsets](https://codeforces.com/blog/entry/73558) 
- [Algorithm Gym :: Data structures](https://codeforces.com/blog/entry/15729)
- [Permutation Tree](https://codeforces.com/blog/entry/78898)
- [Non-trivial DP tricks and Techniques](https://codeforces.com/blog/entry/47764)
- [Geometry: Polygon Algorithms](https://codeforces.com/blog/entry/48868)
- [Hashing](https://codeforces.com/blog/entry/60445)
- [Dynamic Convex Hull](https://codeforces.com/blog/entry/75929)
- [Fast and furious C++ I/O](https://codeforces.com/blog/entry/45835)
- 



- https://codeforces.com/blog/entry/57282
- [The On-Line Encyclopedia of Integer Sequences](https://oeis.org/)

## Simple tricks

- gcd(F(n),F(m)) = F(gcd(n,m)) where F(n) is nth fib with first two term as 0,1
- a+b=a⊕b+2(a&b)
- a+b=a|b+a&b
- a⊕b=a|b—a&b
- gcd(a,b) = gcd(a,a-b) = gcd(a,a%b)
- gcd(a^m−1, a^n−1) = a^gcd(m,n)−1

- To count the number of occurrences of an element in a range, we can  carry for each element a vector containing all the positions it occurs  in increasing order. Then, `upper_bound(r)-lower_bound(l)` gives us the number of occurrences in O(log(n)).

#### Catalan Numbers

For n = 0, 1, 2, 3, … values of Catalan numbers are 1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862

Catalan number Cn = (2n)! / ((n + 1)! * n!)

- Total number of possible Binary Search Trees with n different keys is Catalan(n)
- Total number of possible Binary Trees with n different keys is Catalan(n)*n!