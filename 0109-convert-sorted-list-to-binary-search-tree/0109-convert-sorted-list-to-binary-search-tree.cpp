
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) {
            return NULL;
        }
        if(!head->next) {
            return new TreeNode(head->val);
        }

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;

        while(fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // slow is at the mid

        TreeNode* root = new TreeNode(slow->val);
        prev->next     = NULL;
        root->left     = sortedListToBST(head);
        root->right    = sortedListToBST(slow->next);

        return root;
    }
};