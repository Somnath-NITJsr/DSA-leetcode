class Solution {
public: 
    void traverseTree(TreeNode* root, string& s) {
        if(!root) {
            return;
        }

        if(!root->left && !root->right) {
            s += to_string(root->val) + "#";
            return;
        }

        traverseTree(root->left, s);
        traverseTree(root->right, s);
        return;
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        // we can use vector , but using the string optimises the space.
        string s1 = "";
        string s2 = "";

        traverseTree(root1, s1);
        traverseTree(root2, s2);

        return s1 == s2;
    }
};