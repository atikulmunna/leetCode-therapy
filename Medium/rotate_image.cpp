#include <vector>
#include <algorithm>

class Solution {
public:
    void rotate(std::vector<std::vector<int>>& matrix) {
        int n = matrix.size();

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                std::swap(matrix[i][j], matrix[j][i]);
            }
        }

        for (int i = 0; i < n; i++) {
            std::reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

/*
 * Approach: Transpose and Reflect
 * * Logic:
 * 1. Constraint Analysis: The problem requires "in-place" modification, meaning
 * we cannot allocate a second N x N matrix to copy values into. We must swap
 * elements within the existing grid.
 * 2. Mathematical Insight: A 90-degree clockwise rotation is geometrically
 * equivalent to a Transpose followed by a Horizontal Reflection (Reversing rows).
 * 3. Step 1 (Transpose): We iterate through the matrix. To avoid swapping elements
 * twice (which would undo the operation), we only iterate through the upper
 * triangle of the matrix (where j >= i). We swap matrix[i][j] with matrix[j][i].
 * 4. Step 2 (Reverse): We iterate through each row of the matrix and reverse
 * the vector. In C++, std::reverse handles this efficiently.
 * * Time Complexity: O(N^2)
 * We iterate over roughly half the elements during the transpose and all elements
 * during the reverse. Since there are N^2 elements, this is quadratic time.
 * * Space Complexity: O(1)
 * We only use a few temporary variables for swapping.
 */