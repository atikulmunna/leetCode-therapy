#include <climits>

class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;

            if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
            if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && pop < -8)) return 0;

            rev = rev * 10 + pop;
        }
        return rev;
    }
};

/*
 * Approach: Pop and Push with Overflow Check
 * * Logic:
 * 1. We treat the number as a stack of digits. We "pop" the last digit off 'x'
 * using modulo (%) and "push" it onto the back of 'rev'.
 * 2. The core mathematical operation to append a digit is: rev = rev * 10 + pop.
 * 3. CRITICAL STEP: Because the problem forbids storing 64-bit integers, we cannot
 * calculate the result and then check for overflow. We must check *before* performing
 * the multiplication.
 * 4. We check if 'rev' is already greater than INT_MAX / 10. If it is, multiplying
 * by 10 will definitely overflow.
 * 5. If 'rev' is exactly equal to INT_MAX / 10, we check if the digit we are about
 * to add ('pop') is greater than 7 (since INT_MAX ends in ...7).
 * 6. We apply the same logic for negative numbers using INT_MIN (which ends in ...8).
 * 7. If any overflow condition is met, we immediately return 0.
 * * Time Complexity: O(log(x))
 * There are roughly log10(x) digits in x, so the loop runs that many times.
 * * Space Complexity: O(1)
 * We only use a few variables for storage.
 */