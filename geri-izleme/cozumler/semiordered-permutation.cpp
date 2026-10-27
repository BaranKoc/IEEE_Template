class Solution {
public:
    int semiOrderedPermutation(vector<int>& nums) {
        int n = nums.size();
        int ind_One = find(nums.begin(), nums.end(), 1) - nums.begin(), ind_N = find(nums.begin(), nums.end(), n) - nums.begin();
        int Result = ind_One + n - (ind_N + 1);
        if(ind_One > ind_N)
            return Result - 1;
        return Result;
    }
};
