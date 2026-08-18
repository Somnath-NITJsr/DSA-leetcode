class Solution {
public:
    void solve(vector<int>& nums, int& n, vector<int>& temp, unordered_set<int>& st, vector<vector<int>>& result) {
        if(temp.size() == n) {
            result.push_back(temp);
            return;
        }


        for(int i=0; i<n; i++) {

            if(st.find(nums[i]) == st.end()) {

                temp.push_back(nums[i]);
                st.insert(nums[i]);

                solve(nums, n, temp, st, result);

                temp.pop_back();
                st.erase(nums[i]);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;
        vector<int> temp;
        vector<vector<int>> result;

        solve(nums, n, temp, st, result);

        return result;
    }
};