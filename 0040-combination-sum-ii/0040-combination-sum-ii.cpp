class Solution {
public:
    void getComboSum(vector<int>& candidates, int target, int idx, vector<int>& curr, vector<vector<int>>& result) {

        // base case
        if(target < 0) {
            return;
        }

        if(target == 0) {
            result.push_back(curr);
            return;
        }

        for(int i=idx; i<candidates.size(); i++) {

            if(i > idx && candidates[i] == candidates[i-1]) {
                continue;
            }

            // do
            curr.push_back(candidates[i]);
            // explore
            getComboSum(candidates, target - candidates[i], i + 1, curr, result);
            // undo
            curr.pop_back();
        }

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        // sort it first - to avoid the duplicates

        sort(begin(candidates), end(candidates));

        vector<int> curr;
        vector<vector<int>> result;

        getComboSum(candidates, target, 0, curr, result);
        
        return result;
    }
};