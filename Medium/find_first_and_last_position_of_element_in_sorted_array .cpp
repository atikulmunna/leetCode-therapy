#include <vector>

class Solution {
public:
    std::vector<int> searchRange(std::vector<int>& nums, int target) {
        std::vector<int> result = {-1, -1};
        if (nums.empty()) return result;

        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                result[0] = mid;
                right = mid - 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        if (result[0] == -1) return result;

        left = 0;
        right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                result[1] = mid;
                left = mid + 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return result;
    }
};

/*
 * Approach: Double Binary Search
 * * Logic:
 * 1. The problem requires O(log n) complexity, which mandates Binary Search.
 * 2. Since the array contains duplicates, a standard binary search might land on
 * any instance of the target (e.g., the middle one), not necessarily the first
 * or last. Therefore, we perform two separate binary searches.
 * 3. Find First Occurrence (Left Bound):
 * - We modify the binary search condition. When nums[mid] == target, we don't
 * return immediately. Instead, we update our 'first' index candidate and move
 * the 'right' pointer to 'mid - 1'. This forces the search to continue looking
 * in the left half for an earlier occurrence.
 * 4. Check Existence:
 * - If the first search finishes and result[0] is still -1, it means the target
 * is not in the array. We can return [-1, -1] immediately.
 * 5. Find Last Occurrence (Right Bound):
 * - We reset the pointers and perform a second binary search.
 * - When nums[mid] == target, we update our 'second' index candidate and move
 * the 'left' pointer to 'mid + 1'. This forces the search to continue looking
 * in the right half for a later occurrence.
 * * Time Complexity: O(log n)
 * We perform two binary searches, so the total time is 2 * log n, which simplifies to O(log n).
 * * Space Complexity: O(1)
 * We only use a few integer variables for pointers.
 */