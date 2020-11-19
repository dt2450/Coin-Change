# Coin-Change
Coin Change Problem

The coin change problem is defined as below:

We have a set denomination coins but they are available in infinite quantity.
For example if the denomination is: [1, 5, 10, 25, 50] then we have
one cent coins, five cent coin, 10 cent coins, 25 cent coins and a 50 cent coins. However,
each coin denomination (1/5/10/25/50) is available in infinite quantity.

Given the coin denomination C[m], where m is the number of denominations
and a currency value n, we have to find all possible ways of having n dollars
using the denominations provided.

For example if n = 1, then there is only ONE way and that is to have 1 cent
coin.
However, if n = 10 we can have 10$ in the following ways:
1.) 1,1,1,1,1,1,1,1,1,1
2.) 1,1,1,1,1,5
3.) 5,5
4.) 10

So there are four ways (order doesn't matter here).

The problem is to find the number of ways of having n $ with C[m] denominations.


# Different Approaches

1. Recursive Approach (coin_prob_recursive.c)

    We use recursion to solve the problem. In this approach, we go through all the possible combinations
    to arrive at the result and clearly the time complexity is exponential in order. Space complexity is of order O(1)
    but if we consider the stack growth due to recursions then the order would be of a similar order as the time
    complexity.

2. Memoization Approach (coin_prob_memoize.c)

    In order to optimize the recursive approach, so that multiple sub-problems are solved only once, we take a
    O(n*m) array. In the memoization approach, we store the results of the recursive call, and use it next time.
    Hence, recursion call happens only if the solution of the call is not already processed. This ensures that
    we are solving the multiple sub-problems only once. It increases the space complexity to O(n*m) and reduces the
    time complexity to about O(n*m).

    Benefits of the memoization approach over the pure recursive approach can be seen with test cases 4 and 5.

3. Dynamic Programming Approach (coin_prob_dynamic.c and coin_prob.c)

    In the dynamic programming approach, we solve the problem iteratively rather than by recursion.
    In order to iteratively solve the problem, we solve it for all n (1 to n) and store the results in an
    O(n*m) array. Hence space complexity is O(n*m). Since there are three loops the time complexity is of the
    order O(n*m^2).

4. Optimized Dynamic Programming Approach (coin_prob_dynamic_opt.c)

    We see that in this particular case, we can optimize the solution to time complexity of O(n*m) and
    space complexity of O(n). This is achieved by reversing the loops so that outer loop is on coin denominations (m)
    and inner loop is on amount (0 to n). With this approach we need only an array of O(n) complexity, as a result
    the solution becomes of the time complexity order O(n*m) and space complexity O(n).


PS: The code works only when the input is in expected format. Hence, invalid inputs or incorrect entry will lead the program to fail.

Test cases have been provided and can be taken as reference for valid input format.

Input format is:

(Currency Value n) (No. of coin denominations m)
(space separated coin denominations)

Example Input:

10 5

1 5 10 25 50

The coin denominations are expected to be in sorted order from least to the highest.


# References
1. Lecture notes of Dr. Clifford Stein
2. https://www.hackerrank.com/challenges/coin-change
