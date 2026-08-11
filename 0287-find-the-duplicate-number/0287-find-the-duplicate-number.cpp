class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        // using the slow and fast pointer - same as detect cycle in LL

        int slow = nums[0];
        int fast = nums[0]; 

        slow = nums[slow]; // move 1
        fast = nums[nums[fast]]; // move 2

        while(slow != fast) {

            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        // now they meet

        slow = nums[0];
        // now they will move 1 steps

        while(slow != fast) {

            slow = nums[slow];
            fast = nums[fast];
        }

        // again they had met, return slow/ fast.. this is the duplicate

        return fast;


        // unordered_map<int, int> mp;

        // for(auto& it: nums) {
            
        //     mp[it]++;
        // }

        // for(auto& it: mp) {
            
        //     if(it.second > 1) {
        //         return it.first;
        //     }
        // }

        // return -1;
    }
};