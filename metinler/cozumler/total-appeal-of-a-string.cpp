class Solution {
public:
	long long appealSum(string s) {
		int n = s.size();
		long long ans = 0;
		for(char ch='a';ch<='z';ch++)
		{
			int prev = 0;
			for(int i=0;i<n;i++)
			{
				if(s[i] == ch) prev = i+1;

				ans+=prev;

			}
		}
		return ans;
	}
};
