# Important Blogs

- **[The Ultimate Topic List (with Resources, Problems and Templates)](https://codeforces.com/blog/entry/95106)**
- [**`The Ultimate Topic List (with Resources, Problems and Templates(Updated)`**](https://shahjalalshohag.github.io/topic-list/)
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
- [Centroid Decomposition on a tree(Beginner)](https://codeforces.com/blog/entry/73707)
- [Number Theory in Competitive Programming](https://artofproblemsolving.com/community/c90633h1291397) 
- [[Tutorial] Burnside's lemma (with example)](https://codeforces.com/blog/entry/62401)
- [[Tutorial] Math note — linear sieve](https://codeforces.com/blog/entry/54090)
- [[Tutorial] Math note — Möbius inversion](https://codeforces.com/blog/entry/53925) 
- [[Tutorial] Math note — Dirichlet convolution](https://codeforces.com/blog/entry/54150)
- [[Tutorial] Generating Functions in Competitive Programming (Part 1)](https://codeforces.com/blog/entry/77468) 
- [[Tutorial] Generating Functions in Competitive Programming (Part 2)](https://codeforces.com/blog/entry/77551) 
- [[Tutorial] Non-trivial DP Tricks and Techniques](https://codeforces.com/blog/entry/47764) 
- [[Tutorial] Slope Trick](https://codeforces.com/blog/entry/47821) 
- [[Tutorial] Matroid intersection in simple words](https://codeforces.com/blog/entry/69287) 
- [SOS Dynamic Programming [Tutorial]](https://codeforces.com/blog/entry/45223) 
- [Dynamic Programming Optimizations](https://codeforces.com/blog/entry/8219)
- [1D/1D Dynamic Programming Optimization - Part I](https://sites.google.com/site/ubcprogrammingteam/news/1d1ddynamicprogrammingoptimization-parti?authuser=0)
- [বিটমাস্ক ডাইনামিক প্রোগ্রামিং](https://www.shafaetsplanet.com/?p=1357)
- 



- https://codeforces.com/blog/entry/57282
- [The On-Line Encyclopedia of Integer Sequences](https://oeis.org/)



## Github Repositories:

- [competitive-programming-library](https://github.com/mochow13/competitive-programming-library)
- [ACM Library](https://github.com/AnikSarker/ACM-Library)
- [AlgoVault](https://github.com/sgtlaugh/algovault)

## Video Lectures:

- [CodeChef's Indian Programming Camp 2016](https://youtube.com/playlist?list=PLi0ZM-RCX5nsTc2Z6woHr5qoF6n3b-thO)
- [Snackdown Training Camp, Day 1](https://blog.codechef.com/2016/07/11/snackdown-training-camp-day-1/) 
- [Snackdown Training Camp, Day 2](https://blog.codechef.com/2016/07/17/snackdown-training-camp-2016-day-2/)
- [Snackdown Training Camp, Day 3](https://blog.codechef.com/2016/07/17/snackdown-training-camp-day-3/)
- 

## Learning Websites

- [USACO guide](https://usaco.guide/adv/LC?lang=cpp) 
- [ শাফায়েতের ব্লগ](https://www.shafaetsplanet.com/)



## Practice Platforms

- [LighOJ](https://lightoj.com/home)
- [CSES problemset](https://cses.fi/problemset/)

## Simple tricks

- gcd(F(n),F(m)) = F(gcd(n,m)) where F(n) is nth fib with first two term as 0,1

- for (int x = m; x; ) { --x &= m; ... } loops
  over all subset masks of m (except m itself).

- x & -x is the least bit in x.

- a+b=a⊕b+2(a&b)

- a+b=a|b+a&b

- a⊕b=a|b—a&b

- gcd(a,b) = gcd(a,a-b) = gcd(a,a%b)

- gcd(a^m−1, a^n−1) = a^gcd(m,n)−1

- To count the number of occurrences of an element in a range, we can  carry for each element a vector containing all the positions it occurs  in increasing order. Then, `upper_bound(r)-lower_bound(l)` gives us the number of occurrences in O(log(n)).

- Number of topological sorting of a directed tree of n node is n!/( ∏ sz(v) ) where sz(v) is subtree size of node v.

- Lucas Theorem:  

  P is the prime which is to be take, No = N%P and Mo = M%P.

  ![](https://latex.artofproblemsolving.com/6/3/2/6328ada5b024e69de1004c54c80e379fc8bff64f.png) 

- For summation of series with precision upto certain decimal, sometimes we can use integration to approximate an answer.

  eg. sum(1/x) for x = 1 to 10^18, we can precalculate answer upto 10^7 and add the rest with ∫(1/x) dx => ln(x), so answer will be prec[1e7] + ln(1e18) - ln(1e7)
