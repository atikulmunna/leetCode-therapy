#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        int n = nums.size();

        std::sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum < 0) {
                    left++;
                } else if (sum > 0) {
                    right--;
                } else {
                    result.push_back({nums[i], nums[left], nums[right]});

                    while (left < right && nums[left] == nums[left + 1]) {
                        left++;
                    }
                    while (left < right && nums[right] == nums[right - 1]) {
                        right--;
                    }

                    left++;
                    right--;
                }
            }
        }

        return result;
    }
};

/*
 * Approach: Sorting + Two Pointers
 * * Logic:
 * 1. Sorting: We sort the array first. This takes O(N log N) but enables the
 * two-pointer technique and makes handling duplicates much easier.
 * 2. Fixing 'i': We iterate through the array, treating nums[i] as the first
 * element of the triplet.
 * 3. Two Pointers: For every 'i', we define 'left' (i+1) and 'right' (end).
 * We try to find two numbers that sum to -nums[i].
 * 4. Movement:
 * - If sum < 0: We need a larger number, so increment 'left'.
 * - If sum > 0: We need a smaller number, so decrement 'right'.
 * - If sum == 0: We found a triplet. Add it to results.
 * 5. Duplicate Handling (CRITICAL):
 * - Outer loop: If nums[i] == nums[i-1], skip iteration to avoid processing
 * the same first number twice.
 * - Inner loop: After finding a match, loop 'left' forward and 'right' backward
 * past any identical numbers to ensure the triplet is unique.
 * * Time Complexity: O(n^2)
 * Sorting is O(n log n). The nested loops are O(n^2). The overall complexity
 * is dominated by the loops.
 * * Space Complexity: O(1) or O(n)
 * Depends on the sorting implementation. We ignore the space taken by the output.
 */