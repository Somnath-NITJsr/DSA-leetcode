class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(!head) {
            return head;
        }

        ListNode* currNode = head;
        ListNode* nextNode = head->next;

        while(nextNode) {

            ListNode* gcdNode = new ListNode(gcd(currNode->val, nextNode->val));

            currNode->next    = gcdNode;
            gcdNode->next     = nextNode;

            currNode          = nextNode;
            nextNode          = nextNode->next;
            
        }
        return head;
    }
};