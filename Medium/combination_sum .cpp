#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
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

            currentPath.push_back(candidates[i]);
            solve(candidates, target - candidates[i], i, currentPath, result);
            currentPath.pop_back();
        }
    }
};


/*
 * Approach: Backtracking with Pruning
 * * Logic:
 * 1. We treat this as a depth-first search on a decision tree.
 * 2. We maintain a 'target' that decreases as we add numbers to our path.
 * 3. To avoid duplicate combinations (like [2,3] and [3,2]), we pass an 'index'
 * variable to the recursive function. The loop inside the function starts from
 * 'index', ensuring we never pick a number that appears *before* our current
 * position in the candidates array.
 * 4. We sort the candidates array at the beginning. This allows a critical optimization:
 * inside the loop, if candidates[i] > target, we can break immediately. We don't
 * need to check the rest of the array because they will definitely be larger
 * and thus invalid.
 * 5. Recursion Step: When we pick a number, we call the function recursively
 * with the SAME index 'i'. This enables the "unlimited use" of the current number.
 * 6. Backtracking Step: After the recursive call returns, we pop the last element
 * off the 'currentPath' to "clean up" before the loop moves to the next candidate.
 * * Time Complexity: O(N^(T/M))
 * N is the number of candidates, T is the target, M is the minimum value in candidates.
 * It is exponential, but pruned heavily in practice.
 * * Space Complexity: O(T/M)
 * This is the maximum depth of the recursion stack (longest possible combination).
 */