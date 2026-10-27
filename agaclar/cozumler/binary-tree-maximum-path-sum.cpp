class Solution {
public:
    int rec(TreeNode* root,int& res ){
        if(root==nullptr) return 0;

        int l = rec(root->left,res);

        int r = rec(root->right,res);

        res = max(res,root->val+l+r);

        return max({l+root->val,r+root->val,0});
    }
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        int x = rec(root,res);
        return res;
    }
};
