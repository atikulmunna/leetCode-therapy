#include <string>
#include <unordered_map>

class Solution {
public:
    int romanToInt(std::string s) {
        std::unordered_map<char, int> romanMap = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}
        };

        int total = 0;
        int n = s.length();

        for (int i = 0; i < n; i++) {
            if (i < n - 1 && romanMap[s[i]] < romanMap[s[i + 1]]) {
                total -= romanMap[s[i]];
            } else {
                total += romanMap[s[i]];
            }
        }

        return total;
    }
};

/*
 * Approach: Left-to-Right Pass with Look-Ahead
 * * Logic:
 * 1. We map each Roman character to its integer value using a Hash Map for
 * quick access (O(1)).
 * 2. We initialize 'total' to 0 and iterate through the string using index 'i'.
 * 3. Inside the loop, we check the "Look Ahead" condition:
 * - Is there a next character (i < n - 1)?
 * - Is the value of the current character LESS than the value of the next character?
 * 4. If both are true, it means we are in a subtractive case (like IV or CM).
 * We subtract the current value from the total.
 * 5. Otherwise (normal case or last character), we add the current value to the total.
 * 6. This single pass correctly handles complex numbers like MCMXCIV because
 * the subtraction operations balance out the additions correctly.
 * * Time Complexity: O(n)
 * We traverse the string exactly once.
 * * Space Complexity: O(1)
 * The map size is constant (7 symbols), regardless of input size.
 */