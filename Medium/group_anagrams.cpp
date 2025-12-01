#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> groups;

        for (std::string s : strs) {
            std::string key = s;
            std::sort(key.begin(), key.end());
            groups[key].push_back(s);
        }

        std::vector<std::vector<std::string>> result;
        for (auto pair : groups) {
            result.push_back(pair.second);
        }

        return result;
    }
};

/*
 * Approach: Categorization by Sorting
 * * Logic:
 * 1. Anagrams are defined by having the exact same characters with the exact
 * same frequencies.
 * 2. Therefore, if we sort the characters of any two anagrams (e.g., "eat" and "tea"),
 * they will result in the identical string ("aet").
 * 3. We use this sorted string as a "Key" in a Hash Map (unordered_map).
 * 4. The "Value" in the map is a vector of strings. This vector holds all the
 * original words that sort into that specific Key.
 * 5. We iterate through the input list once. For each string:
 * - We create a copy and sort it to find the Key.
 * - We access the map using that Key and push the original string into the vector.
 * 6. Finally, we iterate through the map and move all the vectors into our
 * result container.
 * * Time Complexity: O(N * K log K)
 * N is the number of strings, and K is the maximum length of a string.
 * We iterate N times, and for each string, we perform a sort taking O(K log K).
 * * Space Complexity: O(N * K)
 * We store every string in the map.
 */