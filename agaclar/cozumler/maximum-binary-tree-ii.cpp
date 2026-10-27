class Solution {
public:

    void insertIntoMaxTreeRec(TreeNode* root,TreeNode* newNode)
    {

        if(!root)
            return;
        if(root->right&&root->right->val<newNode->val)
        {
            newNode->left=root->right;
            root->right=newNode;

            return;

        }
        if(!root->right)
        {root->right=newNode;

        return;}

         insertIntoMaxTreeRec( root->right, newNode);

    }
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
         TreeNode* curr=new TreeNode(val);

        if(root->val<val)
        {
            curr->left=root;
            root=curr;
        }else
        {
              insertIntoMaxTreeRec( root, curr);

        }
        return root;

    }
};
