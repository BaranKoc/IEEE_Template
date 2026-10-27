class Solution {
public:
   int dp[1001][2001];
   int solve(vector<vector<int>>&v,int index,int coin)
   {
       if(index>=v.size()||coin==0)
           return 0;
       if(dp[index][coin]!=-1)
           return dp[index][coin];

       int ans=solve(v,index+1,coin);

       int loop=v[index].size()-1;
       int sum=0;

       for(int j=0;j<=min(coin-1,loop);j++)
       {
           sum=sum+v[index][j];
           ans=max(ans,sum+solve(v,index+1,coin-(j+1)));

       }

       return dp[index][coin]=ans;
   }
   int maxValueOfCoins(vector<vector<int>>& piles, int k) {
       memset(dp,-1,sizeof(dp));
       return solve(piles,0,k);
   }
};
