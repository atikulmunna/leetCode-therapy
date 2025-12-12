#include <string>
#include <vector>
#include <numeric>

class Solution {
public:
    std::string getPermutation(int n, int k) {
        std::vector<int> numbers;
        int fact = 1;

        for (int i = 1; i < n; i++) {
            fact *= i;
            numbers.push_back(i);
        }
        numbers.push_back(n);

        k--;
        std::string result = "";

        for (int i = n - 1; i >= 0; i--) {
            int index = k / fact;

            result += std::to_string(numbers[index]);

            numbers.erase(numbers.begin() + index);

            k %= fact;

            if (i > 0) {
                fact /= i;
            }
        }

        return result;
    }
};

/*
 * Approach: Factorial Number System (Mathematical Construction)
 * * Logic:
 * 1. Brute forcing all permutations takes O(N!), which is too slow.
 * We can construct the sequence directly.
 * 2. Grouping: For N numbers, there are N! permutations. These permutations
 * are divided into N groups based on their first digit, each group containing
 * (N-1)! elements.
 * 3. Selection:
 * - We find the index of the current group by calculating 'k / (N-1)!'.
 * - This index tells us which number from our available list (initially 1..N)
 * goes next.
 * 4. Update:
 * - After picking a number, we remove it from the list (shifting remaining numbers).
 * - We update 'k' to 'k % (N-1)!' to find the relative position within the
 * selected group.
 * - We update the factorial value for the next step (dividing by the current index).
 * 5. 0-Indexing: We decrement k at the start because the problem gives a
 * 1-based index, but modulo arithmetic works naturally with 0-based indices.
 * * Time Complexity: O(N^2)
 * We iterate N times. Inside the loop, erasing an element from a vector takes O(N).
 * * Space Complexity: O(N)
 * To store the available numbers and the result string.
 */