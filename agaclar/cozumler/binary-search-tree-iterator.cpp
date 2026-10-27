class BSTIterator {
public:
    stack<TreeNode*> stk;
    BSTIterator(TreeNode* root) {
        pushAll(root);

    }

    int next() {

        TreeNode* node = stk.top();
        int ans = node->val;
        stk.pop();

        pushAll(node->right);

        return ans;

    }

    bool hasNext() {
        return stk.size() != 0;
    }

    void pushAll(TreeNode* root){

        while(root!= NULL){
            stk.push(root);
            root = root->left;
        }

    }
};
