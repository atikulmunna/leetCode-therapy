#include <string>

class Solution {
public:
    int lengthOfLastWord(std::string s) {
        int n = s.length();
        int length = 0;
        int i = n - 1;

        while (i >= 0 && s[i] == ' ') {
            i--;
        }

        while (i >= 0 && s[i] != ' ') {
            length++;
            i--;
        }

        return length;
    }
};

/*
 * Approach: Reverse Iteration
 * * Logic:
 * 1. The problem asks for the *last* word, making a reverse traversal the most
 * direct approach.
 * 2. Stage 1 (Trim): We initialize a pointer 'i' at the end of the string.
 * We iterate backwards, decrementing 'i' as long as we encounter space characters.
 * This effectively ignores any trailing whitespace.
 * 3. Stage 2 (Count): Once the first non-space character is found, we enter the
 * counting phase. We continue decrementing 'i' and incrementing our 'length' counter.
 * 4. Termination: The loop stops when we either hit a space (meaning the word
 * has finished) or we run out of characters (index < 0).
 * * Time Complexity: O(N)
 * In the worst case (a single word like "A..."), we iterate through the whole string.
 * * Space Complexity: O(1)
 * We traverse the string in-place without allocating extra memory.
 */