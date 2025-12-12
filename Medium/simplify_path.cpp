#include <string>
#include <vector>
#include <sstream>

class Solution {
public:
    std::string simplifyPath(std::string path) {
        std::vector<std::string> stack;
        std::stringstream ss(path);
        std::string component;

        while (std::getline(ss, component, '/')) {
            if (component == "" || component == ".") {
                continue;
            }

            if (component == "..") {
                if (!stack.empty()) {
                    stack.pop_back();
                }
            }
            else {
                stack.push_back(component);
            }
        }
        std::string result = "";
        for (const std::string& dir : stack) {
            result += "/" + dir;
        }

        return result.empty() ? "/" : result;
    }
};

/*
 * Approach: Stack with Tokenization
 * * Logic:
 * 1. Tokenization: The input string is a sequence of directory names separated by
 * slashes. We use 'std::stringstream' and 'std::getline' to split the string
 * by the delimiter '/'.
 * 2. The Stack: We use a 'std::vector' as a stack to keep track of the current
 * path hierarchy.
 * 3. Processing Tokens:
 * - Empty String ("") or Dot ("."): These are "no-ops". Multiple slashes (//)
 * result in empty tokens, and a single dot means "stay here". We skip these.
 * - Double Dot (".."): This means "go to parent". If our stack is not empty,
 * we pop the last added directory. If the stack is empty (we are at root),
 * we do nothing (cannot go above root).
 * - Directory Name: Any other string is a valid directory. We push it onto the stack.
 * 4. Reconstruction: After processing all tokens, the vector contains the
 * canonical path components in order. We iterate through the vector and append
 * "/" + directory_name to our result string.
 * 5. Edge Case: If the resulting string is empty (e.g., input was "/../"),
 * we must return "/" representing the root.
 * * Time Complexity: O(N)
 * We process each character of the string roughly once during splitting and joining.
 * * Space Complexity: O(N)
 * To store the stack of directory names.
 */