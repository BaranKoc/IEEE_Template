class Solution {
public:

    int waysToPartition(vector<int>& nums, int k) {
        unordered_map<long long int,int> left;
        unordered_map<long long int,int> right;

        long long int sum=accumulate(nums.begin(),nums.end(),0L);
        long long int leftSum=0;
        int n=nums.size();

        for(int i=0;i<n-1;i++){
            leftSum+=nums[i];
            long long int rightSum=sum-leftSum;
            long long int difference=leftSum-rightSum;
            right[difference]++;
        }

        int res=right[0];
        leftSum=0;
        for(int i=0;i<n;i++){
            long long int D=k-nums[i];
            res=max(res,right[-D]+left[D]);

            leftSum+=nums[i];
            long long int rightSum=sum-leftSum;
            left[leftSum-rightSum]++;
            right[leftSum-rightSum]--;
            if(right[leftSum-rightSum]==0){
                right.erase(leftSum-rightSum);
            }
        }
        return res;
    }
};
