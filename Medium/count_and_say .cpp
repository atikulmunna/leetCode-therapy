#include <string>

class Solution {
public:
    std::string countAndSay(int n) {
        if (n == 1) return "1";

        std::string result = "1";

        for (int i = 1; i < n; i++) {
            std::string current = "";
            int count = 1;

            for (int j = 0; j < result.length(); j++) {
                if (j + 1 < result.length() && result[j] == result[j + 1]) {
                    count++;
                } else {
                    current += std::to_string(count) + result[j];
                    count = 1;
                }
            }
            result = current;
        }

        return result;
    }
};

/*
 * Approach: Iterative Simulation (Run-Length Encoding)
 * * Logic:
 * 1. Base Case: If n is 1, we simply return "1" as defined.
 * 2. We start with the string "1" stored in the variable 'result'.
 * 3. We loop 'n - 1' times. Each iteration transforms the 'result' string into
 * the next sequence in the pattern.
 * 4. Inside the transformation loop:
 * - We assume the current character is the start of a group and initialize 'count' to 1.
 * - We check the neighbor (j + 1). If the neighbor exists and is identical to the
 * current character, we increment 'count'.
 * - If the neighbor is different (or we are at the end of the string), the group
 * is finished. We "say" the group by appending the count and the digit itself
 * to a temporary string 'current'.
 * - We then reset 'count' to 1 for the next group.
 * 5. After scanning the entire string, we update 'result' to be the new 'current' string.
 * * Time Complexity: O(M)
 * Where M is the total number of digits generated across all iterations. The sequence
 * grows roughly by a factor of 1.3 each step.
 * * Space Complexity: O(M)
 * We store the string for the current iteration.
 */