class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();

        // Assumption

        int candidate1 = NULL; 
        int count1     = 0;

        int candidate2  = NULL;
        int count2     = 0;

        for(int i=0; i<n; i++) {

            if(nums[i] == candidate1) {
                count1++;
            } else if(nums[i] == candidate2) {
                count2++;
            } else if(count1 == 0) {
                candidate1 = nums[i];
                count1++;
            } else if(count2 == 0) {
                candidate2 = nums[i];
                count2++;
            } else {
                count1--;
                count2--;
            }

        }


        // Verification is required for the Majority Element II

        vector<int> ans;

        int freq1 = 0;
        int freq2 = 0;

        for(auto& it: nums) {
            
            if(it == candidate1) {
                freq1++;
            } else if(it == candidate2) {
                freq2++;
            }
        }

        if(freq1 > (n/3)) {
            ans.push_back(candidate1);
        }

        if(freq2 > (n/3)) {
            ans.push_back(candidate2);
        }

        return ans;

        // unordered_map<int, int> mpp;

        // vector<int> ans;

        // for(auto& it: nums) {

        //     mpp[it]++;
        // }

        // for(auto& it: mpp) {

        //     if(it.second > (n/3)) {
        //         ans.push_back(it.first);
        //     }
        
        // }

        // return ans;
    }
};