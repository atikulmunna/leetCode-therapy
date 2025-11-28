class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;

        while (prev->next && prev->next->next) {
            ListNode* first = prev->next;
            ListNode* second = prev->next->next;

            prev->next = second;
            first->next = second->next;
            second->next = first;

            prev = first;
        }

        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};

/*
 * Approach: Iterative Swap with Dummy Node
 * * Logic:
 * 1. We use a 'dummy' node pointing to the head. This allows us to handle the
 * swap of the first two nodes using the exact same logic as any other pair in the list.
 * 2. We use a 'prev' pointer that sits immediately before the pair of nodes
 * we want to swap. Initially, 'prev' is the dummy node.
 * 3. We iterate as long as 'prev' has at least two nodes following it
 * (prev->next and prev->next->next).
 * 4. Inside the loop, we identify the two nodes to be swapped: 'first' and 'second'.
 * 5. We perform the pointer rotation in three specific steps:
 * a. prev->next = second; (Link the previous part of the list to the new first node).
 * b. first->next = second->next; (Link the old first node to the rest of the list).
 * c. second->next = first; (Link the new first node back to the old first node).
 * 6. Finally, we advance the 'prev' pointer to 'first' (which is now the second
 * node in the current pair) to set up for the next pair.
 * * Time Complexity: O(n)
 * We visit each node once.
 * * Space Complexity: O(1)
 * We only use pointers for manipulation; no extra data structures are created.
 */