class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;

        int k = 1;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) {
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
 * 1. Since the array is sorted, duplicates are always adjacent.
 * 2. We keep the first element (index 0) as it is effectively the first unique number.
 * 3. We initialize a 'writer' pointer (k) at index 1. This tracks the position
 * where the next unique element should be placed.
 * 4. We iterate through the array with a 'reader' pointer (i) starting from index 1.
 * 5. Comparison: We check if nums[i] is different from nums[i-1].
 * - If they are equal, nums[i] is a duplicate, so we ignore it.
 * - If they are not equal, nums[i] is a new unique number. We copy it to
 * the position 'nums[k]' and increment 'k'.
 * 6. By the end of the loop, the first 'k' elements are the unique numbers in
 * sorted order. We return 'k'.
 * * Time Complexity: O(n)
 * We traverse the array exactly once.
 * * Space Complexity: O(1)
 * We modify the array in-place without using extra data structures.
 */