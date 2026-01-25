class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) {
            return true;
        }

        if (!p || !q || p->val != q->val) {
            return false;
        }

        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

/*
 * Approach: Depth-First Search (Recursion)
 * * Logic:
 * 1. Strategy: We traverse both trees in lock-step. We need to verify three things
 * at every node:
 * a) Structure: Do both nodes exist, or are both null?
 * b) Value: Do the nodes have the same integer value?
 * c) Subtrees: Are the left subtrees identical AND the right subtrees identical?
 * 2. Base Cases:
 * - Success: If (!p && !q), both pointers have reached null at the same time.
 * This path is identical. Return true.
 * - Failure: If one is null and the other isn't (!p || !q), the structure differs.
 * Return false.
 * 3. Value Check:
 * - If p->val != q->val, the values differ. Return false.
 * 4. Recursion:
 * - We return true ONLY if both recursive calls (left vs left, right vs right) return true.
 * * Time Complexity: O(N)
 * We visit each node in the trees exactly once (where N is the number of nodes in the smaller tree).
 * * Space Complexity: O(H)
 * The recursion stack depth depends on the height of the tree.
 */