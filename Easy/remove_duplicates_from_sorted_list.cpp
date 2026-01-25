class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* current = head;

        while (current != nullptr && current->next != nullptr) {
            if (current->val == current->next->val) {
                current->next = current->next->next;
            } else {
                current = current->next;
            }
        }

        return head;
    }
};

/*
 * Approach: Linear Scan
 * * Logic:
 * 1. Traversal: We initialize a pointer 'current' to the head of the list.
 * 2. Condition: We loop as long as 'current' and 'current->next' are not null.
 * 3. Duplicate Detection:
 * - We compare the value of the current node with the value of the next node.
 * - If they are equal (Duplicate), we delete the next node by relinking
 * 'current->next' to 'current->next->next'.
 * - Important: We do NOT advance 'current' in this case. We must stay on the
 * same node to check if the *new* next node is also a duplicate (e.g., 1->1->1).
 * 4. Move Forward:
 * - If the values are different, the current node is unique (or we've finished
 * removing its duplicates). We advance 'current' to the next node.
 * * Time Complexity: O(N)
 * We visit each node exactly once.
 * * Space Complexity: O(1)
 * We modify the list in-place using a single pointer.
 */