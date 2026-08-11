class Solution {
public:
    int subarraySum(vector<int>& nums, int K) {
        int n     = nums.size();
        int count = 0;

        unordered_map<int, int> mp;

        // mp.insert({0, 1}); // 0 is the cummulative sum, 1 is the freq
        mp[0] = 1;
        int cSum = 0;

        for(int i=0; i<n; i++) {

            cSum   += nums[i];
            int rem = cSum - K;

            if(mp.find(rem) != mp.end()) {
                count += mp[rem];
            }

            mp[cSum]++;
        }

        return count;




        // for(int i=0; i<n; i++) {

        //     for(int j=i; j<n; j++) {

        //         int sum = 0;

        //         for(int k = i; k<=j; k++) {
        //             sum += nums[k];
        //         }

        //         if(sum == K) {
        //             count++;
        //         }
        //     }
        // }

        // return count;
    }
};