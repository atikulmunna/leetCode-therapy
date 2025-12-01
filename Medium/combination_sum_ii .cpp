#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
        std::vector<std::vector<int>> result;
        std::vector<int> currentPath;

        std::sort(candidates.begin(), candidates.end());

        solve(candidates, target, 0, currentPath, result);
        return result;
    }

private:
    void solve(std::vector<int>& candidates, int target, int index,
               std::vector<int>& currentPath, std::vector<std::vector<int>>& result) {

        if (target == 0) {
            result.push_back(currentPath);
            return;
        }

        for (int i = index; i < candidates.size(); i++) {
            if (candidates[i] > target) {
                break;
            }

            if (i > index && candidates[i] == candidates[i - 1]) {
                continue;
            }

            currentPath.push_back(candidates[i]);
            solve(candidates, target - candidates[i], i + 1, currentPath, result);
            currentPath.pop_back();
        }
    }
};

/*
 * Approach: Backtracking with Duplicate Handling
 * * Logic:
 * 1. Sorting: We sort the candidates array first. This is mandatory to handle
 * duplicates efficiently and allows for optimization (breaking early).
 * 2. Recursion State: We track the current 'target', the current 'index' in the
 * array, and the 'currentPath' of numbers selected.
 * 3. Base Case: If target is 0, we found a valid combination. Add to result.
 * 4. The Loop: We iterate through candidates starting from 'index'.
 * 5. Optimization: If candidates[i] > target, we break. Since the array is sorted,
 * all subsequent numbers are also too large.
 * 6. Duplicate Skip (CRITICAL):
 * - We check: if (i > index && candidates[i] == candidates[i-1]).
 * - 'i > index' ensures we are not checking the very first element chosen
 * in this specific recursive step. We only care about skipping duplicates *after* * the first instance has been processed at this level.
 * - This prevents generating identical branches in the decision tree.
 * 7. Recurse: We call solve with 'i + 1' (not 'i') because each element can
 * only be used once.
 * 8. Backtrack: Remove the last element to explore other possibilities.
 * * Time Complexity: O(2^N)
 * In the worst case, we explore a subset tree. Sorting takes O(N log N).
 * * Space Complexity: O(N)
 * The recursion depth can go up to N.
 */