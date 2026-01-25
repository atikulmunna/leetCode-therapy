#include <string>
#include <vector>

class Solution {
public:
    int numDecodings(std::string s) {
        int n = s.length();
        std::vector<int> dp(n + 1, 0);

        dp[0] = 1;

        for (int i = 1; i <= n; ++i) {

            if (s[i - 1] != '0') {
                dp[i] += dp[i - 1];
            }

            if (i >= 2) {
                std::string twoChars = s.substr(i - 2, 2);
                if (twoChars >= "10" && twoChars <= "26") {
                    dp[i] += dp[i - 2];
                }
            }
        }

        return dp[n];
    }
};

/*
 * Approach: Dynamic Programming (1D Array)
 * * Logic:
 * 1. State Definition: dp[i] represents the number of ways to decode the prefix of string 's' of length 'i'.
 * 2. Base Case: dp[0] = 1. This is a standard DP initialization for "empty" valid prefixes to allow the math
 * for the first 2-digit jump to work correctly (dp[2] += dp[0]).
 * 3. Transitions: We iterate from length 1 to n.
 * - Single Digit Decode: We look at the character at s[i-1]. If it is NOT '0', it contributes
 * dp[i-1] ways to the current total (since 1-9 maps to A-I).
 * - Two Digit Decode: We look at the substring s[i-2...i-1]. If it forms a valid number between
 * "10" and "26", it contributes dp[i-2] ways (since 10-26 maps to J-Z).
 * 4. Edge Cases:
 * - Leading '0': If s[0] is '0', dp[1] stays 0, and consequently the final result is 0.
 * - Invalid sequences like "30" or "00": These will fail both the single-digit check (current is '0')
 * and the two-digit check (value is not 10-26), resulting in 0 ways carried forward.
 * * Time Complexity: O(N)
 * We iterate through the string once.
 * * Space Complexity: O(N)
 * We use a DP array of size N+1. (This can be optimized to O(1) by only storing the last two states).
 */