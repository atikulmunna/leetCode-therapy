#include <vector>
#include <algorithm>

class Solution {
public:
    int firstMissingPositive(std::vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                std::swap(nums[i], nums[nums[i] - 1]);
            }
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        return n + 1;
    }
};

/*
 * Approach: Cyclic Sort (In-Place Indexing)
 * * Logic:
 * 1. Constraint Analysis: We need O(n) time and O(1) space. This suggests we
 * cannot use a separate Hash Set or boolean array. We must use the input
 * array itself to store information.
 * 2. The Ideal State: In a perfect scenario, an array of size n would contain
 * numbers [1, 2, ..., n] such that nums[i] == i + 1.
 * 3. Phase 1 (Rearrangement): We iterate through the array. For every number 'x':
 * - If x is between 1 and n (inclusive), it belongs at index 'x - 1'.
 * - We check if the target position (nums[x-1]) already holds the correct number 'x'.
 * - If not, we SWAP the current number with the number at the target position.
 * - We repeat this SWAP logic in a while loop for the current index 'i' because
 * the number we just swapped *in* might also be misplaced and need moving.
 * 4. Phase 2 (Scan): After rearrangement, we scan the array from left to right.
 * - The first index 'i' where nums[i] != i + 1 indicates that the number 'i + 1'
 * is missing.
 * 5. Phase 3 (Edge Case): If the loop finishes without finding a mismatch,
 * it means the array contains [1, 2, ..., n]. The missing number is n + 1.
 * * Time Complexity: O(n)
 * Although there is a while loop inside the for loop, each number is swapped
 * to its correct position at most once. The amortized complexity is linear.
 * * Space Complexity: O(1)
 * We modify the array in-place.
 */