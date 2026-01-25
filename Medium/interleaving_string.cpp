#include <string>
#include <vector>

class Solution {
public:
    bool isInterleave(std::string s1, std::string s2, std::string s3) {
        int m = s1.length();
        int n = s2.length();

        if (m + n != s3.length()) {
            return false;
        }

        std::vector<std::vector<bool>> dp(m + 1, std::vector<bool>(n + 1, false));

        dp[0][0] = true;

        for (int i = 1; i <= m; ++i) {
            dp[i][0] = dp[i - 1][0] && (s1[i - 1] == s3[i - 1]);
        }

        for (int j = 1; j <= n; ++j) {
            dp[0][j] = dp[0][j - 1] && (s2[j - 1] == s3[j - 1]);
        }

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                bool fromS1 = dp[i - 1][j] && (s1[i - 1] == s3[i + j - 1]);
                bool fromS2 = dp[i][j - 1] && (s2[j - 1] == s3[i + j - 1]);

                dp[i][j] = fromS1 || fromS2;
            }
        }

        return dp[m][n];
    }
};

/*
 * Approach: 2D Dynamic Programming
 * * Logic:
 * 1. State Definition: dp[i][j] represents whether the first i characters of s1
 * and the first j characters of s2 can interleave to form the first i+j characters of s3.
 * 2. Pre-check: If lengths of s1 + s2 don't equal s3, return false immediately.
 * 3. Base Case & Initialization:
 * - dp[0][0] is true (empty + empty = empty).
 * - First Column (j=0): We only use s1. If s1[i-1] == s3[i-1] AND previous state was valid.
 * - First Row (i=0): We only use s2. If s2[j-1] == s3[j-1] AND previous state was valid.
 * 4. Recurrence: For cell (i, j), we check two possibilities:
 * - Did we arrive here by consuming a character from s1?
 * Check if dp[i-1][j] is true AND s1[i-1] == s3[i+j-1].
 * - Did we arrive here by consuming a character from s2?
 * Check if dp[i][j-1] is true AND s2[j-1] == s3[i+j-1].
 * - If either is true, dp[i][j] is true.
 * * Time Complexity: O(M * N)
 * We fill an M x N grid.
 * * Space Complexity: O(M * N)
 * For the 2D DP table. (This can be optimized to O(min(M, N)) using a 1D array).
 */