class Solution {
public:
    int uniquePaths(int m, int n) {
        int T = m + n - 2;

        int R = std::min(m - 1, n - 1);

        long long result = 1;

        for (int i = 1; i <= R; i++) {
            result = result * (T - i + 1) / i;
        }

        return (int)result;
    }
};

/*
 * Approach: Combinatorics (Math)
 * * Logic:
 * 1. Problem Reduction:
 * To get from the top-left (0,0) to the bottom-right (m-1, n-1),
 * the robot must make exactly:
 * - (m - 1) moves Down
 * - (n - 1) moves Right
 *
 * The total number of steps is fixed regardless of the path taken:
 * Total Steps (T) = (m - 1) + (n - 1) = m + n - 2
 *
 * 2. The Combinatorial Question:
 * The problem simplifies to: "In a sequence of T total steps, how many
 * ways can we choose which specific steps are 'Right' moves?"
 * (The remaining steps will automatically be 'Down' moves).
 *
 * This is the definition of "n Choose k" (Combinations):
 * Ways = C(Total Steps, Right Moves)
 * = (m + n - 2)! / [ (m-1)! * (n-1)! ]
 *
 * 3. Optimization (Choosing k):
 * Mathematically, C(T, k) is the same as C(T, T-k).
 * We choose k = min(m - 1, n - 1) to reduce the number of iterations
 * in our calculation loop.
 *
 * 4. Calculation Loop:
 * We calculate C(T, k) iteratively to avoid computing massive factorials directly.
 * The formula for C(T, k) is:
 * T * (T-1) * ... * (T - k + 1)
 * -----------------------------
 * 1 * 2 * ... * k
 *
 * In each iteration 'i' from 1 to k:
 * - We multiply the result by (T - i + 1)  [The numerator part]
 * - We divide the result by 'i'            [The denominator part]
 * * Note: We use 'long long' for the result variable to prevent integer overflow
 * during the intermediate multiplication steps.
 *
 * Time Complexity: O(min(m, n))
 * Space Complexity: O(1)
 */