class Solution {
public:
    TreeNode* prev;
    Solution(){
        prev = NULL;
    }
    bool isValidBST(TreeNode* root) {
        if (root == NULL)
            return true;
        bool a = isValidBST(root->left);
        if (!a)
            return false;
        if (prev != NULL)
        {
            if (prev->val >= root->val)
                return false;
        }
        prev = root;
        return isValidBST(root->right);
    }
};
