#include <vector>
#include <algorithm>

class Solution {
private:
    void backtrack(int n, int k, int start, std::vector<int>& current_combination, std::vector<std::vector<int>>& result) {

        if (current_combination.size() == k) {
            result.push_back(current_combination);
            return;
        }

        for (int i = start; i <= n; ++i) {

            if (k - current_combination.size() > n - i + 1) {

                break;
            }

            current_combination.push_back(i);

            backtrack(n, k, i + 1, current_combination, result);
            current_combination.pop_back();
        }
    }

public:
    std::vector<std::vector<int>> combine(int n, int k) {
        std::vector<std::vector<int>> result;
        std::vector<int> current_combination;

        backtrack(n, k, 1, current_combination, result);

        return result;
    }
};

/*
 * Approach: Backtracking (Depth-First Search)
 * * Logic:
 * 1. Backtracking Framework: The solution uses a recursive helper function
 * (backtrack) to explore the solution space tree. Each level of recursion
 * corresponds to selecting one number for the combination.
 * 2. State Variables:
 * - 'n' and 'k' are the fixed constraints.
 * - 'start' (initially 1) tracks the smallest number we can choose in the
 * current step. By starting the loop at 'start' and passing 'i + 1' in the
 * recursive call, we ensure that:
 * a) We avoid duplicate permutations (e.g., [1, 2] vs [2, 1]).
 * b) We only explore combinations where numbers are in increasing order.
 * 3. Base Case: The recursion stops when the 'current_combination' vector
 * has exactly 'k' elements. The combination is complete and is added to 'result'.
 * 4. Backtracking Action: The crucial step is the 'pop_back()' after the
 * recursive call returns. This removes the last choice made, allowing the
 * loop to try the next number (i+1) in the current level, which is the core
 * mechanism of backtracking.
 * 5. Optimization (Pruning): The 'if' check within the loop is a pruning technique.
 * If the number of elements still needed ('k - current_size') is greater than
 * the number of elements remaining in the pool ('n - i + 1'), we know we
 * cannot complete the combination, so we break the loop early, saving time.
 * * Time Complexity: O(C(n, k) * k)
 * We generate C(n, k) total combinations, and it takes O(k) time to copy
 * each combination into the result list.
 * * Space Complexity: O(C(n, k) * k)
 * To store all the combinations in the result list. O(k) space is also
 * used for the recursion stack depth.
 */