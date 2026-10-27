class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mn = nums[0], mx = nums[0];
        for(auto n: nums)
        {

            if(n > mx) mx = n;
            if(n < mn) mn = n;
        }

        for(int i = mn; i >= 1; i--)
        {

            if((mn % i == 0) && (mx % i == 0)) return i;
        }
        return 1;
    }
};
