class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        int n = nums.size();

        sort(begin(nums), end(nums));

        long long sum = 0;

        int prev = 0, curr = 0;

        for(int i=0; i<n; i++) {

            curr = nums[i];

            long long diff = (curr - prev - 1);

            if(diff <= 0) {
                prev = curr;
                continue;
            }

            if(diff > k) {
                diff = k;
                curr = prev + k + 1;
            }

            sum += (diff * 1LL * (curr + prev) / 2);

            prev = curr;

            k -= diff;

            if(k == 0) break;
        }

        if(k) {
            sum += (k * 1LL * (2 * prev + k + 1) / 2);
        }

        return sum;
    }
};
