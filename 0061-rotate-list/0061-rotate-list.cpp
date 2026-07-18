class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k == 0) {
            return head;
        }

        int N = 1; // start at head

        ListNode* tail = head;

        while(tail->next) {
            tail = tail->next;
            N++;
        }

        // Normalise
        k = k%N;

        if(k == 0) {
            return head;
        }

        // connect tail to head to make it circular
        tail->next = head;

        int remain = N - k;

        // need to traverse till remain

        ListNode* newTail = head;
        for(int i=1; i<remain; i++) {
            newTail = newTail->next;
        }

        ListNode* newHead = newTail->next;
        newTail->next = NULL;

        return newHead;

    }
};