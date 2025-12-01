#include <vector>

class Solution {
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        bool rows[9][9] = {false};
        bool cols[9][9] = {false};
        bool boxes[9][9] = {false};

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '1';
                    int boxIndex = (i / 3) * 3 + (j / 3);

                    if (rows[i][num] || cols[j][num] || boxes[boxIndex][num]) {
                        return false;
                    }

                    rows[i][num] = true;
                    cols[j][num] = true;
                    boxes[boxIndex][num] = true;
                }
            }
        }

        return true;
    }
};

/*
 * Approach: One-Pass Iteration with Array Hashing
 * * Logic:
 * 1. Data Structures: We use three 2D boolean arrays (9x9) to act as hash sets.
 * - 'rows[i][num]' tracks if number 'num' has appeared in row 'i'.
 * - 'cols[j][num]' tracks if number 'num' has appeared in col 'j'.
 * - 'boxes[k][num]' tracks if number 'num' has appeared in 3x3 box 'k'.
 * 2. Iteration: We iterate through the 9x9 board exactly once using nested loops.
 * 3. Processing:
 * - If the character is '.', we skip it.
 * - We convert the character to an integer index (0-8) by subtracting '1'.
 * - We calculate the unique index for the 3x3 sub-box using the formula:
 * k = (row / 3) * 3 + (col / 3).
 * 4. Validation: Before marking a number as "seen", we check if it is already
 * marked as true in the corresponding row, column, or box array. If it is,
 * we immediately return false.
 * 5. Marking: If the number is valid so far, we mark it as true in all three arrays.
 * * Time Complexity: O(1)
 * The board size is fixed at 9x9. We perform a constant number of operations (81 iterations).
 * * Space Complexity: O(1)
 * The tracking arrays are fixed size (3 * 9 * 9 booleans), regardless of input content.
 */