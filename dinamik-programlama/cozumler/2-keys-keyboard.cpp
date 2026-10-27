class Solution {
public:

    int byPrimeFactorization(int n) {
        if(n == 1)
            return 0;
        if(n == 2)
            return 2;
        int factor = 2, ans = 0;
        while(n > 1) {
            while(n % factor == 0) {
                ans += factor;
                n /= factor;
            }
            factor++;
        }
        return ans;
    }

    int byDp(int n) {
        vector<int> dp(1001, INT_MAX);
        dp[0] = dp[1] = 0;
        dp[2] = 2, dp[3] = 3;
        for(int i = 4; i <= n; i++) {
            dp[i] = i;
            for(int j = 2; j <= i / 2; j++) {
                int x = i - j;
                if(x % j == 0) {
                    dp[i] = min(dp[i], dp[j] + 1 + (x / j));
                }
            }
        }
        return dp[n];
    }

    int minSteps(int n) {
        return byPrimeFactorization(n);
    }
};
