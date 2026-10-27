class Solution {
public:
    int findMin(vector<int>& nums) {
        int result = -1;
        int first = nums[0];

        for(int i = 1; i<nums.size();i++){
            if(nums[i-1]>nums[i]){
                result = nums[i];
                break;
            }
        }

        if(result == -1) {
            return first;
        }
        return result;
    }
};
