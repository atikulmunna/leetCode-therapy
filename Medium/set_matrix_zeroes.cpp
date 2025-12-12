#include <vector>

class Solution {
public:
    void setZeroes(std::vector<std::vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        bool firstRowZero = false;
        bool firstColZero = false;

        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0) {
                firstColZero = true;
                break;
            }
        }

        for (int j = 0; j < n; j++) {
            if (matrix[0][j] == 0) {
                firstRowZero = true;
                break;
            }
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        if (firstColZero) {
            for (int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }

        if (firstRowZero) {
            for (int j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
        }
    }
};

/*
 * Approach: In-Place Marking (O(1) Space)
 * * Logic:
 * 1. Constraint: We need to modify the matrix in-place. If we simply iterated
 * and set zeros as we found them, the new zeros would trigger chain reactions
 * in future iterations, turning the whole matrix to zero incorrectly.
 * 2. Strategy: We break the process into two passes.
 * - Pass 1: "Flagging". We determine which rows and columns *will* become zero.
 * - Pass 2: "Setting". We actually write the zeros.
 * 3. Space Optimization: Instead of allocating O(m+n) extra arrays to store
 * the flags, we use the first row (matrix[0][j]) and first column (matrix[i][0])
 * of the input matrix itself as storage.
 * 4. Corner Case (The Firsts): Since the first row and column are being used as
 * storage, we can't store *their own* status inside themselves without conflict.
 * We use two separate booleans ('firstRowZero', 'firstColZero') to remember if
 * the first row/col originally contained a zero.
 * 5. Execution:
 * - We check the first row/col and set the booleans.
 * - We loop through the rest of the matrix (1 to end). If we see a 0, we mark
 * the corresponding header in row 0 and col 0.
 * - We loop through the inner matrix again. If the header for that cell is 0,
 * we set the cell to 0.
 * - Finally, we check the booleans and zero out the first row/col if needed.
 * * Time Complexity: O(M * N)
 * We traverse the matrix twice.
 * * Space Complexity: O(1)
 * We only use two boolean variables.
 */