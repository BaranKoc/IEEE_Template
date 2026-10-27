class Solution {

private:

    int MOD = 1e9 + 7;

public:

    int sumOfFlooredPairs(vector<int>& nums) {

        int max_n = INT_MIN;
        for(int n : nums) max_n = max(max_n, n);

        vector<int> occs(max_n + 1, 0);
        for(int n : nums) occs[n]++;

        vector<int> occs_acc(max_n + 1, 0);
        for(int i = 1; i < max_n + 1; ++i) {
            occs_acc[i] = occs[i] + occs_acc[i - 1];
        }

        long long ans = 0;
        for(int i = 0; i < max_n + 1; ++i) {

            if(occs[i] != 0) {

                int k = 1;
                int k_next;

                do {

                    k_next = k + 1;

                    int r = min(k_next * i - 1, max_n);
                    int l = k * i - 1;

                    ans += ((long long) occs_acc[r] - (long long) occs_acc[l]) * (long long) occs[i] * k++;

                } while(k_next * i - 1 < max_n);
            }
        }

        return ans % MOD;
    }
};
