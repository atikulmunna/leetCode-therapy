#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        solve(nums, 0, result);
        return result;
    }

private:
    void solve(std::vector<int>& nums, int start, std::vector<std::vector<int>>& result) {
        if (start == nums.size()) {
            result.push_back(nums);
            return;
        }

        for (int i = start; i < nums.size(); i++) {
            std::swap(nums[start], nums[i]);
            solve(nums, start + 1, result);
            std::swap(nums[start], nums[i]);
        }
    }
};

/*
 * Approach: Backtracking via Swapping
 * * Logic:
 * 1. We view the problem as placing numbers into positions one by one.
 * 2. The function 'solve' takes a 'start' index, which represents the
 * position we are currently trying to fill.
 * 3. We iterate through the array from 'start' to the end. In each iteration 'i',
 * we treat 'nums[i]' as the candidate for the 'start' position.
 * 4. Step 1 (Choose): We swap 'nums[start]' and 'nums[i]'. This effectively
 * fixes 'nums[i]' at the current position.
 * 5. Step 2 (Explore): We recursively call 'solve' for 'start + 1'. This tells
 * the function to go fill the *next* slot.
 * 6. Base Case: When 'start' equals the size of the array, it means all positions
 * are filled. We copy the current state of 'nums' into our result list.
 * 7. Step 3 (Un-choose/Backtrack): After the recursive call returns, we swap
 * 'nums[start]' and 'nums[i]' again. This restores the array to the state it
 * was in before the swap, allowing the loop to proceed and try the next candidate.
 * * Time Complexity: O(N * N!)
 * There are N! permutations. For each permutation, we take O(N) time to copy
 * the array into the result.
 * * Space Complexity: O(N)
 * The recursion stack depth is N.
 */