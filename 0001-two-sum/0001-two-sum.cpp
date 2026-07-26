class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        // BRUTE FORCE-----------------------------------
        
       /*
        vector<int>index;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                if(nums[i]+nums[j]==target)
                {
                    index.push_back(i);
                    index.push_back(j);
                    break;
                }
            }
        }
        return index;
       */


        // BETTER USING HASHING-------------------------
        
        unordered_map<int,int>mpp;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            int first=nums[i];
            int second=target-first;
            if(mpp.find(second)!=mpp.end())
            {
                return {mpp[second],i}; //return YES;
            }
            mpp[first]=i;
        }
        return{-1,-1};  //  return NO;
        

        // For Optimal we can use two pointers approach but we have to sort the array
        /*
        int i=0;
        int j=nums.size()-1;
        while(i<j)
        {
            int sum=nums[i]+nums[j];
            if(sum==target) return {i,j};
            else if(sum<target) i++;
            else j--;
        }
        return {-1,-1};
        */


    }
};