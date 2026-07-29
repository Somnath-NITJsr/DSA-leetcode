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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // first create two temp nodes for traversing the nodes
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;

        // create a dummy node for continuing the series
        ListNode* dummyNode = new ListNode(-1);
        // create a temp node which will point to the dummyNode
        ListNode* temp = dummyNode;
        int carry = 0;

        while (temp1 != NULL || temp2 != NULL) {
            int sum = carry;
            // sum = carry is important as carry will be added to sum after
            // every traversing

            // if temp1 and temp2 are not null then add the val
            if (temp1)
                sum += temp1->val;
            if (temp2)
                sum += temp2->val;

            // create a new node for the each sum
            ListNode* newNode = new ListNode(sum % 10);
            carry = sum / 10;

            // connect the temp node to the newNode
            temp->next = newNode;
            temp = temp->next;

            // check if the temp1 and temp2 are available to proceed
            if (temp1)
                temp1 = temp1->next;
            if (temp2)
                temp2 = temp2->next;
        }
        if (carry) {
            ListNode* newCarry = new ListNode(carry);
            temp->next = newCarry;
        }
        return dummyNode->next;
    }
};