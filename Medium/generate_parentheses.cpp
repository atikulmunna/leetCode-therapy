#include <vector>
#include <string>

class Solution {
private:
    void solve(int n, int openCount, int closeCount, std::string& current, std::vector<std::string>& result) {
        if (openCount == n && closeCount == n) {
            result.push_back(current);
            return;
        }

        if (openCount < n) {
            current.push_back('(');
            solve(n, openCount + 1, closeCount, current, result);
            current.pop_back();
        }


        if (closeCount < openCount) {
            current.push_back(')');
            solve(n, openCount, closeCount + 1, current, result);
            current.pop_back();
        }
    }

public:
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> result;
        std::string current;
        solve(n, 0, 0, current, result);
        return result;
    }
};

/*
 * Approach: Backtracking (Depth-First Search)
 * * Logic:
 * 1. The solution uses a recursive helper function (solve) to explore the decision
 * tree of placing '(' or ')'.
 * 2. State Tracking: The function tracks the maximum allowed pairs (n), the
 * current number of open parentheses placed (openCount), and the current
 * number of close parentheses placed (closeCount).
 * 3. Base Case: The recursion stops when both openCount and closeCount equal 'n',
 * indicating a valid, complete string of length 2n.
 * 4. Constraint 1 (Open Bracket): A '(' is added only if openCount < n.
 * This ensures we don't exceed the required number of open brackets.
 * 5. Constraint 2 (Close Bracket): A ')' is added only if closeCount < openCount.
 * This ensures the string remains "well-formed" at every step (i.e., we never
 * have a closing bracket without a corresponding unclosed open bracket).
 * 6. Backtracking: After each recursive call, the last character is removed
 * (current.pop_back()) to backtrack to the previous state and explore the next possible choice.
 * * Time Complexity: O(4^n / sqrt(n))
 * The complexity is proportional to the Nth Catalan number, $C_n$, which is the number of valid combinations.
 * * Space Complexity: O(n)
 * This is dominated by the recursion stack depth.
 */