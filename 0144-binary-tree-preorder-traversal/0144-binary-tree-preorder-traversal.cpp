class Solution {
public:
    void preOrder(TreeNode* root, vector<int>& result) {
        if(!root) {
            return;
        }

        result.push_back(root->val);
        preOrder(root->left, result);
        preOrder(root->right, result);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        
        vector<int> result;
        preOrder(root, result);

        return result;
    }
};