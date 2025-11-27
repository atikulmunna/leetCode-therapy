#include <string>
#include <vector>

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        if (strs.empty()) {
            return "";
        }

        std::string prefix = strs[0];

        for (int i = 1; i < strs.size(); i++) {
            while (strs[i].find(prefix) != 0) {
                prefix = prefix.substr(0, prefix.length() - 1);
                if (prefix.empty()) {
                    return "";
                }
            }
        }

        return prefix;
    }
};

/*
 * Approach: Horizontal Scanning (Prefix Shrinking)
 * * Logic:
 * 1. We treat the first string in the array (strs[0]) as our candidate 'prefix'.
 * 2. We iterate through the remaining strings in the array one by one.
 * 3. For each string 's', we check if it starts with our current 'prefix'.
 * - In C++, 'string.find(prefix)' returns 0 if the prefix is found at the very start.
 * 4. If it doesn't match, we are "too optimistic". We shorten the 'prefix' by removing
 * the last character and check again. We repeat this while loop until a match is found
 * or the prefix becomes empty.
 * 5. If the prefix becomes empty at any point, we know there is no common prefix,
 * so we return "" immediately.
 * 6. After checking all strings, the remaining value in 'prefix' is the answer.
 * * Time Complexity: O(S)
 * S is the sum of all characters in all strings. In the worst case (all strings are identical),
 * we compare every character.
 * * Space Complexity: O(1)
 * We only use a variable to store the prefix (ignoring the space taken by the result itself),
 * as we modify the prefix in place or create substrings.
 */