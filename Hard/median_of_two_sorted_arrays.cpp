#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size();
        int n = nums2.size();
        int low = 0, high = m;

        while (low <= high) {
            int partitionX = (low + high) / 2;
            int partitionY = (m + n + 1) / 2 - partitionX;

            int maxLeftX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
            int minRightX = (partitionX == m) ? INT_MAX : nums1[partitionX];

            int maxLeftY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
            int minRightY = (partitionY == n) ? INT_MAX : nums2[partitionY];

            if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
                if ((m + n) % 2 == 0) {
                    return (double)(std::max(maxLeftX, maxLeftY) + std::min(minRightX, minRightY)) / 2;
                } else {
                    return (double)std::max(maxLeftX, maxLeftY);
                }
            } else if (maxLeftX > minRightY) {
                high = partitionX - 1;
            } else {
                low = partitionX + 1;
            }
        }

        return 0.0;
    }
};

/*
 * Approach: Binary Search on Partition
 * * Logic:
 * 1. We always perform binary search on the smaller array (nums1) to minimize complexity.
 * If nums1 is larger, we recursively swap them.
 * 2. We try to find a "partition" (cut) in nums1. Based on this cut, the cut in nums2 
 * is automatically calculated to ensure the "Left Half" has (m + n + 1) / 2 elements.
 * 3. We check if the partition is valid by comparing the elements around the cut:
 * - maxLeftX <= minRightY
 * - maxLeftY <= minRightX
 * 4. We use INT_MIN and INT_MAX to handle edge cases where the partition falls 
 * at index 0 (nothing on left) or index m (nothing on right).
 * 5. If the condition is met, we calculate the median:
 * - If total length is even: Average of max(Lefts) and min(Rights).
 * - If total length is odd: max(Lefts).
 * 6. If maxLeftX > minRightY, we are too far right in nums1, so we move left (high = partitionX - 1).
 * 7. Otherwise, we move right (low = partitionX + 1).
 * * Time Complexity: O(log(min(m, n)))
 * We partition the smaller array of size m.
 * * Space Complexity: O(1)
 * We only store a few integer variables for indices and values.
 */