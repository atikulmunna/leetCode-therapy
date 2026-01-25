#include <vector>

class Solution {
public:
    int numTrees(int n) {
        std::vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }

        return dp[n];
    }
};

/*
 * Approach: Dynamic Programming
 * * Logic:
 * 1. State Definition: dp[i] represents the number of unique BSTs that can be formed with 'i' nodes.
 * 2. Base Cases:
 * - dp[0] = 1: An empty tree is one valid structure (conceptually necessary for the math to work).
 * - dp[1] = 1: A single node is one valid structure.
 * 3. Recurrence Relation:
 * - To find dp[i], we consider every number 'j' (from 1 to i) as the root.
 * - If 'j' is the root, there are 'j-1' nodes in the left subtree and 'i-j' nodes in the right subtree.
 * - The number of ways to form the tree with root 'j' is dp[j-1] * dp[i-j].
 * - We sum this product for all possible roots 'j'.
 * 4. Iteration: We build the array from size 2 up to n.
 * * Time Complexity: O(N^2)
 * We have two nested loops. The outer loop runs N times, and the inner loop runs 'i' times.
 * * Space Complexity: O(N)
 * We use an array of size N+1 to store the intermediate results.
 */