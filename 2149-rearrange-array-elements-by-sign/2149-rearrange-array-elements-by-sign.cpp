class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos;
        vector<int> neg;


        for(int i=0; i<nums.size(); i++) {

            if(nums[i] < 0) {
                neg.push_back(nums[i]);
            } else {
                pos.push_back(nums[i]);
            }
        }

        int pPos = 0;
        int pNeg = 1;

        for(int i=0; i<pos.size(); i++) {
            nums[pPos] = pos[i];
            nums[pNeg] = neg[i];

            pPos += 2;
            pNeg += 2;
        }

        return nums;

    }
};