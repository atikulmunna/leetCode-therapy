#include <vector>

class Solution {
public:
    std::vector<int> grayCode(int n) {
        std::vector<int> result;
        result.reserve(1 << n);
        result.push_back(0);

        for (int i = 0; i < n; ++i) {
            int currentSize = result.size();
            int mask = 1 << i;

            for (int j = currentSize - 1; j >= 0; --j) {
                result.push_back(result[j] | mask);
            }
        }
        return result;
    }
};

/*
 * Approach: Iterative Reflection (Mirroring)
 * * Logic:
 * 1. Base Case: Start with the sequence [0] for n=0 (conceptually).
 * 2. Iteration: To generate the sequence for the i-th bit (from 0 to n-1):
 * - We take the existing sequence generated so far.
 * - We iterate through this existing sequence BACKWARDS (reflecting it).
 * - For each element in the backward traversal, we set the i-th bit (OR with 1 << i).
 * - We append this new value to the sequence.
 * 3. Why it works:
 * - The original part of the sequence already satisfies the Gray code property.
 * - The new mirrored part satisfies it because it's just the original sequence reversed.
 * - The critical junction (where original ends and mirror begins) satisfies the property:
 * The last element of the original is 'x'. The first element of the new part is 'x | mask'.
 * They differ by exactly one bit (the mask bit).
 * * Time Complexity: O(2^n)
 * We generate exactly 2^n integers.
 * * Space Complexity: O(1)
 * Excluding the space required for the output vector.
 */