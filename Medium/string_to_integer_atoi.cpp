#include <string>
#include <climits>

class Solution {
public:
    int myAtoi(std::string s) {
        int i = 0;
        int n = s.length();
        int sign = 1;
        int result = 0;

        while (i < n && s[i] == ' ') {
            i++;
        }

        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';

            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > 7)) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }

            result = result * 10 + digit;
            i++;
        }

        return result * sign;
    }
};

/*
 * Approach: Deterministic Finite Automaton (Scanner)
 * * Logic:
 * 1. We process the string sequentially using an index 'i'.
 * 2. Phase 1 (Whitespace): We iterate while s[i] is a space (' ') to skip leading whitespace.
 * 3. Phase 2 (Sign): We check if the next character is '+' or '-'. If found, we update
 * the 'sign' variable (1 or -1) and advance the index.
 * 4. Phase 3 (Digits): We iterate as long as the current character is a digit (0-9).
 * - We convert the char to int using 's[i] - '0''.
 * - CRITICAL: Before adding the digit to 'result', we check for 32-bit integer overflow.
 * - We use the check: if (result > INT_MAX / 10) or (result == INT_MAX / 10 && digit > 7).
 * - If overflow is detected, we return INT_MAX (if sign is +1) or INT_MIN (if sign is -1).
 * - Otherwise, we update result = result * 10 + digit.
 * 5. If we encounter a non-digit character during Phase 3, the loop terminates naturally.
 * 6. Finally, we return result * sign.
 * * Time Complexity: O(n)
 * We traverse the string at most once.
 * * Space Complexity: O(1)
 * We only use a few variables for tracking state.
 */