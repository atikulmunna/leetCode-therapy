#include <vector>
#include <algorithm>
#include <cmath>

class Solution {
public:
    int threeSumClosest(std::vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        int closestSum = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < nums.size() - 2; i++) {
            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right) {
                int currentSum = nums[i] + nums[left] + nums[right];

                if (std::abs(target - currentSum) < std::abs(target - closestSum)) {
                    closestSum = currentSum;
                }

                if (currentSum < target) {
                    left++;
                } else if (currentSum > target) {
                    right--;
                } else {
                    return currentSum;
                }
            }
        }

        return closestSum;
    }
};

/*
 * Approach: Sorting with Two Pointers (Minimizing Distance)
 * * Logic:
 * 1. Sorting: We sort the array first. This is required to use the two-pointer
 * technique effectively.
 * 2. Initialization: We arbitrarily pick the sum of the first three elements as
 * our initial 'closestSum' to have a baseline for comparison.
 * 3. Iteration: We loop through the array with index 'i' (fixing the first number).
 * 4. Two Pointers: We set 'left' (i + 1) and 'right' (end of array) to find the
 * other two numbers.
 * 5. Update Closest: In every step, we calculate 'currentSum'. We check if the
 * absolute difference (|target - currentSum|) is smaller than our current best record.
 * If it is, we update 'closestSum'.
 * 6. Move Pointers:
 * - If currentSum < target, we are too low. Increment 'left' to increase the sum.
 * - If currentSum > target, we are too high. Decrement 'right' to decrease the sum.
 * - If currentSum == target, the distance is 0. We cannot do better, so return immediately.
 * * Time Complexity: O(n^2)
 * Sorting takes O(n log n), and the nested loop structure takes O(n^2).
 * * Space Complexity: O(1)
 * We use constant extra space (ignoring the space required for sorting).
 */