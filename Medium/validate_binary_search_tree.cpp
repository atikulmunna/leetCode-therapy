#include <climits>

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return validate(root, LONG_MIN, LONG_MAX);
    }

private:
    bool validate(TreeNode* node, long long minVal, long long maxVal) {
        if (!node) {
            return true;
        }

        if (node->val <= minVal || node->val >= maxVal) {
            return false;
        }

        return validate(node->left, minVal, node->val) &&
               validate(node->right, node->val, maxVal);
    }
};

/*
 * Approach: Depth-First Search with Valid Ranges
 * * Logic:
 * 1. Constraint Propagation: In a BST, a node determines the upper limit for its
 * left subtree and the lower limit for its right subtree.
 * 2. Function Signature: We define a helper function 'validate' that takes the
 * current node and the allowable range (minVal, maxVal).
 * 3. Base Case: An empty node (nullptr) is always valid.
 * 4. Validation:
 * - We check if the current node's value is strictly within (minVal, maxVal).
 * - If node->val <= minVal or node->val >= maxVal, the BST property is violated.
 * 5. Recursion:
 * - When moving Left: The new upper bound is the current node's value.
 * Range becomes (minVal, node->val).
 * - When moving Right: The new lower bound is the current node's value.
 * Range becomes (node->val, maxVal).
 * 6. Data Types: We use 'long long' for the min/max bounds. This is necessary
 * because the problem constraints allow node values to be INT_MIN or INT_MAX.
 * If we used 'int', comparing INT_MAX + 1 would cause overflow or false negatives.
 * * Time Complexity: O(N)
 * We visit every node exactly once.
 * * Space Complexity: O(H)
 * O(H) for the recursion stack, where H is the height of the tree.
 */