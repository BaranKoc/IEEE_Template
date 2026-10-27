class Solution {
public:
    int countNodes(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }
        return countNodes(root->left) + countNodes(root->right) + 1;
    }

    bool findTarget(TreeNode* root, int k) {
        int totalCount = countNodes(root);
        int count = 0;
        stack<TreeNode*> inorder;
        stack<TreeNode*> revInorder;

        TreeNode* currNode = root;
        while(currNode != NULL){
            inorder.push(currNode);
            currNode = currNode->left;
        }

        currNode = root;
        while(currNode != NULL){
            revInorder.push(currNode);
            currNode = currNode->right;
        }

        while(count < totalCount-1){
            TreeNode* inordertop = inorder.top();
            TreeNode* revinordertop = revInorder.top();
            if(inordertop->val + revinordertop->val == k){
                return true;
            }
            else if(inordertop->val + revinordertop->val > k){

                TreeNode* currtop = revinordertop;
                count++;
                revInorder.pop();
                if(currtop->left){
                    currtop = currtop->left;
                    while(currtop){
                        revInorder.push(currtop);
                        currtop = currtop->right;
                    }
                }
            }
            else{

                TreeNode* currtop = inordertop;
                count++;
                inorder.pop();
                if(currtop->right){
                    currtop = currtop->right;
                    while(currtop){
                        inorder.push(currtop);
                        currtop = currtop->left;
                    }
                }
            }
        }
        return false;
    }
};
