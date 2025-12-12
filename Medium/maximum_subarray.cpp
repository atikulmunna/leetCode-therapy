#include <vector>
#include <algorithm>

class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        int maxSum = nums[0];
        int currentSum = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            currentSum = std::max(nums[i], currentSum + nums[i]);
            maxSum = std::max(maxSum, currentSum);
        }

        return maxSum;
    }
};

/*
 * Approach: Kadane's Algorithm (Dynamic Programming)
 * * Logic:
 * 1. We start by initializing 'maxSum' and 'currentSum' to the first element
 * of the array. This handles the edge case where the array contains only one
 * number (even if negative).
 * 2. We iterate from the second element (index 1) to the end.
 * 3. The Core Decision (currentSum): At each step 'i', we calculate
 * max(nums[i], currentSum + nums[i]).
 * - This effectively decides whether to extend the previous subarray
 * (currentSum + nums[i]) or start a brand new subarray at the current
 * position (nums[i]).
 * - If 'currentSum' was negative before adding nums[i], adding it would only
 * make the result smaller than nums[i] alone. So, we discard the history
 * and restart.
 * 4. The Global Maximum (maxSum): After updating 'currentSum', we check if
 * this new local maximum is better than the global maximum found so far.
 * * Time Complexity: O(n)
 * We traverse the array exactly once.
 * * Space Complexity: O(1)
 * We only use two variables for tracking state.
 */