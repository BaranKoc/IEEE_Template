class Solution {
public:

    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(!root1 and !root2) return true ;
        if(!root1 or  !root2) return false ;
        if(root1->val != root2->val) return false ;

        bool a = flipEquiv(root1->left,root2->right) ;
        bool b = flipEquiv(root1->right,  root2->left) ;

        bool aa = flipEquiv(root1->left,root2->left) ;
        bool bb = flipEquiv(root1->right,root2->right) ;

        return (a and b) || (aa and bb );
    }
};
