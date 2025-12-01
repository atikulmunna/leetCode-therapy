#include <vector>
#include <string>

class Solution {
public:
    bool isMatch(std::string s, std::string p) {
        int n = s.length();
        int m = p.length();

        std::vector<std::vector<bool>> dp(n + 1, std::vector<bool>(m + 1, false));

        dp[0][0] = true;

        for (int j = 1; j <= m; j++) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 1];
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (p[j - 1] == '?' || p[j - 1] == s[i - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                } else {
                    dp[i][j] = false;
                }
            }
        }

        return dp[n][m];
    }
};

/*
 * Approach: Dynamic Programming (2D Grid)
 * * Logic:
 * 1. We create a 2D boolean table 'dp' of size (n+1) x (m+1).
 * 2. dp[i][j] answers: "Does the prefix of 's' of length 'i' match the prefix of 'p' of length 'j'?"
 * 3. Initialization:
 * - dp[0][0] is true (empty matches empty).
 * - We fill the first row (dp[0][j]) to handle patterns starting with '*' (e.g., p="*" matches s="").
 * 4. We iterate through the grid.
 * - Case 1: p[j-1] is '?' or matches s[i-1]. We inherit the result from dp[i-1][j-1] (diagonal).
 * - Case 2: p[j-1] is '*'. The '*' can act as empty (dp[i][j-1]) OR it can consume the current character
 * from string 's' (dp[i-1][j]). If either is true, the current state is true.
 * - Case 3: Character mismatch. dp[i][j] is false.
 * 5. Finally, dp[n][m] contains the result for the full string and pattern.
 * * Time Complexity: O(n * m)
 * We fill every cell in the matrix once.
 * * Space Complexity: O(n * m)
 * We store the entire DP table. (Can be optimized to O(m) since we only need the previous row).
 */