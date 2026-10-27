**	#Vote if u like ❤️**

	class Solution {
	public:
		void fun(TreeNode *root , int l , map<int , vector<int>> &m)
		{
			if(root == NULL) return;
			m[l].push_back(root -> val);
			fun(root -> left, l + 1, m);
			fun(root -> right, l + 1 , m);
		}
		int deepestLeavesSum(TreeNode* root) {
			map<int , vector<int>> m;
			fun(root , 0 , m);
		   auto itr = m.rbegin();
			int sum = 0;
			for(int i = 0; i < itr-> second.size(); i++) {sum += itr -> second[i];}
			return sum;
		}
	};

														-Yash:)
