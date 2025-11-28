class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }

        if (list1 != nullptr) {
            tail->next = list1;
        } else if (list2 != nullptr) {
            tail->next = list2;
        }

        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
};

/*
 * Approach: Iterative "Zipper" Method with Dummy Node
 * * Logic:
 * 1. We create a 'dummy' node to act as the starting point. This simplifies the
 * code because we don't need special checks to see if the head of the new list
 * is empty or initialized.
 * 2. We use a 'tail' pointer to track the end of our new merged list. Initially,
 * it points to the dummy node.
 * 3. We iterate while BOTH 'list1' and 'list2' are not null.
 * 4. Inside the loop, we compare the values of the current nodes of list1 and list2.
 * - If list1 is smaller or equal, we attach list1 to 'tail->next' and advance list1.
 * - If list2 is smaller, we attach list2 to 'tail->next' and advance list2.
 * 5. We advance the 'tail' pointer to the newly added node.
 * 6. Once one list is exhausted (becomes null), we simply attach the remainder
 * of the other list to the end of our merged list. Since the remaining nodes are
 * already sorted, we don't need to iterate through them.
 * 7. We return dummy->next (the actual head of the merged list) and delete the
 * dummy node to prevent memory leaks.
 * * Time Complexity: O(N + M)
 * We traverse each node in both lists exactly once.
 * * Space Complexity: O(1)
 * We are only rearranging existing nodes, not creating new ones (except the dummy).
 */