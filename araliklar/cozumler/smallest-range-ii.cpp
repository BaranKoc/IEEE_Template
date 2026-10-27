class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int mn = nums.front();
        int mx = nums.back();
        if(mx - mn <= k) return mx - mn;
        int newMn = INT_MAX, newMx = INT_MIN;
        int ans = mx - mn;
        mn = mn + k;
        mx = mx - k;
        for(int i = 1; i < nums.size(); ++i){
            newMn = min(mn, nums[i] - k);
            newMx = max(mx, nums[i-1] + k);
            ans = min(ans, newMx - newMn);
        }
        return ans;
    }

};
