#include <vector>

class Solution {
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;

        int m = matrix.size();
        int n = matrix[0].size();

        int left = 0;
        int right = m * n - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            int row = mid / n;
            int col = mid % n;
            int midValue = matrix[row][col];

            if (midValue == target) {
                return true;
            } else if (midValue < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return false;
    }
};

/*
 * Approach: Binary Search (Virtual 1D Array)
 * * Logic:
 * 1. The problem states that the rows are sorted and the start of a new row
 * is greater than the end of the previous one. This means the entire matrix
 * is effectively a single sorted array of size M * N.
 * 2. Instead of iterating row by row or copying data to a new array, we treat
 * the matrix indices as a continuous range from 0 to (M*N - 1).
 * 3. We perform a standard Binary Search on this range.
 * 4. Index Mapping: The key to this solution is converting the 1D 'mid' index
 * back into 2D (row, col) coordinates without extra space.
 * - Row index = mid / columns
 * - Col index = mid % columns
 * 5. Comparison: We compare matrix[row][col] with the target.
 * - If it matches, return true.
 * - If smaller, ignore the left half (left = mid + 1).
 * - If larger, ignore the right half (right = mid - 1).
 * * Time Complexity: O(log(m * n))
 * We perform a binary search over the total number of elements.
 * * Space Complexity: O(1)
 * We only use a few variables for pointers and values.
 */