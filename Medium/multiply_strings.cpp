#include <string>
#include <vector>

class Solution {
public:
    std::string multiply(std::string num1, std::string num2) {
        if (num1 == "0" || num2 == "0") return "0";

        int n = num1.size();
        int m = num2.size();
        std::vector<int> pos(n + m, 0);

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int mul = (num1[i] - '0') * (num2[j] - '0');

                int p1 = i + j;
                int p2 = i + j + 1;

                int sum = mul + pos[p2];

                pos[p2] = sum % 10;

                pos[p1] += sum / 10;
            }
        }

        std::string sb;
        for (int p : pos) {
            if (!(sb.empty() && p == 0)) {
                sb.push_back(p + '0');
            }
        }

        return sb.empty() ? "0" : sb;
    }
};

/*
 * Approach: Simulation of Vertical Multiplication
 * * Logic:
 * 1. Constraints: We cannot convert strings to integers directly because 200 digits
 * far exceed the capacity of long long. We must manipulate the digits manually.
 * 2. Setup: A product of a number with length N and a number with length M will
 * have a length of at most N + M. We create an integer array 'pos' of this size.
 * 3. Double Loop: We iterate through both strings from right to left (indices n-1 to 0).
 * 4. Index Math: When multiplying digit at num1[i] and num2[j]:
 * - The result impacts indices [i + j] and [i + j + 1] in the 'pos' array.
 * - [i + j + 1] is the standard position (remainder).
 * - [i + j] is the carry position.
 * 5. Accumulation: Crucially, we add the product to whatever value is *already* * in pos[i + j + 1] (from previous steps). We take the modulo for the current
 * spot and add the division result (carry) to the left neighbor.
 * 6. String Build: Finally, we iterate through the 'pos' array and convert integers
 * to characters. We skip any leading zeros (unless the result is just "0").
 * * Time Complexity: O(N * M)
 * We visit every combination of digit pairs exactly once.
 * * Space Complexity: O(N + M)
 * Used for the 'pos' array to store the intermediate calculation.
 */