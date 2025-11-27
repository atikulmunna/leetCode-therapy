#include <string>
#include <vector>

class Solution {
public:
    std::string intToRoman(int num) {
        const std::vector<std::pair<int, std::string>> valToSymbol = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
            {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
        };

        std::string result = "";

        for (const auto& pair : valToSymbol) {
            while (num >= pair.first) {
                result += pair.second;
                num -= pair.first;
            }
        }

        return result;
    }
};

/*
 * Approach: Greedy Algorithm with Extended Lookup Table
 * * Logic:
 * 1. We treat the problem like a "Change Making" problem (making change with the fewest coins).
 * 2. To handle the subtraction rules (like IV, IX, CM) without complex conditional logic,
 * we treat these combinations as distinct valid "coins" or symbols.
 * 3. We create a lookup table (vector of pairs) sorted from largest value to smallest:
 * 1000->M, 900->CM, 500->D, ... 1->I.
 * 4. We iterate through this table. For each value, we check if our number is
 * greater than or equal to it.
 * 5. While the number is large enough, we append the corresponding symbol to our
 * result string and subtract the value from our number.
 * 6. We repeat this until the number reaches 0.
 * * Time Complexity: O(1)
 * Although it looks like a loop, the constraints (num <= 3999) mean the loop runs
 * a finite, constant number of times (max 15 iterations for 3888).
 * * Space Complexity: O(1)
 * The size of the lookup table is fixed and small.
 */