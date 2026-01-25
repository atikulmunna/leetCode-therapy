class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* lessHead = new ListNode(0);
        ListNode* greaterHead = new ListNode(0);

        ListNode* less = lessHead;
        ListNode* greater = greaterHead;

        while (head != nullptr) {
            if (head->val < x) {
                less->next = head;
                less = less->next;
            } else {
                greater->next = head;
                greater = greater->next;
            }
            head = head->next;
        }

        greater->next = nullptr;
        less->next = greaterHead->next;

        return lessHead->next;
    }
};

/*
 * Approach: Two Pointer / Two Dummy Heads
 * * Logic:
 * 1. Strategy: Instead of trying to move nodes in-place within a single list (which is messy),
 * we build two new lists: "less" and "greater".
 * 2. Initialization: We create two dummy nodes, 'lessHead' and 'greaterHead', to serve
 * as anchors. 'less' and 'greater' pointers track the tails of these lists.
 * 3. Traversal: We iterate through the original list.
 * - If head->val < x: Append to the 'less' list.
 * - Else: Append to the 'greater' list.
 * 4. Merging:
 * - Terminate the 'greater' list by setting greater->next = nullptr. This is vital because
 * the last node in the 'greater' list might still point to a node that was moved to the 'less' list,
 * creating a cycle.
 * - Link the end of the 'less' list to the beginning of the 'greater' list (less->next = greaterHead->next).
 * 5. Return: Return lessHead->next (skipping the dummy). If 'less' is empty, this correctly
 * returns the start of 'greater' (or null if both are empty).
 * * Time Complexity: O(N)
 * We traverse the list exactly once.
 * * Space Complexity: O(1)
 * We only verify pointers and reorganize existing nodes; we do not allocate new nodes for values.
 */