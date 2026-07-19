class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
    
        ListNode* prev   = head;
        ListNode* curr   = head->next;
        int currPosition = 1;
        int minDist      = INT_MAX;
        int maxDist      = 0;

        int firstCriticalPointPos = 0;
        int prevCriticalPointPos  = 0;

        while(curr->next) {

            if((curr->val < prev->val && curr->val < curr->next->val) || (curr->val > prev->val && curr->val > curr->next->val)) {

                if(prevCriticalPointPos == 0) {
                    prevCriticalPointPos  = currPosition;
                    firstCriticalPointPos = currPosition;
                } else {
                    minDist               = min(minDist, currPosition - prevCriticalPointPos);
                    prevCriticalPointPos  = currPosition;
                }
            } 

            currPosition++;
            prev = curr;
            curr = curr->next;
        }

        maxDist = prevCriticalPointPos - firstCriticalPointPos;

        if(minDist == INT_MAX) {
            return {-1, -1};
        }

        return {minDist, maxDist};
    }
};