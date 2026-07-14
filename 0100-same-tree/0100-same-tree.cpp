class Solution {
public:
    // void solve(TreeNode* root, vector<string>& tree, bool isLeft) {       
    //     if(!root) {
    //         if(isLeft) {
    //         tree.push_back("NULL_");
    //         }
    //         else{
    //             tree.push_back("_NULL");
    //         }
    //         return;
    //     }

    //     tree.push_back(to_string(root->val));
    //     solve(root->left, tree, true);
    //     solve(root->right, tree, false);
    // }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // vector<string> tree1;
        // vector<string> tree2;

        // solve(p, tree1, true);
        // solve(q, tree2, true);

        // return tree1 == tree2;

        if(!p && !q) {
            return true; // no nodes
        }

        if(!p || !q) {
            return false; // either p or q exists
        }

        if(p->val != q->val) {
            return false;
        }

        // check whether left of p is same as left of q
        // similarly check whether the right of q is same as right of q
        return isSameTree(p->left, q->left)
                && isSameTree(p->right, q->right);
    }
};