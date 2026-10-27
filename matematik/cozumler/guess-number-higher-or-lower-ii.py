class Solution:

    def getMoneyAmount(self, n):

        @lru_cache(None)
        def dp(l=1, r=n) -> int:
            if r - l < 1:
                return 0
            ans = 1000
            for choice in range((l + r) // 2, r):
                ans = min(ans, choice + max(dp(l, choice - 1), dp(choice + 1, r)))
            return ans
        return dp()
