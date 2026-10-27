class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int n =  nums.size();
        int si =0;
        int ei = 0;
        int result =0, prev_count =0;
        while(ei < n){
            if(left <= nums[ei]  &&  nums[ei]<= right){
              prev_count = ei- si +1;
              result += prev_count;
            }else if (  nums[ei] < left){
                 result += prev_count;
            }else{

                si = ei +1;
                prev_count =0;
            }
            ei++;
       }
      return result;
    }
};
