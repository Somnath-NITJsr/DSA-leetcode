class Solution {
public:
    void DFS(TreeNode* root, map<int, int>& mp, int level) {
        if(!root) {
            return;
        }

        mp[level] += root->val;

        DFS(root->left, mp, level+1);
        DFS(root->right, mp, level+1);
    }
    int maxLevelSum(TreeNode* root) {

        if(!root) {
            return 0;
        }

        map<int, int> mp;

        DFS(root, mp, 1);

        int resultLevel = 1;
        int maxSUM      = INT_MIN;

        for(auto& it: mp) {
            int level = it.first;
            int sum   = it.second;

            if(sum > maxSUM) {
                maxSUM      = sum;
                resultLevel = level;
            }
        }

        return resultLevel;

        /*
        // BFS
        queue<TreeNode* > q;
        q.push(root);

        int level = 1;
        int ans = 1;
        int maxSUM = INT_MIN;

        while(!q.empty()) {

            int N      = q.size();
            int sum    = 0;
            while(N--) {

                TreeNode* node = q.front();
                q.pop();

                sum += node->val;

                if(node->left) {
                    q.push(node->left);
                }

                if(node->right) {
                    q.push(node->right);
                }
            }
            
            if(sum > maxSUM) {
                maxSUM = sum;
                ans    = level;
            }
            level++;
        }
        return ans;
        */
    }
};