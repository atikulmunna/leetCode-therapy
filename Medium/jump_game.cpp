#include <vector>
#include <algorithm>

class Solution {
public:
    bool canJump(std::vector<int>& nums) {
        int maxReach = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {

            if (i > maxReach) {
                return false;
            }


            maxReach = std::max(maxReach, i + nums[i]);


            if (maxReach >= n - 1) {
                return true;
            }
        }

        return true;
    }
};

/*
 * Approach: Greedy
 * * Logic:
 * 1. We maintain a variable 'maxReach' that tracks the furthest index we can
 * possibly jump to, given the path we have traversed so far.
 * 2. We iterate through the array index by index.
 * 3. Failure Condition: At any index 'i', if 'i > maxReach', it implies that
 * there is no way to reach this index from the starting point. The "chain"
 * of jumps is broken. We return false.
 * 4. Update: If the index is reachable, we calculate the potential reach from
 * this specific spot (i + nums[i]). We update 'maxReach' if this new jump
 * extends our horizon.
 * 5. Success Condition: If the loop finishes (or maxReach covers the last index),
 * it means the end is reachable.
 * * Time Complexity: O(n)
 * We verify each element exactly once.
 * * Space Complexity: O(1)
 * We use only one variable to track the state.
 */