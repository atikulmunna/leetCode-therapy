class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* groupPrev = dummy;

        while (true) {
            ListNode* kth = groupPrev;
            for (int i = 0; i < k; i++) {
                kth = kth->next;
                if (!kth) {
                    ListNode* result = dummy->next;
                    delete dummy;
                    return result;
                }
            }

            ListNode* groupNext = kth->next;
            ListNode* prev = groupNext;
            ListNode* curr = groupPrev->next;
            ListNode* newGroupTail = curr;

            for (int i = 0; i < k; i++) {
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }

            groupPrev->next = prev;
            groupPrev = newGroupTail;
        }
    }
};

/*
 * Approach: Iterative Look-Ahead with Constant Space
 * * Logic:
 * 1. Dummy Node: We initialize a 'dummy' node pointing to the head. This serves
 * as a stationary anchor, as the actual head of the list changes after the first reversal.
 * 2. Group Pointer: We use 'groupPrev' to track the node immediately preceding
 * the group we are currently processing. Initially, it is the dummy node.
 * 3. The Look-Ahead: Inside the loop, we iterate 'k' steps forward using a pointer 'kth'.
 * - If 'kth' becomes null before reaching 'k' steps, it means the remaining nodes
 * are fewer than 'k'. We stop and return the list as is.
 * 4. Reversal Setup:
 * - We identify 'groupNext' (the node after the k-th node).
 * - We identify 'curr' (the start of the group to be reversed).
 * - We initialize 'prev' to 'groupNext'. This is a key optimization: by pointing
 * 'prev' to the rest of the list immediately, the new tail of our reversed group
 * is automatically connected to the next segment, saving us a re-connection step later.
 * 5. Reversal Loop: We perform a standard linked list reversal for exactly 'k' nodes.
 * 6. Wiring:
 * - After the reversal loop, 'prev' sits at the new head of the group (originally the k-th node).
 * - We link 'groupPrev->next' to 'prev' to connect the previous part of the list
 * to this newly reversed group.
 * - We update 'groupPrev' to 'newGroupTail' (originally the first node) to prepare
 * for the next iteration.
 * * Time Complexity: O(N)
 * We traverse the list essentially twice (once to find the k-th node, once to reverse),
 * which is linear time.
 * * Space Complexity: O(1)
 * We use only a fixed number of pointers for manipulation.
 */