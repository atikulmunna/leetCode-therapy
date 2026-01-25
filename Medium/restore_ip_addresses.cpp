#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::string> restoreIpAddresses(std::string s) {
        std::vector<std::string> result;
        std::string currentIP;
        backtrack(s, 0, 0, currentIP, result);
        return result;
    }

private:
    void backtrack(const std::string& s, int index, int dots, std::string currentIP, std::vector<std::string>& result) {
        if (dots == 4) {
            if (index == s.length()) {
                currentIP.pop_back();
                result.push_back(currentIP);
            }
            return;
        }

        for (int i = 1; i <= 3; ++i) {
            if (index + i > s.length()) break;

            std::string segment = s.substr(index, i);

            if ((segment.length() > 1 && segment[0] == '0') ||
                (std::stoi(segment) > 255)) {
                continue;
            }

            backtrack(s, index + i, dots + 1, currentIP + segment + ".", result);
        }
    }
};

/*
 * Approach: Backtracking
 * * Logic:
 * 1. Structure: We need to partition the string into exactly 4 segments. This implies
 * placing 3 dots, or essentially making 4 recursive decisions.
 * 2. Recursive Step:
 * - At 'index', we attempt to form a segment of length 1, 2, and 3.
 * - For each length, we extract the substring.
 * 3. Validation Rules:
 * - Leading Zeros: If the segment length is > 1 and it starts with '0', it's invalid (e.g., "01").
 * However, a single digit "0" is valid.
 * - Value Limit: Converting the substring to an integer must yield a value <= 255.
 * 4. Backtracking Execution:
 * - If valid, we append the segment and a dot to our 'currentIP' string and recurse
 * with 'dots + 1'.
 * - Note: In this implementation, we pass 'currentIP' by value (copy) for simplicity,
 * which handles the "un-choose" step implicitly. For higher performance, one could
 * use a reference and explicit push/pop operations.
 * 5. Base Case:
 * - If 'dots' reaches 4, we check if we have consumed the entire string ('index == s.length()').
 * - If so, we remove the trailing dot and store the result.
 * * Time Complexity: O(1)
 * The depth of the tree is fixed at 4, and the branching factor is at most 3. The
 * total number of operations is constant (3^4 = 81 iterations max). The string length
 * is limited (max 12 digits for a valid IP).
 * * Space Complexity: O(1)
 * The recursion stack depth is fixed at 4.
 */