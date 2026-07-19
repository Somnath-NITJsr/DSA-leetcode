class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {

        head = head->next;

        if(!head) {
            return NULL;
        }
        
        ListNode* temp = head;
        int sum        = 0;
        
        while(temp && temp->val != 0) {
            sum += temp->val;
            temp = temp->next;
        }
        
        head->val  = sum;
        head->next = mergeNodes(temp);
        
        return head;
        
        /*
        ListNode* p1 = head->next;
        ListNode* p2 = p1;

        while(p2) {
            int sum = 0;

            while(p2 && p2->val != 0) {
                sum += p2->val;
                p2   = p2->next;
            }
            // p2 has reached 0 or null, now update the p1
            p1->val  = sum;
            p2       = p2->next;
            p1->next = p2;
            p1       = p1->next;
        }

        return head->next;
        */
    }
};