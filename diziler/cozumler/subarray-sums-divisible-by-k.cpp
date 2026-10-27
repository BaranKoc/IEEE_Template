class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {

        int ans = 0;

        unordered_map<int, int> mapp;
        mapp.insert({0,1});

        int presum = 0;

        int rem = 0;

        for(int i=0; i<nums.size(); i++)
        {
            presum += nums[i];
            rem = presum % k;
            if(rem < 0)
                rem += k;

            if(mapp.find(rem) != mapp.end())
            {
                ans += mapp[rem];
                mapp[rem]++;
            }
            else
            {
                mapp.insert({rem,1});
            }
        }
        return ans;
    }
};
