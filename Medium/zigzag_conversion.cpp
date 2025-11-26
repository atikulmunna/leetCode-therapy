#include <string>
#include <vector>

class Solution {
public:
    std::string convert(std::string s, int numRows) {
        if (numRows == 1) return s;

        std::vector<std::string> rows(std::min(numRows, int(s.size())));
        int curRow = 0;
        bool goingDown = false;

        for (char c : s) {
            rows[curRow] += c;
            if (curRow == 0 || curRow == numRows - 1) {
                goingDown = !goingDown;
            }
            curRow += goingDown ? 1 : -1;
        }

        std::string result;
        for (std::string row : rows) {
            result += row;
        }
        return result;
    }
};

/*
 * Approach: Simulation (Row-by-Row)
 * * Logic:
 * 1. We handle the edge case where numRows is 1. In this case, no zigzagging
 * occurs, so we simply return the original string.
 * 2. We create a vector of strings, where each element represents a row in the
 * zigzag pattern. We limit the number of rows to the lesser of numRows or the
 * string length (to save space if the string is very short).
 * 3. We iterate through the input string character by character.
 * 4. We maintain a 'curRow' index and a boolean flag 'goingDown'.
 * 5. If we reach the top row (0) or the bottom row (numRows - 1), we flip
 * the 'goingDown' flag to change direction.
 * 6. We place the character in the current row and update 'curRow' (increment
 * if going down, decrement if going up).
 * 7. Finally, we concatenate all the strings in our vector to form the result.
 * * Time Complexity: O(n)
 * We visit every character in the input string exactly once.
 * * Space Complexity: O(n)
 * We store all characters of the string in the 'rows' vector.
 */