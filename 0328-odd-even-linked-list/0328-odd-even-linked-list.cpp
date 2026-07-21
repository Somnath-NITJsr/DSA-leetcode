class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next) {
            return head;
        }

        ListNode* odd       = head;
        ListNode* even      = head->next;
        ListNode* evenStart = head->next;

        while(even && even->next) {
            odd->next  = odd->next->next;
            odd        = even->next;

            even->next = even->next->next;
            even       = odd->next;
        }

        odd->next = evenStart;

        return head;
    }
};