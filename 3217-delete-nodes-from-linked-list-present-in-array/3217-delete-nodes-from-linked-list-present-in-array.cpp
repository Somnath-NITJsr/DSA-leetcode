class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        if(!head || !head->next) {
            return head;
        }

        // store the nums into the set
        unordered_set<int> st(begin(nums), end(nums));

        while(head && st.find(head->val) != st.end()) {
            ListNode* temp = head; // store first and then delete
            head           = head->next; // move the head till its not present in the st
            // delete(temp);  // the pointer must be deleted
        }

        // head is safe , create one pointer , pointed to head
        ListNode* curr = head;

        while(curr && curr->next) {
            if(st.find(curr->next->val) != st.end()) {
                ListNode* temp = curr->next;
                curr->next     = curr->next->next;
                // delete(temp);
            } else {
                curr = curr->next;
            }
        }

        return head;
    }
};