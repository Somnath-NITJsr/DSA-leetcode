class Solution {
public:
    long SUM  = 0;
    long maxP = 0;
    int MOD   = 1e9 + 7;
    int totalSum(TreeNode* root) {
        if(!root) {
            return 0;
        }

        int leftSubtreeSum  = totalSum(root->left);
        int rightSubtreeSum = totalSum(root->right);
        long subtreeSum     = root->val + leftSubtreeSum + rightSubtreeSum;

        long remainingSum   = SUM - subtreeSum;

        maxP = max(maxP, remainingSum* subtreeSum);

        return subtreeSum;
    }

    int maxProduct(TreeNode* root) {
        
        if(!root) {
            return 0;
        }
        maxP = 0;

        SUM = totalSum(root);
        totalSum(root);

        return maxP % MOD;
    }
};