#include <vector>
#include <stack>

class Solution {
public:
    std::vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> result;
        std::stack<TreeNode*> st;
        TreeNode* curr = root;

        while (curr != nullptr || !st.empty()) {

            while (curr != nullptr) {
                st.push(curr);
                curr = curr->left;
            }

            curr = st.top();
            st.pop();

            result.push_back(curr->val);

            curr = curr->right;
        }

        return result;
    }
};

/*
 * Approach: Iterative using Stack
 * * Logic:
 * 1. Goal: Visit nodes in Left -> Root -> Right order.
 * 2. Structure: We use a Stack to store nodes that we have passed but not yet processed
 * (because we had to go deeper into their left children first).
 * 3. The Outer Loop: Runs as long as there are nodes to process (either 'curr' is pointing
 * to a node, or there are nodes waiting in the stack).
 * 4. The Inner Loop (Go Left):
 * - From the current node, we keep moving strictly to the left.
 * - We push every node we encounter onto the stack.
 * - This continues until 'curr' becomes null (we hit the bottom-left).
 * 5. Processing (The Pivot):
 * - We pop the top node from the stack. This node is the "left-most" unprocessed node
 * available.
 * - We add its value to the result.
 * 6. The Transition (Go Right):
 * - After processing a node (Left and Root are done relative to the subtree), we move
 * 'curr' to 'curr->right'.
 * - In the next iteration of the outer loop, we will try to go left again from this
 * new right child.
 * * Time Complexity: O(N)
 * We visit every node exactly once.
 * * Space Complexity: O(H)
 * The stack size depends on the height of the tree (H). In the worst case (skewed tree),
 * it is O(N). In a balanced tree, it is O(log N).
 */