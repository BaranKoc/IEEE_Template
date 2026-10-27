class Solution {
public:
    int minPairSum(vector<int>& nums){

        sort(nums.begin(),nums.end());
        int start=0,end=nums.size()-1,min_max_pair_sum=0;

        while(start<end){
            min_max_pair_sum=max(min_max_pair_sum,nums[start++]+nums[end--]);
        }
        return min_max_pair_sum;
    }
};
