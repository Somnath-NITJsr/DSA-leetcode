class Solution {
public:
    int maxLevelSum(TreeNode* root) {
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
    }
};