class Solution {
public:
    int findSum(TreeNode* root, string s) {
        if(!root) {
            return 0;
        }

        s += to_string(root->val);

        if(!root->left && !root->right) {
            return stoi(s);
        }

        return findSum(root->left, s)+ findSum(root->right, s);
    }
    int sumNumbers(TreeNode* root) {
        if(!root) {
            return 0;
        }

        string s = "";

        return findSum(root, s);
        
    }
};