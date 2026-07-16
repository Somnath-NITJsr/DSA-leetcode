class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root) {
            return 0;
        }

        int level = 1;

        queue<TreeNode* > q;
        q.push(root);

        while(!q.empty()) {

            int N = q.size();
            while(N--) {
                TreeNode* node = q.front();
                q.pop();

                if(!node->left && !node->right) {
                    return level;
                }

                if(node->left) {
                    q.push(node->left);
                }
                if(node->right) {
                    q.push(node->right);
                }
            }
            level++;
        }

        return -1;
    }
};