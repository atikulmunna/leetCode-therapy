#include <vector>

class Solution {
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        int p1 = m - 1;
        int p2 = n - 1;
        int p = m + n - 1;

        while (p2 >= 0) {
            if (p1 >= 0 && nums1[p1] > nums2[p2]) {
                nums1[p] = nums1[p1];
                p1--;
            } else {
                nums1[p] = nums2[p2];
                p2--;
            }
            p--;
        }
    }
};

/*
 * Approach: Two Pointers (Reverse Order)
 * * Logic:
 * 1. Strategy: Since 'nums1' has enough space at the end to hold 'nums2',
 * we can merge the arrays in-place. However, merging from the front would
 * require shifting elements (O(N^2)). Merging from the back (largest to smallest)
 * allows us to place elements directly into their final positions without
 * overwriting data in 'nums1' that hasn't been read yet.
 * 2. Pointers:
 * - 'p1' tracks the current largest element in the valid part of 'nums1'.
 * - 'p2' tracks the current largest element in 'nums2'.
 * - 'p' tracks the insertion position (starting from the very end of nums1).
 * 3. Loop:
 * - We iterate as long as 'nums2' still has elements (p2 >= 0).
 * - We compare nums1[p1] and nums2[p2]. We place the larger of the two into nums1[p].
 * 4. Edge Case (p1 runs out):
 * - If 'p1' becomes < 0 (all valid nums1 elements are used), the 'if' condition fails,
 * and we naturally copy the rest of 'nums2' into the remaining slots.
 * - If 'p2' becomes < 0 first, the loop ends, and any remaining elements in 'nums1'
 * are already in their correct sorted places.
 * * Time Complexity: O(M + N)
 * We iterate through both arrays once.
 * * Space Complexity: O(1)
 * We modify nums1 in-place.
 */