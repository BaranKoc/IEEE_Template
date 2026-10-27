class Solution {
public:
    int solve(vector<int> &nums, int ans)
    {
        sort (nums.begin(), nums.end()) ;

        for (auto i : nums)
        {
            if (ans == i)
            {
                return solve (nums, ans*2);
            }
        }
        return ans ;
    }

    int findFinalValue(vector<int>& nums, int original) {
        int ans = original ;
        int result = solve (nums, ans) ;

        return result ;
    }
};
