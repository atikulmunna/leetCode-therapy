#include <vector>
#include <string>
#include <unordered_map>

class Solution {
public:
    std::vector<int> findSubstring(std::string s, std::vector<std::string>& words) {
        std::vector<int> result;
        if (s.empty() || words.empty()) return result;

        int wordLen = words[0].length();
        int numWords = words.size();
        int totalLen = wordLen * numWords;
        int n = s.length();

        std::unordered_map<std::string, int> wordCount;
        for (const std::string& w : words) {
            wordCount[w]++;
        }

        for (int i = 0; i < wordLen; i++) {
            int left = i;
            int right = i;
            std::unordered_map<std::string, int> currentCount;
            int count = 0;

            while (right + wordLen <= n) {
                std::string word = s.substr(right, wordLen);
                right += wordLen;

                if (wordCount.find(word) != wordCount.end()) {
                    currentCount[word]++;
                    count++;

                    while (currentCount[word] > wordCount[word]) {
                        std::string leftWord = s.substr(left, wordLen);
                        currentCount[leftWord]--;
                        count--;
                        left += wordLen;
                    }

                    if (count == numWords) {
                        result.push_back(left);
                    }
                } else {
                    currentCount.clear();
                    count = 0;
                    left = right;
                }
            }
        }

        return result;
    }
};

/*
 * Approach: Sliding Window with Fixed-Length Offsets
 * * Logic:
 * 1. Pre-computation: We calculate the length of a single word ('wordLen'), the
 * total number of words ('numWords'), and the total length of the substring we
 * are looking for ('totalLen'). We also store the frequency of the target words
 * in a hash map ('wordCount').
 * 2. Offsets: Because words can start at any index, we must run the sliding window
 * logic starting from index 0, 1, 2... up to 'wordLen - 1'. This ensures we check
 * every possible alignment of words.
 * 3. Sliding Window:
 * - We maintain two pointers, 'left' and 'right', and a temporary hash map
 * 'currentCount' to track words found in the current window.
 * - We extract the word at the 'right' pointer.
 * 4. Valid Word Handling:
 * - If the word is in our target list, we add it to 'currentCount'.
 * - If adding this word makes the count exceed the required limit (e.g., we need
 * two "foo"s but found a third), we slide the 'left' pointer forward, removing words
 * from the window until the count becomes valid again.
 * - If the total count of words matches 'numWords', we record the 'left' index.
 * 5. Invalid Word Handling:
 * - If the word at 'right' is NOT in the target list, the continuous chain is broken.
 * We essentially reset the window: clear 'currentCount', reset 'count', and move
 * 'left' to match 'right'.
 * * Time Complexity: O(N)
 * Even though we have nested loops, the outer loop runs 'wordLen' times, and the
 * inner loop steps by 'wordLen'. This results in traversing the string roughly
 * once overall (specifically N * wordLen / wordLen = N).
 * * Space Complexity: O(M * W)
 * We store the hash maps, where M is the number of words and W is the word length.
 */