class Solution {
public:
    TreeNode* prunHelper(TreeNode* root) {
        if(!root) {
            return NULL;
        }

        root->left  = prunHelper(root->left);
        root->right = prunHelper(root->right);

        if (root->left == NULL && root->right == NULL && root->val == 0) {
            return NULL;
        }

        return root;
    }
    TreeNode* pruneTree(TreeNode* root) {
        
        return prunHelper(root);
    }
};