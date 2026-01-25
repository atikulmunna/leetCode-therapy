#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    std::unordered_map<std::string, bool> memo;

    bool isScramble(std::string s1, std::string s2) {
        if (s1 == s2) return true;
        if (s1.length() != s2.length()) return false;

        std::string key = s1 + "_" + s2;
        if (memo.count(key)) {
            return memo[key];
        }

        int n = s1.length();
        std::vector<int> count(26, 0);
        for (int i = 0; i < n; i++) {
            count[s1[i] - 'a']++;
            count[s2[i] - 'a']--;
        }

        for (int i = 0; i < 26; i++) {
            if (count[i] != 0) {
                return memo[key] = false;
            }
        }

        for (int i = 1; i < n; i++) {
            bool noSwap = isScramble(s1.substr(0, i), s2.substr(0, i)) &&
                          isScramble(s1.substr(i), s2.substr(i));

            if (noSwap) {
                return memo[key] = true;
            }

            bool swap = isScramble(s1.substr(0, i), s2.substr(n - i)) &&
                        isScramble(s1.substr(i), s2.substr(0, n - i));

            if (swap) {
                return memo[key] = true;
            }
        }

        return memo[key] = false;
    }
};


/*
 * Approach: Recursion with Memoization
 * * Logic:
 * 1. Base Cases:
 * - If strings are identical, return true.
 * - If lengths differ, return false.
 * - If character frequencies differ (Anagram check), return false immediately.
 * This is a critical optimization (pruning).
 * 2. Recursive Step:
 * - We iterate through all possible split points 'i' from 1 to length-1.
 * - For each split, we split s1 into Left (L1) and Right (R1).
 * - We check two scenarios against s2:
 * a) No Swap: L1 matches s2's left part (L2) AND R1 matches s2's right part (R2).
 * b) Swap: L1 matches s2's RIGHT part (R2) AND R1 matches s2's LEFT part (L2).
 * 3. Memoization:
 * - We store the result of (s1, s2) in a hash map to avoid recomputing the same
 * substring comparisons. The key is typically "s1_s2".
 * * Time Complexity: O(N^4)
 * There are O(N^2) substrings. For each recursion, we loop O(N) split points,
 * and substring operations take O(N).
 * * Space Complexity: O(N^3)
 * Storing O(N^2) states in the map, with keys of length O(N).
 */
