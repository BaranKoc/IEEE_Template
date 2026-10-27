class Solution {
public:
    int val = 0;
    TreeNode* convertBST(TreeNode* root) {

        if(root)
        {
            convertBST(root->right);
            val += root->val;
            root->val = val;
            convertBST(root->left);
        }

        return root;
    }
};
