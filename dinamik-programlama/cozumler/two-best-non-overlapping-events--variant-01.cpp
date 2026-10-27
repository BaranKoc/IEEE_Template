class Solution {
public:

    int maxTwoEvents(vector<vector<int>>& events) {
        int n=events.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));

        sort(events.begin(),events.end());

        return solve(events,0,0,dp);
    }

    int solve(vector<vector<int>>&nums,int idx,int k,vector<vector<int>>&dp)
    {

        if(k==2)
        {
            return 0;
        }
        if(idx>=nums.size())
        {
            return 0;
        }

        if(dp[idx][k]!=-1)
        {
            return dp[idx][k];
        }

        vector<int>ans={nums[idx][1],INT_MAX,INT_MAX};

        int nextindex=upper_bound(begin(nums),end(nums),ans)-begin(nums);

        int include=nums[idx][2]+solve(nums,nextindex,k+1,dp);

        int exclude=solve(nums,idx+1,k,dp);

        return dp[idx][k]=max(include,exclude);
    }
};
