class Solution {
public:
    int stoneGameVII(vector<int>& S) {
        int N = S.size();
        vector<int> dp(N);
        for (int i = N - 2; ~i; i--) {
            int total = S[i];
            for (int j = i + 1; j < N; j++) {
                total += S[j];
                dp[j] = max(total - S[i] - dp[j], total - S[j] - dp[j-1]);
            }
        }
        return dp[N-1];
    }
};
