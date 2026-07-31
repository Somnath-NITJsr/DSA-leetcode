class Solution {
public:
    void solve(vector<int>& nums, int i, int p, int& n, vector<int>& result, vector<int>& temp) {
        if(i == n) {

            if(temp.size() > result.size()) {
                result = temp; // assign , not push
            }
            return;
        }

        if(p == -1 || nums[i] % p == 0) { // we can take 
            temp.push_back(nums[i]);
            solve(nums, i+1, nums[i], n, result, temp);
            temp.pop_back(); // when we are using the pass by ref, we must pop_back
        }

        solve(nums, i+1, p, n, result, temp); // skip
        return;
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {

        int n = nums.size();

        sort(begin(nums), end(nums));


        vector<int> t(n, 1);
        vector<int> prev_index(n, -1);

        int maxL       = 1;
        int last_index = 0;

        for(int i=1; i<n; i++) {

            for(int j=0; j<i; j++) {


                // in LIS, we did the nums[i] > nums[j] .. & for the pred- we used the checkPred
                // similar
                if(nums[i] % nums[j] == 0) {

                    if(t[i] < t[j] + 1) {
                        t[i]          = t[j] + 1;
                        prev_index[i] = j;
                    } 

                    if(t[i] > maxL) {
                        maxL       = t[i];
                        last_index = i;
                    }

                }
            }
        }


        vector<int> result; // here the elements will be pushed

        while(last_index != -1) {

            result.push_back(nums[last_index]);

            last_index = prev_index[last_index];
        }

        return result;


        // int n = nums.size();
        // sort(begin(nums), end(nums));

        // vector<int> result;
        // vector<int> temp;

        // solve(nums, 0, -1, n, result, temp);
        // return result;
    }
};