#include <vector>

class Solution {
public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
        std::vector<int> result;
        if (matrix.empty()) return result;

        int top = 0;
        int bottom = matrix.size() - 1;
        int left = 0;
        int right = matrix[0].size() - 1;

        while (top <= bottom && left <= right) {
            for (int i = left; i <= right; i++) {
                result.push_back(matrix[top][i]);
            }
            top++;

            for (int i = top; i <= bottom; i++) {
                result.push_back(matrix[i][right]);
            }
            right--;

            if (top <= bottom) {

                for (int i = right; i >= left; i--) {
                    result.push_back(matrix[bottom][i]);
                }
                bottom--;
            }

            if (left <= right) {

                for (int i = bottom; i >= top; i--) {
                    result.push_back(matrix[i][left]);
                }
                left++;
            }
        }

        return result;
    }
};

/*
 * Approach: Simulation with Boundaries
 * * Logic:
 * 1. We define four variables representing the current boundaries of the
 * unprocessed matrix: 'top', 'bottom', 'left', and 'right'.
 * 2. We enter a loop that continues as long as the boundaries are valid
 * (top <= bottom AND left <= right).
 * 3. Inside the loop, we perform 4 sequential loops representing the 4 directions:
 * - Left to Right (along the top boundary). After this, we increment 'top'.
 * - Top to Bottom (along the right boundary). After this, we decrement 'right'.
 * - Right to Left (along the bottom boundary). After this, we decrement 'bottom'.
 * - Bottom to Top (along the left boundary). After this, we increment 'left'.
 * 4. Critical Edge Case: After the first two movements (Right and Down),
 * the boundaries might have crossed (e.g., in a single row matrix).
 * We must check (top <= bottom) before traversing Left, and check (left <= right)
 * before traversing Up to avoid duplicate elements.
 * * Time Complexity: O(m * n)
 * We visit every element exactly once.
 * * Space Complexity: O(1)
 * Ignoring the output vector, we use constant extra space.
 */