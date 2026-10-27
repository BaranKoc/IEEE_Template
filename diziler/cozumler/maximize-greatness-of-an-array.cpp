class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int ans=0;
        int ind=n-1;
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i]<nums[ind])
            {
                ind--;
                ans++;
            }
        }
        return ans;
    }
};
