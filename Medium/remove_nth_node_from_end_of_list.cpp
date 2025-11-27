class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* fast = dummy;
        ListNode* slow = dummy;

        for (int i = 0; i <= n; i++) {
            fast = fast->next;
        }

        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        ListNode* nodeToDelete = slow->next;
        slow->next = slow->next->next;

        delete nodeToDelete;
        ListNode* result = dummy->next;
        delete dummy;

        return result;
    }
};

/*
 * Approach: One-Pass with Two Pointers (The "Gap" Method)
 * * Logic:
 * 1. Dummy Node: We create a 'dummy' node pointing to the head. This is crucial
 * for handling edge cases, specifically when the node to be removed is the
 * head itself (e.g., list [1], n=1).
 * 2. Setup Pointers: We initialize two pointers, 'fast' and 'slow', both pointing
 * to the dummy node.
 * 3. Create the Gap: We move the 'fast' pointer forward by n + 1 steps.
 * This creates a gap of 'n' nodes between 'fast' and 'slow'. We do n + 1
 * so that 'slow' ends up one node *before* the target, allowing us to unlink it.
 * 4. Slide the Window: We move both pointers forward simultaneously until 'fast'
 * reaches nullptr (the end of the list).
 * 5. Remove Node: Because of the fixed gap, 'slow' is now pointing to the node
 * immediately preceding the target node. We update 'slow->next' to point to
 * 'slow->next->next', effectively skipping the target node.
 * 6. Memory Management: We explicitly delete the removed node and the dummy
 * node to prevent memory leaks (good practice in C++).
 * 7. Return: We return dummy->next, which points to the (possibly new) head
 * of the list.
 * * Time Complexity: O(L)
 * We traverse the list of length L exactly once.
 * * Space Complexity: O(1)
 * We use only constant extra space for pointers.
 */