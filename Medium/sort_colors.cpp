#include <vector>
#include <algorithm>

class Solution {
public:
    void sortColors(std::vector<int>& nums) {
        int low = 0;
        int mid = 0;
        int high = nums.size() - 1;

        while (mid <= high) {
            if (nums[mid] == 0) {

                std::swap(nums[low], nums[mid]);
                low++;
                mid++;
            } else if (nums[mid] == 1) {

                mid++;
            } else {
                std::swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};

/*
 * Approach: Dutch National Flag Algorithm (Three Pointers)
 * * Logic:
 * 1. Partitions: We divide the array into four regions:
 * - nums[0...low-1]: Region of 0s.
 * - nums[low...mid-1]: Region of 1s.
 * - nums[mid...high]: Unsorted/Unknown region being processed.
 * - nums[high+1...n-1]: Region of 2s.
 * 2. Pointers: We use 'low' and 'high' as boundaries and 'mid' as the scanner.
 * 3. Processing: We iterate with 'mid' as long as it hasn't crossed 'high'.
 * - If nums[mid] == 0, we swap it into the 0s region by moving it to 'low',
 * and increment both 'low' and 'mid'.
 * - If nums[mid] == 1, it belongs in the middle region, so we simply increment 'mid'.
 * - If nums[mid] == 2, we swap it into the 2s region by moving it to 'high',
 * and decrement 'high'. We must NOT increment 'mid' because the element
 * swapped into the current 'mid' position is an unknown that must be checked
 * in the next iteration.
 * * Time Complexity: O(N)
 * We traverse the array with the 'mid' pointer exactly once.
 * * Space Complexity: O(1)
 * We modify the array in-place and use only three integer pointers.
 */