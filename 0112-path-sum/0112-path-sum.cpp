class Solution {
public:
    bool dfsPathSum(TreeNode* root, int sum, int& targetSum) {
        if(!root) {
            return false;
        }

        sum += root->val;

        if(!root->left && !root->right) {
            if(sum == targetSum) {
                return true;
            }
        }

        return dfsPathSum(root->left, sum, targetSum) ||
        dfsPathSum(root->right, sum, targetSum);

    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;

        return dfsPathSum(root, sum, targetSum);
    }
};