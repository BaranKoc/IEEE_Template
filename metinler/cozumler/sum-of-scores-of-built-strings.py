class Solution:

    def sumScores(self, s):
        n = len(s)
        dp, ans, j = ([1] * n, [0] * n, 0)
        for i in range(1, n):
            while s[i] != s[j] and j > 0:
                j = ans[j - 1]
            if s[i] == s[j]:
                dp[i] += dp[j]
                ans[i] = j + 1
                j += 1
        return sum(dp)
