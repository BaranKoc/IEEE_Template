class Solution(object):

    def countTexts(self, pressedKeys):
        dp = [1] + [0] * len(pressedKeys)
        mod = 10 ** 9 + 7
        for i, n in enumerate(pressedKeys):
            dp[i + 1] = dp[i]
            if i >= 1 and pressedKeys[i - 1] == n:
                dp[i + 1] += dp[i - 1]
                dp[i + 1] %= mod
                if i >= 2 and pressedKeys[i - 2] == n:
                    dp[i + 1] += dp[i - 2]
                    dp[i + 1] %= mod
                    if i >= 3 and pressedKeys[i - 3] == n and (n == '7' or n == '9'):
                        dp[i + 1] += dp[i - 3]
                        dp[i + 1] %= mod
        return dp[-1]
