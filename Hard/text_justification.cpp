#include <vector>
#include <string>
#include <numeric>
#include <algorithm>
#include <cmath>

class Solution {
private:
    std::string createSpaces(int count) {
        return std::string(count, ' ');
    }
    std::string justifyLine(const std::vector<std::string>& words, int maxWidth, bool isLastLine) {
        int wordsCount = words.size();

        int wordsLength = 0;
        for (const std::string& word : words) {
            wordsLength += word.length();
        }

        int totalSpaces = maxWidth - wordsLength;

        if (wordsCount == 1 || isLastLine) {
            std::string line = words[0];
            for (int i = 1; i < wordsCount; ++i) {
                line += " " + words[i];
            }
            line += createSpaces(maxWidth - line.length());
            return line;
        }

        int gaps = wordsCount - 1;
        int baseSpaces = totalSpaces / gaps;
        int extraSpaces = totalSpaces % gaps;

        std::string line = words[0];

        for (int i = 0; i < gaps; ++i) {
            int currentSpaces = baseSpaces + (extraSpaces > 0 ? 1 : 0);

            line += createSpaces(currentSpaces);
            line += words[i + 1];

            if (extraSpaces > 0) {
                extraSpaces--;
            }
        }

        return line;
    }

public:
    std::vector<std::string> fullJustify(std::vector<std::string>& words, int maxWidth) {
        std::vector<std::string> result;
        int n = words.size();
        int i = 0;

        while (i < n) {
            std::vector<std::string> currentLine;
            int currentLength = 0;

            int j = i;
            while (j < n) {
                int wordLength = words[j].length();
                int potentialLength = currentLength + wordLength + (currentLine.empty() ? 0 : 1);

                if (potentialLength <= maxWidth) {
                    currentLine.push_back(words[j]);
                    currentLength += wordLength;
                    currentLength += (currentLine.size() > 1 ? 1 : 0);
                    j++;
                } else {
                    break;
                }
            }

            int wordsLength = 0;
            for (const std::string& word : currentLine) {
                wordsLength += word.length();
            }

            bool isLastLine = (j == n);
            result.push_back(justifyLine(currentLine, maxWidth, isLastLine));

            i = j;
        }

        return result;
    }
};

/*
 * Approach: Greedy Line-by-Line Processing
 * * Logic:
 * 1. Line Grouping: The outer loop greedily groups the maximum number of
 * words that can fit on a single line, respecting the 'maxWidth' constraint.
 * 'i' tracks the start of the current line, and 'j' finds the end.
 *
 * 2. Justification Function (justifyLine): This function handles the space
 * distribution rules for the line passed to it.
 *
 * 3. Last Line / Single Word (isLastLine || wordsCount == 1):
 * - These lines are always LEFT-JUSTIFIED.
 * - Words are separated by a single space, and the remaining space up to
 * 'maxWidth' is padded at the end of the line.
 *
 * 4. Full Justification (Multiple words, not last line):
 * - Calculate Total Spaces (S) needed: S = maxWidth - Total Words Length.
 * - Calculate Gaps (G) available: G = Words Count - 1.
 * - Base Spaces: S / G (The minimum number of spaces every gap must have).
 * - Extra Spaces: S % G (The remainder spaces distributed one-by-one to the
 * GAPS on the LEFT).
 * - The first 'Extra Spaces' number of gaps receive (Base Spaces + 1), and
 * the remaining gaps receive (Base Spaces). This ensures the spacing is
 * as even as possible, preferring larger gaps on the left.
 *
 * 5. Time Complexity: O(N)
 * Where N is the total number of characters across all words. Each word
 * is visited once for grouping and once for justification.
 * * Space Complexity: O(N)
 * To store the resulting justified strings.
 */