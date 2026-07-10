class Solution {
public:
    TreeNode* dfs(TreeNode* root, int curr, int& val, int& depth) {
        if(!root) {
            return NULL;
        }   

        if(curr == depth - 1) {
            TreeNode* leftTemp  = root->left;
            TreeNode* rightTemp = root->right;

            root->left  = new TreeNode(val);
            root->right = new TreeNode(val);

            root->left->left   = leftTemp;
            root->right->right = rightTemp;

            return root;
        }

        root->left  = dfs(root->left, curr+1, val, depth);
        root->right = dfs(root->right, curr+1, val, depth);

        return root;
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        
        if(depth == 1) {

            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;

        }      
        
        int curr = 1;

        return dfs(root, curr, val, depth);

    }
};