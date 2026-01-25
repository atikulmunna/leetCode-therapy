class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;

        for (int i = 0; i < left - 1; ++i) {
            prev = prev->next;
        }

        ListNode* curr = prev->next;

        for (int i = 0; i < right - left; ++i) {
            ListNode* nextNode = curr->next;
            curr->next = nextNode->next;
            nextNode->next = prev->next;
            prev->next = nextNode;
        }

        return dummy->next;
    }
};

/*
 * Approach: Iterative Link Inversion (One Pass)
 * * Logic:
 * 1. Dummy Node: A dummy node is created to point to the head. This simplifies edge cases
 * where the reversal starts at the very first node (left = 1), as we always need a
 * 'prev' pointer outside the reversal range.
 * 2. Setup:
 * - We advance 'prev' to the node at index 'left - 1'.
 * - 'curr' is initialized to 'prev->next' (the node at index 'left').
 * 3. The Reversal Loop:
 * - We execute the loop 'right - left' times.
 * - In each iteration, we move the node 'nextNode' (which is 'curr->next') to the
 * position immediately after 'prev'.
 * - Step A: Detach 'nextNode' from its current spot (curr->next = nextNode->next).
 * - Step B: Link 'nextNode' to the front of the sublist (nextNode->next = prev->next).
 * - Step C: Link 'prev' to 'nextNode' (prev->next = nextNode).
 * - Conceptually, 'curr' stays at the "back" of the growing reversed section, while
 * 'nextNode' hops over to the front.
 * * Time Complexity: O(N)
 * We traverse up to the 'right' index once.
 * * Space Complexity: O(1)
 * We only use a few pointers for manipulation.
 */