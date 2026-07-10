class Solution {
public:
    void inOrder(TreeNode* root, string& s) {
        if(!root) {
            return;
        }

        // leaf node
        if(!root->left && !root->right) {
            s += to_string(root->val) + "#";
            return;
        }

        inOrder(root->left, s);
        inOrder(root->right, s);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {

        // to optimise the space, we used the string, otherwise vector can be used
        string s1 = "";
        string s2 = "";

        inOrder(root1, s1);
        inOrder(root2, s2);

        return s1 == s2;
    }
};