class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {

        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<int> ans;
        for(int i = 0; i < n; i++)
        {
            vector<int> tmp;
            tmp.push_back(nums[i]);

            int j = i - 1;
            while(j >= 0)
            {
                if(tmp.back() % nums[j] == 0)
                    tmp.push_back(nums[j]);

                j--;
            }

            reverse(tmp.begin(), tmp.end());

            j = i + 1;
            while(j < n)
            {
                if(nums[j] % tmp.back() == 0)
                    tmp.push_back(nums[j]);

                j++;
            }

            if(ans.size() < tmp.size())
                ans = tmp;
        }

        return ans;
    }
};
