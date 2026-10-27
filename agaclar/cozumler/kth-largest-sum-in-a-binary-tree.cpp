class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<vector<int>>v;
        int i,n;
        if(!root)return -1;
        queue<TreeNode*>q;
        priority_queue<long long>pq;
        q.push(root);
        while(!q.empty()){
            n=q.size();
            long long sum=0;
            for(i=0;i<n;i++){
                TreeNode* x = q.front();
                q.pop();
                sum+=x->val;
                if(x->left)q.push(x->left);
                if(x->right)q.push(x->right);
            }
            pq.push(sum);
        }
        if(pq.size()<k)return -1;
        k=k-1;
        while(k--)pq.pop();
        return pq.top();
    }
};
