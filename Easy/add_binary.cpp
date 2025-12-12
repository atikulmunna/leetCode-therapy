#include <string>
#include <algorithm>

class Solution {
public:
    std::string addBinary(std::string a, std::string b) {
        std::string result = "";
        int i = a.length() - 1;
        int j = b.length() - 1;
        int carry = 0;

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;

            if (i >= 0) {
                sum += a[i] - '0';
                i--;
            }

            if (j >= 0) {
                sum += b[j] - '0';
                j--;
            }

            result += std::to_string(sum % 2);

            carry = sum / 2;
        }

        std::reverse(result.begin(), result.end());
        return result;
    }
};

/*
 * Approach: Simulation (Right-to-Left Scan)
 * * Logic:
 * 1. Pointers: We initialize two pointers, 'i' and 'j', pointing to the last
 * characters of strings 'a' and 'b'. We also have a 'carry' variable initialized to 0.
 * 2. The Loop: The condition 'i >= 0 || j >= 0 || carry' ensures we continue
 * until we have processed all digits AND handled any remaining carry (e.g., 1 + 1 = 10,
 * the '1' is a new digit generated purely from carry).
 * 3. Summation: In each step, we start 'sum' with the carry. If 'i' is valid,
 * we add a[i] (converting char to int) and decrement 'i'. Same for 'j'.
 * 4. Digit Computation:
 * - The digit to append is 'sum % 2'.
 * - The new carry is 'sum / 2'.
 * 5. Reversal: Since we appended digits starting from the end (LSD), our result string
 * is backwards. We reverse it at the end to get the correct binary representation.
 * * Time Complexity: O(max(N, M))
 * Where N and M are lengths of 'a' and 'b'. We iterate through the longer string once.
 * * Space Complexity: O(max(N, M))
 * To store the result string.
 */