#include <string>

class Solution {
public:
    bool isNumber(std::string s) {
        bool seenDigit = false;
        bool seenExponent = false;
        bool seenDot = false;

        for (int i = 0; i < s.length(); i++) {
            char c = s[i];

            if (isdigit(c)) {
                seenDigit = true;
            } else if (c == '+' || c == '-') {
                if (i > 0 && s[i - 1] != 'e' && s[i - 1] != 'E') {
                    return false;
                }
            } else if (c == 'e' || c == 'E') {

                if (seenExponent || !seenDigit) {
                    return false;
                }
                seenExponent = true;
                seenDigit = false;
            } else if (c == '.') {
                if (seenDot || seenExponent) {
                    return false;
                }
                seenDot = true;
            } else {
                return false;
            }
        }
        return seenDigit;
    }
};

/*
 * Approach: Linear Scan with Flags
 * * Logic:
 * 1. We iterate through the string character by character.
 * 2. We maintain three flags: 'seenDigit', 'seenExponent', and 'seenDot'.
 * 3. Case Digits: If we see a digit, we mark 'seenDigit' as true.
 * 4. Case Signs (+/-): A sign is valid ONLY if it's the first character (index 0)
 * OR if the character immediately preceding it was an 'e' or 'E'. Any other
 * position is invalid (e.g., "12+3" or "++1").
 * 5. Case Exponent (e/E):
 * - It is invalid if we have ALREADY seen an exponent (e.g., "1e2e3").
 * - It is invalid if we have NOT seen a digit yet (e.g., "e3").
 * - If valid, we mark 'seenExponent' as true. Crucially, we set 'seenDigit'
 * back to false. This enforces the rule that an exponent must be followed by
 * an integer (e.g., "1e" will fail because seenDigit ends as false).
 * 6. Case Dot (.):
 * - It is invalid if we have ALREADY seen a dot (e.g., "1.2.3").
 * - It is invalid if we have ALREADY seen an exponent (e.g., "1e2.3" is not allowed).
 * - Otherwise, mark 'seenDot' as true.
 * 7. Invalid Characters: Any spaces or letters other than e/E return false immediately.
 * 8. Final Check: We return 'seenDigit'. This ensures the string isn't just symbols
 * (like ".") and ensures any exponent was properly followed by a number.
 * * Time Complexity: O(N)
 * We scan the string once.
 * * Space Complexity: O(1)
 * We use a few boolean variables.
 */