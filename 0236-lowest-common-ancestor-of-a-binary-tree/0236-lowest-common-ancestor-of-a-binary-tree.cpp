class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) {
            return NULL;
        }

        if(root == p || root == q) {
            return root;
        }

        // traverse both ends
        TreeNode*  leftN = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightN = lowestCommonAncestor(root->right, p, q);

        // check
        // if i got from both side, then the root is the answer
        if(leftN && rightN) {
            return root;
        }

        // if we got the leftN as the ans , but rightN is null then return leftN
        if(leftN) {
            return leftN;
        }
        // if we got the rightN as the ans , but leftN is null then return rightN
        return rightN;
    }
};