class Solution {
public:
    int maxSum;
    int solve(TreeNode* root) {
        if(!root) {
            return 0;
        }
        
        int l = solve(root->left);
        int r = solve(root->right);

        int left_right_and_root = l + r + root->val; // 1
         
        int left_or_right = max(l, r) + root->val; // 2
        
        int only_root_is_good = root->val; // 3

        maxSum = max({maxSum, left_right_and_root, left_or_right, only_root_is_good}); // here we are storing the max value

        return max(left_or_right, only_root_is_good);  // returning to explore further
    }

    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN;

        solve(root);

        return maxSum;
    }
};