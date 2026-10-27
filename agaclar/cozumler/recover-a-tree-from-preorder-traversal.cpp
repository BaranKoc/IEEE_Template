class Solution {
public:

    int findIndex(int ind, string &traversal){
        int req = traversal.size();
        for(int i=ind; i<traversal.size(); i++){
            if(traversal[i] == '-'){
                req = i;
                break;
            }
        }
        return req;
    }

    TreeNode* recoverFromPreorder(string traversal) {

        int depth = 0;
        stack<pair<TreeNode*,int>> st;

        int ind = findIndex(0, traversal);
        string str = traversal.substr(0, ind);
        TreeNode *root = new TreeNode(stoi(str));

        st.push({root, 0});

        int i = ind;

        while(i<traversal.size()){

            if(traversal[i] == '-'){
                depth++;
                i++;
                continue;
            }

            int ind = findIndex(i, traversal);
            string str = traversal.substr(i, ind-i);
            TreeNode *node = new TreeNode(stoi(str));

            while(!st.empty() && st.top().second != depth-1){
                st.pop();
            }

            if(st.top().first->left){
                st.top().first->right = node;
            }
            else{
                st.top().first->left = node;
            }

            st.push({node, depth});
            depth = 0;
            i = ind;
        }

        return root;
    }
};
