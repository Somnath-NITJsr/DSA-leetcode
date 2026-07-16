class Solution {
public:
    int DFS(TreeNode* root) {
        if(!root) {
            return 0;
        }

        if(!root->left && !root->right) {
            return 1;
        }

        int l = DFS(root->left);
        int r = DFS(root->right);

        if(!root->left) {
            return 1 + r;
        }

        if(!root->right) {
            return 1 + l;
        }

        return 1 + min(l, r);

    }
    int minDepth(TreeNode* root) {
        if(!root) {
            return 0;
        }
        
        return DFS(root);
        

        /*
        // BFS
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
        */
    }
};