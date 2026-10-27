class Solution {
public:
	void sortmat(int i,int j,vector<vector<int>>& mat,int m,int n,vector<int>& temp){
		if(i>=m || j>=n){
			sort(temp.begin(),temp.end());
			return ;
		}
		temp.push_back(mat[i][j]);
		sortmat(i+1,j+1,mat,m,n,temp);
		mat[i][j]=temp.back();
		temp.pop_back();
	}

	vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
		int m=mat.size();
		int n=mat[0].size();
		vector<int>temp;

		for(int j=0;j<n;j++) sortmat(0,j,mat,m,n,temp);

		for(int i=1;i<m;i++) sortmat(i,0,mat,m,n,temp);
		return mat;
	}
};
