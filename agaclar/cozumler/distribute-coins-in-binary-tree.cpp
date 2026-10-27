class Solution {
public:

    int traverse(TreeNode* root, int &moves)
    {
        if(!root) return 0;

        int left = traverse(root->left,moves);

        int right = traverse(root->right,moves);

        moves += abs(left) + abs(right);

        return root->val + left + right -1;
    }

    int distributeCoins(TreeNode* root) {

        int moves = 0;
        traverse(root,moves);
        return moves;
    }
};
