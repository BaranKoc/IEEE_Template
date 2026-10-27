class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {

        double ans = INT_MIN;

        int i = 0;
        int j = 0;
        int sum = 0;

        while(j<nums.size()){

            sum = sum+nums[j];

            if(j-i+1 < k){
                j++;
            }
            else if(j-i+1 == k){

                double nos = k*1.0;
                ans = max(ans, sum/nos);

                int v = nums[i];
                sum = sum - v;

                i++;
                j++;
            }
        }

        return ans;

    }
};
