class Solution {
public:
    int maxDiff;

    void findMaxDiffUtil(TreeNode* root, TreeNode* child) {
        if(!root || !child) {
            return;
        }

        maxDiff = max(maxDiff, abs(child->val - root->val));

        findMaxDiffUtil(root, child->left);
        findMaxDiffUtil(root, child->right);
    }

    void findMaxDiff(TreeNode* root) {
        if(!root) {
            return;
        }


        findMaxDiffUtil(root, root->left);
        findMaxDiffUtil(root, root->right);

        findMaxDiff(root->left);
        findMaxDiff(root->right);
    }
    int maxAncestorDiff(TreeNode* root) {
        maxDiff = -1;

        findMaxDiff(root);
        return maxDiff;
    }
};