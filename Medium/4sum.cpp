#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
        std::vector<std::vector<int>> result;
        int n = nums.size();

        if (n < 4) return result;

        std::sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            for (int j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                int left = j + 1;
                int right = n - 1;

                while (left < right) {
                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];

                    if (sum == target) {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});

                        while (left < right && nums[left] == nums[left + 1]) left++;
                        while (left < right && nums[right] == nums[right - 1]) right--;

                        left++;
                        right--;
                    } else if (sum < target) {
                        left++;
                    } else {
                        right--;
                    }
                }
            }
        }

        return result;
    }
};

/*
 * Approach: Sorting + Double Loop + Two Pointers
 * * Logic:
 * 1. Sorting: We sort the array first (O(N log N)) to group duplicates and enable
 * the two-pointer technique.
 * 2. Fixing Two Numbers: Unlike 3Sum where we fix one number, here we fix two numbers
 * using nested loops (indices 'i' and 'j').
 * 3. Two Pointers: For the remaining part of the array (from j+1 to end), we use
 * 'left' and 'right' pointers to find the last two numbers that satisfy the target sum.
 * 4. Overflow Protection (CRITICAL): The constraints state that numbers can be up to 10^9.
 * Adding four such numbers can result in 4*10^9, which exceeds the limit of a
 * standard signed 32-bit integer (~2*10^9). We cast values to 'long long' during
 * the sum calculation to prevent overflow errors.
 * 5. Duplicate Handling:
 * - Loop 'i': Skip if nums[i] == nums[i-1].
 * - Loop 'j': Skip if nums[j] == nums[j-1] (but ensure j > i+1).
 * - Pointers: When a match is found, loop 'left' forward and 'right' backward
 * past identical values to avoid duplicate quadruplets.
 * * Time Complexity: O(n^3)
 * We have two nested loops and a linear two-pointer scan inside.
 * * Space Complexity: O(1)
 * Ignoring the space required for sorting and the output vector.
 */