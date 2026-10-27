class Solution {
public:
	int minSwapsCouples(vector<int>& row) {
		int cnt=0,n=row.size();

		for(auto &x : row){
			if(x&1){
				x--;
			}
		}

		for( int i=0; i<n; i+=2){
			int ele=row[i];
			int j=i+1;

			while(j<n and row[j]!=ele) j++;
			if(j!=i+1){

				swap(row[j], row[i+1]);
				cnt++;
			}
		}
		return cnt;
	}
};
