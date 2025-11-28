#include <vector>
#include <queue>

class Solution {
    struct CompareNode {
        bool operator()(ListNode* const& p1, ListNode* const& p2) {
            return p1->val > p2->val;
        }
    };

public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        std::priority_queue<ListNode*, std::vector<ListNode*>, CompareNode> minHeap;

        for (ListNode* head : lists) {
            if (head != nullptr) {
                minHeap.push(head);
            }
        }

        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        while (!minHeap.empty()) {
            ListNode* smallest = minHeap.top();
            minHeap.pop();

            tail->next = smallest;
            tail = tail->next;

            if (smallest->next != nullptr) {
                minHeap.push(smallest->next);
            }
        }

        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
};

/*
 * Approach: Min-Heap (Priority Queue)
 * * Logic:
 * 1. We need to repeatedly find the minimum value among the current heads of the k lists.
 * 2. Instead of scanning all k lists every time (which takes O(k)), we use a Min-Heap.
 * A Min-Heap allows us to retrieve the minimum element in O(1) and insert a new
 * element in O(log k).
 * 3. We define a custom comparator struct 'CompareNode' because the standard C++
 * priority_queue is a Max-Heap by default. We reverse the comparison (> instead of <)
 * to treat smaller numbers as "higher priority."
 * 4. We initialize the heap by pushing the head node of every non-empty list.
 * 5. In the main loop:
 * - We pop the top node (the smallest).
 * - We link it to our result list.
 * - CRITICAL: If the popped node has a 'next' node, we push that 'next' node
 * back into the heap. This ensures the heap always contains the current frontier
 * of the k lists.
 * 6. We repeat this until the heap is empty.
 * * Time Complexity: O(N log k)
 * N is the total number of nodes across all lists. We perform one push and one
 * pop for every node. Each heap operation takes O(log k).
 * * Space Complexity: O(k)
 * The heap stores at most k nodes at any given time (one from each list).
 */