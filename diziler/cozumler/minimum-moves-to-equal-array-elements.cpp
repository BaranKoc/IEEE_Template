class Solution {
public:
    int minMoves(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        int cnt = 0, n = nums.size();

        for(int i = 1; i < n; i++)
            cnt += nums[i] - nums[0];

        return cnt;
    }
};
