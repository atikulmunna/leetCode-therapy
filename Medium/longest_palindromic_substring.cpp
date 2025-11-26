#include <string>
#include <algorithm>

class Solution {
public:
    std::string longestPalindrome(std::string s) {
        if (s.empty()) return "";

        int start = 0;
        int maxLen = 0;

        for (int i = 0; i < s.length(); i++) {
            int len1 = expandAroundCenter(s, i, i);
            int len2 = expandAroundCenter(s, i, i + 1);
            int len = std::max(len1, len2);

            if (len > maxLen) {
                maxLen = len;
                start = i - (len - 1) / 2;
            }
        }

        return s.substr(start, maxLen);
    }

private:
    int expandAroundCenter(const std::string& s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        return right - left - 1;
    }
};

/*
 * Approach: Expand Around Center
 * * Logic:
 * 1. We treat every index 'i' in the string as a potential center of a palindrome.
 * 2. Because palindromes can be odd-length (e.g., "aba") or even-length
 * (e.g., "abba"), we check two expansion cases for every 'i':
 * - Case 1: Center is the character itself (i, i).
 * - Case 2: Center is the gap between the character and the next one (i, i+1).
 * 3. The helper function 'expandAroundCenter' expands outward using two pointers
 * as long as the characters match and we stay within bounds.
 * 4. We calculate the length of the palindrome found. The formula (right - left - 1)
 * corrects for the fact that the pointers moved one step too far before the loop ended.
 * 5. If the found length is greater than our current 'maxLen', we update 'maxLen'
 * and calculate the new 'start' index using the formula: i - (len - 1) / 2.
 * * Time Complexity: O(n^2)
 * We iterate through the string (n), and for each character, we might expand
 * to the ends of the string (n).
 * * Space Complexity: O(1)
 * We only use a few integer variables to store indices and lengths.
 */