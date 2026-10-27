class Solution {
public:
    vector<int> dp(TreeNode* root)
    {
        vector<int> ans(2,0);
        if(root==NULL) return ans;
        vector<int> left=dp(root->left);
        vector<int> right=dp(root->right);
        ans[0]=root->val+left[1]+right[1];
        ans[1]=max(left[0],left[1])+max(right[0],right[1]);
        return ans;
    }
    int rob(TreeNode* root) {
        vector<int> ans=dp(root);
        return max(ans[0],ans[1]);
    }
};
