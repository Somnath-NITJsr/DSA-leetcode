class Solution {
public:
    int countNodes(TreeNode* root) {
        if(!root) {
            return 0;
        }

        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    bool dfs(TreeNode* root, int i, int& totalNode) {
        if(!root) {
            return true;
        }

        if(i > totalNode) {
            return false;
        }

        return dfs(root->left, 2*i, totalNode) && dfs(root->right, 2*i + 1, totalNode);
    }
    bool isCompleteTree(TreeNode* root) {
        
        int totalNode = countNodes(root);

        int i = 1;
        return dfs(root, i, totalNode);


        /*
        // USING BFS
        if(!root) return false;

        queue<TreeNode* > q;
        q.push(root);

        bool past = false;

        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if(node == NULL) {
                past = true;
            } else {
                
                if(past == true) {
                    return false;
                }
                
                q.push(node->left);
                q.push(node->right);
            }
        }
        return true;
        */
    }
};