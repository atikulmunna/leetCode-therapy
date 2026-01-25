class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;

        while (head) {
            if (head->next && head->val == head->next->val) {
                while (head->next && head->val == head->next->val) {
                    head = head->next;
                }
                prev->next = head->next;
            } else {
                prev = prev->next;
            }
            head = head->next;
        }

        return dummy->next;
    }
};

/*
 * Approach: Iterative with Sentinel (Dummy) Node
 * * Logic:
 * 1. Sentinel Node: Since the head of the list itself might be removed (if it's a duplicate),
 * we use a 'dummy' node pointing to the head. This simplifies edge case handling.
 * 2. Two Pointers:
 * - 'prev': Tracks the last node that is guaranteed to be distinct (safe).
 * - 'head': Used to scan the list and detect duplicates.
 * 3. Duplicate Detection:
 * - We check if 'head' and 'head->next' have the same value.
 * - If they do, we enter a loop to skip ALL nodes with that value. 'head' ends up pointing
 * to the last duplicate in the sequence.
 * - We then bypass the entire sequence by setting 'prev->next' to 'head->next'.
 * Note that we do NOT move 'prev' forward here, because the new node at 'head->next'
 * might also be the start of a duplicate sequence (e.g., 1->2->2->3->3).
 * 4. Distinct Case:
 * - If 'head' and 'head->next' are different, 'head' is unique. We verify this node
 * by moving 'prev' forward to 'head'.
 * * Time Complexity: O(N)
 * We traverse the linked list exactly once.
 * * Space Complexity: O(1)
 * We use only pointers for logic (ignoring the dummy node allocation).
 */