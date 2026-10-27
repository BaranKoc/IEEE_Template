class Solution {
public:

    int deleteAndEarn(vector<int>& nums)
    {
        int size = nums.size();

        vector<int> memo(10001 , 0);
        vector<int> res(10001 , 0);

        for(auto num : nums)
            res[num]++;

        for(int i = 0 ; i < 10001 ; i++)
            memo[i] += (i < 3) ? (i * res[i]) : (i * res[i]) + max(memo[i-2] , memo[i-3]);

        return max(memo[10000] , memo[9999]);
    }
};
