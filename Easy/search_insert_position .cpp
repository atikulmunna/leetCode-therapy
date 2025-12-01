#include <vector>

class Solution {
public:
    int searchInsert(std::vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return left;
    }
};

/*
 * Approach: Standard Binary Search
 * * Logic:
 * 1. We assume the standard binary search setup with 'left' = 0 and 'right' = n-1.
 * 2. We enter a while loop as long as 'left' <= 'right'.
 * 3. We calculate 'mid'. If nums[mid] equals the target, we have found it, so we
 * return 'mid' immediately.
 * 4. If nums[mid] < target, it means the target (or its insertion spot) must be
 * to the right. We move 'left' to 'mid + 1'.
 * 5. If nums[mid] > target, the target (or insertion spot) is to the left.
 * We move 'right' to 'mid - 1'.
 * 6. The Loop Termination: If the target is NOT found, the loop breaks when
 * 'left' becomes greater than 'right'.
 * 7. At this specific moment, the 'left' pointer naturally rests at the index
 * where the target *should* be inserted to keep the array sorted. This is the
 * "invariant" of the binary search algorithm.
 * * Time Complexity: O(log n)
 * We halve the search space in every iteration.
 * * Space Complexity: O(1)
 * We use constant extra space.
 */