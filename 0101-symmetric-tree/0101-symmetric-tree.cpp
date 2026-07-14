class Solution {
public:
    bool checkSymmetric(TreeNode* p, TreeNode* q) {
        if(!p && !q) {
            return true;
        }

        if(!p || !q) {
            return false;
        }

        if(p->val != q->val) {
            return false;
        }

        return checkSymmetric(p->left, q->right) && checkSymmetric(p->right, q->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) {
            return true;
        }

        return checkSymmetric(root->left, root->right);
    }
};