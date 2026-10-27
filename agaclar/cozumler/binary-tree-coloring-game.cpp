class Solution {
public:

    TreeNode *nodex, *parentx;
    Solution(){
        nodex = NULL;
        parentx = NULL;
    }
    int count(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        int a = count(root->left);
        int b = count(root->right);
        return a + b + 1;
    }
    bool findx(TreeNode *root, int x)
    {
        if (root == NULL)
            return false;
        parentx = root;
        if (root->val == x)
        {
            nodex = root;
            return true;
        }
        bool a = findx(root->left, x);
        if (a)
            return true;
        bool b = findx(root->right, x);
        return b;
    }
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        findx(root, x);
        int p = n - count(nodex);
        int r = count(nodex->right);
        int l = count(nodex->left);
        int mx = max(p,r);
        mx = max(mx, l);
        if (mx > n/2)
            return true;
        else
            return false;
    }
};
