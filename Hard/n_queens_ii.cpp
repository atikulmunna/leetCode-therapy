#include <vector>

class Solution {
public:
    int totalNQueens(int n) {
        int count = 0;
        std::vector<bool> cols(n, false);
        std::vector<bool> diag1(2 * n, false);
        std::vector<bool> diag2(2 * n, false);

        solve(0, n, cols, diag1, diag2, count);
        return count;
    }

private:
    void solve(int row, int n,
               std::vector<bool>& cols,
               std::vector<bool>& diag1,
               std::vector<bool>& diag2,
               int& count) {

        if (row == n) {
            count++;
            return;
        }

        for (int col = 0; col < n; col++) {
            int d1 = row - col + n - 1;
            int d2 = row + col;

            if (!cols[col] && !diag1[d1] && !diag2[d2]) {
                cols[col] = true;
                diag1[d1] = true;
                diag2[d2] = true;

                solve(row + 1, n, cols, diag1, diag2, count);

                cols[col] = false;
                diag1[d1] = false;
                diag2[d2] = false;
            }
        }
    }
};

/*
 * Approach: Backtracking with Optimized Validation
 * * Logic:
 * 1. State Tracking: We use three boolean arrays to efficiently track constraints:
 * - 'cols': Tracks occupied columns.
 * - 'diag1': Tracks occupied main diagonals. The unique identifier is (row - col).
 * We offset this by (n - 1) to ensure indices remain positive.
 * - 'diag2': Tracks occupied anti-diagonals. The unique identifier is (row + col).
 * * 2. Recursion: The 'solve' function attempts to place a queen in the current 'row'.
 * * 3. Iteration: We iterate through every column 'col' in the current row.
 * * 4. Check: For each position (row, col), we check if it is under attack by inspecting
 * our tracking arrays. If 'cols[col]', 'diag1[d1]', or 'diag2[d2]' is true,
 * the position is invalid.
 * * 5. Place & Recurse: If the position is safe, we mark the column and diagonals
 * as occupied and recursively call 'solve' for 'row + 1'.
 * * 6. Base Case: If 'row' equals 'n', it means we have successfully placed queens
 * in all rows. We increment the 'count'.
 * * 7. Backtrack: After returning from the recursive call, we unmark the column
 * and diagonals to allow the loop to try the next column position for the current row.
 * * Time Complexity: O(N!)
 * The number of possibilities reduces with each row (N choices for the first,
 * N-1 for the second, etc.).
 * * Space Complexity: O(N)
 * We use three arrays of size proportional to N, and the recursion stack depth is N.
 */