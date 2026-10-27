class Solution {
public:
    int largestPerimeter(vector<int>& nums) {

        sort(nums.begin(),nums.end());

        for (int i=nums.size()-2; i>=1 ; i--){

        if (nums[i]+nums[i-1] >nums[i+1])return (nums[i]+nums[i+1]+nums[i-1]);
        }
        return 0;

    }
};
