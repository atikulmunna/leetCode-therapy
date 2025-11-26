#include <string>
#include <vector>

class Solution {
public:
    bool isMatch(std::string s, std::string p) {
        int m = s.length();
        int n = p.length();

        std::vector<std::vector<bool>> dp(m + 1, std::vector<bool>(n + 1, false));

        dp[0][0] = true;

        for (int j = 1; j <= n; j++) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 2];
            }
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 2];
                    if (p[j - 2] == '.' || p[j - 2] == s[i - 1]) {
                        dp[i][j] = dp[i][j] || dp[i - 1][j];
                    }
                } else if (p[j - 1] == '.' || p[j - 1] == s[i - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
            }
        }

        return dp[m][n];
    }
};

/*
 * Approach: Dynamic Programming (Bottom-Up)
 * * Logic:
 * 1. We define a 2D boolean table 'dp', where dp[i][j] represents whether the
 * first 'i' characters of string 's' match the first 'j' characters of pattern 'p'.
 * 2. We initialize dp[0][0] = true because an empty pattern matches an empty string.
 * 3. Base Case Initialization: We handle patterns like "a*b*c*" matching an empty string.
 * If p[j-1] is '*', we look back two steps (dp[0][j-2]) to see if the part before
 * the '*' matched.
 * 4. We iterate through the grid with 'i' (string index) and 'j' (pattern index).
 * 5. Case 1: The current pattern character p[j-1] is '*'.
 * - Option A (Zero Occurrences): We check dp[i][j-2]. This ignores the character
 * before '*' and the '*' itself.
 * - Option B (One or More Occurrences): We check if the character preceding '*'
 * (p[j-2]) matches the current string char s[i-1] (or is '.'). If it matches,
 * we look at dp[i-1][j] (keeping the pattern '*' active but consuming a
 * character from 's').
 * 6. Case 2: The current pattern character is '.' or matches s[i-1].
 * - We look at the diagonal result dp[i-1][j-1].
 * 7. Finally, dp[m][n] contains the answer for the full string and pattern.
 * * Time Complexity: O(m * n)
 * We fill a table of size (m+1) x (n+1) exactly once.
 * * Space Complexity: O(m * n)
 * We store the boolean table. (This can be optimized to O(n) space since we only
 * need the previous row, but O(m*n) is standard for clarity).
 */