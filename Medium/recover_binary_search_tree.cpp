#include <algorithm>

class Solution {
private:
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;
    TreeNode* prev = nullptr;

    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        if (prev != nullptr && prev->val > root->val) {

            if (first == nullptr) {
                first = prev;
                second = root;
            } else {

                second = root;
            }
        }
        prev = root;
        inorder(root->right);
    }

public:
    void recoverTree(TreeNode* root) {
        first = nullptr;
        second = nullptr;
        prev = nullptr;
        inorder(root);
        if (first && second) {
            std::swap(first->val, second->val);
        }
    }
};

/*
 * Approach: Inorder Traversal (DFS)
 * * Logic:
 * 1. Property: An inorder traversal of a BST yields a sorted sequence (e.g., 1, 2, 3, 4, 5).
 * 2. The Swap Effect: If two nodes are swapped, the sequence will have "dips" where a larger
 * number precedes a smaller one.
 * - Example (Non-adjacent swap 1 & 5): 5, 2, 3, 4, 1.
 * - Dip 1: 5 > 2. 'First' is 5.
 * - Dip 2: 4 > 1. 'Second' is 1.
 * - Example (Adjacent swap 2 & 3): 1, 3, 2, 4, 5.
 * - Dip 1: 3 > 2. 'First' is 3, 'Second' is 2. (No second dip occurs).
 * 3. Algorithm:
 * - We maintain a 'prev' pointer tracking the previously visited node in the inorder sequence.
 * - If prev->val > root->val, we found a violation.
 * - If it's the first violation (first == null), we mark 'prev' as the first swapped node.
 * - We also tentatively mark 'root' as the second node (handles adjacent case).
 * - If we find a second violation later, we update 'second' to the current 'root'.
 * 4. Fix: After the traversal, swap the values of 'first' and 'second'.
 * * Time Complexity: O(N)
 * We traverse the tree once.
 * * Space Complexity: O(H)
 * For the recursion stack. (Can be improved to O(1) using Morris Traversal).
 */