class Solution {
public:

    bool helper(int &ind, TreeNode *root, vector<int> &voyage, vector<int> &ans){
        if(root == NULL || ind == voyage.size()){
            ind--;
            return true;
        }

        if(root->val != voyage[ind]){
            ans.clear();
            ans.push_back(-1);
            return false;
        }

        if(root->left && root->left->val != voyage[ind+1]){
            TreeNode *temp = root->left;
            root->left = root->right;
            root->right = temp;

            ans.push_back(root->val);
        }

        return helper(++ind, root->left, voyage, ans) &&
            helper(++ind, root->right, voyage, ans);
    }

    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        int ind = 0;
        vector<int> ans;
        helper(ind, root, voyage, ans);
        return ans;
    }
};
