#include <vector>
#include <algorithm>

class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int max_area = 0;

        while (left < right) {
            int current_width = right - left;
            int current_height = std::min(height[left], height[right]);
            int current_area = current_width * current_height;

            max_area = std::max(max_area, current_area);

            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return max_area;
    }
};

/*
 * Approach: Two Pointers (Greedy Strategy)
 * * Logic:
 * 1. We initialize two pointers: 'left' at the beginning of the array (index 0)
 * and 'right' at the end (index n-1). This guarantees we start with the maximum
 * possible width.
 * 2. We calculate the area formed by the lines at these pointers:
 * Area = (right - left) * min(height[left], height[right]).
 * 3. We update our 'max_area' if the current area is larger than the previous record.
 * 4. The Greedy Decision: We need to move one pointer inward to check for a better
 * potential area. The height of the water is limited by the *shorter* line.
 * - If we move the taller line, the width decreases, and the height is still
 * limited by the shorter line (or becomes even smaller). The area cannot increase.
 * - Therefore, we always move the pointer pointing to the shorter line inward,
 * hoping to find a taller line that compensates for the loss in width.
 * 5. We repeat this process until the 'left' and 'right' pointers meet.
 * * Time Complexity: O(n)
 * We traverse the array exactly once, checking each element at most once.
 * * Space Complexity: O(1)
 * We use constant extra space for variables.
 */