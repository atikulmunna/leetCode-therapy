class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) {
            return true;
        }
        return isMirror(root->left, root->right);
    }

private:
    bool isMirror(TreeNode* t1, TreeNode* t2) {
        if (!t1 && !t2) {
            return true;
        }

        if (!t1 || !t2) {
            return false;
        }

        if (t1->val != t2->val) {
            return false;
        }

        return isMirror(t1->left, t2->right) && isMirror(t1->right, t2->left);
    }
};

/*
 * Approach: Depth-First Search (Recursive Mirroring)
 * * Logic:
 * 1. Initial Split: The root itself is trivially symmetric. The real test is whether
 * the root's left subtree is a mirror reflection of its right subtree. We pass
 * root->left and root->right into a helper function.
 * 2. Parallel Traversal: The 'isMirror' function takes two nodes, one from the left
 * branch and one from the right branch.
 * 3. Base Conditions:
 * - If both are nullptr, we've reached the bottom evenly (return true).
 * - If only one is nullptr, the tree is lopsided (return false).
 * 4. Value Validation: If both nodes exist but their values don't match, the symmetry
 * is broken (return false).
 * 5. The Criss-Cross Recursion: This is the core of the algorithm. We must check two pairs:
 * - The "Outer" children: t1's left child matched against t2's right child.
 * - The "Inner" children: t1's right child matched against t2's left child.
 * Both of these recursive checks must return true for the current subtrees to be symmetric.
 * * Time Complexity: O(N)
 * We visit each node in the tree exactly once to perform the comparison.
 * * Space Complexity: O(H)
 * The space is dictated by the recursion stack. In the worst case (a completely linear,
 * unbalanced tree), it would be O(N). For a balanced symmetric tree, it is O(log N),
 * where H is the height of the tree.
 */