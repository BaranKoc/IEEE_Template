class Solution {
public:
    TreeNode* temp;
    vector<int>z;
    TreeNode* increasingBST(TreeNode* root)
    {
        incresing(root);
        sort(z.begin(), z.end());
        temp = new TreeNode(z[0]);
        create(temp, z);
        return temp;
    }
    void incresing(TreeNode* root)
    {
        if(root == NULL)  return;

        z.push_back(root->val);
        incresing(root->left);
        incresing(root->right);
    }
    void create(TreeNode* create, vector<int> ze)
    {

        for(int i = 1; i<ze.size(); i++)
        {
            cout<<ze[i]<<endl;
            create->right = new TreeNode(ze[i]);
            create = create->right;
        }
    }
};
