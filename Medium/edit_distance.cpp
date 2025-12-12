#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    int minDistance(std::string word1, std::string word2) {
        int m = word1.length();
        int n = word2.length();

        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1));
        for (int i = 0; i <= m; i++) {
            dp[i][0] = i;
        }

        for (int j = 0; j <= n; j++) {
            dp[0][j] = j;
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {

                int cost = (word1[i - 1] == word2[j - 1]) ? 0 : 1;

                dp[i][j] = std::min({
                    dp[i - 1][j] + 1,
                    dp[i][j - 1] + 1,
                    dp[i - 1][j - 1] + cost
                });
            }
        }

        return dp[m][n];
    }
};

/*
 * Approach: Dynamic Programming (Levenshtein Distance)
 * * Logic:
 * 1. DP Table Definition: A matrix dp[i][j] is created, where the rows (i)
 * correspond to prefixes of 'word1' and columns (j) correspond to prefixes of 'word2'.
 * The value dp[i][j] is the minimum number of operations to convert word1[0..i-1]
 * to word2[0..j-1].
 * * 2. Base Cases (Initialization):
 * - dp[i][0] = i: Converting a prefix of length 'i' into an empty string requires 'i' deletions.
 * - dp[0][j] = j: Converting an empty string into a prefix of length 'j' requires 'j' insertions.
 * * 3. Recurrence Relation: For every cell dp[i][j], we consider three possible ways
 * to arrive at this minimum distance:
 * - Deletion (word1[i-1] is deleted): Cost = dp[i-1][j] + 1.
 * - Insertion (word2[j-1] is inserted): Cost = dp[i][j-1] + 1.
 * - Substitution/Match (word1[i-1] is replaced by word2[j-1]): Cost = dp[i-1][j-1] + cost.
 * - Cost is 0 if characters match, 1 if they don't.
 * * We choose the minimum of these three costs.
 * * * Time Complexity: O(m * n)
 * We fill an m x n grid, performing O(1) calculation for each cell.
 * * Space Complexity: O(m * n)
 * For the DP table. (Can be optimized to O(min(m, n)) using only two rows).
 */