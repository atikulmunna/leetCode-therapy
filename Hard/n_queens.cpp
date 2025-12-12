#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::vector<std::string>> solveNQueens(int n) {
        std::vector<std::vector<std::string>> results;
        std::vector<std::string> board(n, std::string(n, '.'));

        std::vector<bool> cols(n, false);
        std::vector<bool> diag1(2 * n, false);
        std::vector<bool> diag2(2 * n, false);

        solve(0, n, board, cols, diag1, diag2, results);
        return results;
    }

private:
    void solve(int row, int n, std::vector<std::string>& board,
               std::vector<bool>& cols,
               std::vector<bool>& diag1,
               std::vector<bool>& diag2,
               std::vector<std::vector<std::string>>& results) {

        if (row == n) {
            results.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {
            int d1 = row - col + n - 1;
            int d2 = row + col;

            if (!cols[col] && !diag1[d1] && !diag2[d2]) {
                board[row][col] = 'Q';
                cols[col] = true;
                diag1[d1] = true;
                diag2[d2] = true;

                solve(row + 1, n, board, cols, diag1, diag2, results);

                board[row][col] = '.';
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
 * 1. Constraint: We place queens row by row. This automatically ensures no two
 * queens share the same row.
 * 2. State Tracking: To check for attacks efficiently, we maintain three boolean arrays:
 * - 'cols': Tracks which columns are occupied.
 * - 'diag1': Tracks the main diagonals (top-left to bottom-right).
 * The unique identifier for these diagonals is (row - col).
 * We shift this by (n-1) to store it in a 0-indexed array.
 * - 'diag2': Tracks the anti-diagonals (top-right to bottom-left).
 * The unique identifier is (row + col).
 * 3. Recursion: The 'solve' function tries to place a queen in the current 'row'.
 * 4. Iteration: We loop through all columns 'col' for the current row.
 * 5. Check: If the column or either diagonal is already marked true, we skip.
 * 6. Place & Mark: If safe, we place 'Q', mark the column/diagonals as occupied,
 * and recursively call 'solve' for 'row + 1'.
 * 7. Backtrack: When the recursion returns, we unmark the column/diagonals and
 * remove the 'Q' to explore other possibilities for this row.
 * * Time Complexity: O(N!)
 * The first row has N choices, the second N-2 (roughly), etc.
 * * Space Complexity: O(N)
 * We store the board and three auxiliary arrays of size proportional to N.
 * The recursion stack depth is N.
 */