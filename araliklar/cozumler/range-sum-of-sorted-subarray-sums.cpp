class Solution
{
public:
    int rangeSum(vector<int>& nums, int n, int left, int right)
    {
        const int m= 1e9+7;
        int ans=0;
        int k=1;
        int size= (n*(n+1))/2;
        vector<int> subsum(size+1);
        for(int i=0;i<n;i++)
        {
            int sum=0;
            for(int j=i;j<n;j++)
            {
                sum+=nums[j];
                subsum[k++]=sum;
            }
        }
        sort(subsum.begin(),subsum.end());
        for(int i=left; i<=right; i++)
        {
            ans=(ans+subsum[i])%m;
        }
        return ans;
    }
};
