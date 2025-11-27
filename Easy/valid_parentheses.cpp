#include <stack>
#include <string>

class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> st;

        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } else {
                if (st.empty()) {
                    return false;
                }

                char top = st.top();
                if ((c == ')' && top == '(') ||
                    (c == '}' && top == '{') ||
                    (c == ']' && top == '[')) {
                    st.pop();
                    } else {
                        return false;
                    }
            }
        }

        return st.empty();
    }
};

/*
 * Approach: Stack (Last-In, First-Out)
 * * Logic:
 * 1. We iterate through the string character by character.
 * 2. If the character is an OPEN bracket ('(', '{', '['), we push it onto the stack.
 * This represents an expectation that it must be closed later.
 * 3. If the character is a CLOSE bracket:
 * - First, we check if the stack is empty. If it is, it means we found a closing
 * bracket without a corresponding opening bracket, so we return false.
 * - Next, we peek at the top of the stack. We check if the pair matches
 * (e.g., if current is ')' and top is '(').
 * - If they match, we pop the opening bracket off the stack (the pair is resolved).
 * - If they do not match (e.g., current is ']' but top is '('), the order is
 * wrong, so we return false.
 * 4. After the loop finishes, we perform a final check: is the stack empty?
 * - If yes, all brackets were matched correctly.
 * - If no, there are unmatched opening brackets remaining (e.g., "(()"), so return false.
 * * Time Complexity: O(n)
 * We traverse the string once, performing O(1) push/pop operations.
 * * Space Complexity: O(n)
 * In the worst case (e.g., "((((("), the stack grows to the size of the input string.
 */