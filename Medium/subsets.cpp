#include <vector>
#include <algorithm>

class Solution {
private:
    void backtrack(std::vector<int>& nums, int start, std::vector<int>& current_subset, std::vector<std::vector<int>>& result) {

        result.push_back(current_subset);
        for (int i = start; i < nums.size(); i++) {
            current_subset.push_back(nums[i]);

            backtrack(nums, i + 1, current_subset, result);

            current_subset.pop_back();
        }
    }

public:
    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        std::vector<int> current_subset;
        backtrack(nums, 0, current_subset, result);

        return result;
    }
};

/*
 * Approach: Backtracking (Depth-First Search)
 * * Logic:
 * 1. Concept: The problem asks for all possible subsets. This is a classic
 * "Power Set" problem. We can view this as a decision tree where, for each
 * element in the input array, we decide whether to include it or not.
 * 2. Recursive Structure:
 * - The 'backtrack' function takes a 'start' index, which tracks where we
 * are in the input array.
 * - Unlike problems that look for a specific size (like Combinations k),
 * EVERY node in our recursion tree represents a valid subset. Therefore,
 * we 'result.push_back(current_subset)' at the very beginning of the
 * function call, before any loops.
 * 3. The Loop:
 * - We iterate from 'start' to the end of the array.
 * - In each iteration 'i', we consider 'nums[i]' as a candidate to add to
 * our current subset.
 * 4. Backtracking Steps:
 * - Choose: Add nums[i] to 'current_subset'.
 * - Recurse: Call backtrack with 'i + 1'. This moves the window forward
 * so we don't reuse the same element (sets contain unique items from indices).
 * - Unchoose: Remove nums[i] (pop_back). This returns the 'current_subset'
 * to its previous state, allowing the loop to proceed to the next number
 * and form a different subset.
 * * Time Complexity: O(N * 2^N)
 * There are 2^N possible subsets. For each subset, we copy it into the result
 * list, which takes O(N) time on average.
 * * Space Complexity: O(N)
 * We use O(N) space for the recursion stack and to store the 'current_subset' temporary vector.
 */