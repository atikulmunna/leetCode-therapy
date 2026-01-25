#include <vector>
#include <stack>
#include <algorithm>

class Solution {
public:
    int maximalRectangle(std::vector<std::vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;

        int rows = matrix.size();
        int cols = matrix[0].size();
        std::vector<int> heights(cols, 0);
        int maxArea = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == '1') {
                    heights[j]++;
                } else {
                    heights[j] = 0;
                }
            }

            maxArea = std::max(maxArea, largestRectangleArea(heights));
        }

        return maxArea;
    }

private:
    int largestRectangleArea(const std::vector<int>& heights) {
        int n = heights.size();
        std::stack<int> st;
        int maxA = 0;

        for (int i = 0; i <= n; i++) {
            int h = (i == n) ? 0 : heights[i];

            while (!st.empty() && heights[st.top()] > h) {
                int height = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                maxA = std::max(maxA, height * width);
            }
            st.push(i);
        }
        return maxA;
    }
};

/*
 * Approach: Dynamic Programming + Monotonic Stack
 * * Logic:
 * 1. Problem Reduction: We treat each row of the matrix as the base line for a histogram.
 * As we iterate down the matrix, we accumulate the heights of continuous '1's.
 * 2. Building Heights:
 * - Create a 'heights' array initialized to 0.
 * - For each row 'i' and column 'j':
 * - If matrix[i][j] is '1', we increment height[j] (extending the bar from above).
 * - If matrix[i][j] is '0', we reset height[j] to 0 (the continuity is broken).
 * 3. Max Area Calculation:
 * - After updating the 'heights' array for the current row, we pass it to the
 * 'largestRectangleArea' helper function.
 * - This helper uses the Monotonic Stack algorithm (O(N)) to find the largest
 * rectangle in the current histogram.
 * 4. Result: We keep track of the global maximum area found across all processed rows.
 * * Time Complexity: O(M * N)
 * We iterate through the matrix cells once (O(M*N)). For each row, the histogram
 * calculation takes O(N). Total is M * N.
 * * Space Complexity: O(N)
 * We use an array of size N for heights and a stack of size up to N.
 */