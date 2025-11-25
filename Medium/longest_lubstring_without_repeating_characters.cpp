#include <string>
#include <unordered_set>
#include <algorithm>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::unordered_set<char> charSet;
        int left = 0;
        int maxLength = 0;

        for (int right = 0; right < s.length(); right++) {
            while (charSet.find(s[right]) != charSet.end()) {
                charSet.erase(s[left]);
                left++;
            }

            charSet.insert(s[right]);
            maxLength = std::max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};

/*
 * Approach: Sliding Window with Hash Set
 * * Logic:
 * 1. We use two pointers, 'left' and 'right', to define a "window" of characters.
 * 2. We use an unordered_set to track unique characters currently inside the window.
 * 3. We iterate with the 'right' pointer to expand the window.
 * 4. Before adding a new character (s[right]), we check if it already exists in the set.
 * 5. If it exists (duplicate found), we enter a while loop: we remove the character 
 * at the 'left' pointer from the set and increment 'left' to shrink the window. 
 * We repeat this until the duplicate is removed.
 * 6. Once the window is valid (no duplicates), we insert the new character and 
 * update 'maxLength' with the current window size (right - left + 1).
 * * Time Complexity: O(n)
 * Although there is a nested while loop, each character is added and removed 
 * at most once. Thus, we traverse the string linearly.
 * * Space Complexity: O(min(m, n))
 * We need space for the set, which stores at most 'm' unique characters, 
 * where 'm' is the size of the character set (e.g., 128 for ASCII).
 */