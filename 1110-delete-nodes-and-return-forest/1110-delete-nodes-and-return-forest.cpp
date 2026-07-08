class Solution {
public:
    TreeNode* deleteHelper(TreeNode* root, unordered_set<int>& st, vector<TreeNode*> & result) {
        if(!root) {
            return NULL;
        }

        // we will traverse left and right
        root->left  = deleteHelper(root->left, st, result);
        root->right = deleteHelper(root->right, st, result);

        // check if the val exists
        if(st.find(root->val) != st.end()) {

            // if left and right exists then insert into the result
            if(root->left) {
                result.push_back(root->left);
            }
            if(root->right) {
                result.push_back(root->right);
            }

            // lastly return null
            return NULL;
        } else {
            return root;
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        
        vector<TreeNode*> result;

        unordered_set<int> st;

        for(int& num : to_delete) {
            st.insert(num);
        }

        deleteHelper(root, st, result);

        // check if the root is not to be deleted
        if(st.find(root->val) == st.end()) {
            result.push_back(root);
        }

        return result;
    }
};