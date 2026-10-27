class Solution {
public:

	int dp[105][105];

	int changes(int i , int j , string& s){
		int cnt = 0;
		while(i < j){
			cnt += (s[i++] != s[j--]);
		}
		return cnt;
	}

	int recur(int idx, int k, string &s){

		if(idx == s.size()){
			return (k == 0) ? 0 : 1e7;
		}

		if(k == 0){
			return 1e7;
		}

		if (dp[idx][k] != -1){
			return dp[idx][k];
		}

		int ans = INT_MAX;
		for (int i = idx ; i < s.size() ; i++){
			ans = min(ans , changes(idx , i , s) + recur(i + 1, k - 1, s));
		}
		return dp[idx][k] = ans;
	}

	int palindromePartition(string s, int k) {

		if(k == s.size()){
			return 0;
		}
		memset(dp , -1 , sizeof(dp));
		return recur(0 , k , s);
	}

};
