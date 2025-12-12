 class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        ListNode* tail = head;
        int n = 1;
        while (tail->next) {
            tail = tail->next;
            n++;
        }

        k = k % n;
        if (k == 0) return head;

        tail->next = head;


        for (int i = 0; i < n - k; i++) {
            tail = tail->next;
        }

        ListNode* newHead = tail->next;
        tail->next = nullptr;

        return newHead;
    }
};

/*
 * Approach: Circular List Transformation
 * * Logic:
 * 1. Edge Cases: If the list is empty, has one node, or k is 0, no rotation is needed.
 * 2. Length & Cycle: We traverse to the end to find the length 'n'.
 * We verify if k is a multiple of n (k % n == 0). If so, we return head.
 * 3. Ring Creation: We connect the last node to the first node (tail->next = head).
 * This creates a cycle.
 * 4. Finding the Pivot: The new tail is located at position 'n - (k % n)'
 * from the original head.
 * 5. Cutting: We advance our pointer to this new tail position. We save the
 * 'next' node as our 'newHead', and then set the current node's 'next' to null
 * to break the cycle.
 * * Time Complexity: O(n)
 * We traverse the list exactly twice (once to find length, once to find the break point).
 * * Space Complexity: O(1)
 * We modify the links in place.
 */