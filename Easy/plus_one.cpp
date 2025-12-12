#include <vector>
#include <numeric>

class Solution {
public:
    std::vector<int> plusOne(std::vector<int>& digits) {
        int n = digits.size();

        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }
            digits[i] = 0;
        }
        std::vector<int> new_digits(n + 1);

        new_digits[0] = 1;

        return new_digits;
    }
};

/*
 * Approach: Reverse Iteration with Carry Simulation
 * * Logic:
 * 1. We start the simulation from the least significant digit (rightmost).
 * 2. If the current digit is NOT 9, we increment it by one and return the
 * array immediately, as no further carry is needed.
 * 3. If the current digit IS 9, we set it to 0 and the carry-over implicitly
 * continues to the next digit via the loop.
 * 4. If the loop completes, it means the number was composed entirely of 9s (e.g., 999).
 * 5. In the "All Nines" case, we must increase the array size by one. We create
 * a new array initialized to zeros and set the first element (the new carry) to 1.
 * * Time Complexity: O(N)
 * In the worst case (all nines), we iterate through all N digits and create a new array.
 * * Space Complexity: O(1) in the non-all-nines case. O(N) in the worst case (all nines)
 * for creating the new result vector.
 */