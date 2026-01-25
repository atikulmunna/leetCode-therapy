#include <vector>
#include <algorithm>
#include <stack>

class Solution {
public:
    int largestRectangleArea(std::vector<int>& heights) {
        int n = heights.size();
        std::stack<int> st;
        int maxArea = 0;

        for (int i = 0; i <= n; i++) {
            int currentHeight = (i == n) ? 0 : heights[i];

            while (!st.empty() && heights[st.top()] > currentHeight) {
                int h = heights[st.top()];
                st.pop();

                int w = st.empty() ? i : i - st.top() - 1;

                maxArea = std::max(maxArea, h * w);
            }
            st.push(i);
        }

        return maxArea;
    }
};

/*
 * Approach: Monotonic Stack
 * * Logic:
 * 1. Concept: For any bar 'h', the largest rectangle fully including 'h' as its
 * full height is bounded by the first smaller bar to its left and the first
 * smaller bar to its right.
 * 2. Stack Property: We maintain a stack of indices such that the heights
 * corresponding to these indices are in strictly non-decreasing order.
 * 3. Iteration: We iterate through the histogram.
 * - If the current bar is taller than the stack's top, we push it.
 * - If the current bar is shorter, it signifies the "Right Boundary" for the
 * bar at the top of the stack.
 * 4. Calculating Area:
 * - When we pop a bar (height 'h') from the stack, the current index 'i'
 * is the Right Boundary.
 * - The new top of the stack (after popping) represents the Left Boundary
 * (the index of the previous smaller element).
 * - Width = (Right Boundary) - (Left Boundary) - 1.
 * - If the stack is empty, it means 'h' was the smallest so far, so width = i.
 * 5. The Sentinel (Edge Case):
 * - We iterate up to 'n' (inclusive). At 'i=n', we treat the height as 0.
 * This forces all remaining bars in the stack to be popped and processed,
 * ensuring we calculate areas for bars that extend to the very end of the array.
 * * Time Complexity: O(N)
 * Each element is pushed onto the stack once and popped once.
 * * Space Complexity: O(N)
 * In the worst case (sorted increasing), the stack holds all N indices.
 */