#include <vector>

class Solution {
public:
    std::vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return buildTrees(1, n);
    }

private:
    std::vector<TreeNode*> buildTrees(int start, int end) {
        std::vector<TreeNode*> allTrees;

        if (start > end) {
            allTrees.push_back(nullptr);
            return allTrees;
        }

        for (int i = start; i <= end; ++i) {
            std::vector<TreeNode*> leftTrees = buildTrees(start, i - 1);
            std::vector<TreeNode*> rightTrees = buildTrees(i + 1, end);

            for (TreeNode* l : leftTrees) {
                for (TreeNode* r : rightTrees) {
                    TreeNode* currentRoot = new TreeNode(i);
                    currentRoot->left = l;
                    currentRoot->right = r;
                    allTrees.push_back(currentRoot);
                }
            }
        }

        return allTrees;
    }
};

/*
 * Approach: Recursion (Divide and Conquer)
 * * Logic:
 * 1. Recursive Definition: To construct all BSTs for the range [start, end], we consider
 * every integer 'i' within that range as a potential root.
 * 2. Splitting: Once 'i' is chosen as the root:
 * - The left child must form a BST using values [start, i-1].
 * - The right child must form a BST using values [i+1, end].
 * 3. Recursive Calls: We call the function recursively to get the list of ALL valid
 * left subtrees and ALL valid right subtrees.
 * 4. Combination: We use a nested loop to pair every possible left subtree with
 * every possible right subtree. For each pair, we create a new root node with value 'i'
 * and attach the subtrees.
 * 5. Base Case: If start > end, it means there are no numbers to put in the tree.
 * We return a list containing a single 'nullptr', representing an empty subtree.
 * This is crucial for the nested loops to run at least once (attaching a null child).
 * * Time Complexity: Catalan Number
 * The number of unique BSTs is given by the Catalan numbers. The complexity is roughly
 * O(4^n / n^(1/2)). It grows very fast.
 * * Space Complexity: O(4^n / n^(1/2))
 * We store all the generated trees.
 */