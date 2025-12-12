class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;

        int prev1 = 2;
        int prev2 = 1;
        int current = 0;

        for (int i = 3; i <= n; i++) {
            current = prev1 + prev2;
            prev2 = prev1;
            prev1 = current;
        }

        return current;
    }
};

/*
 * Approach: Dynamic Programming (Space Optimized)
 * * Logic:
 * 1. Problem Reduction:
 * To reach step 'n', the final move must have been either a 1-step jump from (n-1)
 * or a 2-step jump from (n-2).
 * Thus, distinct_ways(n) = distinct_ways(n-1) + distinct_ways(n-2).
 * * 2. Fibonacci Connection:
 * This relation is identical to the Fibonacci sequence: F(n) = F(n-1) + F(n-2).
 * - n=1: 1 way.
 * - n=2: 2 ways (1+1, 2).
 * * 3. Iterative Solution:
 * Instead of maintaining an entire array (DP table) of size N, we only need the
 * counts for the previous two steps to calculate the current one.
 * We use two variables:
 * - 'prev1' tracks the ways to reach (i-1).
 * - 'prev2' tracks the ways to reach (i-2).
 * * 4. Loop:
 * We iterate from step 3 up to n. In each iteration:
 * - We calculate 'current' = 'prev1' + 'prev2'.
 * - We shift our window: 'prev2' becomes the old 'prev1', and 'prev1' becomes
 * the new 'current'.
 * * * Time Complexity: O(n)
 * We iterate from 3 to n exactly once.
 * * Space Complexity: O(1)
 * We use only three integer variables regardless of input size.
 */