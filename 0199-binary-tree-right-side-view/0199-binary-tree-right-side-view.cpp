class Solution {
public:
    void preOrder(TreeNode* root, int level, vector<int>& result) {
        if(!root) return;

        if(result.size() < level) {
            result.push_back(root->val);
        }

        preOrder(root->right, level+1, result);
        preOrder(root->left, level+1, result);
    }
    vector<int> rightSideView(TreeNode* root) {
        

        // dfs
        vector<int> result;
        preOrder(root, 1, result);

        /*

        // using the level order traversal
        
        if(!root) return {};

        queue<TreeNode* > que;
        que.push(root);

        while(!que.empty()) {
            int N = que.size();
            TreeNode* node = NULL;

            while(N--) {
                node = que.front();
                que.pop();

                if(node->left) {
                    que.push(node->left);
                } 
                if(node->right) {
                    que.push(node->right);
                }
            }
            result.push_back(node->val);
        }
        */
        return result;
    }
};