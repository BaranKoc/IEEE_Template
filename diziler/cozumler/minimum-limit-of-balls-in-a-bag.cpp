class Solution {
public:
    bool isPossible(vector<int>&nums,int mid_penalty,int maxOperations)
    {
        int operations=0;

        for(int i=0;i<nums.size();i++)
        {
            operations+=(nums[i]/mid_penalty);
            if(nums[i]%mid_penalty==0)
                operations--;
        }

        return operations<=maxOperations?1:0;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int low_penalty=1,high_penalty=*max_element(nums.begin(),nums.end());
        int ans=high_penalty;
        while(low_penalty<=high_penalty)
        {
            int mid_penalty=low_penalty+(high_penalty-low_penalty)/2;
            if(mid_penalty==0)
                break;
            if(isPossible(nums,mid_penalty,maxOperations))
            {
                ans=mid_penalty;
                high_penalty=mid_penalty-1;
            }
            else
                low_penalty=mid_penalty+1;
        }
        return ans;
    }
};
