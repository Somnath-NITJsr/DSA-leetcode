class Solution {
public:
    void dfsPathSum(TreeNode* root, int& targetSum, int sum, vector<int> temp, vector<vector<int>>& result) {
        if(!root) {
            return;
        }

        sum += root->val;
        temp.push_back(root->val);

        if(!root->left && !root->right) {
            if(sum == targetSum) {
                result.push_back(temp);
            }
            return;
        }

        dfsPathSum(root->left, targetSum, sum, temp, result);
        dfsPathSum(root->right, targetSum, sum, temp, result);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        vector<vector<int>> result;

        vector<int> temp;
        int sum = 0;

        dfsPathSum(root, targetSum, sum, temp, result);

        return result;
    }
};