class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(!head || !head->next) {
            return NULL;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;

        while(fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // now slow is at the mid
        prev->next = prev->next->next;
        delete(slow);
        return head;
    }
};