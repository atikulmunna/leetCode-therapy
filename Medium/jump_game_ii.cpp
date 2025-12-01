#include <vector>
#include <algorithm>

class Solution {
public:
    int jump(std::vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        int jumps = 0;
        int currentEnd = 0;
        int farthest = 0;

        for (int i = 0; i < n - 1; i++) {
            farthest = std::max(farthest, i + nums[i]);

            if (i == currentEnd) {
                jumps++;
                currentEnd = farthest;
            }
        }

        return jumps;
    }
};

/*
 * Approach: Greedy BFS (Breadth-First Search)
 * * Logic:
 * 1. Instead of trying every path (DFS) or standard DP (O(N^2)), we use a Greedy
 * approach that runs in O(N).
 * 2. We maintain a "window" of indices that are reachable with the current number
 * of jumps.
 * 3. 'currentEnd' marks the boundary of the current jump level.
 * 4. 'farthest' tracks the maximum index we can reach from ANY index within the
 * current window.
 * 5. We iterate through the array from 0 to n-2 (we stop before the last index
 * because we are counting jumps *to* the end).
 * 6. At every step 'i', we update 'farthest' = max(farthest, i + nums[i]).
 * 7. When 'i' reaches 'currentEnd', it means we have finished processing all
 * possibilities for the current jump count. We must take another jump to proceed
 * further.
 * 8. We increment 'jumps' and update 'currentEnd' to 'farthest'.
 * * Time Complexity: O(N)
 * We traverse the array exactly once.
 * * Space Complexity: O(1)
 * We use constant extra space variables.
 */