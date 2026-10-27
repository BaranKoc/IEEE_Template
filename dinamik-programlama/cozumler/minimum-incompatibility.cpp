const int INF = 1e9;

class Solution {
public:
    int minimumIncompatibility(vector<int>& nums, int k) {
        int i, n = nums.size(), subset_size = n / k;
        sort(nums.begin(), nums.end());

        vector<int> range(1 << n, INF);

        for(int mask = 1; mask < (1 << n); mask++) {
            int small = -1, big = -1;
            bool dup = false;

            for(i=0; i<n && !dup; i++)
                if(mask & (1 << i)) {
                    if(small == -1)
                        small = nums[i];
                    if(big == nums[i])
                        dup = true;
                    big = nums[i];
                }

            if(!dup)
                range[mask] = big - small;
        }

        vector<int> dp(1 << n, INF);
        dp[0] = 0;

        for(int mask = 1; mask < (1 << n); mask++) {

            for(int submask = mask; submask; submask = (submask - 1) & mask) {

                if(__builtin_popcount(submask) == subset_size)

                    dp[mask] = min(dp[mask], range[submask] + dp[mask ^ submask]);
            }
        }

        return dp.back() >= INF ? -1 : dp.back();
    }
};
