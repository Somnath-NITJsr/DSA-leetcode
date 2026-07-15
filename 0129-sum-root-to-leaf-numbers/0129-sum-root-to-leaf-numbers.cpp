class Solution {
public:
    // int findSum(TreeNode* root, string s) {
    //     if(!root) {
    //         return 0;
    //     }

    //     s += to_string(root->val);

    //     if(!root->left && !root->right) {
    //         return stoi(s);
    //     }

    //     return findSum(root->left, s)+ findSum(root->right, s);
    // }

    int findSUM(TreeNode* root, int sum) {
        if(!root) {
            return 0;
        }

        // sum = 0 , 10* sum + root->val
        sum = (10* sum) + root->val;

        if(!root->left && !root->right) {
            return sum;
        }

        return findSUM(root->left, sum) + findSUM(root->right, sum);
    }

    int sumNumbers(TreeNode* root) {
        if(!root) {
            return 0;
        }

        return findSUM(root, 0);

        // string s = "";

        // return findSum(root, s);
        
    }
};