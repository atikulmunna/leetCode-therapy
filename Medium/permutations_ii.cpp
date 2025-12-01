#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        std::vector<int> current;
        std::vector<bool> used(nums.size(), false);

        std::sort(nums.begin(), nums.end());

        solve(nums, used, current, result);
        return result;
    }

private:
    void solve(std::vector<int>& nums, std::vector<bool>& used, std::vector<int>& current, std::vector<std::vector<int>>& result) {
        if (current.size() == nums.size()) {
            result.push_back(current);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue;

            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) {
                continue;
            }

            used[i] = true;
            current.push_back(nums[i]);

            solve(nums, used, current, result);

            used[i] = false;
            current.pop_back();
        }
    }
};

/*
 * Approach: Backtracking with "Used" Array
 * * Logic:
 * 1. Sorting: We sort the array first. This is crucial because it places duplicate
 * numbers next to each other, allowing us to easily check for redundancy.
 * 2. State Tracking: Unlike the previous problem (where we swapped elements), here
 * we build the permutation in a separate 'current' vector. We use a boolean 'used'
 * array to track which indices from the original 'nums' are included in the current path.
 * 3. Base Case: When 'current' size matches 'nums' size, we store the result.
 * 4. Iteration: We loop through the 'nums' array.
 * 5. Pruning (The Duplicate Logic):
 * - Condition 1: If 'used[i]' is true, we skip (can't reuse the same physical item).
 * - Condition 2: if (i > 0 && nums[i] == nums[i-1] && !used[i-1]).
 * - Explanation: This condition handles the duplicates. If the current number is
 * the same as the previous one, and the previous one is NOT used, it means we have
 * already explored the recursive branch starting with that value (in the previous
 * iteration of this loop). Starting another branch with the same value would produce
 * identical results. Therefore, we skip it.
 * 6. Backtrack: We mark the item as used, recurse, and then unmark it (backtrack)
 * to allow the next iteration to use it.
 * * Time Complexity: O(N * N!)
 * In the worst case (no duplicates), it is the same as standard permutations.
 * Duplicates significantly prune the tree.
 * * Space Complexity: O(N)
 * For the 'used' array and recursion stack.
 */