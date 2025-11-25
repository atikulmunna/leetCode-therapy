class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* tail = dummyHead;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int digit1 = (l1 != nullptr) ? l1->val : 0;
            int digit2 = (l2 != nullptr) ? l2->val : 0;

            int sum = digit1 + digit2 + carry;
            int digit = sum % 10;
            carry = sum / 10;

            ListNode* newNode = new ListNode(digit);
            tail->next = newNode;
            tail = tail->next;

            l1 = (l1 != nullptr) ? l1->next : nullptr;
            l2 = (l2 != nullptr) ? l2->next : nullptr;
        }

        ListNode* result = dummyHead->next;
        return result; 
    }
};

/*
 * Approach: Elementary Math with Dummy Head
 * * Logic:
 * 1. We treat the linked lists as if we are adding numbers column by column 
 * on paper, starting from the ones digit (head of the lists).
 * 2. We initialize a 'dummyHead' node. This simplifies edge cases where the 
 * result list is empty or when we need to return the head of the new list 
 * after moving our 'tail' pointer forward.
 * 3. We use a single loop that continues as long as there is a node in l1, 
 * a node in l2, or a non-zero carry.
 * 4. Inside the loop, we handle null pointers by assuming a value of 0.
 * 5. We calculate the sum (val1 + val2 + carry), determine the new digit 
 * (sum % 10), and update the carry (sum / 10).
 * 6. We attach the new digit to our result list and advance pointers.
 * 7. Finally, we return dummyHead->next, which is the actual start of our calculation.
 * * Note on Memory: In a real-world scenario (local IDE), you would delete 
 * dummyHead to prevent a memory leak, but in competitive programming (LeetCode), 
 * it is often omitted for brevity as the program terminates immediately.
 * * Time Complexity: O(max(N, M))
 * We iterate through the lists once, where N and M are the lengths of l1 and l2.
 * * Space Complexity: O(max(N, M))
 * The length of the new list is at most max(N, M) + 1.
 */