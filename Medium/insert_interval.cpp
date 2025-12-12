#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> insert(std::vector<std::vector<int>>& intervals, std::vector<int>& newInterval) {
        std::vector<std::vector<int>> result;
        int n = intervals.size();
        int i = 0;

        while (i < n && intervals[i][1] < newInterval[0]) {
            result.push_back(intervals[i]);
            i++;
        }

        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = std::min(newInterval[0], intervals[i][0]);
            newInterval[1] = std::max(newInterval[1], intervals[i][1]);
            i++;
        }
        result.push_back(newInterval);

        while (i < n) {
            result.push_back(intervals[i]);
            i++;
        }

        return result;
    }
};

/*
 * Approach: Linear Scan (Three Stages)
 * * Logic:
 * 1. The problem guarantees the input list is sorted. This allows us to process
 * the intervals in a linear pass (O(N)).
 * 2. Stage 1 (Left): We iterate through the intervals. As long as the current
 * interval ends before the 'newInterval' starts (intervals[i][1] < newInterval[0]),
 * there is no overlap. We simply push these valid intervals into our result.
 * 3. Stage 2 (Merge): Once the loop breaks, we have hit the overlap zone (or the
 * position where the new interval belongs). We continue iterating as long as the
 * current interval's start time is <= newInterval's end time.
 * - Inside this loop, we merge the intervals by updating 'newInterval' to cover
 * the minimum start and maximum end.
 * - We do NOT push to result yet, because the merged interval might continue
 * to consume subsequent intervals.
 * 4. After the merge loop finishes, 'newInterval' is fully consolidated. We push
 * it to the result.
 * 5. Stage 3 (Right): We push all remaining intervals (which are guaranteed to
 * be to the right of the merged interval) into the result.
 * * Time Complexity: O(N)
 * We process each interval exactly once.
 * * Space Complexity: O(1)
 * Excluding the output vector, we use constant extra space.
 */