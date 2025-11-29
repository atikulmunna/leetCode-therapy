#include <vector>
#include <algorithm>

class Solution {
public:
    void nextPermutation(std::vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;

        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }

        if (i >= 0) {
            int j = n - 1;
            while (nums[j] <= nums[i]) {
                j--;
            }
            std::swap(nums[i], nums[j]);
        }

        std::reverse(nums.begin() + i + 1, nums.end());
    }
};

/*
 * Approach: Single Pass (Find, Swap, Reverse)
 * * Logic:
 * 1. Find the Pivot: We iterate backwards from the end of the array to find the
 * first index 'i' where the order stops increasing (nums[i] < nums[i+1]).
 * This identifies the suffix that is currently maximized (descending).
 * 2. Find Successor: If such an 'i' exists (meaning the array isn't entirely
 * descending), we look for the smallest number in the suffix that is larger than
 * nums[i]. We do this by iterating backwards again from the end to find the first
 * 'j' where nums[j] > nums[i].
 * 3. Swap: We swap nums[i] and nums[j]. This increments the prefix to the next
 * smallest possibility.
 * 4. Reverse: The suffix starting at i+1 is currently in descending order.
 * To get the smallest permutation for this new prefix, we reverse the suffix
 * to make it ascending.
 * 5. Edge Case: If no pivot 'i' is found (loop ends with i = -1), it means the
 * entire array is in descending order (e.g., [3, 2, 1]). In this case, we skip
 * the swap logic and simply reverse the whole array to get the lowest possible
 * order (e.g., [1, 2, 3]).
 * * Time Complexity: O(n)
 * We traverse the array roughly twice (once to find the pivot, once to reverse),
 * so it is linear time.
 * * Space Complexity: O(1)
 * The modifications are done in-place.
 */