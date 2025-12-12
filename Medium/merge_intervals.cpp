#include <vector>
#include <algorithm>
#include <cmath>

class Solution {
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
        if (intervals.empty()) return {};

        std::sort(intervals.begin(), intervals.end());

        std::vector<std::vector<int>> merged;
        merged.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++) {

            std::vector<int>& last = merged.back();
            std::vector<int>& current = intervals[i];


            if (current[0] <= last[1]) {

                last[1] = std::max(last[1], current[1]);
            } else {

                merged.push_back(current);
            }
        }

        return merged;
    }
};

/*
 * Approach: Sorting
 * * Logic:
 * 1. Sorting: The key to this problem is sorting the intervals by their start times.
 * This ensures that if intervals overlap, they will appear consecutively in the array.
 * 2. Initialization: We create a 'merged' vector and seed it with the first interval
 * from the sorted list.
 * 3. Iteration: We loop through the remaining intervals.
 * 4. Comparison: We compare the 'current' interval with the 'last' interval in
 * our 'merged' list.
 * 5. Overlap Condition: If current[0] <= last[1] (i.e., the current interval starts
 * before or exactly when the previous one ends), we merge them.
 * - Merging means updating the 'end' time of the 'last' interval to be the
 * maximum of the two end times. (We don't change the start time because, due to
 * sorting, the 'last' interval is guaranteed to have the earlier start time).
 * 6. Disjoint Condition: If there is no overlap, we simply push the 'current'
 * interval onto the 'merged' list.
 * * Time Complexity: O(N log N)
 * Dominated by the sorting step. The iteration itself is O(N).
 * * Space Complexity: O(N)
 * Or O(log N) depending on the sorting implementation, to store the output.
 */