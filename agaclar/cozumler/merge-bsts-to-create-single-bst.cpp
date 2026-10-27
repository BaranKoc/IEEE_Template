class Solution {
public:
    TreeNode* canMerge(vector<TreeNode*>& trees) {

        unordered_map<int,TreeNode*> mp;

        unordered_map<TreeNode*,pair<int,int>> mini;
        for(int i=0;i<trees.size();i++)
        {
            pair<int,int> ans={trees[i]->val,trees[i]->val};
            if(trees[i]->left)
            {

                mp[trees[i]->left->val]={trees[i]};
                ans.first=trees[i]->left->val;
            }
            if(trees[i]->right)
            {
                mp[trees[i]->right->val]=trees[i];
                ans.second=trees[i]->right->val;
            }
            mini[trees[i]]=ans;
        }

        int count=0;
        int rootCount=0;
        TreeNode* root=NULL;

        for(int i=0;i<trees.size();i++)
        {

            if(mp.find(trees[i]->val)!=mp.end())
            {
                count++;

                TreeNode* parent=mp[trees[i]->val];
                if(trees[i]->val < parent->val)
                {

                    if(parent->val <= mini[trees[i]].second)
                        return NULL;

                    mini[parent].first=mini[trees[i]].first;

                    parent->left=trees[i];
                }
                else  if(trees[i]->val > parent->val)
                {

                    if(parent->val >= mini[trees[i]].first)
                        return NULL;

                    mini[parent].second=mini[trees[i]].second;

                    parent->right=trees[i];
                }

                mp.erase(trees[i]->val);
            }
            else{

                if(rootCount==1)
                    return NULL;
                else
                {
                    rootCount++;
                    root=trees[i];
                }
            }
        }

        if(count!=trees.size()-1)
            return NULL;
        return root;

    }
};
