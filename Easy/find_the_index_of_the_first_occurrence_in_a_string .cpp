#include <string>

class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        int n = haystack.length();
        int m = needle.length();

        if (m > n) return -1;

        for (int i = 0; i <= n - m; i++) {
            int j = 0;
            while (j < m && haystack[i + j] == needle[j]) {
                j++;
            }
            if (j == m) {
                return i;
            }
        }

        return -1;
    }
};

/*
 * Approach: Brute Force Sliding Window
 * * Logic:
 * 1. We define 'n' as the length of the haystack and 'm' as the length of the needle.
 * 2. Optimization: If the needle is longer than the haystack, a match is impossible,
 * so we return -1 immediately.
 * 3. We iterate through the haystack using index 'i'.
 * - IMPORTANT: We only need to iterate up to 'n - m'. If we go further, there
 * aren't enough characters left in the haystack to fit the needle.
 * 4. Inside the loop, we verify if the substring starting at 'i' matches the needle.
 * - We use a second pointer 'j' to iterate through the needle.
 * - We compare haystack[i + j] with needle[j].
 * - If they match, we increment 'j'.
 * - If they don't match, the while loop breaks.
 * 5. After the inner loop, if 'j' equals 'm', it means we successfully matched
 * every character in the needle. We return 'i' (the starting index).
 * 6. If the outer loop finishes without returning, the needle is not found. Return -1.
 * * Time Complexity: O((N-M) * M)
 * In the worst case (e.g., haystack="aaaaaaab", needle="ba"), we compare nearly
 * every character M times.
 * * Space Complexity: O(1)
 * We do not use any extra memory structure.
 * * Note: In a real-world project, you would use 'haystack.find(needle)',
 * which is optimized (often using heuristics) and cleaner.
 */