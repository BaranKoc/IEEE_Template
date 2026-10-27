class Solution {
public:

    void getLeafOrder(TreeNode* root, vector<int> &leafOrder){
        if(root == NULL){
            return;
        }

        if(root->left == NULL and root->right == NULL){
            leafOrder.push_back(root->val);
            return;
        }

        getLeafOrder(root->left, leafOrder);
        getLeafOrder(root->right, leafOrder);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leafOrder1;
        vector<int> leafOrder2;

        getLeafOrder(root1, leafOrder1);
        getLeafOrder(root2, leafOrder2);

        return leafOrder1 == leafOrder2;
    }
};
