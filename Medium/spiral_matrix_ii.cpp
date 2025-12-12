#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> generateMatrix(int n) {
        std::vector<std::vector<int>> matrix(n, std::vector<int>(n));

        int top = 0;
        int bottom = n - 1;
        int left = 0;
        int right = n - 1;
        int num = 1;

        while (num <= n * n) {
            for (int i = left; i <= right; i++) {
                matrix[top][i] = num;
                num++;
            }
            top++;

            for (int i = top; i <= bottom; i++) {
                matrix[i][right] = num;
                num++;
            }
            right--;

            for (int i = right; i >= left; i--) {
                matrix[bottom][i] = num;
                num++;
            }
            bottom--;

            for (int i = bottom; i >= top; i--) {
                matrix[i][left] = num;
                num++;
            }
            left++;
        }

        return matrix;
    }
};

/*
 * Approach: Simulation with Boundaries
 * * Logic:
 * 1. Initialization: We create an n x n matrix initialized with zeros.
 * We define four boundary variables (top, bottom, left, right) to represent
 * the edges of the current spiral layer.
 * 2. The Loop: We continue filling the matrix as long as our counter 'num'
 * is less than or equal to n*n.
 * 3. Directional Filling:
 * - We fill the top row (left to right) and increment 'top' to "close" that row.
 * - We fill the right column (top to bottom) and decrement 'right'.
 * - We fill the bottom row (right to left) and decrement 'bottom'.
 * - We fill the left column (bottom to top) and increment 'left'.
 * 4. This sequential updating of boundaries naturally spirals inward until
 * the center is reached.
 * * Time Complexity: O(n^2)
 * We visit and fill each of the n^2 cells exactly once.
 * * Space Complexity: O(1)
 * Excluding the returned matrix, we use constant extra space.
 */