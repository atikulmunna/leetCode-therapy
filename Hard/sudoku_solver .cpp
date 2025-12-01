#include <vector>

class Solution {
public:
    void solveSudoku(std::vector<std::vector<char>>& board) {
        solve(board);
    }

private:
    bool solve(std::vector<std::vector<char>>& board) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == '.') {
                    for (char c = '1'; c <= '9'; c++) {
                        if (isValid(board, i, j, c)) {
                            board[i][j] = c;

                            if (solve(board)) {
                                return true;
                            }

                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    bool isValid(std::vector<std::vector<char>>& board, int row, int col, char c) {
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == c) return false;
            if (board[row][i] == c) return false;
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) return false;
        }
        return true;
    }
};

/*
 * Approach: Backtracking (Depth-First Search)
 * * Logic:
 * 1. The Core Recursion: The 'solve' function tries to fill the board one empty cell at a time.
 * 2. Finding Empty Cells: We iterate through the grid. The first time we find a '.' (empty cell),
 * we stop to process it. This ensures we fill the board systematically.
 * 3. Trying Numbers: For the found empty cell, we try every digit from '1' to '9'.
 * 4. Validation: Before placing a digit, we call 'isValid'.
 * - It checks the entire Row for the same digit.
 * - It checks the entire Column for the same digit.
 * - It checks the specific 3x3 Sub-box. The formula '3 * (row / 3) + i / 3' handles the
 * coordinate mapping to check the correct block.
 * 5. Recursive Step:
 * - If a digit is valid, we place it in the cell.
 * - We then immediately call 'solve(board)' recursively. This attempts to solve the
 * rest of the board given this new state.
 * - If the recursive call returns true, it means we found a solution! We bubble the 'true'
 * all the way up.
 * 6. Backtracking (The Undo Step):
 * - If the recursive call returns false, it means the digit we chose led to a dead end
 * somewhere down the line.
 * - We reset the cell back to '.' (undo the choice) and continue the loop to try
 * the next digit.
 * 7. Failure: If we try digits '1'-'9' and none work, we return 'false', triggering
 * a backtrack in the previous stack frame.
 * 8. Success: If the loops complete without finding any '.' cells, we return 'true'.
 * * Time Complexity: O(9^m)
 * Where 'm' is the number of empty cells. In the worst case, we try 9 possibilities for every empty cell.
 * * Space Complexity: O(m)
 * The recursion stack depth is equal to the number of empty cells we need to fill.
 */