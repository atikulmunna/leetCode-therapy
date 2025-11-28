#include <climits>
#include <cmath>
#include <algorithm>

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        bool negative = (dividend < 0) ^ (divisor < 0);

        long n = std::abs((long)dividend);
        long d = std::abs((long)divisor);
        long quotient = 0;

        while (n >= d) {
            long temp = d;
            long multiplier = 1;

            while (n >= (temp << 1)) {
                temp <<= 1;
                multiplier <<= 1;
            }

            n -= temp;
            quotient += multiplier;
        }

        return negative ? -quotient : quotient;
    }
};

/*
 * Approach: Bitwise Shifting (Powers of Two Subtraction)
 * * Logic:
 * 1. Edge Case: We handle the specific overflow case where dividend is INT_MIN
 * (-2^31) and divisor is -1. The result 2^31 exceeds the max positive 32-bit integer,
 * so we return INT_MAX.
 * 2. Signs: We determine the sign of the result using XOR (^). If the signs are
 * different, the result is negative.
 * 3. Conversion: We convert both inputs to 'long' and take their absolute values.
 * We use 'long' because abs(INT_MIN) causes an overflow in a standard 32-bit 'int'.
 * 4. The Loop (Doubling Strategy):
 * - We check if the dividend (n) is greater than or equal to the divisor (d).
 * - Inside, we try to double the divisor (temp << 1) as many times as possible
 * while it remains smaller than or equal to 'n'.
 * - We keep a 'multiplier' that doubles along with the divisor (1, 2, 4, 8...).
 * 5. Update: Once we find the largest chunk that fits, we subtract it from 'n'
 * and add the 'multiplier' to our total 'quotient'.
 * 6. We repeat this process with the remaining 'n' until 'n' is smaller than 'd'.
 * 7. Finally, we apply the sign and return.
 * * Time Complexity: O(log(dividend)^2) or O(log N)
 * In each outer loop iteration, we reduce the dividend by at least half roughly.
 * The inner loop scans bits. It is extremely fast compared to linear subtraction.
 * * Space Complexity: O(1)
 * We use constant extra space.
 */