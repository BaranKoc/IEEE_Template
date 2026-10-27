class Solution
{
    public:
    vector<TreeNode*> solve(int start, int end)
    {

        if(start>end){
            return {NULL};
        }
        vector<TreeNode*> lChild, rChild, res;

        for(int i=start; i<=end; i++)
        {

            lChild = solve(start, i-1);
            rChild = solve(i+1, end);

            for(auto l: lChild)
            {
                for(auto r: rChild)
                {

                    TreeNode* node = new TreeNode(i);

                    node->left = l;
                    node->right = r;
                    res.push_back(node);
                }
            }
        }

        return res;
    }
    vector<TreeNode*> generateTrees(int n) {
        return solve(1, n);
    }
};
