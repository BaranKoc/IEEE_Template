class Solution {
public:
    TreeNode* help(int &i,vector<int>& preorder, int bound ){
        if(i==preorder.size() || preorder[i] > bound)
            return NULL;
         TreeNode* root = new TreeNode(preorder[i++]);
         root->left = help(i,preorder,root->val);
         root->right = help(i,preorder,bound);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {

        int i=0;
        return help(i,preorder,INT_MAX);
    }
};
