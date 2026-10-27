#define ll long long

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {

        sort(nums.begin(), nums.end());

        int left = 0, right = 0, ans = 1;
        ll total = 0, n = nums.size();
        while(right < n){

            total += nums[right];

            while((1ll)*(right - left + 1)*nums[right] - total > k){
                total -= nums[left];
                left++;
            }

            ans = max(ans, right - left + 1);
            right++;
        }
        return ans;
    }
};
