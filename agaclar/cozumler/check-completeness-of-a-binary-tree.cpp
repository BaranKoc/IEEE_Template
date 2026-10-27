class Solution {
public:
    bool isComplete = true;

    pair<int,int> helper(TreeNode *root){

        if(root == NULL){
            return {0, 0};
        }

        pair<int,int> lst = helper(root->left);
        pair<int,int> rst = helper(root->right);

        if(rst.second > lst.first || lst.second - rst.first > 1){
            isComplete = false;
        }

        return {min(lst.first, rst.first)+1, max(lst.second, rst.second)+1};
    }

    bool isCompleteTree(TreeNode* root) {
        helper(root);
        return isComplete;
    }
};
