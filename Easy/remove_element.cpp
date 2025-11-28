class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[k] = nums[i];
                k++;
            }
        }

        return k;
    }
};

/*
 * Approach: Two Pointers (Reader/Writer)
 * * Logic:
 * 1. We use a 'writer' pointer 'k' initialized to 0. This tracks the position
 * where the next non-val element should be placed.
 * 2. We iterate through the array using a 'reader' pointer 'i'.
 * 3. For every element 'nums[i]', we check if it equals 'val'.
 * - If it equals 'val', we skip it (do nothing).
 * - If it does not equal 'val', it is a valid element. We copy it to
 * position 'nums[k]' and increment 'k'.
 * 4. This effectively overwrites the "removed" elements with the valid ones
 * at the front of the array.
 * 5. Finally, 'k' represents the count of valid elements.
 * * Time Complexity: O(n)
 * We traverse the array exactly once.
 * * Space Complexity: O(1)
 * We modify the array in-place using constant extra space.
 */