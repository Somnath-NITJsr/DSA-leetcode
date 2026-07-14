class Solution {
public:
    string getSubtreesString(TreeNode* root, vector<TreeNode*>& result, string& s, unordered_map<string, int>& mp) {
        if(!root) {
            return "N";
        }

        s = to_string(root->val) + "," + getSubtreesString(root->left, result, s, mp) + "," + getSubtreesString(root->right, result, s, mp);

        if(mp[s] == 1) {
            result.push_back(root);
        }
        mp[s]++;

        return s;

    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        string s = "";
        vector<TreeNode* > result;
        unordered_map<string, int> mp;
        getSubtreesString(root, result, s, mp);

        return result;
    }
};