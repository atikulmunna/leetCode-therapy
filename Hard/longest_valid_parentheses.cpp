#include <string>
#include <stack>
#include <algorithm>

class Solution {
public:
    int longestValidParentheses(std::string s) {
        std::stack<int> indices;
        indices.push(-1);
        int maxLen = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                indices.push(i);
            } else {
                indices.pop();
                if (indices.empty()) {
                    indices.push(i);
                } else {
                    maxLen = std::max(maxLen, i - indices.top());
                }
            }
        }

        return maxLen;
    }
};

/*
 * Approach: Stack with Index Tracking
 * * Logic:
 * 1. Unlike the basic "Valid Parentheses" problem, we need to calculate lengths.
 * Therefore, we store indices in the stack instead of characters.
 * 2. Base Case: We push -1 onto the stack initially. This acts as a "base" marker
 * so that if the valid substring starts at index 0, we can calculate length as
 * (current_index - (-1)).
 * 3. Iterate through the string:
 * - If we see '(': Push the index 'i'.
 * - If we see ')': Pop the top element (representing the matching '(').
 * 4. After popping:
 * - If the stack is empty, it means this ')' has no matching '(' and breaks the
 * continuity. We push the current index 'i' to serve as the new "base" marker for
 * any valid substrings that might follow.
 * - If the stack is NOT empty, we have found a valid substring. The current length
 * is 'i - indices.top()'. We update 'maxLen'.
 * * Time Complexity: O(n)
 * We traverse the string once, pushing and popping each index at most once.
 * * Space Complexity: O(n)
 * In the worst case (e.g., "((((("), the stack size grows to n.
 */