class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        if(root -> left == NULL || root -> right == NULL) return false;

        queue<pair<TreeNode*, TreeNode*> > q;

        q.push({root, NULL});

        q.push({NULL, NULL});

        pair<bool, TreeNode*> foundx = {false, NULL}, foundy = {false, NULL};

        while(!q.empty()){
            TreeNode* top = q.front().first;
            TreeNode* parent = q.front().second;
            q.pop();

            if(top == NULL){

                if(foundx.first && foundy.first && foundx.second != foundy.second) return true;

                if(foundx.first || foundy.first) return false;

                if(!q.empty()) q.push({NULL, NULL});
            }
            else{

                if(top -> val == x) foundx = {true, parent};
                if(top -> val == y) foundy = {true, parent};

                if(top -> left) q.push({top -> left, top});
                if(top -> right) q.push({top -> right, top});
            }
        }
        return false;
    }
};
