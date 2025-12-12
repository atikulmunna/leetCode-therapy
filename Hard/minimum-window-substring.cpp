#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    std::string minWindow(std::string s, std::string t) {
        int m = s.length();
        int n = t.length();

        if (n == 0 || m == 0 || n > m) {
            return "";
        }

        std::unordered_map<char, int> targetMap;
        for (char c : t) {
            targetMap[c]++;
        }

        int required = targetMap.size();
        int formed = 0;

        std::unordered_map<char, int> windowMap;

        int minLength = INT_MAX;
        int minLeft = 0;

        int l = 0;
        for (int r = 0; r < m; ++r) {
            char c = s[r];
            windowMap[c]++;

            if (targetMap.count(c) && windowMap[c] == targetMap[c]) {
                formed++;
            }

            while (l <= r && formed == required) {
                if (r - l + 1 < minLength) {
                    minLength = r - l + 1;
                    minLeft = l;
                }

                char leftChar = s[l];

                windowMap[leftChar]--;
                if (targetMap.count(leftChar) && windowMap[leftChar] < targetMap[leftChar]) {
                    formed--;
                }
                l++;
            }
        }

        return (minLength == INT_MAX) ? "" : s.substr(minLeft, minLength);
    }
};


/*
 * Approach: Sliding Window with Two HashMaps
 * * Logic:
 * 1. Target Tracking: We first create 'targetMap' to store the exact frequency of
 * every character required from T. 'required' tracks the number of unique characters
 * that must be fully matched.
 * 2. Window Expansion: The right pointer 'r' expands the window one character at a time.
 * - 'windowMap' stores the character counts in the current window S[l...r].
 * - When a character 'c' reaches its required count in 'targetMap', we increment
 * 'formed', indicating we've matched one more unique requirement.
 * 3. Window Contraction: Once 'formed' equals 'required', a valid window exists.
 * - We check and record the current minimum length and starting index.
 * - The left pointer 'l' moves right to shrink the window.
 * - The key is detecting when the window becomes INVALID: if the character S[l] is
 * required, and removing it (windowMap[S[l]]--) causes its count to drop below
 * targetMap[S[l]], we must decrement 'formed' and stop contracting.
 * 4. Result: If 'minLength' remains INT_MAX, no valid window was found. Otherwise,
 * we use substr to return the minimum window.
 * * Time Complexity: O(M + N)
 * M is the length of S, N is the length of T. The right pointer 'r' iterates M times,
 * and the left pointer 'l' iterates at most M times.
 * * Space Complexity: O(C)
 * Where C is the size of the character set (e.g., 52 for all uppercase/lowercase English letters),
 * used for the two hash maps.
 */