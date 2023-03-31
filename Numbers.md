#### Catalan Numbers

<hr>

**Values:** For n = 0, 1, 2, 3, … values of Catalan numbers are 1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862

**Formula**: Catalan number Cn = (2n)! / ((n + 1)! * n!)

**Properties:**

- Total number of possible Binary Search Trees with n different keys is Catalan(n)
- Total number of possible Binary Trees with n different keys is Catalan(n)*n!

####  Catalan's Triangle

<hr>

**Definition:** Catalan's triangle is a number triangle whose entries C ( n , k )give the number of strings consisting of n X's and k Y's such that no initial segment of the string has more Y's than X's.

**Values:**

sequence [A009766](https://oeis.org/A009766) in the [OEIS](https://en.wikipedia.org/wiki/On-Line_Encyclopedia_of_Integer_Sequences)

| n\k  | 0    | 1    | 2    | 3    | 4    | 5    | 6    | 7    | 8    |
| ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
| 0    | 1    |      |      |      |      |      |      |      |      |
| 1    | 1    | 1    |      |      |      |      |      |      |      |
| 2    | 1    | 2    | 2    |      |      |      |      |      |      |
| 3    | 1    | 3    | 5    | 5    |      |      |      |      |      |
| 4    | 1    | 4    | 9    | 14   | 14   |      |      |      |      |
| 5    | 1    | 5    | 14   | 28   | 42   | 42   |      |      |      |
| 6    | 1    | 6    | 20   | 48   | 90   | 132  | 132  |      |      |
| 7    | 1    | 7    | 27   | 75   | 165  | 297  | 429  | 429  |      |
| 8    | 1    | 8    | 35   | 110  | 275  | 572  | 1001 | 1430 | 1430 |

**Formula:**

Recurrence:

![](https://wikimedia.org/api/rest_v1/media/math/render/svg/7a284f32206f0d1cd2ce87390d8b95a2572f8398)

General:

![](https://wikimedia.org/api/rest_v1/media/math/render/svg/475e24591d1d9e24a32c7e110ce2311028dc5d12)

**Properties:**

- C(n,k) is the number of regular bracket sequence of n pair of brackets with first k being the first bracket.
- C(n,k) is the number of full binary trees with n+1 internal nodes and jump-length k
- C(n,k) is also the number of nondecreasing parking functions of length n+1 whose maximum element is k+1
- C(n,k) is the number of Dyck paths from (0,0) to (n+2,n+2) which start with n-k+2 east steps and touch the diagonal y=x only on the last north step.



#### Polite Number  

<hr>
**Definition:** A polite number or staircase number is a positive integer that can be written as the sum of two or more consecutive positive integers. 

**Values**: 3, 5, 6, 7, 9, 10, 11, 12, 13, 14, 15, 17, 18, 19, 20, 21, 22, 23, 24,  25, 26, 27, 28, 29, 30, 31, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43,  44, 45, 46, 47, 48, 49, 50, ... (sequence [A138591](https://oeis.org/A138591) in the [OEIS](https://en.wikipedia.org/wiki/On-Line_Encyclopedia_of_Integer_Sequences)).

**Formula**:  The politeness of *x* equals the number of [odd](https://en.wikipedia.org/wiki/Odd_number) [divisors](https://en.wikipedia.org/wiki/Divisor) of *x* that are greater than one.

**Method**: Find the number of divisors of that number ignoring the factors of 2. 90 = 2x3^2x5^1. So the politeness is (2+1)x(1+1)-1 = 5



#### Stirling Number of Second Kind

<hr>
**Definition**: Stirling number of the second kind (or Stirling partition number) is the number of ways to partition a set of n objects into k non-empty subsets and is denoted by S(n,k)

**Values:**

sequence [A008277](https://oeis.org/A008277) in the [OEIS](https://en.wikipedia.org/wiki/On-Line_Encyclopedia_of_Integer_Sequences):

|  n\k |    0 |    1 |    2 |    3 |     4 |     5 |     6 |    7 |    8 |    9 |   10 |
| ---: | ---: | ---: | ---: | ---: | ----: | ----: | ----: | ---: | ---: | ---: | ---: |
|    0 |    1 |      |      |      |       |       |       |      |      |      |      |
|    1 |    0 |    1 |      |      |       |       |       |      |      |      |      |
|    2 |    0 |    1 |    1 |      |       |       |       |      |      |      |      |
|    3 |    0 |    1 |    3 |    1 |       |       |       |      |      |      |      |
|    4 |    0 |    1 |    7 |    6 |     1 |       |       |      |      |      |      |
|    5 |    0 |    1 |   15 |   25 |    10 |     1 |       |      |      |      |      |
|    6 |    0 |    1 |   31 |   90 |    65 |    15 |     1 |      |      |      |      |
|    7 |    0 |    1 |   63 |  301 |   350 |   140 |    21 |    1 |      |      |      |
|    8 |    0 |    1 |  127 |  966 |  1701 |  1050 |   266 |   28 |    1 |      |      |
|    9 |    0 |    1 |  255 | 3025 |  7770 |  6951 |  2646 |  462 |   36 |    1 |      |
|   10 |    0 |    1 |  511 | 9330 | 34105 | 42525 | 22827 | 5880 |  750 |   45 |    1 |

**Formula:**

Recurrence: 

S(n,k) = k*S(n-1,k)+S(n-1,k-1)

and S(0,0) = 1 ; S(n,0) = S(0,n) = 0

Iterative:

![](https://wikimedia.org/api/rest_v1/media/math/render/svg/f6804fc81d0be09e3345b48778c4f965966657e3)

**Properties**:

- Number of Onto functions of n distinct elements to k set is S(n,k)*k!