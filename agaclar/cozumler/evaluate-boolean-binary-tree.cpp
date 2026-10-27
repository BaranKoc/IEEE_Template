class Solution {
public:
    bool evaluateTree(TreeNode* root) {
        return (root->val < 2) ? root->val : (root->val == 2) ? evaluateTree(root->left) || evaluateTree(root->right) : evaluateTree(root->left) && evaluateTree(root->right);
    }
};
