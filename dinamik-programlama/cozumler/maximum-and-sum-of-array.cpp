class Solution {
private:
    int dp[20][60000];
    vector<int> a;
    int n;
    int k;

    int ans;
    int h[12];
    int search(int start, int mask) {
        if (start == n) return 0;
        if (dp[start][mask] != -1) return dp[start][mask];

        for (int i = 1; i <= k; i++) {
            int cnt = (mask % h[i+1]) / h[i];
            if (cnt <= 1) {
                dp[start][mask] = max(dp[start][mask], (a[start] & i) + search(start+1, mask + h[i]));
            }
        }
        return dp[start][mask];
    }
public:
    int maximumANDSum(vector<int>& nums, int numSlots) {

        a.assign(nums.begin(), nums.end());
        memset(dp, -1, sizeof(dp));

        n = nums.size();
        k = numSlots;
        ans = 0;
        h[0] = 1;
        for (int i = 1; i < 12; i++)
			h[i] = h[i-1] * 3;
        return search(0, 0);
    }
};
