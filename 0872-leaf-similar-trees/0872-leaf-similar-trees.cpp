class Solution {
public: 
    void traverseTree(TreeNode* root, vector<int>& v) {
        if(!root) {
            return;
        }

        if(!root->left && !root->right) {
            v.push_back(root->val);
            return;
        }

        traverseTree(root->left, v);
        traverseTree(root->right, v);
        return;
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {

        // using vector is more cleaner, type-safe and avoids the overhead of converting numbers to text.
        vector<int> v1;
        vector<int> v2;

        traverseTree(root1, v1);
        traverseTree(root2, v2);

        return v1 == v2;
    }
};