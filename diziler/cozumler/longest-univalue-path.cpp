class Solution {
public:
    int maxlen=0;
    pair<int,int> util(TreeNode* root,int val ){
        if(!root)
            return {0,-1001};

        pair<int,int> l=util(root->left,root->val);
        pair<int,int> r=util(root->right,root->val);

        if(l.second==root->val && r.second==root->val){
          maxlen=max(maxlen,l.first+r.first+1);
          return {max(l.first,r.first)+1,root->val};

        }

        else if(l.second==root->val){
            maxlen=max(maxlen,l.first+1);
            return {l.first+1,root->val};
        }
        else if(r.second==root->val){
            maxlen=max(maxlen,r.first+1);
            return {r.first+1,root->val};
        }
        else{
            return {1,root->val};
        }

    }
    int longestUnivaluePath(TreeNode* root) {
        if(!root)
            return 0;
        util(root,root->val);
        return max(maxlen-1,0);

    }
};
