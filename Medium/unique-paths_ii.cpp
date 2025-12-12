#include <vector>

class Solution {
public:
    int uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1) {
            return 0;
        }

        std::vector<int> dp(n, 0);

        dp[0] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (obstacleGrid[i][j] == 1) {
                    dp[j] = 0;
                } else {
                    if (j > 0) {
                        dp[j] += dp[j - 1];
                    }
                }
            }
        }

        return dp[n - 1];
    }
};

/*
 * Approach: Dynamic Programming (Space Optimized)
 * * Logic:
 * 1. Edge Case Check: If the starting point (0,0) or the ending point (m-1, n-1)
 * contains an obstacle ('1'), it's impossible to traverse. Return 0 immediately.
 * 2. DP State: We use a 1D array 'dp' of size 'n' (number of columns).
 * - 'dp[j]' represents the number of unique paths to reach the cell at the
 * current row and column 'j'.
 * 3. Base Case: We set dp[0] = 1 initially because there is exactly one way to
 * be at the start (by simply standing there).
 * 4. Iteration: We loop through each cell of the grid.
 * 5. Obstacle Logic:
 * - If obstacleGrid[i][j] == 1, we set dp[j] = 0. This effectively blocks flow.
 * Any path trying to go through this cell counts as 0.
 * 6. Path Summation:
 * - If the cell is empty (0), we calculate paths.
 * - Current dp[j] holds the value from the row above (Down move).
 * - dp[j-1] holds the value from the left column (Right move).
 * - So, dp[j] = dp[j] (from top) + dp[j-1] (from left).
 * * Time Complexity: O(m * n)
 * We visit every cell once.
 * * Space Complexity: O(n)
 * We use a single row for the DP table.
 */