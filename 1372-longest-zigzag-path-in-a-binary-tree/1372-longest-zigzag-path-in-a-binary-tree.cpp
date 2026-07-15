class Solution {
public:
    // void solve(TreeNode* root, int& maxPath, int steps, bool goLeft) {
    //     if(!root) {
    //         return;
    //     }

    //     maxPath = max(maxPath, steps);

    //     if(goLeft) {
    //         solve(root->left, maxPath, steps+1, false);
    //         solve(root->right, maxPath, 1, true);
    //     } else {
    //         solve(root->right, maxPath, steps+1, true);
    //         solve(root->left, maxPath, 1, false);
    //     }

    // }

    void solve(TreeNode* root, int l, int r, int& maxPath) {
        if(!root) {
            return;
        }

        maxPath = max({maxPath, l, r});

        solve(root->left, r+1, 0, maxPath);
        solve(root->right, 0, l+1, maxPath);
    }
    int longestZigZag(TreeNode* root) {
        // int maxPath = 0;
        // int steps   = 0;
        // // bool goLeft = true;

        // solve(root, maxPath, steps, true);
        // solve(root, maxPath, steps, false);
        // return maxPath;

        int maxPath = 0;
        solve(root, 0, 0, maxPath);
        return maxPath;
    }
};