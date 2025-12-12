#include <algorithm>

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;

        int left = 1;
        int right = x;
        int result = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (mid <= x / mid) {
                result = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return result;
    }
};

/*
 * Approach: Binary Search
 * * Logic:
 * 1. Monotonicity: The square of a non-negative number increases as the number
 * increases. This sorted property allows us to use Binary Search.
 * 2. Range: The square root of x is always between 0 and x.
 * 3. The Loop: We pick a 'mid' point.
 * - If mid * mid <= x: It means 'mid' is a valid candidate for the integer square root
 * (it's less than or equal to the true root). We store it in 'result' and try
 * to find a larger number that still satisfies the condition (move 'left' up).
 * - If mid * mid > x: It means 'mid' is strictly larger than the true root.
 * We must look in the lower half (move 'right' down).
 * 4. Overflow Prevention: Instead of computing 'mid * mid', which might overflow
 * a 32-bit integer if mid is large (e.g., near 2^16), we check 'mid <= x / mid'.
 * * Time Complexity: O(log x)
 * We cut the search space in half with every iteration.
 * * Space Complexity: O(1)
 * We use constant extra space.
 */