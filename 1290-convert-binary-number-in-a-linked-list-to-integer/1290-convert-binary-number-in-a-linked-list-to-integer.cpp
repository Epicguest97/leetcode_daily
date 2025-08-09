class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int ans = 0;
        ListNode* temp = head;
        while (temp != nullptr) {
            ans = (ans << 1) | temp->val;  
            temp = temp->next;
        }
        return ans;
    }
};
