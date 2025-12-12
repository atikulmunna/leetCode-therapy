#include <vector>
#include <algorithm>

class Solution {
public:
    int minPathSum(std::vector<std::vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        for (int j = 1; j < n; j++) {
            grid[0][j] += grid[0][j - 1];
        }


        for (int i = 1; i < m; i++) {
            grid[i][0] += grid[i - 1][0];
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {

                grid[i][j] += std::min(grid[i - 1][j], grid[i][j - 1]);
            }
        }

        return grid[m - 1][n - 1];
    }
};

/*
 * Approach: Dynamic Programming (In-Place)
 * * Logic:
 * 1. DP State: We reuse the 'grid' itself as our DP table. 'grid[i][j]' will
 * store the minimum path sum to reach position (i, j) from (0, 0).
 * 2. Base Cases (Edges):
 * - First Row (i=0): We can only move Right. So, grid[0][j] is simply the sum
 * of all previous cells in that row.
 * - First Column (j=0): We can only move Down. So, grid[i][0] is the sum of
 * all previous cells in that column.
 * 3. Recurrence Relation: For any inner cell (i, j), we can arrive from the
 * top (i-1, j) or the left (i, j-1). To minimize the total sum, we pick the
 * smaller of these two neighbors and add it to the current cell's value.
 * - grid[i][j] += min(grid[i-1][j], grid[i][j-1])
 * 4. Result: After iterating through the entire grid, the value at the bottom-right
 * corner (grid[m-1][n-1]) represents the minimum cost of the full path.
 * * Time Complexity: O(m * n)
 * We visit every cell exactly once.
 * * Space Complexity: O(1)
 * We modify the input grid in-place. If modifying input is forbidden,
 * O(m * n) space would be needed for a separate DP table.
 */