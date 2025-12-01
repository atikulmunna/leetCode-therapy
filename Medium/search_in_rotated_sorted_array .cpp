#include <vector>

class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return mid;
            }

            if (nums[left] <= nums[mid]) {
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            else {
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }

        return -1;
    }
};


/*
 * Approach: Modified Binary Search
 * * Logic:
 * 1. Standard Binary Search usually relies on the entire range being sorted.
 * In a rotated array, at least one half (left or right) is ALWAYS sorted.
 * 2. We compare nums[left] and nums[mid] to determine which half is sorted.
 * - If nums[left] <= nums[mid], the left half is sorted.
 * - Otherwise, the right half is sorted.
 * 3. Once we identify the sorted half, we check if the 'target' lies strictly
 * within the range of that sorted half.
 * - If it does, we move our pointers to search inside that half.
 * - If it doesn't, we eliminate that half and search the other (possibly unsorted) half.
 * 4. We repeat this process until 'left' > 'right' or we find the target.
 * * Time Complexity: O(log n)
 * We cut the search space in half during every iteration.
 * * Space Complexity: O(1)
 * We use constant extra space.
 */