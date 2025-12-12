#include <vector>
#include <algorithm>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) {
            return n;
        }
        int i = 2;
        for (int j = 2; j < n; j++) {

            if (nums[j] > nums[i - 2]) {
                nums[i] = nums[j];
                i++;
            }
        }
        return i;
    }
};

/*
 * Approach: Two Pointers (Slow 'i' and Fast 'j')
 * * Logic:
 * 1. Constraints: The input array is sorted, and we must perform the modification in-place
 * with O(1) extra space, allowing duplicates up to two times.
 * 2. Pointers Initialization:
 * - The first two elements (nums[0] and nums[1]) are always valid, so the final
 * array length will be at least 2. We start the slow pointer 'i' at index 2.
 * - The fast pointer 'j' starts at index 2 to scan the rest of the array.
 * 3. The Core Condition: The comparison is between nums[j] (the element being checked)
 * and nums[i-2] (the element two steps behind the current placement position).
 * - If nums[j] > nums[i-2], it means the value at nums[j] is either a completely
 * new number or it is the second instance of the number at nums[i-1]. In both cases,
 * it is valid to include it. We place nums[j] at nums[i] and advance 'i'.
 * - If nums[j] == nums[i-2], it means this is the third time the same number has
 * appeared in a row (or more). We skip this element by only advancing 'j' and not 'i'.
 * 4. Result: The final value of 'i' is the new length of the array, as 'i' tracks
 * the position immediately after the last valid element.
 * * Time Complexity: O(N)
 * We traverse the array exactly once with the fast pointer 'j'.
 * * Space Complexity: O(1)
 * The modification is done in-place.
 */
