class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();


        // Assumption

        int candidate = nums[0];
        int count     = 1;


        for(int i=1; i<n; i++) {

            if(candidate == nums[i]) {
                count++;
            } else {
                count--;
            }

            if(count == 0) {
                candidate = nums[i];
                count++;
            }
        }

        // Verification not required, in Majority Element I - max 1 majority element
        return candidate;

        // unordered_map<int, int> mpp;

        // for(auto& it: nums) {

        //     mpp[it]++;

        // }

        // for(auto& it: mpp) {

        //     if(it.second > (n/2)) {
        //         return it.first;
        //     }
            
        // }
        
        // return -1;
    }
};