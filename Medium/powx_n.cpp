#include <cmath>

class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;

        if (N < 0) {
            x = 1 / x;
            N = -N;
        }

        double current_product = x;
        double result = 1.0;

        while (N > 0) {
            if (N % 2 == 1) {
                result = result * current_product;
            }
            current_product = current_product * current_product;
            N = N / 2;
        }

        return result;
    }
};

/*
 * Approach: Binary Exponentiation (Iterative)
 * * Logic:
 * 1. Data Type Handling: We assign 'n' to a 'long long' variable 'N'. This is
 * strictly to handle the edge case where n = INT_MIN (-2^31). If we tried to do
 * n = -n on INT_MIN, it would overflow a signed 32-bit integer.
 * 2. Negative Exponent: If N is negative, the math rule is x^-N = (1/x)^N.
 * So, we replace 'x' with '1/x' and make 'N' positive.
 * 3. The Loop: We iterate while N > 0.
 * - If N is ODD (N % 2 == 1): We multiply our 'result' by the 'current_product'.
 * This "peels off" one instance of x.
 * - Regardless of even/odd, we then Square the Base (current_product *= current_product)
 * and Halve the Exponent (N /= 2).
 * 4. This effectively processes the exponent based on its binary representation.
 * For example, x^10 (binary 1010):
 * - Bit 0 (0): Don't add to result. Square x -> x^2.
 * - Bit 1 (1): Add x^2 to result. Square x^2 -> x^4.
 * - Bit 2 (0): Don't add. Square x^4 -> x^8.
 * - Bit 3 (1): Add x^8 to result. Square x^8 -> x^16.
 * Result = x^2 * x^8 = x^10.
 * * Time Complexity: O(log n)
 * We divide N by 2 in every iteration.
 * * Space Complexity: O(1)
 * We use constant extra space.
 */