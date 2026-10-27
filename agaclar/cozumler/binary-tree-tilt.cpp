class Solution {
public:

    int getTiltSum(TreeNode* root, int &tiltSum){
        if(root == NULL){
            return 0;
        }
        if(root->left == NULL and root->right == NULL){
            tiltSum+=0;
            return root->val;
        }

        int leftSubTreeSum = getTiltSum(root->left, tiltSum);
        int rightSubTreeSum = getTiltSum(root->right, tiltSum);

        tiltSum += abs(leftSubTreeSum - rightSubTreeSum);

        return (root->val + leftSubTreeSum + rightSubTreeSum);

    }

    int findTilt(TreeNode* root) {

        int tiltSum = 0;

        getTiltSum(root, tiltSum);

        return tiltSum;
    }
};
