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

# Order
The solution is non-recursive and since there are three nested loops, the order is O(nm^2)
However, in reality the solution is much quicker due to the memoization used. The memoization approach
optimizes the code significantly, by solving the multiple sub-problems only once.


# References
1. Lecture notes of Dr. Clifford Stein
2. https://www.hackerrank.com/challenges/coin-change
