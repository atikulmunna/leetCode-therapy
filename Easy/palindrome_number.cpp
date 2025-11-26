class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        long reversed = 0;
        int original = x;

        while (x > 0) {
            reversed = reversed * 10 + x % 10;
            x /= 10;
        }

        return original == reversed;
    }
};

/*
 * Approach: Revert and Compare
 * * Logic:
 * 1. Edge Case Handling:
 * - Negative numbers cannot be palindromes (e.g., -121 != 121-), so return false.
 * - Numbers ending in 0 (other than 0 itself) cannot be palindromes because
 * integers cannot start with 0. Return false.
 * 2. We create a copy of the original number ('original') because the 'x' variable
 * will be destroyed during the reversal process.
 * 3. We use a 'long' variable for 'reversed'. This is critical because reversing
 * a large 32-bit integer (like 1999999999) results in a number (9999999991)
 * that exceeds the maximum size of a standard 'int', causing an overflow error.
 * 4. We loop through 'x', extracting the last digit (x % 10) and building the
 * reversed number (reversed * 10 + digit).
 * 5. Finally, we compare the 'original' number with the 'reversed' version.
 * * Time Complexity: O(log10(n))
 * We process each digit of the number once.
 * * Space Complexity: O(1)
 * We use constant extra space.
 */