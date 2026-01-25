#include <vector>
#include <algorithm>

class Solution {
private:
    void backtrack(std::vector<int>& nums, int start, std::vector<int>& current, std::vector<std::vector<int>>& result) {
        result.push_back(current);

        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i - 1]) {
                continue;
            }

            current.push_back(nums[i]);
            backtrack(nums, i + 1, current, result);
            current.pop_back();
        }
    }

public:
    std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        std::vector<int> current;

        std::sort(nums.begin(), nums.end());

        backtrack(nums, 0, current, result);

        return result;
    }
};

/*
 * Approach: Backtracking with Duplicate Pruning
 * * Logic:
 * 1. Sorting: We sort the input array first. This clusters duplicates together
 * so we can easily identify them during traversal.
 * 2. Backtracking Structure: Similar to "Subsets I", we explore the decision tree.
 * Since every node in the tree represents a valid subset, we add 'current' to
 * 'result' at the start of the helper function.
 * 3. Duplicate Handling (Pruning):
 * - Inside the loop, we iterate through candidate numbers to add to the subset.
 * - The condition 'if (i > start && nums[i] == nums[i - 1])' is the key.
 * - 'i > start': Ensures we don't skip the first instance of a number in the
 * current recursion level (we *can* pick duplicates like [2, 2]).
 * - 'nums[i] == nums[i - 1]': Checks if the current number is a duplicate of
 * the previous one. If we skip the first '2' and pick the second '2' for the
 * same position, we would generate a duplicate subset. Thus, we skip it.
 * * Time Complexity: O(N * 2^N)
 * Sorting takes O(N log N). In the worst case (all unique), we generate 2^N
 * subsets, and copying each takes O(N).
 * * Space Complexity: O(N)
 * For the recursion stack and the temporary 'current' vector.
 */