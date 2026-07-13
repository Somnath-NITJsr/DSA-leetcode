class Solution {
public:
    // int maxDiff;

    // void findMaxDiffUtil(TreeNode* root, TreeNode* child) {
    //     if(!root || !child) {
    //         return;
    //     }

    //     maxDiff = max(maxDiff, abs(child->val - root->val));

    //     findMaxDiffUtil(root, child->left);
    //     findMaxDiffUtil(root, child->right);
    // }

    // void findMaxDiff(TreeNode* root) {
    //     if(!root) {
    //         return;
    //     }


    //     findMaxDiffUtil(root, root->left);
    //     findMaxDiffUtil(root, root->right);

    //     findMaxDiff(root->left);
    //     findMaxDiff(root->right);
    // }

    int findMaxDiff(TreeNode* root, int maxV, int minV) {
        if(!root) {
            return abs(maxV - minV);
        }

        maxV = max(maxV, root->val);
        minV = min(minV, root->val);

        int l = findMaxDiff(root->left, maxV, minV);
        int r = findMaxDiff(root->right, maxV, minV);

        return max(l, r);
    }
    
    int maxAncestorDiff(TreeNode* root) {
        // maxDiff = -1;

        // findMaxDiff(root);
        // return maxDiff;

        return findMaxDiff(root, root->val, root->val);
    }
};