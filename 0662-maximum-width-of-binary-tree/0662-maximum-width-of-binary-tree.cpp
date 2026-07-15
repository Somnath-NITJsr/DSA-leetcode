class Solution {
public:
    typedef unsigned long long ll;
    int widthOfBinaryTree(TreeNode* root) {
        // level order traversal - BFS

        queue<pair<TreeNode*, ll> >q;
        q.push({root, 0});

        ll maxWidth = 0;

        while(!q.empty()) {
            ll L = q.front().second;
            ll R = q.back().second;

            maxWidth = max(maxWidth, R - L + 1);
            int N = q.size();

            while(N--) {
                TreeNode* node = q.front().first;
                ll idx        = q.front().second;
                q.pop();

                if(node->left) {
                    q.push({node->left, 2*idx + 1});
                }
                if(node->right) {
                    q.push({node->right, 2*idx + 2});
                }
            }
        }

        return maxWidth;
    }
};