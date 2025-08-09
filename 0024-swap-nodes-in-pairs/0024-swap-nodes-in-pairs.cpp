/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) {
            // If the list is empty or has only one node, no swap needed
            return head;
        }

        ListNode* dummyHead = new ListNode(0); // Dummy node to simplify edge cases
        dummyHead->next = head;
        ListNode* current = dummyHead;

        while (current->next && current->next->next) {
            ListNode* first = current->next; // First node of the pair
            ListNode* second = current->next->next; // Second node of the pair

            // Swapping the nodes
            first->next = second->next;
            second->next = first;
            current->next = second;

            // Move to the next pair
            current = first;
        }

        ListNode* newHead = dummyHead->next;
        delete dummyHead;
        return newHead;
    }
};
