class Solution {
public:
    string res;
    void solve(TreeNode* root,string cur){
        if(!root) return;
        cur.push_back((char)('a'+root->val));
        if(!root->left and !root->right){

            reverse(cur.begin(),cur.end());
            if(res=="" or cur<res) res=cur;
            return;
        }
        solve(root->left,cur);
        solve(root->right,cur);
        return;
    }
    string smallestFromLeaf(TreeNode* root) {
        if(!root) return "";
        solve(root,"");
        return res;
    }
};
