#include <vector>

class Solution {
public:
    bool search(std::vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                return true;
            }

            if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
                low++;
                high--;
                continue;
            }

            if (nums[low] <= nums[mid]) {
                if (nums[low] <= target && target < nums[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else {
                if (nums[mid] < target && target <= nums[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }

        return false;
    }
};

/*
 * Approach: Binary Search with Duplicate Handling
 * * Logic:
 * 1. Standard Binary Search Framework:
 * We maintain 'low' and 'high' pointers to define the search space.
 * * 2. Ambiguity Handling (The "II" Variation):
 * If nums[low] == nums[mid] == nums[high], we cannot determine if the pivot
 * is in the left or right half (e.g., [1, 0, 1, 1, 1] vs [1, 1, 1, 0, 1]).
 * We resolve this by incrementing 'low' and decrementing 'high' to skip
 * the duplicate values. This safely shrinks the window without losing the
 * target (since we already checked if nums[mid] == target).
 * * 3. Identify Sorted Half:
 * Once ambiguity is resolved, we check which half is sorted:
 * - If nums[low] <= nums[mid]: The Left Half is sorted.
 * - We check if the target lies strictly within [low, mid).
 * - Else: The Right Half is sorted.
 * - We check if the target lies strictly within (mid, high].
 * * Time Complexity:
 * - Average: O(log N)
 * - Worst Case: O(N) (Occurs if the array contains many duplicates, e.g., [1,1,1,1]).
 * * Space Complexity: O(1)
 */