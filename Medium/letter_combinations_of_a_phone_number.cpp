#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::string> letterCombinations(std::string digits) {
        if (digits.empty()) {
            return {};
        }

        std::vector<std::string> result;
        std::string current;
        std::vector<std::string> mapping = {
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        solve(digits, 0, current, mapping, result);
        return result;
    }

private:
    void solve(const std::string& digits, int index, std::string& current,
               const std::vector<std::string>& mapping, std::vector<std::string>& result) {

        if (index == digits.length()) {
            result.push_back(current);
            return;
        }

        int digit = digits[index] - '0';
        std::string letters = mapping[digit];

        for (char letter : letters) {
            current.push_back(letter);
            solve(digits, index + 1, current, mapping, result);
            current.pop_back();
        }
    }
};

/*
 * Approach: Backtracking (Depth-First Search)
 * * Logic:
 * 1. Mapping: We create a lookup table (vector or array) where index 'i' stores
 * the string of letters corresponding to digit 'i'. (e.g., mapping[2] = "abc").
 * 2. Edge Case: If the input string is empty, we return an empty vector immediately.
 * 3. Recursion (The 'solve' function):
 * - We maintain a 'current' string representing the path we have built so far.
 * - We maintain an 'index' integer representing which digit in the input string
 * we are currently processing.
 * 4. Base Case: If 'index' equals the length of the input digits, it means we
 * have formed a complete combination. We add 'current' to our 'result' list
 * and return.
 * 5. Recursive Step:
 * - We identify the digit at the current index.
 * - We retrieve the possible letters for that digit.
 * - We iterate through each letter:
 * a. Add the letter to 'current'.
 * b. Recursively call 'solve' for the next index (index + 1).
 * c. Backtrack: Remove the letter (pop_back) from 'current' to prepare for
 * the next iteration of the loop.
 * * Time Complexity: O(4^N * N)
 * In the worst case (digits 7 or 9), each digit has 4 choices. N is the number of digits.
 * * Space Complexity: O(N)
 * The recursion stack depth goes up to N.
 */