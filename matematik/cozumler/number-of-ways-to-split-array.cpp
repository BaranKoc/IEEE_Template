class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {

        long long sumFromBack(0), sumFromFront(0);
        for (auto& i : nums) sumFromBack += i;

        int n(size(nums)), res(0);
        for (auto i=0; i<n-1; i++) {

            sumFromFront += nums[i];
            sumFromBack -= nums[i];
            if (sumFromFront >= sumFromBack) res++;
        }
        return res;
    }
};
